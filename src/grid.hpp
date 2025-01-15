#pragma once

#include <raylib.h>
#include <vector>
#include "colors.hpp"
#include <iostream>

// BALATRO JOKERS ARE 71x95

// Y: MUST BE UNDER OR EQUAL TO 512
const int GRID_SIZE_ROWS = 32;
// X: MUST BE UNDER OR EQUAL TO 512
const int GRID_SIZE_COLUMNS = 32;

class Grid {
    public:
        Grid();
        void Draw();
        Color grid[GRID_SIZE_ROWS][GRID_SIZE_COLUMNS];
        void DrawHoverHighlight();
        void ChangePixelColor(const Color&);
        void CoverGrid(const Color&);  
        Color ColorPicker();
        float GetPixelSize() const { return pixelSize; }

    private:
        int sizeRows;
        int sizeColumns;
        double pixelSize;   
        Vector2 FindPixelHovered(); 

};