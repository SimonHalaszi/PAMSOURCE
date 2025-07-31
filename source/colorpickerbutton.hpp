#pragma once
#include <raylib.h>
#include "constants.hpp"
#include "colors.hpp"
#include "grid.hpp"

class ColorPickerButton {
    public:
        ColorPickerButton(const Vector2&);
        void Toggle();
        void ColorPicker(Color& currentColor, Grid& grid);
        void Draw();
        bool Inside();

        void SetPickingColor(const bool& newValue) { pickingColor = newValue; }
        bool GetPickingColor() const { return pickingColor; }
    private:
        Vector2 origin;
        bool pickingColor;           
        Font font = GetFontDefault();     
};