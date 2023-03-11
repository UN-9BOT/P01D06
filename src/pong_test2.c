#include <stdio.h>

//int rackets(int cor1, int cor2);
int check_click(char var);
//int check_click_2(char var);

int main()
{
    
    int cor1 = 13; //координаты оп оси у у ракеток
    int cor2 = 13;
    
    while(1)
    {
        
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
/*
int rackets(int cor1, int cor2)
{
    //printf("%d %d \n", cor1, cor2);
    
    int HT = 26;
    int WT = 81;
    //printf("%d %d \n", cor1, cor2);
    
    
    for(int i = 0; i<= HT; i++)
    {
        
        for(int j = 0; j<= WT; j++)
        {
            
            //if(i == 1 || i == HT)
            //{
            //    //рисуем -------
            //}
            if(i != 1 && i != HT)
            {
                if(j == 0)
                {
                    if(i == cor1 - 1 || i == cor1 || i == cor1 + 1)
                    {
                        printf("|");
                    }
                    else
                        printf(" ");
                }
                else if(j==WT)
                {
                    if(i == cor2 - 1 || i == cor2 || i == cor2 +1)
                    {
                        printf("|");
                        printf("\n");
                    }
                    else
                        printf(" ");
                }
                else
                    printf(" ");
            }
            
            
        }
        
    }
    
    
    
    
    return 0;
}
*/
