#pragma once
#include <raylib.h>
#include "constants.hpp"
#include "colors.hpp"

enum Channel{Rgb, rGb, rgB};

class RGBButton {
    public:
        RGBButton(const Vector2, Channel);
        void Draw(const Color&) const;
        bool Inside() const;
        int ChangeChannel(const Color& color) const;

    private:
        Vector2 origin;
        Channel channel;
        Font font = GetFontDefault();  
};