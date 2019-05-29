#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>
#define N 3
 void test();
 void menu();
 void game();
 void board(char arr[N][N]);
 void player_move(char arr[N][N]);
 void computer_move(char arr[N][N]);
 char win(char arr[N][N]);
 void init_board(char arr[N][N]);
 int full(char arr[N][N]);
