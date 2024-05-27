#pragma once
#include <ncurses.h>
#include <iostream>

class nave {
    public:
        void setup();
        void draw();

        void setX(int x);
        void setY(int y);

        int getX();
        int getY();

    private:
        int m_x, m_y;
};