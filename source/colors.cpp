#include "colors.hpp"

bool CompareColors(const Color& colorOne, const Color& colorTwo) {
    return (colorOne.r == colorTwo.r) && (colorOne.g == colorTwo.g) && (colorOne.b == colorTwo.b) && (colorOne.a == colorTwo.a);
}