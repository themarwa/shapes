#include "Move.h"

void Move::moveSelectedShapes(ShapeManager& manager, int dx, int dy) {
    for (Shape* shape : manager.getShapes()) {
        if (shape->isSelected()) {
            shape->move(dx, dy);
        }
    }
}