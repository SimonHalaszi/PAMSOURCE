#pragma once

#include "grid.hpp"
#include "colors.hpp"

class Brella {
    public:
        Brella() : currentColor(white), pickingColor(false) {}
        void Draw();
        void HandleInputs();
        
    private:
        Color currentColor;
        Grid grid;
        std::vector<Color> palette = GetPaletteColors();
        Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
        bool pickingColor;

        void SelectColor();
        void ColorPicker();
        
        void ChangeRedChannel();
        void ChangeGreenChannel();
        void ChangeBlueChannel();
        void ColorPickerToggle();

        void DrawCurrentColor();
        void DrawPalette();
        void DrawClearButton();
        void DrawRGBButtons();
        void DrawColorPickerButton();

        void DrawRedChannelButton();
        void DrawGreenChannelButton();
        void DrawBlueChannelButton();

        bool InGridArea();
        bool InPaletteArea();
        bool InClearButton();
        bool InColorPickerButton();        
        
        bool InRedChannelButton();
        bool InGreenChannelButton();
        bool InBlueChannelButton();
};