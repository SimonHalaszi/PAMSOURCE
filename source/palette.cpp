#include "palette.hpp"

Palette::Palette(const Vector2& og, const Color colors[9]) {
    origin = og;
    for(int i = 0; i < 9; ++i) {
        paletteColors[i] = colors[i];
    }
} 

Color Palette::SelectColor() const {
    int color = 0;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j, ++color) {
            if(CheckCollisionPointRec(GetMousePosition(), {(origin.x + (i * BUTTON_HEIGHT)), (origin.y + (j * BUTTON_HEIGHT )), BUTTON_HEIGHT , BUTTON_HEIGHT})) {
                return paletteColors[color];
            }
        }
    }
    return black;    
}

void Palette::Draw() const {
    DrawRectangle((origin.x - BORDER_WIDTH), (origin.y - BORDER_WIDTH), (BUTTON_LENGTH + (BORDER_WIDTH * 2)), (BUTTON_LENGTH + (BORDER_WIDTH * 2)), lightgray);
    int color = 0;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j, ++color) {
            DrawRectangle((origin.x) + (i * BUTTON_HEIGHT), (origin.y) + (j * BUTTON_HEIGHT), BUTTON_HEIGHT, BUTTON_HEIGHT, paletteColors[color]);
        }
    }    
}

bool Palette::Inside() const {
    return CheckCollisionPointRec(GetMousePosition(), {(origin.x), (origin.y), BUTTON_LENGTH, BUTTON_LENGTH});
}