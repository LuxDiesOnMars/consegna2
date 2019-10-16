//macano due funzioni di ctype !!!!

#include <stdio.h>
#include <ctype.h>


int main(void)
{   int i=0;
    int contatoreSpazi=0;
    int contatoreNuovaLinea=0;
    int contatoreCaratteriLetti=0;
    int contatoreCaratteriMaiuscoli=0;
    int contatoreCaratteriMinuscoli=0;
    int contatoreErrori=0;
    int contatoreCaratteriSpeciali=0;
    int contatoreNumeri=0;

    char stringa[100];
    scanf("%[^#]",&stringa);
    //printf("%s",stringa);
    for(;stringa[i]!='\0';i++)
    {
        if(isalnum(stringa[i]))
        {
            if(isalpha(stringa[i]))
            {
                if(isupper(stringa[i]))
                {
                    ++contatoreCaratteriMaiuscoli;
                }
                else if(islower(stringa[i]))
                {
                    ++contatoreCaratteriMinuscoli;
                }
                else ++contatoreErrori;

            }
            else if(isdigit(stringa[i]))
            {
                ++contatoreNumeri;
            }
            else ++contatoreErrori;
        }
        else
        {
            switch(stringa[i])
            {
                case '\n':
                    ++contatoreNuovaLinea;break;
                case ' ':
                    ++contatoreSpazi;break;
                default:
                    ++contatoreCaratteriSpeciali;

            }
        }
    }
    if(contatoreErrori!=0)
    {
        printf("ERRORE");
        return 0;
    }
    else contatoreCaratteriLetti=i;
    printf("\nn.spazi: %5d\n",contatoreSpazi);
    printf("n.caratteri nuova linea: %5d\n",contatoreNuovaLinea);
    printf("n.caratteri speciali: %5d\n",contatoreCaratteriSpeciali);
    printf("n.caratteri letti: %5d\n",contatoreCaratteriLetti);
    printf("n.caratteri maiuscoli: %5d\n",contatoreCaratteriMaiuscoli);
    printf("n.caratteri minuscoli: %5d\n",contatoreCaratteriMinuscoli);
    printf("n.caratteri numerici: %5d\n",contatoreNumeri);
    return 0;
}
