//Ryan Perrina, Merli  Davide, Manuel Luzietti, Giulia Tedeschi
//16-10-2019
//try to guess a number
int main()
{
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(void)
{
    unsigned int min,max,valmax,baking,count;
    unsigned int num;
    unsigned char answer='N';
    unsigned char sign;

    printf("Insert the  min e max value :\n");
    scanf("%d %d",&min,& valmax);
    fflush(stdin);
    while(min<0)    //while the min value is < 0 you have to reinsert a value
    {
        printf("reinsert a min value this time>0");
        scanf("%d",&min);
    }


    if(min>valmax)  //setting the correct range of value
    {
        baking=min;
        min=valmax;
        valmax=baking;

    }


    srand(time(NULL));   //initialize the generator of casual number
    max=valmax-min;      //starting the game

    do{
        num=min+rand() %max;   //generate casual  number the range
        printf("your number is: %d?press y for yes and n for no...\n",num);
        scanf("%c",&answer);
        fflush(stdin);
        if(toupper(answer)=='N')  //using toupper we can accept also the upper case
        {
            printf("your number is (<) or (>) of %d?\n",num);
            scanf("%c",&sign);
            fflush(stdin);
            if(sign=='<')
            {
                max=(num)-min;   //resetting the correct range of values
                valmax=max+min;
            }
            else if(sign=='>')
                {
                    min=num+1;
                    max=valmax-min+1;
                }
        }
     count++;
    }while(toupper(answer)!= 'Y'); //using toupper we can accept also the upper case
    printf("Guessed!\n");
    printf("i have guessed in %d\n",count);
    return 0;
}
     }
