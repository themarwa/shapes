#ifndef ROTATESHAPE_H
#define ROTATESHAPE_H

#include "ShapeManager.h"

class RotateShape {
public:
    static void rotateSelectedShapes(ShapeManager& manager, int angle);
};

#endif