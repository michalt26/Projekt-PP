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
        printf("masa: %.1f \n", a->masa);
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

void wyszukiwanie(dinozaury *head){
    char sz[20];
    dinozaury *a=head;
    int z=0;
    printf("\npodaj gatunek dinozaura do znalezienia: ");
    wczytywanieT(sz, 20);
    while(a!=NULL){
        if (strcmp(a->gatunek,sz)==0){
            printf("\nznalezione dinozaury: \n");
            printf("dieta: %s \n", a->dieta);
            printf("masa: %.1f kg\n", a->masa);
            printf("zagroda: %s \n", a->zagroda);
            printf("temperament: %s \n", a->temperament);
            printf("status bezpieczenstwa: %s \n", a->status);
            z=1;
        }
    a=a->next;
    }
    if (z==0){
        printf("nie ma dinozaura o takiej nazwie");
    }
}

void modyfikacja(dinozaury *head){
        char sz[20];
        dinozaury *a=head;
        int z;
        if (head=NULL){
            printf("\nbrak danych\n");
            return;
        }
        printf("\npodaj gatunek do modyfikacji: \n");
        wczytywanieT(sz, 20);
        int opcja=-1;
        while (a!=NULL){
            if (strcmp(a->gatunek,sz)==0){
                z=1;
                while(opcja!=0){
                    printf("\nmodyfikowany:  %s\n", a->gatunek);
                    printf("wybierz parametry do zmiany: \n");
                    printf("0 - zamknij\n");
                    printf("1 - aktualizacja wagi\n");
                    printf("2 - zmiana zagrody\n");
                    printf("3 - aktualizacja statusu bezpieczenstwa\n");
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
                            printf("zamykanie...\n");
                            break;
                        case 1:
                            printf("nowa masa: \n");
                            scanf("%f", &a->masa);
                            while(getchar()!='\n');
                            printf("pomyslnie zaktualizowano mase\n");
                            break;
                        case 2:
                            printf("nowa zagroda: ");
                            wczytywanieT(a->zagroda,20);
                            printf("pomyslnie zmieniono zagrode\n");
                            break;
                        case 3:
                            printf("nowy status bezpieczenstwa:\n ");
                            wczytywanieT(a->status,20);
                            printf("pomyslnie zaktualizowano status bezpieczenstwa\n");
                            break;
                        default:
                            printf("!! wprowadz poprawny numer !! \n");
                        }
                }
                return;
        }
        a=a->next;
        if (z==0){
            printf("nie ma dinozaura o podanym gatunku\n");
        }
    }
}

void usuwanie(dinozaury **head){
    char sz[20];
    dinozaury *a=*head;
    dinozaury *p=NULL; //poprzedni element
    printf("\npodaj gatunek do usuniecia: ");
    wczytywanieT(sz,20);
    while (a!=NULL){
        if (strcmp(a->gatunek, sz)==0){
            if ((strcmp(a->status, "zagrozenie")==0) || (strcmp(a->status, "ucieczka")==0)){
                printf("nie mozna usunac dinozaura, status to: %s\n",a->status);
                return;
            }
        if (p==NULL){
            *head=a->next;
        }
        else{
            p->next=a->next;
        }
        free(a);
        printf("\npomyslnie usunieto dinozaura: %s\n",sz);
        return;
    }
    p=a;
    a=a->next;
    }
    printf("nie ma dinozaura o podanym gatunku\n");
}

void zapis (dinozaury *head){
    dinozaury *a=head;
    FILE *plik;
    char nazwa[100];
    printf("\npodaj nazwe pliku\n");
    scanf("%s",nazwa);
    plik=fopen(nazwa, "w");
    if (plik==NULL){
        printf("\n !! nie mozna zapisac pliku !! \n");
        return;
    }
    while(a!=NULL){
        printf("zapisywanie %s...\n", a->gatunek);
        fprintf(plik, "%s\n", a->gatunek);
        fprintf(plik, "%s\n", a->dieta);
        fprintf(plik, "%.1f\n", a->masa);
        fprintf(plik, "%s\n", a->zagroda);
        fprintf(plik, "%s\n", a->temperament);
        fprintf(plik, "%s\n", a->status);
        a=a->next;
    }
    fclose(plik);
    printf("\nzapisano baze do pliku %s\n", nazwa);
}

void wczytywanie(dinozaury **head){
    FILE *plik;
    char bufor[50];
    char nazwa[100];
    zwolnienieListy(*head); // zeby sie nie wczytalo 2 razy to samo
    *head=NULL;
    printf("\npodaj nazwe pliku\n");
    scanf("%s",nazwa);
    plik=fopen(nazwa, "r");
    if (plik==NULL){
        printf("\n !! nie ma pliku o podanej nazwie %s !! \n", nazwa);
        return;
    }
    while (fscanf(plik,"%s",bufor)!=EOF){
        dinozaury *nowy=(dinozaury*)malloc(sizeof(dinozaury));
        strcpy(nowy->gatunek,bufor);
        fscanf(plik, "%s", nowy->dieta);
        fscanf(plik, "%f", &nowy->masa);
        fscanf(plik, "%s", nowy->zagroda);
        fscanf(plik, "%s", nowy->temperament);
        fscanf(plik, "%s", nowy->status);
        nowy->next=*head;
        *head=nowy;  //dodanie na poczatek
    }
    fclose(plik);
    printf("\nwczytano baze z pliku %s\n",nazwa);
}