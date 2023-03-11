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
