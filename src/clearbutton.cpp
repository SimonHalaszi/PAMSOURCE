#include "clearbutton.hpp"

ClearButton::ClearButton(const Vector2& og) {
    origin = og;
}

void ClearButton::Draw() {
    DrawRectangle((origin.x - BORDER_WIDTH), (origin.y - BORDER_WIDTH), (BUTTON_LENGTH + (BORDER_WIDTH * 2)), (BUTTON_HEIGHT + (BORDER_WIDTH * 2)), lightgray);
    DrawRectangle((origin.x), (origin.y), BUTTON_LENGTH, BUTTON_HEIGHT, black);
    Vector2 textSize = MeasureTextEx(font, "CLEAR", FONT_SIZE, FONT_SPACING);
    DrawTextEx(font, "CLEAR", {(origin.x + (BUTTON_LENGTH - textSize.x) / 2), (origin.y + (BUTTON_HEIGHT - textSize.y) / 2)}, FONT_SIZE, FONT_SPACING, lightgray);    
}

bool ClearButton::Inside() {
    return CheckCollisionPointRec(GetMousePosition(), {(CL_ORIGIN.x), (CL_ORIGIN.y), BUTTON_LENGTH, BUTTON_HEIGHT});
}