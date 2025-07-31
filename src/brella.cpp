#include "brella.hpp"
#include <string>

Brella::Brella() {
    currentColor = white; 
}

void Brella::DrawCurrentColor() {
    DrawRectangle((CC_ORIGIN.x - BORDER_WIDTH), (CC_ORIGIN.y - BORDER_WIDTH), (BUTTON_LENGTH + (BORDER_WIDTH * 2)), (BUTTON_LENGTH + (BORDER_WIDTH * 2)), lightgray);
    DrawRectangle((CC_ORIGIN.x), (CC_ORIGIN.y), BUTTON_LENGTH, BUTTON_LENGTH, currentColor);
}

void Brella::PrintFPS() {
    int FPS = GetFPS();
    std::cout << FPS << std::endl;
}

void Brella::Draw() {
    grid.Draw();
    
    if(grid.Inside()) {
        if(colorPickerButton.GetPickingColor() || (makeRectButton.GetMakingRect() && !makeRectButton.SelectedOnce())) {
            grid.DrawHoverHighlight(0);
        } 
        else if(makeRectButton.GetMakingRect() && makeRectButton.SelectedOnce()) {
            // DONT DRAW ANYTHING
        }
        else {
            grid.DrawHoverHighlight(brushSizeButton.GetBrushRadius());
        }
    }
    if(makeRectButton.SelectedOnce()) {
        grid.DrawRectSelection(makeRectButton.GetSelectionOne());
    }

    DrawCurrentColor();
    
    palette.Draw();
    brushSizeButton.Draw();
    exportButton.Draw();
    clearButton.Draw();
    redButton.Draw(currentColor);
    greenButton.Draw(currentColor);
    blueButton.Draw(currentColor);   
    makeRectButton.Draw(); 
    colorPickerButton.Draw();
}

void Brella::HandleInputs() {
    static bool waitForMouseRelease = false;

    if (!grid.Inside() && makeRectButton.SelectedOnce()) {
        makeRectButton.SetSelectionOne({-1000, -1000});
        makeRectButton.SetSelectionTwo({-1000, -1000});
        makeRectButton.SetMakingRect(false);
        waitForMouseRelease = false;
    }

    if (IsKeyPressed(KEY_E)) {
        currentColor = white;
    }
    if (IsKeyPressed(KEY_C)) {
        grid.CoverGrid(white);
    }
    if (IsKeyPressed(KEY_F)) {
        grid.CoverGrid(currentColor);
    }

    // Key Binding for
    if (IsKeyPressed(KEY_R)) {
        makeRectButton.Toggle();
    }

    // Typical Drawing
    if (!makeRectButton.GetMakingRect() && !colorPickerButton.GetPickingColor()) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            if (grid.Inside() && !waitForMouseRelease) {
                grid.FillInCircle(GetMousePosition(), brushSizeButton.GetBrushRadius(), currentColor);
            }
        }
    }

    // Checking for button clicks
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if (clearButton.Inside()) {
            grid.CoverGrid(white);
        }
        if (palette.Inside()) {
            currentColor = palette.SelectColor();
        }
        if (redButton.Inside()) {
            currentColor.r = redButton.ChangeChannel(currentColor);
        }
        if (greenButton.Inside()) {
            currentColor.g = greenButton.ChangeChannel(currentColor);
        }
        if (blueButton.Inside()) {
            currentColor.b = blueButton.ChangeChannel(currentColor);
        }
        if (brushSizeButton.Inside()) {
            brushSizeButton.ChangeBrushRadius();
        }
        if (colorPickerButton.Inside()) {
            colorPickerButton.Toggle();
        }
        if (makeRectButton.Inside()) {
            makeRectButton.Toggle();
        }
        if (exportButton.Inside()) {
            exportButton.ExportCanvas();
        }
    }
    
    // Handles MakeRect Logic
    if (!colorPickerButton.GetPickingColor() && makeRectButton.GetMakingRect() && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if (grid.Inside()) {
            makeRectButton.MakeRect(grid, currentColor);
            waitForMouseRelease = true;
        }
    }

    // Handles Color Picking Logic
    if (colorPickerButton.GetPickingColor() && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if (grid.Inside()) {
            colorPickerButton.ColorPicker(currentColor, grid);
            waitForMouseRelease = true;
        }
    }

    // Checking if Mouse button is released
    if (waitForMouseRelease && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        waitForMouseRelease = false;
    }

    // Debug function
    if (IsKeyPressed(KEY_ZERO)) {
        grid.PrintGridToConsole();
    }
}

