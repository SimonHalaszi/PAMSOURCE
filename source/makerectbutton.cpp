#include "makerectbutton.hpp"

MakeRectButton::MakeRectButton(const Vector2& og) {
    origin = og;
    makingRect = false;
    selectionOne = {-1000, -1000};
    selectionTwo = {-1000, -1000};
}

void MakeRectButton::MakeRect(Grid& grid, const Color& currentColor) {
    if(makingRect) {
        if(selectionOne.x != -1000) {
            selectionTwo = GetMousePosition();
            grid.FillInRect(selectionOne, selectionTwo, currentColor);
            selectionOne = {-1000, -1000};
            selectionTwo = {-1000, -1000};
            makingRect = false;
        } else {
            selectionOne = GetMousePosition();
            return;
        }
    }    
}

void MakeRectButton::Toggle() {
    if(makingRect) {
        makingRect = false;
        selectionOne = {-1000, -1000};
        selectionTwo = {-1000, -1000};
    } else {
        makingRect = true;
    }    
}

bool MakeRectButton::Inside() {
    return CheckCollisionPointRec(GetMousePosition(), {(origin.x), (origin.y), BUTTON_LENGTH, BUTTON_HEIGHT});
}

void MakeRectButton::Draw() {
    DrawRectangle((origin.x - BORDER_WIDTH), (origin.y - BORDER_WIDTH), (BUTTON_LENGTH + (BORDER_WIDTH * 2)), (BUTTON_HEIGHT + (BORDER_WIDTH * 2)), lightgray);
    
    if(makingRect) {
        DrawRectangle((origin.x), (origin.y), BUTTON_LENGTH, BUTTON_HEIGHT, green);
    } else {
        DrawRectangle((origin.x), (origin.y), BUTTON_LENGTH, BUTTON_HEIGHT, black);
    }
    
    Vector2 textSize = MeasureTextEx(font, "MK RECT", FONT_SIZE, FONT_SPACING);
    DrawTextEx(font, "MK RECT", {(origin.x + (BUTTON_LENGTH - textSize.x) / 2), (origin.y + (BUTTON_HEIGHT - textSize.y) / 2)}, FONT_SIZE, FONT_SPACING, lightgray);
}