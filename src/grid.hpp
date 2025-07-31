#pragma once

#include <raylib.h>
#include <vector>
#include "colors.hpp"
#include <iostream>
#include "constants.hpp"

class Grid {
    public:
        Grid();
        void Draw() const;
        void DrawHoverHighlight(int) const;
        void ChangePixelColor(const Color&);
        void CoverGrid(const Color&);  
        Color ColorGetter(const Vector2&) const;
        float GetPixelSize() const { return pixelSize; }
        int GetRowCount() const { return sizeRows; }
        int GetColumnCount() const { return sizeColumns; }
        void PrintGridToConsole() const;
        void FillInRect(const Vector2&, const Vector2&, const Color&);
        void DrawRectSelection(const Vector2&) const;
        void FillInCircle(const Vector2&, int, const Color&);
        bool Inside() const;  

    private:
        int sizeRows;
        int sizeColumns;
        double pixelSize;   
        Vector2 FindPixelHovered(const Vector2&) const; 
        Color grid[GRID_SIZE_ROWS][GRID_SIZE_COLUMNS];

};