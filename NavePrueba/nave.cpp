#include "nave.h"
#include <ncurses.h>

void nave::setup() {
    m_x = 60;
    m_y = 20;
}

/*Esta hay que modificarla dependiendo de como queramos dibujar la nave*/
void nave::draw() {
    mvaddch(m_y, m_x, '*');
}

void nave::setX(int x) {
    m_x = x;
}

void nave::setY(int y) {
    m_y = y;
}

int nave::getX() {
    return m_x;
}

int nave::getY() {
    return m_y;
}