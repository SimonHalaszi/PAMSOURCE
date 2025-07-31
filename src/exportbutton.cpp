#include "exportbutton.hpp"

ExportButton::ExportButton(const Vector2& og) {
    origin = og;
}

void ExportButton::Draw() {
    DrawRectangle((origin.x - BORDER_WIDTH), (origin.y - BORDER_WIDTH), (BUTTON_LENGTH + (BORDER_WIDTH * 2)), (BUTTON_HEIGHT + (BORDER_WIDTH * 2)), lightgray);
    DrawRectangle((origin.x), (origin.y), BUTTON_LENGTH, BUTTON_HEIGHT, black);
    Vector2 textSize = MeasureTextEx(font, "EXPORT", FONT_SIZE, FONT_SPACING);
    DrawTextEx(font, "EXPORT", {(origin.x + (BUTTON_LENGTH - textSize.x) / 2), (origin.y + (BUTTON_HEIGHT - textSize.y) / 2)}, FONT_SIZE, FONT_SPACING, lightgray);
}

bool ExportButton::Inside() {
    return CheckCollisionPointRec(GetMousePosition(), {(origin.x), (origin.y), BUTTON_LENGTH, BUTTON_HEIGHT});
}

void ExportButton::ExportCanvas() {
    TakeScreenshot("uncroppedexport.png");
    exportCanvas = LoadImage("uncroppedexport.png");
    ImageCrop(&exportCanvas, {GRID_OFFSET, GRID_OFFSET, PIXEL_SIZE * GRID_SIZE_COLUMNS, PIXEL_SIZE * GRID_SIZE_ROWS});
    ExportImage(exportCanvas, "export.png");
    UnloadImage(exportCanvas);    
}