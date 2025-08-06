#include "Selection.h"

void selectSingleShape(ShapeManager& manager, int mouseX, int mouseY) {
    for (Shape* shape : manager.getShapes()) {
        if (shape->contains(mouseX, mouseY)) {
            manager.clearSelection();
            manager.selectShape(shape);
            return;
        }
    }
    manager.clearSelection(); 
}

void selectMultipleShapes(ShapeManager& manager, int x1, int y1, int x2, int y2) {
    int left = std::min(x1, x2);
    int right = std::max(x1, x2);
    int top = std::min(y1, y2);
    int bottom = std::max(y1, y2);

    manager.clearSelection();

    for (Shape* shape : manager.getShapes()) {
        int x, y, w, h;
        shape->getBounds(x, y, w, h);

        if (x >= left && x + w <= right && y >= top && y + h <= bottom) {
            manager.selectShape(shape);
        }
    }
}