#include <stdio.h>
#define HT 25
#define WT 80

<<<<<<< HEAD
#include <stdio.h>
#include <math.h>

int field_rackets(int q, int cor);
int check_click(char var, int cor);
//int field();
//int l_racket();
//int r_racket();

int main()
{
    int cor = 13;
    
    while(1)
    {
        char var;
        scanf("%c", &var);
        cor = check_click(var, cor);
        //printf("!!! %d\n", cor);
    
    
    }
    return 0;
}
   

/*
int r_racket()
{
    
}

int l_racket()
{
    
}
*/
int field_rackets(int q, int cor) {
    int HT = 25;
    int WT = 80;
    
    if(q == 1)
    {
        for (int k = 0; k <= HT; k++)
        {
            if (k == 0 || k == HT) {
                for (int i = 0; i <= WT; i++) {
                    printf("%c", '-');
                }
            }
            else if (k==cor-1)
            {
                for (int i = 1; i<=3; i++)
                {
                    
                    printf("|");
                    printf("\n");
                    k++;
                }
                cor = cor - 1;
            }
            else
                printf("\n");
        }
        printf("\n");
    }
    
    
    else if(q == -1)
    {
        for (int k = 0; k <= HT; k++) {
            if (k == 0 || k == HT) {
                for (int i = 0; i <= WT; i++) {
                    printf("%c", '-');
                }
            }
            else if (k==cor-1)
            {
                for (int i = 1; i<=3; i++)
                {
                    
                    printf("|");
                    printf("\n");
                    k++;
                }
                cor = cor + 1;
            }
            else
                printf("\n");
            
        }
        printf("\n");
    }
    else if(q == 2)
    {
        for (int k = 0; k <= HT; k++) {
            if (k == 0 || k == HT) {
                for (int i = 0; i <= WT; i++) {
                    printf("%c", '-');
                }
            }
            else if (k==cor-1)
            {
                for (int i = 1; i<=3; i++)
                {
                    
                    printf("|");
                    printf("\n");
                    k++;
                }
                cor = cor + 1;
            }
            else
                printf("\n");
            
        }
        printf("\n");
    }
    else if(q == -2)
    {
        for (int k = 0; k <= HT; k++) {
            if (k == 0 || k == HT) {
                for (int i = 0; i <= WT; i++) {
                    printf("%c", '-');
                }
            }
            else if (k==cor-1)
            {
                for (int i = 1; i<=3; i++)
                {
                    
                    printf("|");
                    printf("\n");
                    k++;
                }
                cor = cor + 1;
            }
            else
                printf("\n");
            
        }
        printf("\n");
    }
    
    
    //printf("### %d\n", cor);
    
    return cor;
}

int check_click(char var, int cor)
{
    char a = 'a';
    char z = 'z';
    char k = 'k';
    char m = 'm';
            
    if (var == a)
    {
        //вызываем функцию field и выводим в консоль поле с обновленными координатами ракетки
        cor = field_rackets(1, cor);
    }
    else if (var == z)
    {
        cor = field_rackets(-1, cor);
    }
        
    else if(var == k)
    {
        cor = field_rackets(2, cor);
    }
            
    else if(var == m)
    {
        cor = field_rackets(-2, cor);
    }
    return cor;
}
=======
void draw(int, int, int, int);
int checkSP(int, int, int);
int check_click(char var);
int checkLose(int, int, int);
>>>>>>> origin/yajairah

int main(void) {
    int x, y, spX, spY;
    int counter1 = 0; 
    int counter2 = 0; 
    int res;
    int cor1 = 13; //координаты оп оси у у ракеток
    int cor2 = 13;
    x = y = spX = spY = 1; 
    draw(x, y, cor1, cor2);
    printf("\n");
    while(1) {
        while (1) {
            
            char var;
            // var = getchar();
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
            res = checkLose(x, y, cor1);
            if (res > 0) {
                if (res == 1) { counter1++; }
                if (res == 2) { counter2++; }
                break;
            }
            res = checkLose(x, y, cor2);
            if (res > 0) {
                if (res == 1) { counter1++; }
                if (res == 2) { counter2++; }
                break;
            }
        printf("%i, %i", counter1, counter2);
        }
    printf("%i, %i", counter1, counter2);
    }
    return (0);
}

void draw(int ballX, int ballY, int rack1, int rack2) { 
    for (int y = 0; y <= HT; y++) {
        if (y == 0 || y == HT) {
            for (int i = 0; i <= WT; i++) { printf("%c", '-'); } 
        }
        for (int x = 80; x >= 0; x--) {  // x
            if ((rack1 == y || rack1+1 == y || rack1-1 == y) && x == 1) {
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
int checkLose(int ballX, int ballY, int rack) {
    printf("%d %d %d    ", ballX, ballY, rack); 
    if (ballX == 79) {
        if (ballY != rack || ballY != rack+1 || ballY != rack-1) { return (2); }
    }
    if (ballX == 1) {
        if (ballY != rack || ballY != rack+1 || ballY != rack-1) { return (1); }
    } 
    return (0);
}

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
