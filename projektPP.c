#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"

int main()
{
    dinozaury *head=NULL;
    int opcja=99;
    while(opcja!=0){
        printf("\n ======= MENU ======= \n");
        printf("1 - dodaj nowego dinozaura\n");
        printf("2 - wyswietl liste dinozaurow\n");
        printf("3 - wyszukiwanie dinozaura po gatunku\n");
        printf("4 - modyfikacja dinozaura\n");
        printf("5 - usuwanie dinozaura \n");
        printf("6 - zapisywanie danych dinozaurow do pliku\n");
        printf("7 - wczytywanie danych dinozaurow z pliku\n");
        printf("0 - zakoncz dzialanie programu\n");
        printf("opcja: ");
        if (scanf("%d",&opcja)!=1){
            while(getchar()!='\n');
            opcja=-1;
        }
        else{
            while(getchar()!='\n');
        }
        switch(opcja){
            case 0:
                zwolnienieListy(head);
                break;
            case 1:
                dodaj(&head);
                break;
            case 2:
                wypisz(head);
                break;
            case 3:
                wyszukiwanie(head);
                break;
            case 4:
                modyfikacja(head);
                break;
            case 5:
                usuwanie(&head);
                break;
            case 6:
                zapis(head);
                break;
            case 7:
                wczytywanie(&head);
                break;
            default:
                printf("!! wprowadz poprawny numer !! \n");
        }
    }
    return 0;
}