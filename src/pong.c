#include <stdio.h>
#define HT 25
#define WT 80

void draw(int, int, int, int);
int checkSP(int, int, int);
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
        draw(x, y, rack1, rack);

        getchar();
    }
    return (0);
}

void draw(int x, int y, int rack1, int rack2) { 
    for (int k = 0; k <= HT; k++) {  // y
        if (k == y) { // y 
            for (int j = 0; j <= WT; j++) {  // x
                if (j == x) { printf("*"); } else { printf(" "); } }
        }         
        if (k == 0 || k == HT) {
            for (int i = 0; i <= WT; i++) { printf("%c", '-'); } 
        } else { printf("\n"); }
    }
}

int checkSP(int coor, int sp, int range) { return ((((coor + sp) < range) && ((coor + sp) > 0) ) ? (sp) : (-sp)); }
