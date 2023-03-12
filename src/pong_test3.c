#include <stdio.h>

//int rackets(int cor1, int cor2);
int check_click(char var);
void draw(int cor1, int cor2);
void draw_2(int cor1, int cor2);
//int check_click_2(char var);
int checkSP(int, int, int);
int checkLose(int, int, int);

int main()
{
    //int ballX, ballY;        // координаты мяча
    //int spX, spY;
    
    int cor1 = 13; //координаты по оси у у ракеток
    int cor2 = 13;
    int flag = 0;
    //flag 1 - ходил первый игрок
    //flag 2 - ходил второй игрок
    char var;
    //char enter;
    //int count = 0;
    draw_2(cor1, cor2);
    while(1)
    {
        //int check;
        //scanf("%c%c", &var, &enter);
        var = getchar();
        //if (check == 2 && enter == '\n')
        //{
            if((var == 'a' || var == 'z') && flag != 1)
            {
                printf("1\n");
                if(cor1 - check_click(var) != 2 && cor1 - check_click(var) != 24)
                {
                    cor1 = cor1 - check_click(var);
                    cor2 = cor2;
                    flag = 1;
                    draw(cor1, cor2);
                }
            }
            else if ((var == 'k' || var == 'm') && flag != 2)
            {
                printf("2\n");
                if(cor2 - check_click(var) != 2 && cor2 - check_click(var) != 24)
                {
                    cor2 = cor2 - check_click(var);
                    cor1 = cor1;
                    flag = 2;
                    draw(cor1, cor2);
                }
                
            }
            else if(var == ' ' && flag == 1)
            {
                printf("3\n");
                cor1 = cor1;
                cor2 = cor2;
                flag = 2;
                draw(cor1, cor2);
            }
            else if(var == ' ' && flag == 2)
            {
                printf("4\n");
                cor1 = cor1;
                cor2 = cor2;
                flag = 1;
                draw(cor1, cor2);
            }
    
            /*
            else
            {
                //printf("5\n");
                printf("Можно сделать только 1 ход\n");
            }
            */
        //}
        //else
        //{
          //  printf("Вводи одну команду\n");
            //check = scanf("%c%c", &var, &enter);
        //}
            
        
        
        /*
        count++;
        printf("Count = %d\n", count);
        
        //printf("%d %d \n", cor1, cor2);
        printf("Переменные: %c!\n", var);
        //printf("+\n");
         */
    }
    
    return 0;
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

void draw(int rack1, int rack2) {
    int HT = 25;
    int WT = 80;
    for (int y = 1; y <= HT; y++) {
        //printf("%d", y);
        if (y == 1 || y == HT) {
            for (int i = 1; i <= WT; i++)
            {
                printf("%c", '#');
                
            }
            printf("\n");
        }
        else{
            for (int x = 1; x <= WT; x++) {  // x
                if ((rack1 == y || rack1+1 == y || rack1-1 == y) && x == 2)
                {
                    printf("|");
                }
                else if ((rack2 == y || rack2+1 == y || rack2-1 == y) && x == 79)
                {
                    printf("|");
                    
                }
                else if (x == 1 || x == 80)
                {
                    printf("§");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        
    }
}

void draw_2(int rack1, int rack2) {
    int HT = 25;
    int WT = 80;
    for (int y = 1; y <= HT; y++) {
        //printf("%d", y);
        if (y == 1 || y == HT) {
            for (int i = 1; i <= WT; i++)
            {
                printf("%c", '#');
                
            }
            printf("\n");
        }
        else{
            for (int x = 1; x <= WT; x++) {  // x
                if ((rack1 == y || rack1+1 == y || rack1-1 == y) && x == 2)
                {
                    printf("|");
                }
                else if ((rack2 == y || rack2+1 == y || rack2-1 == y) && x == 79)
                {
                    printf("|");
                    
                }
                else if (x == 1 || x == 80)
                {
                    printf("§");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        
    }
}

int checkSP(int coor, int sp, int range) {
    return ((((coor + sp) <= range) && ((coor + sp) >= 0)) ? (sp) : (-sp));
}

/*
int check_input()
{
    //если игрок1 сделал ход, то следующим ходит игрок2
    //return 1 - ход разрешен; return 0 - ход запрещен
    
    
    
    
}
*/

