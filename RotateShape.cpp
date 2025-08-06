#include "RotateShape.h"

void RotateShape::rotateSelectedShapes(ShapeManager& manager, int angle) {
    for (Shape* shape : manager.getShapes()) {
        if (shape->isSelected()) {
            shape->rotate(angle);
        }
    }
}