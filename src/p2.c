#include <stdio.h>
#define HT 25
#define WT 80

void draw(int, int, int, int);
int checkSPforWT(int, int, int);
int checkSPforHT(int, int, int);
int check_click(char);
int checkLose(int, int);
void prCounter(int, int);
void prWinner(int);

int main(void) {
    int flag;
    int ballX, ballY;        // координаты мяча
    int spX, spY;            // направление
    int counter1, counter2;  // счетчик результатов
    int rack1, rack2;        // координаты оп оси у у ракеток

    ballX = 40;
    ballY = 13;
    spX = spY = 1;
    counter1 = counter2 = flag = 0;
    rack1 = rack2 = 13;

    while (counter1 != 21 && counter2 != 21) {
        char var;  // symbol for input
        var = getchar();
        if ((var == 'a' || var == 'z') && flag != 1) {
            if (rack1 - check_click(var) != 2 && rack1 - check_click(var) != 24) {
                rack1 = rack1 - check_click(var);
                flag = 1;
            }
        } else if ((var == 'k' || var == 'm') && flag != 2) {
            if (rack2 - check_click(var) != 2 && rack2 - check_click(var) != 24) {
                rack2 = rack2 - check_click(var);
                flag = 2;
            }

        } else if (var == ' ' && flag == 1) {
            flag = 2;
        } else if (var == ' ' && flag == 2) {
            flag = 1;
        }
        draw(ballX, ballY, rack1, rack2);
        spX = checkSPforWT(ballX, spX, WT);
        spY = checkSPforHT(ballY, spY, HT);
        ballX += spX;
        ballY += spY;
        draw(ballX, ballY, rack1, rack2);  // print all data
        if (ballX == 2) {
            counter2 += checkLose(ballY, rack1);
        } else if (ballX == 79) {
            counter1 += checkLose(ballY, rack2);
        }
        prCounter(counter1, counter2);
    }
    prWinner((counter1 > counter2) ? 1 : 2);
}

void draw(int ballX, int ballY, int rack1, int rack2) {
    for (int y = 1; y <= HT; y++) {  // Ось ракетки
        if (y == 1 || y == HT) {
            for (int i = 1; i <= WT; i++) {  // Ось границ
                printf("%c", '-');
            }
            printf("\n");
        } else {
            for (int x = 1; x <= WT; x++) {
                if ((rack1 == y || rack1 + 1 == y || rack1 - 1 == y) && x == 1) {
                    printf("|");
                } else if ((rack2 == y || rack2 + 1 == y || rack2 - 1 == y) && x == 80) {
                    printf("|");
                } else if (ballX == x && ballY == y) {
                    printf("o");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}

int checkSPforWT(int coor, int sp, int range) {
    return ((((coor + sp) < range) && ((coor + sp) > 1)) ? (sp) : (-sp));
}
int checkSPforHT(int coor, int sp, int range) {
    return ((((coor + sp) < range) && ((coor + sp) > 1)) ? (sp) : (-sp));
}

int checkLose(int ballY, int rack) {
    int res;
    if (ballY != rack && ballY != rack + 1 && ballY != rack - 1) {
        res = 1;
    } else
        res = 0;
    return (res);
}

int check_click(char var) {
    int res;
    if (var == 'a' || var == 'k') {
        res = 1;
    } else if (var == 'z' || var == 'm') {
        res = -1;
    } else if (var == ' ') {
        res = 0;
    } else
        res = 0;
    return (res);
}

void prCounter(int c1, int c2) {
    for (int i = 0; i < 15; i++) {
        printf(" ");
    }
    printf("Player1");
    for (int i = 0; i < 15; i++) {
        printf(" ");
    }
    printf("%i || %i", c1, c2);
    for (int i = 0; i < 15; i++) {
        printf(" ");
    }
    printf("Player2");
    for (int i = 0; i < 15; i++) {
        printf(" ");
    }
    printf("\n\r");
}

void prWinner(int win) {
    for (int y = 1; y <= HT; y++) {  // Ось ракетки
        if (y == 1 || y == HT) {
            for (int i = 1; i <= WT; i++) {  // Ось границ
                printf("%c", '-');
            }
            printf("\n");
        } else {
            for (int x = 1; x <= WT; x++) {
                if ((13 == y || 14 == y || 12 == y) && x == 1) {
                    printf("|");
                } else if ((13 == y || 14 == y || 12 == y) && x == WT) {
                    printf("|");
                } else if (y == 13 && x == 33) {
                    if (win == 1) {
                        printf("Winner is Player1");
                        x += 16;
                    } else {
                        x += 16;
                        { printf("Winner is Player2"); }
                    }
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}
