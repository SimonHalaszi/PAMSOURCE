#include "brushsizebutton.hpp"

BrushSizeButton::BrushSizeButton(const Vector2& og) {
    origin = og;
    brushRadius = 0;
}

void BrushSizeButton::ChangeBrushRadius() {  
    if(CheckCollisionPointRec(GetMousePosition(), {(origin.x), (origin.y), BUTTON_LENGTH/2, BUTTON_HEIGHT})) {
        if(brushRadius == 0) {
            return;
        }
        --brushRadius;
    }
    if(CheckCollisionPointRec(GetMousePosition(), {(origin.x + BUTTON_LENGTH/2), (origin.y), BUTTON_LENGTH/2, BUTTON_HEIGHT})) {       
        if(brushRadius == 9) {
            return;
        }
        ++brushRadius;
    }
}

bool BrushSizeButton::Inside() {
    return CheckCollisionPointRec(GetMousePosition(), {(origin.x), (origin.y), BUTTON_LENGTH, BUTTON_HEIGHT});
}

void BrushSizeButton::Draw() {
    DrawRectangle((origin.x - BORDER_WIDTH), (origin.y - BORDER_WIDTH), (BUTTON_LENGTH + (BORDER_WIDTH * 2)), (BUTTON_HEIGHT + (BORDER_WIDTH * 2)), lightgray);
    DrawRectangle((origin.x), (origin.y), BUTTON_LENGTH, BUTTON_HEIGHT, black);

    Vector2 textSize = MeasureTextEx(font, "++", FONT_SIZE, FONT_SPACING);
    DrawTextEx(font, "--", {(origin.x + (BUTTON_LENGTH / 2 - textSize.x) / 2), (origin.y + (BUTTON_HEIGHT - textSize.y) / 2)}, FONT_SIZE, FONT_SPACING, lightgray); 
    DrawTextEx(font, "++", {(origin.x + (BUTTON_LENGTH / 2) + (BUTTON_LENGTH / 2 - textSize.x) / 2), (origin.y + (BUTTON_HEIGHT - textSize.y) / 2)}, FONT_SIZE, FONT_SPACING, lightgray);
    
    char* br = new char[2]; 
    br[0] = (brushRadius + '0');
    br[1] = '\0';

    Vector2 brTextSize = MeasureTextEx(font, br, FONT_SIZE, FONT_SPACING);
    DrawTextEx(font, br, {(origin.x + (BUTTON_LENGTH - brTextSize.x) / 2), (origin.y + (BUTTON_HEIGHT - brTextSize.y) / 2)}, FONT_SIZE, FONT_SPACING, lightgray); 
    
    delete [] br;    
}
