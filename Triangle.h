#pragma once
#include "Shape.h"

class Triangle : public Shape {
public:
    int x1, y1, x2, y2, x3, y3;

    Triangle(int _id, int _x1, int _y1, int _x2, int _y2, int _x3, int _y3)
        : Shape(_id), x1(_x1), y1(_y1), x2(_x2), y2(_y2), x3(_x3), y3(_y3) {}

    void draw() override {
        if (selected) setcolor(RED);
        else setcolor(WHITE);
        line(x1, y1, x2, y2);
        line(x2, y2, x3, y3);
        line(x3, y3, x1, y1);
    }

    void move(int dx, int dy) override {
        x1 += dx; y1 += dy;
        x2 += dx; y2 += dy;
        x3 += dx; y3 += dy;
    }

    void resize(float factor) override {
        
    }

    void rotate(float angleDegrees) override {
        
    }

    bool isInside(int px, int py) override {
        return false; 
    }
};