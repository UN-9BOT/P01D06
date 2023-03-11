#include <stdio.h>
#include <math.h>

int rackets(int cor1, cor2);
int check_click(char var, int cor1, int cor2);
int check_click_2(char var, int cor1, int cor2);

int main()
{
    int cor1 = 13;
    int cor2 = 13;
    
    while(1)
    {
        
        
        char var;
        scanf("%c", &var);
        check_click(var, cor1, cor2);
        

        
        
    }
    
    return 0;
}

int rackets(int cor1, cor2)
{
    int HT = 25;
    int WT = 80;
    
    for(int i = 1; i<= HT; i++)
    {
        if(i==cor1-1 || i == cor || i == cor + 1)
        {
            printf("|");
            //printf("\n");
        }
        
        
        for(int j = 1; j<= WT; j++)
        {
            
            if (j==80)
            {
                if(i==cor2-1 || i==cor2 || i == cor2 + 1)
                {
                    printf("|");
                    printf("\n");
                    i++;
                }
            }
            
            
        }
        
    }
}

int check_click(char var, int cor1, int cor2)
{

            
    if(check_click_2(var) == 1) //двигали первую ракетку вверх
    {
        rackets(cor1 - 1; cor2);
    }
    else if(check_click_2(var) == -1) //двигали первую ракетку вниз
    {
        rackets(cor1 + 1; cor2);
    }
    else if(check_click_2(var) == 2) //двигали вторую ракетку вверх
    {
        rackets(cor1; cor2 - 1);
    }
    else if(check_click_2(var) == -2) //двигали вторую ракетку вниз
    {
        rackets(cor1; cor2 - 1);
    }
    else if(check_click_2(var) == 0) //ход пропустили, ракетки не двигали
    {
        rackets(cor1; cor2);
    }
    return 0;
}

int check_click_2(char var)
{
    char a = 'a';
    char z = 'z';
    char k = 'k';
    char m = 'm';
    char ws = ' ';
    
    if(var == a)
    {
        return 1;
    }
    else if (var == z)
    {
        return  -1;
    }
    else if (var == k)
    {
        return  2;
    }
    else if (var == m)
    {
        return  -2;
    }
    else if (var == ws)
    {
        return 0;
    }
    return 0;
}
