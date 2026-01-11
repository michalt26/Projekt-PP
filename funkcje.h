#ifndef FUNKCJE_H
#define FUNKCJE_H

typedef struct dinozaury{
    char gatunek[20];
    char dieta[20];
    float masa;
    char zagroda[20];
    char temperament[20];
    char status[20];
    struct dinozaury *next;
}dinozaury;
void dodaj(dinozaury **head);
void wypisz(dinozaury *head);
void zwolnienieListy(dinozaury *head);
void wyszukiwanie(dinozaury *head);
void modyfikacja(dinozaury *head);
void usuwanie(dinozaury **head);
void zapis(dinozaury *head);
void wczytywanie(dinozaury **head);
#endif