#include <iostream>
#include <ncurses.h>
#include "nave.h"

using namespace std;

const int ancho = 120;
const int alto = 40;
const int delay = 30;

bool game_over;
bool salir;

nave Primeranave;

void setup();
void input();
void update();
void draW();
void gameover();

int main(int argc, char const *argv[])
{
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    if (LINES < alto || COLS < ancho) {
        endwin();
        printf("La tedrminal debe de tener como minimo %d%d\n\n", ancho, alto);
        exit(1);
    }

    setup();

    salir = false;

    while (!salir)
    {
        while (!game_over)
        {
            input();
            update();
            draW();
        }
        gameover();
    }
    
    endwin();

    cout << endl;
    return 0;
}

void setup() {
    game_over = false;
    Primeranave.draw();
}
void input() {
    int tecla = getch();

    switch(tecla) {
        case KEY_UP:
            Primeranave.setY(Primeranave.getY() - 1);
            break;
        case KEY_DOWN:
            Primeranave.setY(Primeranave.getY() + 1);
            break;
        case KEY_LEFT:
            Primeranave.setX(Primeranave.getX() - 1);
            break;
        case KEY_RIGHT:
            Primeranave.setX(Primeranave.getX() + 1);
            break;
        case 27:
            game_over = true;
            break;
    }   
}

void update() {

}

void draw() {
    erase();
    box(stdscr, 0, 0);

    Primeranave.draw();

    refresh();
    delay_output(delay);    
}

void gameover() {
    for (int y = 10; y < 16; y++) {
        mvhline(y, 40, ' ', 40);
    }
    mvaddch(9, 39, ACS_ULCORNER);
    mvaddch(9, 80, ACS_URCORNER);
    mvaddch(16, 39, ACS_LLCORNER);
    mvaddch(16, 80, ACS_LRCORNER);

    mvhline(9, 40, ACS_HLINE, 40);
    mvhline(16, 40, ACS_HLINE, 40);

    mvvline(10, 39, ACS_VLINE, 6);
    mvvline(10, 80, ACS_VLINE, 6);

    mvprintw(12, 55, "Game Over");
    mvprintw(13, 50, "VOlver a JUgar? (s/n)");

    int opcion = getch();

    if (opcion == 's' || opcion == 'S') {
        game_over = false;
        setup();
    }
    else if(opcion == 'n' || opcion == 'N') {
        salir = true;
    }
}
