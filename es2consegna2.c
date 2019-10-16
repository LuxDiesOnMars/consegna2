#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(void)
{
    int min,max,Valmax;
    int num;
    char risposta='N';
    char segno;

    printf("inserisci min e max:\n");
    scanf("%d %d",&min,&Valmax);
    fflush(stdin);

    if(min<0)min=0;
    if(min>Valmax)
    {
        int mem=min;
        min=Valmax;
        Valmax=mem;

    }


    srand(time(NULL));
    max=Valmax-min;  //parte

    do{
        num=min+rand() %max;
        printf("il numero scelto è %d?(y/n)(%d %d)\n",num,min,max+min);
        scanf("%c",&risposta);
        fflush(stdin);
        if(toupper(risposta)=='N')
        {
            printf("il numero pensato viene prima(<) o dopo(>) %d?\n",num);
            scanf("%c",&segno);
            fflush(stdin);
            if(segno=='<')
            {
                max=(num-1)-min;
                Valmax=max+min;
            }
            else if(segno=='>')
                {
                    min=num+1;
                    max=Valmax-min;
                }
        }

    }while(toupper(risposta)!= 'Y');
    printf("INDOVINATO!\n");
    return 0;
}
