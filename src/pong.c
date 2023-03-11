#include <stdio.h>
#define HT 25
#define WT 80

void draw(int, int);
int checkSP(int, int, int);
int field_rackets(int, int);

int main(void) {
    int x, y, spX, spY;

    x = y = spX = spY = 1; 
    draw(x, y);
    printf("\n");
    while (1) {
        spX = checkSP(x, spX, WT);
        spY = checkSP(y, spY, HT);
        x += spX;
        y += spY;
        //
        draw(x,y);
        getchar();
    }
    return (0);
}

void draw(int x, int y) { 
    for (int k = 0; k < HT; k++) {  // y
        if (k == y) { // y 
            for (int j = 0; j < WT; j++) { 
                if (j == x) { printf("*"); } else { printf(" "); } }
        }         
        if (k == 0 || k == HT) {
            for (int i = 0; i <= WT; i++) {
                printf("%c", '-'); 
            } 
        } else { printf("\n"); }
    }
}

int checkSP(int coor, int sp, int range) { return ((((coor + sp) < range) && ((coor + sp) > 0) ) ? (sp) : (-sp)); }
