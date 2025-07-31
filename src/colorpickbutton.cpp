#include "colorpickerbutton.hpp"

ColorPickerButton::ColorPickerButton(const Vector2& og) {
    origin = og;
    pickingColor = false;
}

void ColorPickerButton::Toggle() {
    if(pickingColor) {
        pickingColor = false;
    } else {
        pickingColor = true;
    }    
}

void ColorPickerButton::ColorPicker(Color& currentColor, Grid& grid) {
    currentColor = grid.ColorGetter(GetMousePosition());
    pickingColor = false;
}

bool ColorPickerButton::Inside() {
    return CheckCollisionPointRec(GetMousePosition(), {(origin.x), (origin.y), BUTTON_LENGTH, BUTTON_HEIGHT});
}

void ColorPickerButton::Draw() {
    DrawRectangle((origin.x - BORDER_WIDTH), (origin.y - BORDER_WIDTH), (BUTTON_LENGTH + (BORDER_WIDTH * 2)), (BUTTON_HEIGHT + (BORDER_WIDTH * 2)), lightgray);
    
    if(pickingColor) {
        DrawRectangle((origin.x), (origin.y), BUTTON_LENGTH, BUTTON_HEIGHT, green);
    } else {
        DrawRectangle((origin.x), (origin.y), BUTTON_LENGTH, BUTTON_HEIGHT, black);
    }
    
    Vector2 textSize = MeasureTextEx(font, "GET COL", FONT_SIZE, FONT_SPACING);
    DrawTextEx(font, "GET COL", {(origin.x + (BUTTON_LENGTH - textSize.x) / 2), (origin.y + (BUTTON_HEIGHT - textSize.y) / 2)}, FONT_SIZE, FONT_SPACING, lightgray);    
}