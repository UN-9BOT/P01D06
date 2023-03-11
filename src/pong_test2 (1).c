#include <stdio.h>

//int rackets(int cor1, int cor2);
int check_click(char var);
void draw(int cor1, int cor2);
//int check_click_2(char var);

int main()
{
    
    int cor1 = 13; //координаты по оси у у ракеток
    int cor2 = 13;
    //int flag = 0;
    //flag 1 - ходил первый игрок
    //flag 2 - ходил второй игрок
    
    
    while(1)
    {
        
        char var;
        scanf("%c", &var);
        if(var == 'a' || var == 'z')
        {
            if(cor1 - check_click(var) != 1 && cor1 - check_click(var) != 24)
            {
                cor1 = cor1 - check_click(var);
                cor2 = cor2;
            }
            
        }
        else if (var == 'k' || var == 'm')
        {
            if(cor2 - check_click(var) != 1 && cor2 - check_click(var) != 24)
            {
                cor2 = cor2 - check_click(var);
                cor1 = cor1;
            }
            
        }
        else if(var == ' ')
        {
            cor1 = cor1;
            cor2 = cor2;
        }
        
        draw(cor1, cor2);
        printf("%d %d \n", cor1, cor2);

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
                if ((rack1 == y || rack1+1 == y || rack1-1 == y) && x == 1)
                {
                    printf("|");
                }
                else if ((rack2 == y || rack2+1 == y || rack2-1 == y) && x == 80)
                {
                    printf("|");
                    
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

/*
void draw(int rack1, int rack2) {
    int HT = 25;
    int WT = 80;
    for (int y = 0; y <= HT; y++) {
        if (y == 0 || y == HT) {
            for (int i = 0; i <= WT; i++)
            {
                printf("%c", '#');
                
            }
            printf("\n");
        }
        for (int x = 0; x <= WT; x++) {  // x
            if ((rack1 == y || rack1+1 == y || rack1-1 == y) && x == 0)
            {
                printf("|");
            }
            else if ((rack2 == y || rack2+1 == y || rack2-1 == y) && x == 80)
            {
                printf("|");
                
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
*/
/*
int check_input()
{
    //если игрок1 сделал ход, то следующим ходит игрок2
    //return 1 - ход разрешен; return 0 - ход запрещен
    
    
    
    
}
*/
