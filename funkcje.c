#include "funkcje.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void wczytywanieT(char *bufor, int rozmiar){
    if (fgets(bufor,rozmiar,stdin)!=NULL){
        size_t len=strlen(bufor);
        if (len>0 && bufor[len-1]=='\n'){
            bufor[len-1]='\0';
        }
    }
}
void dodaj(dinozaury **head){
    dinozaury *nowy=(dinozaury*)malloc(sizeof(dinozaury));
    if (nowy==NULL){
        printf("brak pamieci\n");
        return;
    }

    printf("\n ======DODAWANIE DINOZAURA====== \n");
    printf("gatunek: ");
    wczytywanieT(nowy->gatunek, 20);
    printf("dieta: ");
    wczytywanieT(nowy->dieta, 20);
    printf("masa(kg): ");
    scanf("%f",&nowy->masa);
    while (getchar()!='\n');
    printf("zagroda: ");
    wczytywanieT(nowy->zagroda, 20);
    printf("temperament: ");
    wczytywanieT(nowy->temperament, 20);
    printf("status bezpieczenstwa: ");
    wczytywanieT(nowy->status, 20);

    nowy->next=*head;
    *head=nowy;
    printf("\npomyslnie dodano wszystkie parametry\n");
    
}

void wypisz(dinozaury *head){
    dinozaury *a=head;
    int nr=1;
    if (head==NULL){
        printf("\n lista jest pusta \n");
        return;
    }
    while (a!=NULL){
        printf("\n ====== %s ====== \n", a->gatunek);
        printf("dieta: %s \n", a->dieta);
        printf("masa: %f \n", a->masa);
        printf("zagroda: %s \n", a->zagroda);
        printf("temperament: %s \n", a->temperament);
        printf("status bezpieczenstwa: %s \n", a->status);
        a=a->next;
    }
    printf("\npomyslnie wypisano wszystkie parametry\n");
}
void zwolnienieListy(dinozaury *head){
    dinozaury *t;
    while (head!=NULL){
        t=head;
        head=head->next;
        free(t);
    }
}