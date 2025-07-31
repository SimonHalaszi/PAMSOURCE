#pragma once

#include "constants.hpp"
#include "grid.hpp"
#include "colors.hpp"
#include "rgbbutton.hpp"
#include "palette.hpp"
#include "brushsizebutton.hpp"
#include "exportbutton.hpp"
#include "clearbutton.hpp"
#include "makerectbutton.hpp"
#include "colorpickerbutton.hpp"

class Brella {
    public:
        Brella();
        void Draw();
        void HandleInputs();
        void PrintFPS();
        
    private:
        Color currentColor;
        void DrawCurrentColor();

        Grid grid;

        Palette palette = Palette(PL_ORIGIN, defaultPaletteColors);
        
        RGBButton redButton = RGBButton(RB_ORIGIN, Rgb);
        RGBButton greenButton = RGBButton(GB_ORIGIN, rGb);
        RGBButton blueButton = RGBButton(BB_ORIGIN, rgB);

        BrushSizeButton brushSizeButton = BrushSizeButton(BS_ORIGIN);

        ExportButton exportButton = ExportButton(EX_ORIGIN);

        ClearButton clearButton = ClearButton(CL_ORIGIN);

        MakeRectButton makeRectButton = MakeRectButton(RT_ORIGIN);
    
        ColorPickerButton colorPickerButton = ColorPickerButton{GC_ORIGIN};
};


