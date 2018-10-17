#ifndef CUSTOMCANVAS_H
#define CUSTOMCANVAS_H

#include <QGraphicsScene>
#include "interfaceerrors.h"

class CustomCanvas: public QGraphicsScene  {
    private:
        int width, height;
        bool isActiveCanvas;
        int size_cube_w, size_cube_h;

    public:
        CustomCanvas(int w, int h, bool active);
        CustomCanvas();
        ~CustomCanvas();

        void setCanvas(int w, int h);

        int getWidth() const;
        int getHeight() const;

        bool getActive();
        void setActive(bool active);

        void setSizeCube(int s_w, int s_h);
        int getWidthCube() const;
        int getHeightCube() const;

        void drawCube(QPoint cube, QPen pen, QColor clr_brush, float percent_offset);
        void drawGrid(int size_map_height, int size_map_width);
};

#endif // CUSTOMCANVAS_H
