#include "ResizeDrag.h"

void resizeShapeByDrag(ShapeManager& manager, int mouseX, int mouseY) {
    Shape* selected = manager.getSelectedShape();
    if (!selected) return;

    int x, y, width, height;
    selected->getBounds(x, y, width, height);

    // نحسب الفرق بين المؤشر والحجم الحالي
    int newWidth = mouseX - x;
    int newHeight = mouseY - y;

    if (newWidth > 10 && newHeight > 10) { // نتأكد من الحد الأدنى للحجم
        float scaleX = (float)newWidth / width;
        float scaleY = (float)newHeight / height;

        float scale = std::min(scaleX, scaleY); // نستخدم أقل Scale للحفاظ على الشكل

        selected->resize(scale);
    }
}