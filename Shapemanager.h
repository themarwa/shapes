using namespace std;
#pragma once
#include <string>
#include <cmath>
#include "CMUgraphicsLib/CMUgraphics.h"
class ShapeManager :public window,public display {
public:
    
    string selshape(int px, int py, int rx1, int ry1, int rx2, int ry2,
        int tx1, int tx2, int tx3, int ty1, int ty2, int ty3,
        int cx, int cy, int radius) {
        
        int dx = px - cx;
        int dy = py - cy;
        string shapeuse="NONE";

        if (px >= rx1 && px <= rx2 && py >= ry1 && py <= ry2) {
            shapeuse = "RECTANGLE";
        }
        else if (px >= min(tx1, min(tx2, tx3)) && px <= max(tx1, max(tx2, tx3)) &&
            py >= min(ty1, min(ty2, ty3)) && py <= max(ty1, max(ty2, ty3))) {
            shapeuse =  "TRIANGLE";
        }
      
         else if (dx * dx + dy * dy <= radius * radius) {
                shapeuse = "CIRCLE";
            }
        else{
            shapeuse="NONE";   
        }
        return shapeuse;
        }


    

    string copy(int px, int py, int rx1, int ry1, int rx2, int ry2,
        int tx1, int tx2, int tx3, int ty1, int ty2, int ty3,
        int cx, int cy, int radius) {

        if (shapestate=="COPY"){

        string ss = selshape(px, py, rx1, ry1, rx2, ry2,
            tx1, tx2, tx3, ty1, ty2, ty3,
            cx, cy, radius);

        if (ss == "CIRCLE") {
            ccx = cx;
            ccy = cy;
            cr = radius;
            copiedShape = "CIRCLE";
        }
        else if (ss == "RECTANGLE") {
            crx1 = rx1;
            cry1 = ry1;
            crx2 = rx2;
            cry2 = ry2;
            copiedShape = "RECTANGLE";
        }
        else if (ss == "TRIANGLE") {
            ctx1 = tx1;
            ctx2 = tx2;
            ctx3 = tx3;
            cty1 = ty1;
            cty2 = ty2;
            cty3 = ty3;
            copiedShape = "TRIANGLE";
        } }
    
        else {
            copiedShape = "NONE";
        }
         return copiedShape;
    }


    void paste(int offsetX = 30, int offsetY = 30, &window w) {
        if (copiedShape == "CIRCLE") {
            w.DrawCircle(ccx + offsetX, ccy + offsetY, cr, FILLED);
        }
        else if (copiedShape == "RECTANGLE") {
            w.DrawRectangle(crx1 + offsetX, cry1 + offsetY,
                crx2 + offsetX, cry2 + offsetY, FILLED);
        }
        else if (copiedShape == "TRIANGLE") {
            w.DrawTriangle(ctx1 + offsetX, cty1 + offsetY,
                ctx2 + offsetX, cty2 + offsetY,
                ctx3 + offsetX, cty3 + offsetY, FILLED);
        }
        shapestate="NONE";
        copiedShape="NONE";
    }

private:

    int ccx, ccy, cr;
    int crx1, cry1, crx2, cry2;
    int ctx1, ctx2, ctx3, cty1, cty2, cty3;
    string copiedShape = "NONE";
};
