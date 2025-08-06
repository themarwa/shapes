#include <graphics.h>
#include <conio.h>
#include "ShapeManager.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "GroupShape.h"

#include <memory>

ShapeManager manager;

void drawUI() {
    setcolor(WHITE);
    outtextxy(10, 10, (char*)"Controls: R=Rectangle, C=Circle, T=Triangle, Arrows=Move, + = Zoom In, - = Zoom Out");
    outtextxy(10, 30, (char*)"G=Group, U=UnGroup, D=Delete, ESC=Exit");
}

int main() {
    initwindow(800, 600, "Shape Drawer");

    bool running = true;

    while (running) {
        cleardevice();
        drawUI();
        manager.drawAll();

        if (_kbhit()) {
            char ch = _getch();
            switch (ch) {
            case 'r':
            case 'R': {
                auto rect = std::make_shared<Rectangle>(manager.getNextId(), 200, 200, 100, 50);
                manager.addShape(rect);
                break;
            }
            case 'c':
            case 'C': {
                auto circ = std::make_shared<Circle>(manager.getNextId(), 300, 300, 40);
                manager.addShape(circ);
                break;
            }
            case 't':
            case 'T': {
                auto tri = std::make_shared<Triangle>(manager.getNextId(), 400, 300, 50);
                manager.addShape(tri);
                break;
            }
            case 72: manager.moveSelected(0, -10); break; // Up
            case 80: manager.moveSelected(0, 10); break;  // Down
            case 75: manager.moveSelected(-10, 0); break; // Left
            case 77: manager.moveSelected(10, 0); break;  // Right
            case '+': manager.resizeSelected(1.25); break;
            case '-': manager.resizeSelected(0.8); break;
            case 'd':
            case 'D': manager.deleteSelected(); break;
            case 'g':
            case 'G': {
                auto group = std::make_shared<GroupShape>(manager.getNextId());
                auto& shapes = manager.getShapes();

                for (int i = 0; i < shapes.size(); ++i) {
                    if (shapes[i]->selected) {
                        group->add(shapes[i]);
                        shapes[i]->selected = false;
                    }
                }
                manager.addShape(group);
                break;
            }
            case 'u':
            case 'U': {
                auto& shapes = manager.getShapes();
                std::vector<std::shared_ptr<Shape>> newShapes;

                for (int i = 0; i < shapes.size(); ++i) {
                    if (shapes[i]->selected) {
                        GroupShape* group = dynamic_cast<GroupShape*>(shapes[i].get());
                        if (group) {
                            for (auto& s : group->groupedShapes)
                                newShapes.push_back(s);
                            shapes.erase(shapes.begin() + i);
                            break;
                        }
                    }
                }

                for (auto& s : newShapes)
                    manager.addShape(s);

                break;
            }
            case 27: // ESC
                running = false;
                break;
            }
        }

        if (GetAsyncKeyState(VK_LBUTTON)) {
            int x = mousex();
            int y = mousey();
            manager.selectShapeAt(x, y);
        }

        delay(30);
    }

    closegraph();
    return 0;
}

