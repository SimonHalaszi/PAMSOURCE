#pragma once
#include <raylib.h>
#include <vector>

// For Hud
constexpr Color black = {39, 40, 41, 255};
constexpr Color lightgray = {216, 217, 218, 255};
constexpr Color highlightcolor = {50, 0, 0, 100};

// For Default Palette
constexpr Color white = {244, 244, 244, 255};
constexpr Color darkred = {111, 25, 38, 255};
constexpr Color red = {222, 50, 76, 255};
constexpr Color orange = {244, 137, 95, 255};
constexpr Color yellow = {248, 225, 111, 255};
constexpr Color green = {149, 207, 146, 255};
constexpr Color blue = {54, 154, 204, 255};
constexpr Color purple = {150, 86, 162, 255};
constexpr Color lilac = {203, 171, 209, 255};

// Default Palette
constexpr Color defaultPaletteColors[9] = {
    white, 
    darkred, 
    red, 
    orange, 
    yellow, 
    green, 
    blue, 
    purple, 
    lilac
};

// Compares Two Colors
bool CompareColors(const Color&, const Color&);