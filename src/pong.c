#include <stdio.h>
#define HT 25
#define WT 80

void draw(int, int, int, int);
int checkSP(int, int, int);
int check_click(char var);
// int checkWin(int, int, int, int);
// int field_rackets(int, int);
int main(void) {
    int x, y, spX, spY;
    
    int cor1 = 13; //координаты оп оси у у ракеток
    int cor2 = 13;
    x = y = spX = spY = 2; 
    draw(x, y, cor1, cor2);
    printf("\n");
    while (1) {
        
        char var;
        scanf("%c", &var);
        //check_click(var, cor1, cor2);
        if(var == 'a' || var == 'z')
        {
            cor1 = cor1 - check_click(var);
            cor2 = cor2;
        }
        else if (var == 'k' || var == 'm')
        {
            cor2 = cor2 - check_click(var);
            cor1 = cor1;
        }
        else if(var == ' ')
        {
            cor1 = cor1;
            cor2 = cor2;
        }
        //rackets(cor1, cor2);

        spX = checkSP(x, spX, WT);
        spY = checkSP(y, spY, HT);
        x += spX;
        y += spY;
        // rack = field_rackets(x, y); 
        draw(x, y, cor2, cor1);
    }
    return (0);
}

void draw(int ballX, int ballY, int rack1, int rack2) { 
    for (int y = 0; y <= HT; y++) {
        if (y == 0 || y == HT) {
            for (int i = 0; i <= WT; i++) { printf("%c", '-'); } 
        }
        for (int x = 80; x >= 0; x--) {  // x
            if ((rack1 == y || rack1+1 == y || rack1-1 == y) && x == 0) {
                printf("|");
            } else if ((rack2 == y || rack2+1 == y || rack2-1 == y) && x == 80) {
                printf("|");
            } else if (ballX == x && ballY == y) { 
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
int check_click(char var)
{
    char a = 'a';
    char z = 'z';
    char k = 'k';
    char m = 'm';
    char ws = ' ';
    
    if(var == a || var == k)
    {
        return 1;
    }
    else if (var == z || var == m)
    {
        return  -1;
    }
    else if (var == ws)
    {
        return 0;
    }
    return 0; //для обработки ошибок
}
