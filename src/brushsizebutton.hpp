#pragma once
#include <raylib.h>
#include "constants.hpp"
#include "colors.hpp"

class BrushSizeButton {
    public:
        BrushSizeButton(const Vector2&);
        void ChangeBrushRadius();
        bool Inside();
        void Draw();
        
        int GetBrushRadius() const { return brushRadius; }

    private:
        Vector2 origin;
        Font font = GetFontDefault();  
        int brushRadius;
};