#include "rgbbutton.hpp"

RGBButton::RGBButton(const Vector2 og, Channel ch) {
    origin = og;
    channel = ch;
}

void RGBButton::Draw(const Color& color) const {
    DrawRectangle((origin.x - BORDER_WIDTH), (origin.y - BORDER_WIDTH), (BUTTON_LENGTH + (BORDER_WIDTH * 2)), (BUTTON_HEIGHT + (BORDER_WIDTH * 2)), lightgray);
    
    switch(channel) {
        case Rgb:
            DrawRectangle((origin.x), (origin.y), BUTTON_LENGTH, BUTTON_HEIGHT, {color.r, 0, 0, 255});
            break;
        case rGb:
            DrawRectangle((origin.x), (origin.y), BUTTON_LENGTH, BUTTON_HEIGHT, {0, color.g, 0, 255});
            break;
        case rgB:
            DrawRectangle((origin.x), (origin.y), BUTTON_LENGTH, BUTTON_HEIGHT, {0, 0, color.b, 255});
            break;
    }
    
    Vector2 textSize = MeasureTextEx(font, "++", FONT_SIZE, FONT_SPACING);
    DrawTextEx(font, "--", {(origin.x + (BUTTON_LENGTH / 2 - textSize.x) / 2), (origin.y + (BUTTON_HEIGHT - textSize.y) / 2)}, FONT_SIZE, FONT_SPACING, lightgray); 
    DrawTextEx(font, "++", {(origin.x + (BUTTON_LENGTH / 2) + (BUTTON_LENGTH / 2 - textSize.x) / 2), (origin.y + (BUTTON_HEIGHT - textSize.y) / 2)}, FONT_SIZE, FONT_SPACING, lightgray);
}

bool RGBButton::Inside() const {
    return CheckCollisionPointRec(GetMousePosition(), {(origin.x), (origin.y), BUTTON_LENGTH, BUTTON_HEIGHT});
}

int RGBButton::ChangeChannel(const Color& color) const {
    int value;
    
    switch(channel) {
        case Rgb:
            value = color.r;
            break;
        case rGb:
            value = color.g;
            break;
        case rgB:
            value = color.b;
            break;
    }    
    
    if(CheckCollisionPointRec(GetMousePosition(), {(origin.x), (origin.y), BUTTON_LENGTH/2, BUTTON_HEIGHT})) {
        if(value <= 5) {
            value = 0;
            return value;
        }
        value -= 5;
    }
    if(CheckCollisionPointRec(GetMousePosition(), {(origin.x + BUTTON_LENGTH/2), (origin.y), BUTTON_LENGTH/2, BUTTON_HEIGHT})) {       
        if(value >= 250) {
            value = 255;
            return value;
        }                
        value += 5;
    }    
    
    return value;
}