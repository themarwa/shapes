#pragma once
#include "Shape.h"
#include <vector>
#include <memory>
#include <algorithm>

class ShapeManager {
private:
    std::vector<std::shared_ptr<Shape>> shapes;
    int nextId = 1;

public:
    void addShape(std::shared_ptr<Shape> shape) {
        shapes.push_back(shape);
    }

    void drawAll() {
        for (auto& shape : shapes)
            shape->draw();
    }

    void moveSelected(int dx, int dy) {
        for (auto& shape : shapes)
            if (shape->selected)
                shape->move(dx, dy);
    }

    void resizeSelected(float factor) {
        for (auto& shape : shapes)
            if (shape->selected)
                shape->resize(factor);
    }

    void rotateSelected(float angle) {
        for (auto& shape : shapes)
            if (shape->selected)
                shape->rotate(angle);
    }

    void selectShapeAt(int x, int y) {
        for (auto& shape : shapes)
            shape->selected = shape->isInside(x, y);
    }

    void deselectAll() {
        for (auto& shape : shapes)
            shape->selected = false;
    }

    void deleteSelected() {
        shapes.erase(std::remove_if(shapes.begin(), shapes.end(),
            [](std::shared_ptr<Shape>& s) { return s->selected; }),
            shapes.end());
    }

    std::vector<std::shared_ptr<Shape>>& getShapes() {
        return shapes;
    }

    int getNextId() {
        return nextId++;
    }
};
