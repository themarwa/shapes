#pragma once
#include "Shape.h"
#include <vector>
#include <memory>

class GroupShape : public Shape {
public:
    std::vector<std::shared_ptr<Shape>> groupedShapes;

    GroupShape(int _id) : Shape(_id) {}

    void add(std::shared_ptr<Shape> shape) {
        groupedShapes.push_back(shape);
    }

    void draw() override {
        for (auto& shape : groupedShapes)
            shape->draw();
    }

    void move(int dx, int dy) override {
        for (auto& shape : groupedShapes)
            shape->move(dx, dy);
    }

    void resize(float factor) override {
        for (auto& shape : groupedShapes)
            shape->resize(factor);
    }

    void rotate(float angle) override {
        for (auto& shape : groupedShapes)
            shape->rotate(angle);
    }

    bool isInside(int x, int y) override {
        for (auto& shape : groupedShapes)
            if (shape->isInside(x, y))
                return true;
        return false;
    }
};

