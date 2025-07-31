#pragma once
#include <raylib.h>
#include "constants.hpp"
#include "colors.hpp"

class ClearButton {
    public:
        ClearButton(const Vector2&);
        void Draw();
        bool Inside();
        
    private:
        Vector2 origin;
        Font font = GetFontDefault(); 
};