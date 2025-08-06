#ifndef MOVE_H
#define MOVE_H

#include "ShapeManager.h"

class Move {
public:
    static void moveSelectedShapes(ShapeManager& manager, int dx, int dy);
};

#endif