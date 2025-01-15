#include "brella.hpp"

void Brella::Draw() {
    grid.Draw();
    grid.DrawHoverHighlight();
    DrawCurrentColor();
    DrawPalette();
    DrawClearButton();
    DrawRGBButtons();
    DrawColorPickerButton();
}

void Brella::SelectColor() {
    int color = 0;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j, ++color) {
            if(CheckCollisionPointRec(GetMousePosition(), {float(544) + (i * 32), float(144) + (j * 32), 32, 32})) {
                currentColor = palette[color];
                return;
            }
        }
    }  
}

void Brella::HandleInputs() {
    if(IsKeyPressed(KEY_E)) {
        currentColor = white;
    }
    if(IsKeyPressed(KEY_R)) {
        grid.CoverGrid(white);
    }
    if(IsKeyPressed(KEY_F)) {
        grid.CoverGrid(currentColor);
    }
    if(!pickingColor && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        if(InGridArea()) {
            grid.ChangePixelColor(currentColor); 
        }
    }
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if(InClearButton()) {
            grid.CoverGrid(white);
        }        
        if(InPaletteArea()) {
            SelectColor();
        }       
        if(InRedChannelButton()) {
            ChangeRedChannel();
        }
        if(InGreenChannelButton()) {
            ChangeGreenChannel();
        }
        if(InBlueChannelButton()) {
            ChangeBlueChannel();
        }
        if(InColorPickerButton()) {
            ColorPickerToggle();
        }
    }
    if(pickingColor && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if(InGridArea()) {
            ColorPicker(); 
        }
    }
}

void Brella::ColorPicker() {
    currentColor = grid.ColorPicker();
    pickingColor = false;
}

void Brella::DrawCurrentColor() {
    DrawRectangle(544, 16, 96, 96, currentColor);
}

void Brella::DrawClearButton() {
    DrawRectangle(544, 272, 96, 32, white);
    DrawTextEx(font, "CLEAR", {552, 272}, 24, 6, {26, 28, 44, 255});
}

void Brella::DrawRedChannelButton() {
    DrawRectangle(544, 320, 96, 32, {currentColor.r, 0, 0, 255});
    DrawTextEx(font, " -", {544, 320}, 24, 6, {26, 28, 44, 255});
    DrawTextEx(font, " +", {592, 320}, 24, 6, {26, 28, 44, 255});
}

void Brella::DrawGreenChannelButton() {
    DrawRectangle(544, 368, 96, 32, {0, currentColor.g, 0, 255});
    DrawTextEx(font, " -", {544, 368}, 24, 6, {26, 28, 44, 255});
    DrawTextEx(font, " +", {592, 368}, 24, 6, {26, 28, 44, 255});
}

void Brella::DrawBlueChannelButton() {
    DrawRectangle(544, 416, 96, 32, {0, 0, currentColor.b, 255});
    DrawTextEx(font, " -", {544, 416}, 24, 6, {26, 28, 44, 255});
    DrawTextEx(font, " +", {592, 416}, 24, 6, {26, 28, 44, 255});
}

void Brella::DrawColorPickerButton() {
    if(pickingColor) {
        DrawRectangle(544, 464, 96, 32, green);
    } else {
        DrawRectangle(544, 464, 96, 32, white);
    }
    DrawTextEx(font, "GET COL.", {552, 464}, 24, 1, {26, 28, 44, 255});
}

void Brella::DrawRGBButtons() {
    DrawRedChannelButton();
    DrawGreenChannelButton();
    DrawBlueChannelButton();
}

void Brella::DrawPalette() {
    int color = 0;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j, ++color) {
            DrawRectangle(544 + (i * 32), 144 + (j * 32), 32, 32, palette[color]);
        }
    }
    DrawTextEx(font, "PALETTE", {544, 112}, 24, 3, white);
}

bool Brella::InGridArea() {
    return CheckCollisionPointRec(GetMousePosition(), {16, 16, GRID_SIZE_COLUMNS * grid.GetPixelSize(), GRID_SIZE_ROWS * grid.GetPixelSize()});
}

bool Brella::InPaletteArea() {
    return CheckCollisionPointRec(GetMousePosition(), {544, 144, 96, 96});
}

bool Brella::InClearButton() {
    return CheckCollisionPointRec(GetMousePosition(), {544, 272, 96, 32});
}

bool Brella::InRedChannelButton() {
    return CheckCollisionPointRec(GetMousePosition(), {544, 320, 96, 32});
}

bool Brella::InGreenChannelButton() {
    return CheckCollisionPointRec(GetMousePosition(), {544, 368, 96, 32});
}

bool Brella::InBlueChannelButton() {
    return CheckCollisionPointRec(GetMousePosition(), {544, 416, 96, 32});
}

bool Brella::InColorPickerButton() {
    return CheckCollisionPointRec(GetMousePosition(), {544, 464, 96, 32});
}

void Brella::ColorPickerToggle() {
    if(pickingColor) {
        pickingColor = false;
    } else {
        pickingColor = true;
    }
}

void Brella::ChangeRedChannel() {
    if(CheckCollisionPointRec(GetMousePosition(), {544, 320, 48, 32})) {
        currentColor.r -= 5;
    }
    if(CheckCollisionPointRec(GetMousePosition(), {592, 320, 48, 32})) {      
        currentColor.r += 5;
    }
}

void Brella::ChangeGreenChannel() {
    if(CheckCollisionPointRec(GetMousePosition(), {544, 368, 48, 32})) {
        currentColor.g -= 5;
    }
    if(CheckCollisionPointRec(GetMousePosition(), {592, 368, 48, 32})) {       
        currentColor.g += 5;
    }
}

void Brella::ChangeBlueChannel() {
    if(CheckCollisionPointRec(GetMousePosition(), {544, 416, 48, 32})) {
        currentColor.b -= 5;
    }
    if(CheckCollisionPointRec(GetMousePosition(), {592, 416, 48, 32})) {       
        currentColor.b += 5;
    }
}