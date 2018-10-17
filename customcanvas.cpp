#include "customcanvas.h"

CustomCanvas::CustomCanvas(int w = 0, int h = 0, bool active = false):
    width(w),
    height(h),
    isActiveCanvas(active),
    size_cube_w(0),
    size_cube_h(0)
{ }

CustomCanvas::CustomCanvas():
    width(0),
    height(0),
    isActiveCanvas(false),
    size_cube_w(0),
    size_cube_h(0)
{ }

CustomCanvas::~CustomCanvas() { }

void CustomCanvas::setCanvas(int w, int h) {
    setSceneRect(0, 0, w, h);
    width = w;
    height = w;
}
int CustomCanvas::getWidth() const{
    return width;
}

int CustomCanvas::getHeight() const{
    return height;
}

int CustomCanvas::getWidthCube() const {
    return size_cube_w;
}

int CustomCanvas::getHeightCube() const {
    return size_cube_h;
}

bool CustomCanvas::getActive() {
    return isActiveCanvas;
}

void CustomCanvas::setActive(bool active) {
    isActiveCanvas = active;
}

void CustomCanvas::setSizeCube(int s_w, int s_h) {
    size_cube_w = s_w;
    size_cube_h = s_h;
}

void CustomCanvas::drawGrid(int size_map_height, int size_map_width) {
    //cols map
    for (int col = 1; col < size_map_height; ++col){
        addLine(col * size_cube_h , 0, col * size_cube_h, height);
    }
    //rows map
    for (int row = 0; row < size_map_width; ++row){
        addLine(0, row * size_cube_w, width, row * size_cube_w);
    }
}

void CustomCanvas::drawCube(QPoint cursor, QPen pen, QColor clr_brush, float percent_offset) {
    if (cursor.x() != INVALID_COORD) {
        int x = cursor.y(), y = cursor.x();
        int offset_width = (int) size_cube_w * percent_offset;
        int offset_height = (int) size_cube_h * percent_offset;
        addRect(x * size_cube_w + offset_width,  y * size_cube_h + offset_height,
                size_cube_w - 2 * offset_width, size_cube_h - 2 * offset_height,  pen, QBrush(clr_brush));
    }
}
