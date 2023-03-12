#include <stdio.h>
#define HT 25
#define WT 80

void draw(int, int, int, int);
int checkSPforWT(int, int, int);
int checkSPforHT(int, int, int);
int checkSPrackets(int, int, int, int, int);
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
    
    draw(40, 13, 13, 13);
    
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
            aw(ballX, ballY, rack1, rack2);
                    spX = checkSPforWT(ballX, spX, WT);
                    spY = checkSPforHT(ballY, spY, HT);
                    spX = checkSPrackets(ballX, ballY, rack1, rack2, spX);
                    ballX += spX;
                    ballY += spY;
                    if (ballX == 2) {
                        counter2 += checkLose(ballY, rack1);
                    } else if (ballX == 79) {
                        counter1 += checkLose(ballY, rack2);
                    }
                    prCounter(counter1, counter2);
                }
                prWinner((counter1 > counter2) ? 1 : 2);
                 
            }
        }
        dr
void draw(int ballX, int ballY, int rack1, int rack2) {
    for (int y = 1; y <= HT; y++) {  // Ось ракетки
        if (y == 1 || y == HT) {
            for (int i = 1; i <= WT; i++) {  // Ось границ
                printf("%c", '-');
            }
            printf("\n");
        } else {
            for (int x = 1; x <= WT; x++) {
                if ((rack1 == y || rack1 + 1 == y || rack1 - 1 == y) && x == 2) {
                    printf("|");
                } else if ((rack2 == y || rack2 + 1 == y || rack2 - 1 == y) && x == 79) {
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
//горизонтальные грани
int checkSPforWT(int coor, int sp, int range) {
    return ((((coor + sp) < range) && ((coor + sp) > 1)) ? (sp) : (-sp));
}
//вертикальные грани
int checkSPforHT(int coor, int sp, int range) {
    return ((((coor + sp) < range) && ((coor + sp) > 1)) ? (sp) : (-sp));
}

int checkSPrackets(int ballX, int ballY, int rack1, int rack2, int spX) {
    
    int rack;
    
    if(spX < 0)//летит в левую ракетку
    {
        //в checkSPrackets передаем  rack1
        //spX = checkSPrackets(ballX, ballY, rack1, spX);
        if (ballX == 3 && ((ballY-1 == rack1 - 1 || ballY-1 == rack1 || ballY-1 == rack1 + 1)||(ballY+1 == rack1 - 1 || ballY+1 == rack1 || ballY+1 == rack1 + 1)))
            
        //if(ballX == 3 && ( () || () || () ))
        {
            spX = -spX;
        }
        //else if(ballX == 78 && (ballY == rack1 - 1 || ballY == rack1 || ballY == rack1 + 1))
        //{
         //   spX = -spX;
        //}
        else
        {
            spX = spX;
        }
        rack = rack1;
    }
    else if(spX>0)//летит в правую ракетку
    {
        //в checkSPrackets передаем  rack2
        //spX = checkSPrackets(ballX, ballY, rack2, spX);
        // (|| (ballY == rack2 - 1 || ballY == rack2 || ballY == rack2 + 1)
        //if (ballX == 3 && ((ballY-1 == rack2 - 1 || ballY-1 == rack2 || ballY-1 == rack2 + 1)||(ballY+1 == rack2 - 1 || ballY+1 == rack2 || ballY+1 == rack2 + 1)))
        ///{
          //  spX = -spX;
        //}
        if(ballX == 78 && ((ballY-1 == rack2 - 1 || ballY-1 == rack2 || ballY-1 == rack2 + 1)||(ballY+1 == rack2 - 1 || ballY+1 == rack2 || ballY+1 == rack2 + 1)))
        {
            spX = -spX;
        }
        else
        {
            spX = spX;
        }
        rack = rack2;
    }
    
    
    printf("%d %d %d %d", ballX, ballY, rack, spX);
    
        
    return spX;
    //return ((((coor + sp) < range) && ((coor + sp) > 1)) ? (sp) : (-sp));
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
