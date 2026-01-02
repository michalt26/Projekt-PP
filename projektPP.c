#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"

int main()
{
    dinozaury *head=NULL;
    int opcja=0;
    while(opcja!=3){
        printf("\n ======= MENU ======= \n");
        printf("1-dodaj nowego dinozaura\n");
        printf("2-wyswietl liste dinozaurow\n");
        printf("3-zakoncz dzialanie programu\n");
        printf("opcja: ");
        if (scanf("%d",&opcja)!=1){
            while(getchar()!='\n');
            opcja=0;
        }
        else{
            while(getchar()!='\n');
        }
        switch(opcja){
            case 1:
                dodaj(&head);
                break;
            case 2:
                wypisz(head);
                break;
            case 3:
                zwolnienieListy(head);
                break;
            default:
                printf("!! wprowadz poprawny numer !! \n");
        }
    }
    return 0;
}