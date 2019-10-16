#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(void)
{
    int min,max;
    int num;
    char risposta='N';
    char segno;

    printf("inserisci min e max:\n");
    scanf("%d %d",&min,&max);
    fflush(stdin);

    if(min<0)min=0;
    if(min>max)
    {
        int mem=min;
        min=max;
        max=mem;

    }


    srand(time(NULL));
    max=max-min;  //parte

    do{
        num=min+rand() %max;
        printf("il numero scelto è %d?(y/n)(min=%d,max=%d)\n",num,min,max);
        scanf("%c",&risposta);
        fflush(stdin);
        if(toupper(risposta)=='N')
        {
            printf("il numero pensato viene prima(<) o dopo(>) %d?\n",num);
            scanf("%c",&segno);
            fflush(stdin);
            if(segno=='<')max=(num-1)-min;
            else if(segno=='>')min=num+1;
        }

    }while(toupper(risposta)!= 'Y');
    printf("INDOVINATO!\n");
    return 0;
}
