#ifndef SELECTION_H
#define SELECTION_H

#include "ShapeManager.h"


void selectSingleShape(ShapeManager& manager, int mouseX, int mouseY);


void selectMultipleShapes(ShapeManager& manager, int x1, int y1, int x2, int y2);

#endif // SELECTION_H