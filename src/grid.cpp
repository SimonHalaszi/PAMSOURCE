#include "grid.hpp"

Grid::Grid() {
    sizeColumns = GRID_SIZE_COLUMNS;
    sizeRows = GRID_SIZE_ROWS;
    if(sizeColumns > sizeRows) {
        pixelSize = double(512/sizeColumns);
    } else {
        pixelSize = double(512/sizeRows);
    }
    CoverGrid(white);
}

void Grid::CoverGrid(const Color& color) {
    for(int row = 0; row < sizeRows; ++row) {
        for(int column = 0; column < sizeColumns; ++column) {
            grid[row][column] = color;
        }
    }
}

void Grid::Draw() const {
    for(int row = 0; row < sizeRows; ++row) {
        for(int column = 0; column < sizeColumns; ++column) {
            DrawRectangle(column * pixelSize + 16, row * pixelSize + 16, pixelSize, pixelSize, grid[row][column]);
        }
    }    
}

void Grid::DrawHoverHighlight() const {
    Vector2 highlightedSquare = FindPixelHovered();
    DrawRectangle(highlightedSquare.x * pixelSize + 16, highlightedSquare.y * pixelSize + 16, pixelSize, pixelSize, {50, 0, 0, 100});
   
}

Vector2 Grid::FindPixelHovered() const {
    Vector2 pos = GetMousePosition();
    for(int row = 0; row < sizeRows; ++row) {
        for(int column = 0; column < sizeColumns; ++column) {
            if(CheckCollisionPointRec(pos, {float(column * pixelSize + 16), float(row * pixelSize + 16), float(pixelSize), float(pixelSize)})) {
                return {float(column), float(row)};
            }
        }
    }
    return {-1000, -1000};     
}   

void Grid::ChangePixelColor(const Color& color) {
    Vector2 pixel = FindPixelHovered();
    grid[int(pixel.y)][int(pixel.x)] = color;
}

Color Grid::ColorPicker() const {
    Vector2 pixel = FindPixelHovered();
    return grid[int(pixel.y)][int(pixel.x)];
}

void Grid::PrintGridToConsole() const {
    for(int row = 0; row < sizeRows; ++row) {
        for(int column = 0; column < sizeColumns; ++column) {
            std::cout << "{" << int(grid[row][column].r) << ", " << int(grid[row][column].g) << ", " << int(grid[row][column].b) << ", 255} ";
        }
        std::cout << std::endl;
    }        
}
