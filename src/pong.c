#include <stdio.h>
#define HT 25
#define WT 80

void draw(int, int, int, int);
int checkSP(int, int, int);
// int checkWin(int, int, int, int);
// int field_rackets(int, int);
int main(void) {
    int x, y, spX, spY, rack1, rack2;

    x = y = spX = spY = 2; 
    draw(x, y, 12, 12);
    printf("\n");
    while (1) {
        spX = checkSP(x, spX, WT);
        spY = checkSP(y, spY, HT);
        x += spX;
        y += spY;
        // rack = field_rackets(x, y); 
        rack1 = 6;
        rack2 = 12;
        draw(x, y, rack1, rack2);
        getchar();
    }
    return (0);
}

void draw(int ballX, int ballY, int rack1, int rack2) { 
    for (int y = 0; y <= HT; y++) {
        if (y == 0 || y == HT) {
            for (int i = 0; i <= WT; i++) { printf("%c", '-'); } 
        }
        for (int x = 80; x >= 0; x--) {  // x
            if (((rack1 == y) || (rack1+1 == y) || (rack1-1 == y)) && (x == 0)) {
                printf("|");
            } else if (((rack2 == y) || (rack2+1 == y) || (rack2-1 == y)) && (x == 80)) {
                printf("|");
            } else if ((ballX == x) && (ballY == y)) { 
                printf("*"); 
            } else {
                printf(" ");
            }        
        }
        printf("\n");
    }
}

int checkSP(int coor, int sp, int range) { return ((((coor + sp) < range) && ((coor + sp) > 0) ) ? (sp) : (-sp)); }
// int checkWin(int ballX, int ballY, int rack1
