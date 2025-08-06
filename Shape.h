#pragma once
#include <graphics.h>

class Shape {
public:
    int id;
    bool selected;

    Shape(int _id) : id(_id), selected(false) {}

    virtual void draw() = 0;
    virtual void move(int dx, int dy) = 0;
    virtual void resize(float factor) = 0;
    virtual void rotate(float angleDegrees) = 0;
    virtual bool isInside(int x, int y) = 0;

    virtual ~Shape() {}
};