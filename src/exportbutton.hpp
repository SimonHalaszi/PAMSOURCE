#pragma once
#include <raylib.h>
#include "constants.hpp"
#include "colors.hpp"

class ExportButton {
    public:
        ExportButton(const Vector2&);
        void Draw();
        bool Inside();
        void ExportCanvas();
        
    private:
        Vector2 origin;
        Font font = GetFontDefault(); 
        Image exportCanvas; 
};