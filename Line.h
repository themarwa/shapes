#pragma once
#include "Shape.h"
#include <graphics.h>
#include <cmath>

class LineShape : public Shape {
public:
    int x1, y1, x2, y2;

    LineShape(int _id, int _x1, int _y1, int _x2, int _y2)
        : Shape(_id), x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}

    void draw() override {
        setcolor(selected ? RED : WHITE);
        line(x1, y1, x2, y2);
    }

    void move(int dx, int dy) override {
        x1 += dx; y1 += dy;
        x2 += dx; y2 += dy;
    }

    void resize(float factor) override {
        int cx = (x1 + x2) / 2;
        int cy = (y1 + y2) / 2;
        x1 = cx + (x1 - cx) * factor;
        y1 = cy + (y1 - cy) * factor;
        x2 = cx + (x2 - cx) * factor;
        y2 = cy + (y2 - cy) * factor;
    }

    void rotate(float angleDegrees) override {
        float angle = angleDegrees * M_PI / 180.0;
        int cx = (x1 + x2) / 2;
        int cy = (y1 + y2) / 2;

        int dx1 = x1 - cx, dy1 = y1 - cy;
        int dx2 = x2 - cx, dy2 = y2 - cy;

        x1 = cx + dx1 * cos(angle) - dy1 * sin(angle);
        y1 = cy + dx1 * sin(angle) + dy1 * cos(angle);
        x2 = cx + dx2 * cos(angle) - dy2 * sin(angle);
        y2 = cy + dx2 * sin(angle) + dy2 * cos(angle);
    }

    bool isInside(int x, int y) override {
        return (x >= std::min(x1,x2) && x <= std::max(x1,x2) &&
                y >= std::min(y1,y2) && y <= std::max(y1,y2));
    }
};
