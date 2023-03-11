//I WANT TO PLAY WITH YOU
//        YOUR FRIEND, AI

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


