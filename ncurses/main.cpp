#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

#define DY 0.31
#define XC 50
#define YC 20


void
init_ncurses()
{
    initscr();
    curs_set(0);
    keypad(stdscr, true);
    halfdelay(1);
}

void
end_ncurses()
{
    curs_set(1);
    endwin();
}

void
pintar(int x, int y)
{
        clear();
        mvprintw(YC - y, XC + x, "hola");
        refresh();
}

void
update_physics(double *x, double *y, double vx, double vy)
{
        *x += vx;
        *y += vy;
}

int
parse_input(double *vx, double *vy)
{
    int input;

    input = getch();
    check_collision();
    switch (input){
        case KEY_UP:
            *vy -= DY;
            break;
        case KEY_DOWN:
            *vy += DY;
            break;
    }

    return input;
}

int
main()
{
    double x = 0,
           y = 0,
           vx = 0.7,
           vy = 0.3;
    int opcion;

    init_ncurses();

    while (parse_input(&vx, &vy) != KEY_BREAK ){
        update_physics(&x, &y, vx, vy);
        pintar((int) x, (int) y);
    }

    end_ncurses();

    return EXIT_SUCCESS;
}
