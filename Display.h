#pragma once
using namespace std;
#include<iostream>
#include<cmath>
#include "CMUgraphicsLib/CMUgraphics.h"
class display:public window {
public :
    display() {
        cout << "displayed the color pallete and copy and paste buttons successfully...";
    }
    string display2(window wind) {
        int mx, my;
        string shapestate="NONE";
        wind.SetPen(BLACK,5);
        wind.DrawRectangle(200,10,230,120);
        wind.DrawRectangle(200,10,230,60);
        wind.DrawRectangle(200, 60, 230, 120);
        wind.DrawString(215,35,"COPY");
        wind.DrawString(215, 90, "PASTE");
        wind.WaitMouseClick(mx, my);
        if (mx > 200 && mx < 230 && my>10 && my < 60) {
            shapestate = "COPY";
        }
        else if (mx > 200 && mx < 230 && my>60 && my < 120) {
            shapestate = "PASTE";
        
        }  

        return shapestate;

        }

    void display1(window w, int wx, int wy, int stx, int sty, int px, int py) {
        w.ChangeTitle("ZC Drawing Project");
        w.SetPen(BLACK);
        w.DrawRectangle(10, 10, 170, 120);
        w.DrawRectangle(10, 10, 50, 60);
        w.DrawRectangle(10, 60, 50, 120);
        w.DrawString(16, 30, "BRUSH");
        w.DrawString(22, 85, "PEN");

        w.SetBrush(RED);     w.DrawRectangle(50, 10, 80, 60, FILLED);
        w.SetBrush(YELLOW);  w.DrawRectangle(80, 10, 110, 60, FILLED);
        w.SetBrush(ORANGE);  w.DrawRectangle(110, 10, 140, 60, FILLED);
        w.SetBrush(GREEN);   w.DrawRectangle(140, 10, 170, 60, FILLED);
        w.SetBrush(BLUE);    w.DrawRectangle(50, 60, 80, 120, FILLED);
        w.SetBrush(PURPLE);  w.DrawRectangle(80, 60, 110, 120, FILLED);
        w.SetBrush(BROWN);   w.DrawRectangle(110, 60, 140, 120, FILLED);
        w.SetBrush(BLACK);   w.DrawRectangle(140, 60, 170, 120, FILLED);


        string  tool;
        if (px >= 10 && px <= 50 && py >= 10 && py <= 60) {
            tool = "BRUSH";
        }
        else if (px >= 10 && px <= 50 && py >= 60 && py <= 120) {
            tool = "PEN";
        }

        if (tool == "BRUSH") {
            if (px >= 50 && px <= 80 && py >= 10 && py <= 60) w.SetBrush(RED);
            else if (px >= 80 && px <= 110 && py >= 10 && py <= 60) w.SetBrush(YELLOW);
            else if (px >= 110 && px <= 140 && py >= 10 && py <= 60) w.SetBrush(ORANGE);
            else if (px >= 140 && px <= 170 && py >= 10 && py <= 60) w.SetBrush(GREEN);
            else if (px >= 50 && px <= 80 && py >= 60 && py <= 120) w.SetBrush(BLUE);
            else if (px >= 80 && px <= 110 && py >= 60 && py <= 120) w.SetBrush(PURPLE);
            else if (px >= 110 && px <= 140 && py >= 60 && py <= 120) w.SetBrush(BROWN);
            else if (px >= 140 && px <= 170 && py >= 60 && py <= 120) w.SetBrush(BLACK);
        }
        else if (tool == "PEN") {
            if (px >= 50 && px <= 80 && py >= 10 && py <= 60) w.SetPen(RED);
            else if (px >= 80 && px <= 110 && py >= 10 && py <= 60) w.SetPen(YELLOW);
            else if (px >= 110 && px <= 140 && py >= 10 && py <= 60) w.SetPen(ORANGE);
            else if (px >= 140 && px <= 170 && py >= 10 && py <= 60) w.SetPen(GREEN);
            else if (px >= 50 && px <= 80 && py >= 60 && py <= 120) w.SetPen(BLUE);
            else if (px >= 80 && px <= 110 && py >= 60 && py <= 120) w.SetPen(PURPLE);
            else if (px >= 110 && px <= 140 && py >= 60 && py <= 120) w.SetPen(BROWN);
            else if (px >= 140 && px <= 170 && py >= 60 && py <= 120) w.SetPen(BLACK);
        }
       
    }
};
