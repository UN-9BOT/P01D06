//I WANT TO PLAY WITH YOU
//        YOUR FRIEND, AI

#include <stdio.h>
#include <math.h>

int field(int q, int cor);

int main()
{
    int cor = 13;
    while(1)
    {
        char var;
        char a = 'a';
        char z = 'z';
        scanf("%c", &var);
        if (var == a)
        {
            //вызываем функцию field и выводим в консоль поле с обновленными координатами ракетки
            cor = field(1, cor);
        }
        else if (var == z)
        {
            cor = field(-1, cor);
        }
            
        
    }
    
    
    
    return 0;
}

int field(int q, int cor) {
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
    
    printf("### %d\n", cor);
    
    return cor;
}


