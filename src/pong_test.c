#include <stdio.h>

int rackets(int cor1, int cor2);
int check_click(char var, int cor1, int cor2);
int check_click_2(char var);

int main()
{
    int cor1 = 13; //координаты оп оси у у ракеток
    int cor2 = 13;
    
    while(1)
    {
       
        char var;
        scanf("%c", &var);
        check_click(var, cor1, cor2);
        cor1 = rackets(cor1, cor2);
        cor2 = check_click(var, cor1, cor2);
        //printf("%d %d \n", cor1, cor2);
      
    }
    
    return 0;
}

int rackets(int cor1, int cor2)
{
    printf("%d %d \n", cor1, cor2);
    
    //int HT = 25;
    //int WT = 80;
    //printf("%d %d \n", cor1, cor2);
    
    /*
    for(int i = 1; i<= WT; i++)
    {
        
        for(int j = 1; j<= HT; j++)
        {
            
            if(i == 1)
            {
                if(j==cor1-1 || j == cor1 || j == cor1 + 1)
                {
                    printf("|");
                    printf("\n");
                }
                else
                {
                    printf(" ");
                    printf("\n");
                }
                    
            }
            else if(i == 80)
            {
                if(i==cor2-1 || i==cor2 || i == cor2 + 1)
                {
                    printf("|");
                    printf("\n");
                    //i++;
                }
                else
                {
                    printf(" ");
                    printf("\n");
                }
            }
            else
                printf(" ");
            
                
        }
        
    }
    */
    
    
    
    return cor1;
}

int check_click(char var, int cor1, int cor2)
{

    if(check_click_2(var) == 1) //двигали первую ракетку вверх
    {
        cor1 = cor1 - 1;
        cor2 = cor2;
    }
    else if(check_click_2(var) == -1) //двигали первую ракетку вниз
    {
        cor1 = cor1 + 1;
        cor2 = cor2;
    }
    else if(check_click_2(var) == 2) //двигали вторую ракетку вверх
    {
        cor1 = cor1;
        cor2 = cor2 - 1;
    }
    else if(check_click_2(var) == -2) //двигали вторую ракетку вниз
    {
        cor1 = cor1;
        cor2 = cor2 - 1;
    }
    else if(check_click_2(var) == 0) //ход пропустили, ракетки не двигали
    {
        cor1 = cor1;
        cor2 = cor2;
    }
    
    rackets(cor1, cor2);
    return cor2;
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
    return -3;
}
