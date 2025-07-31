#pragma once

#include <raylib.h>
#include <vector>
#include "constants.hpp"
#include "colors.hpp"

class Palette {
    public:
        Palette(const Vector2&, const Color[9]);
        Color SelectColor() const;
        void Draw() const;
        bool Inside() const;

    private:
        Vector2 origin;
        Color paletteColors[9];
};