#include "grid.hpp"

Grid::Grid() {
    sizeColumns = GRID_SIZE_COLUMNS;
    sizeRows = GRID_SIZE_ROWS;
    if(sizeColumns > sizeRows) {
        pixelSize = double(GRID_LONGER_SIDE/sizeColumns);
    } else {
        pixelSize = double(GRID_LONGER_SIDE/sizeRows);
    }
    CoverGrid(white);
}

void Grid::CoverGrid(const Color& color) {
    for(int row = 0; row < GRID_SIZE_ROWS; ++row) {
        std::fill(grid[row], grid[row] + GRID_SIZE_COLUMNS, color);
    }
}

void Grid::Draw() const {
    DrawRectangle(GRID_OFFSET - BORDER_WIDTH, GRID_OFFSET - BORDER_WIDTH, GRID_SIZE_COLUMNS * pixelSize + (BORDER_WIDTH * 2), GRID_SIZE_ROWS * pixelSize + (BORDER_WIDTH * 2), lightgray);

    for (int row = 0; row < sizeRows; ++row) {
        int startColumn = 0;
        while (startColumn < sizeColumns) {
            Color currentColor = grid[row][startColumn];
            
            int endColumn = startColumn;
            while (endColumn < sizeColumns && CompareColors(grid[row][endColumn], currentColor)) {
                ++endColumn;
            }

            DrawRectangle(startColumn * pixelSize + GRID_OFFSET, row * pixelSize + GRID_OFFSET, (endColumn - startColumn) * pixelSize, pixelSize, currentColor);
            
            startColumn = endColumn;
        }
    } 
}

void Grid::DrawHoverHighlight(int radius) const {
    Vector2 centerPixel = FindPixelHovered(GetMousePosition());

    int centerX = int(centerPixel.x);
    int centerY = int(centerPixel.y);

    for (int row = centerY - radius; row <= centerY + radius; ++row) {
        if (row < 0 || row >= sizeRows) { 
            continue; 
        }

        for (int col = centerX - radius; col <= centerX + radius; ++col) {
            
            if (col < 0 || col >= sizeColumns) {
                continue;
            }

            int dx = col - centerX;
            int dy = row - centerY;
            
            if (dx * dx + dy * dy <= radius * radius) {
                DrawRectangle(col * pixelSize + GRID_OFFSET, row * pixelSize + GRID_OFFSET, pixelSize, pixelSize, highlightcolor);
            }
        }
    }
}

void Grid::DrawRectSelection(const Vector2& firstSelection) const {
    Vector2 highlightStart = FindPixelHovered(firstSelection);
    Vector2 highlightEnd = FindPixelHovered(GetMousePosition());

    int leftXBound = std::min(highlightStart.x, highlightEnd.x);
    int rightXBound = std::max(highlightStart.x, highlightEnd.x);
    int topYBound = std::min(highlightStart.y, highlightEnd.y);
    int bottomYBound = std::max(highlightStart.y, highlightEnd.y);

    for(int row = topYBound; row <= bottomYBound; ++row) {
        DrawRectangle(float(leftXBound * pixelSize + GRID_OFFSET), float(row * pixelSize + GRID_OFFSET), float((rightXBound - leftXBound + 1) * pixelSize), float(pixelSize), highlightcolor);             
    }
}

Vector2 Grid::FindPixelHovered(const Vector2& pos) const {
    float calcX = pos.x - GRID_OFFSET; 
    float calcY = pos.y - GRID_OFFSET; 
    
    if (calcX < 0 || 
        calcY < 0 || 
        calcX >= sizeColumns * pixelSize || 
        calcY >= sizeRows * pixelSize) {
        return {-1000, -1000};
    }

    int column = int(calcX / pixelSize);
    int row = int(calcY / pixelSize);

    return {float(column), float(row)};   
}   

void Grid::ChangePixelColor(const Color& color) {
    Vector2 pixel = FindPixelHovered(GetMousePosition());
    grid[int(pixel.y)][int(pixel.x)] = color;
}

Color Grid::ColorGetter(const Vector2& pos) const {
    Vector2 pixel = FindPixelHovered(pos);
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

void Grid::FillInRect(const Vector2& one, const Vector2& two, const Color& color) {
    Vector2 boundOne = FindPixelHovered(one);
    Vector2 boundTwo = FindPixelHovered(two);

    int leftXBound = std::min(boundOne.x, boundTwo.x);
    int rightXBound = std::max(boundOne.x, boundTwo.x);
    int topYBound = std::min(boundOne.y, boundTwo.y);
    int bottomYBound = std::max(boundOne.y, boundTwo.y);

    for(int row = topYBound; row <= bottomYBound; ++row) {
        std::fill(grid[row] + leftXBound, grid[row] + rightXBound + 1, color);
    }
}

void Grid::FillInCircle(const Vector2& center, int radius, const Color& color) {
    Vector2 centerPixel = FindPixelHovered(center);

    int centerX = int(centerPixel.x);
    int centerY = int(centerPixel.y);

    if (centerX == -1000 && centerY == -1000) {
        return;
    }

    for (int row = centerY - radius; row <= centerY + radius; ++row) {
        
        if (row < 0 || row >= sizeRows) { 
            continue;
        }

        for (int col = centerX - radius; col <= centerX + radius; ++col) {
            
            if (col < 0 || col >= sizeColumns) {
                continue;
            }

            int dx = col - centerX;
            int dy = row - centerY;
            if (dx * dx + dy * dy <= radius * radius) {
                grid[row][col] = color;
            }
        }
    }
}

bool Grid::Inside() const {
    return CheckCollisionPointRec(GetMousePosition(), {GRID_OFFSET, GRID_OFFSET, sizeColumns * float(pixelSize), sizeRows * float(pixelSize)});
}