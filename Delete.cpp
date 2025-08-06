#include "Delete.h"

void deleteSelectedShape(ShapeManager& manager) {
    if (manager.getSelectedShape() != nullptr) {
        manager.deleteShape(manager.getSelectedShape());
        manager.deselect(); // نلغي التحديد بعد الحذف
    }
}