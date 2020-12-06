#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <assert.h>

#include "cli.h"
#include "game.h"
#include "state.h"

static void init_cli_style()
{
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
}

static void draw_cell(char c, int row, int col, WINDOW *win)
{
    wmove(win, row + 1, col * 2 + 2);
    wprintw(win, "%c%c", c, ' ');
}

static void draw_active_board(struct game *game, WINDOW *win)
{
    assert(game != NULL);
    struct game_state state = get_active_state(game);

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (is_flag(state, i, j))
            {

                wattron(win, COLOR_PAIR(3));
                draw_cell('F', i, j, win);
                wattroff(win, COLOR_PAIR(3));
            }
            else if (!is_visible(state, i, j))
            {
                if (check_game_status(game) == VICTORY)
                {
                    wattron(win, COLOR_PAIR(4));
                    draw_cell('*', i, j, win);
                    wattroff(win, COLOR_PAIR(4));
                }
                else
                {
                    wattron(win, COLOR_PAIR(1));
                    draw_cell('-', i, j, win);
                    wattroff(win, COLOR_PAIR(1));
                }
            }
            else if (is_mine(state, i, j))
            {
                wattron(win, COLOR_PAIR(2));
                draw_cell('*', i, j, win);
                wattroff(win, COLOR_PAIR(2));
            }
            else
            {
                unsigned value = calc_cell_value(state, i, j);
                assert(value >= 0 && value <= 8);
                char value_c = value + '0';
                if (value == 0)
                    value_c = ' ';

                attron(COLOR_PAIR(1));
                draw_cell(value_c, i, j, win);
                attroff(COLOR_PAIR(1));
            }
        }
    }
    refresh();
}

static int do_game_loop(struct game *game, WINDOW *win)
{

    wmove(win, 1, 2);
    while (1)
    {
        int current_y, current_x;
        getyx(win, current_y, current_x);
        draw_active_board(game, win);
        wmove(win, current_y, current_x);

        int c = wgetch(win);
        int col = (current_x - 2) / 2;
        int row = (current_y - 1);

        switch (c)
        {
        case KEY_LEFT:
            if (current_x > 2)
                current_x -= 2;
            break;
        case KEY_RIGHT:
            if (current_x < WINDOW_WIDTH - 3)
                current_x += 2;
            break;
        case KEY_UP:
            if (current_y > 1)
                current_y--;
            break;
        case KEY_DOWN:
            if (current_y < WINDOW_HEIGHT - 2)
                current_y++;
            break;
        case '\n':
            expose_field(game, row, col);
            break;
        case 'f':
            toggle_flag(game, row, col);
            break;
        case 'u':
            undo_move(game);
            break;
        case 'r':
            redo_move(game);
            break;
        case 'q':
            return 0;
        case 'n':
            return 1;
            break;
        default:
            break;
        }

        wmove(win, current_y, current_x);
        wrefresh(win);
    }
}

int start_cli_game(struct game *game)
{

    init_cli_style();
    cbreak();
    noecho();
    refresh();

    int max_x;
    getmaxyx(stdscr, max_x, max_x);
    int horizontal_offset = (max_x - WINDOW_WIDTH - INSTRUCTIONS_WIDTH) / 2;

    int height = WINDOW_HEIGHT;
    int width = WINDOW_WIDTH;

    WINDOW *title_win = create_newwin(TITLE_HEIGHT, TITLE_WIDTH, MARGIN, MARGIN + horizontal_offset);
    wattrset(title_win, COLOR_PAIR(3) | A_BOLD);
    mvwprintw(title_win, 1, 7, "WELC0ME T0 B1NARY SWEEPER");
    wrefresh(title_win);

    WINDOW *instructions_win = create_newwin(INSTRUCTIONS_HEIGHT, INSTRUCTIONS_WIDTH, TITLE_HEIGHT + MARGIN, WINDOW_WIDTH + MARGIN * 2 + horizontal_offset);

    wattron(instructions_win, A_UNDERLINE);
    mvwprintw(instructions_win, 1, 2, "Seed %d", game->seed);
    wattroff(instructions_win, A_UNDERLINE);
    mvwprintw(instructions_win, 2, 2, "[arrow] move");
    mvwprintw(instructions_win, 3, 2, "[enter] expose");
    mvwprintw(instructions_win, 4, 4, "[f] flag");
    mvwprintw(instructions_win, 5, 4, "[u] undo");
    mvwprintw(instructions_win, 6, 4, "[r] redo");
    mvwprintw(instructions_win, 7, 4, "[n] new game");
    mvwprintw(instructions_win, 8, 4, "[q] quit");
    wrefresh(instructions_win);

    int starty = TITLE_HEIGHT + MARGIN;
    int startx = MARGIN + horizontal_offset;
    WINDOW *game_win = create_newwin(height, width, starty, startx);

    keypad(game_win, TRUE);
    wmove(game_win, 1, 1);
    wrefresh(game_win);
    int exit = do_game_loop(game, game_win);

    destroy_win(instructions_win);
    destroy_win(game_win);
    destroy_win(title_win);

    return exit;
}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{
    WINDOW *local_win;

    local_win = newwin(height, width, starty, startx);
    box(local_win, 0, 0);
    wborder(local_win, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(local_win);
    return local_win;
}

void destroy_win(WINDOW *local_win)
{
    wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(local_win);
    delwin(local_win);
}

static int read_state(FILE *file, struct game_state *state)
{
    if (state == NULL || file == NULL)
    {
        return -1;
    }

    if (fread(&(state->mine_board), sizeof(state->mine_board), 1, file) != 1)
    {
        return -1;
    }

    if (fread(&(state->flag_board), sizeof(state->flag_board), 1, file) != 1)
    {
        return -1;
    }

    if (fread(&(state->visibility_board), sizeof(state->visibility_board), 1, file) != 1)
    {
        return -1;
    }

    return 0;
}

static int load_game(struct game **game, const char *filename)
{
    struct game *load_game = malloc(sizeof(struct game));
    if (load_game == NULL)
    {
        return -1;
    }

    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        fprintf(stderr, "Can't open file %s\n", filename);
        return -1;
    }

    struct game_state state;
    while (read_state(file, &state) == 0)
    {
        struct history_element *el = malloc(sizeof(struct history_element));

        if (el == NULL)
        {
            return -1;
        }

        el->state = state;
        if (load_game->active_history != NULL)
        {
            load_game->active_history->next = el;
            el->prev = load_game->active_history;
        }
        load_game->active_history = el;
    }

    fclose(file);

    *game = load_game;

    return 0;
}

int main(int argc, char *argv[])
{

    struct game *game = NULL;
    int seed;

    if (argc == 2)
    {
        if (load_game(&game, argv[1]))
        {
            fprintf(stderr, "Couldn't open or parse file %s\n", argv[1]);
            return -1;
        }
    }
    else
    {
        srand(time(0));
        seed = rand();
        game = create_new_game(seed, DEFAULT_MINE_COUNT);
    }

    initscr();
    while (start_cli_game(game))
    {
        seed = rand();
        delete_game(game);
        game = create_new_game(seed, DEFAULT_MINE_COUNT);
    }

    refresh();

    endwin();

    return 0;
}
