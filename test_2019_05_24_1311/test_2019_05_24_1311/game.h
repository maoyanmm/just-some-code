#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define boom_count 10

void test();
void menu();
void game();
void init_board(char mine[ROWS][COLS], int rows, int cols, char set);
void set_boom(char mine[ROWS][COLS], int rows, int cols);
void display_board(char mine[ROWS][COLS], int rows, int cols);
void find_boom(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int countcount(char mine[ROWS][COLS], int x, int y);
void spread(char mine[ROWS][COLS], char show[ROWS][COLS],int x, int y);
void one_more_life(char mine[ROWS][COLS], int row, int col);


