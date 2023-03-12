#include <stdio.h>
#define HT 25
#define WT 80

void draw(int, int, int, int);
int checkSPforWT(int, int, int);
int checkSPforHT(int, int, int);
int check_click(char var);
int checkLose(int, int, int);
void whiller(void);

int main(void) {
    int ballX, ballY;        // координаты мяча
    int spX, spY;            // направление
    int counter1, counter2;  // счетчик результатов
    int rack1, rack2;        //координаты оп оси у у ракеток

    ballX = 40;
    ballY = 13;
    spX = spY = 1;
    counter1 = counter2 = 0;
    rack1 = rack2 = 13;

    while (1) {
        while (1) {
            char var;
            scanf("%c", &var);
            if (var == 'a' || var == 'z') {
                if (rack1 - check_click(var) != 2 && rack1 - check_click(var) != 24) {
                    rack1 = rack1 - check_click(var);
                }
            } else if (var == 'k' || var == 'm') {
                if (rack2 - check_click(var) != 2 && rack2 - check_click(var) != 24) {
                    rack2 = rack2 - check_click(var);
                }
            } //else if (var == ' ') {
               // rack1 = rack1;
               // rack2 = rack2;
            //}

            spX = checkSPforWT(ballX, spX, WT);
            spY = checkSPforHT(ballY, spY, HT);
            ballX += spX;
            ballY += spY;
            draw(ballX, ballY, rack1, rack2);
            printf("%i %i %i %i \n", ballX, ballY, rack1, rack2);
            if (ballX == 2)  {
                counter2 += checkLose(ballX, ballY, rack1);
            }
            else if (ballX == 79) {
                counter1 += checkLose(ballX, ballY, rack2);
            } 
            printf("%i, %i\n", counter1, counter2);
        }
    }
}
void draw(int ballX, int ballY, int rack1, int rack2) {
    for (int y = 1; y <= HT; y++) {  // Ось ракетки
        // printf("%i", y);
        if (y == 1 || y == HT) {
            for (int i = 1; i <= WT; i++) { // Ось границ
                printf("%c", '-');
                // printf("%i",i % 10);
            }
            printf("\n");
        } else {
            for (int x = 1; x <= WT; x++) {
                if ((rack1 == y || rack1 + 1 == y || rack1 - 1 == y) && x == 1) {
                    printf("|");
                } else if ((rack2 == y || rack2 + 1 == y || rack2 - 1 == y) && x == 80) {
                    printf("|");
                } else if (ballX == x && ballY == y) {
                    printf("*");}
                else {
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
          
int checkLose(int ballX, int ballY, int rack) {
    printf("%d %d %d \n", ballX, ballY, rack);
    if (ballY != rack && ballY != rack + 1 && ballY != rack - 1) {
        return (1);
    } else  return (0);
    return (0);
}

int check_click(char var) {
    if (var == 'a' || var == 'k') {
        return 1;
    } else if (var == 'z' || var == 'm') {
        return -1;
    } else if (var == ' ') {
        return 0;
    } else
        return 0;  //для обработки ошибок
}
