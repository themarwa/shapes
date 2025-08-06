#pragma once
#include "Shape.h"
#include <cmath>

class Rectangle : public Shape {
public:
    int x, y, width, height;

    Rectangle(int _id, int _x, int _y, int _w, int _h)
        : Shape(_id), x(_x), y(_y), width(_w), height(_h) {}

    void draw() override {
        if (selected) setcolor(RED);
        else setcolor(WHITE);
        rectangle(x, y, x + width, y + height);
    }

    void move(int dx, int dy) override {
        x += dx;
        y += dy;
    }

    void resize(float factor) override {
        width = static_cast<int>(width * factor);
        height = static_cast<int>(height * factor);
    }

    void rotate(float angleDegrees) override {
        
    }

    bool isInside(int px, int py) override {
        return px >= x && px <= x + width && py >= y && py <= y + height;
    }
};