#pragma once
#include "Shape.h"
#include <cmath>

class Circle : public Shape {
public:
    int x, y, r;

    Circle(int _id, int _x, int _y, int _r)
        : Shape(_id), x(_x), y(_y), r(_r) {}

    void draw() override {
        if (selected) setcolor(RED);
        else setcolor(WHITE);
        circle(x, y, r);
    }

    void move(int dx, int dy) override {
        x += dx;
        y += dy;
    }

    void resize(float factor) override {
        r = static_cast<int>(r * factor);
    }

    void rotate(float angleDegrees) override {
        
    }

    bool isInside(int px, int py) override {
        int dx = px - x;
        int dy = py - y;
        return dx * dx + dy * dy <= r * r;
    }
};