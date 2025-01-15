#include "colors.hpp"

const Color white = {244, 244, 244, 255};
const Color darkred = {111, 25, 38, 255};
const Color red = {222, 50, 76, 255};
const Color orange = {244, 137, 95, 255};
const Color yellow = {248, 225, 111, 255};
const Color green = {149, 207, 146, 255};
const Color blue = {54, 154, 204, 255};
const Color purple = {150, 86, 162, 255};
const Color lilac = {203, 171, 209, 255};

// Default Palette
std::vector<Color> GetPaletteColors() {
    return {white, darkred, red, orange, yellow, green, blue, purple, lilac};
}