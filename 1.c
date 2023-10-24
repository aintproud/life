#include <ncurses.h>

int main() {
    // Initialize ncurses
    initscr();
    start_color();

    // Define color pairs
    init_pair(1, COLOR_RED, COLOR_BLACK);

    // Enable color pair 1
    attron(COLOR_PAIR(1));

    // Print the red number 1
    mvprintw(0, 0, "1");

    // Refresh the screen to show the changes
    refresh();

    // Wait for user input
    getch();

    // End ncurses
    endwin();

    return 0;
}