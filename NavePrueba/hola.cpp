#include <ncurses.h>

int main(){

    initscr();

    printw("Hello word");
    refresh();
    getch();
    endwin();
    return 0;
}