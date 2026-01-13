/**
 * Napisati program koji kreira i ispisuje listu od N celih brojeva.
 * Dodati funkcije za brisanje elementa iz liste, kao i umetanje u listu.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
    int podatak;
    struct element *sledeci;
} Element;

void greska(const char *poruka)
{
    printf("%s", poruka);
    exit(EXIT_FAILURE);
}

/* funkcija za odredjivanje duzine liste */
int duzina(Element *p)
{
    int broj = 0;
    while (p != NULL)
    {
        broj++;
        p = p->sledeci;
    }
    return broj;
}

/* funkcija za dodavanje novog elementa na kraj liste */
Element *dodaj(Element *p, int n)
{
    /* dodavanje elementa ako je lista prazna */
    if (p == NULL)
    {
        /* kreiranje novog elementa i promena glave liste */
        p = (Element *)malloc(sizeof(Element));
        if (p == NULL)
            greska("Greska pri alokaciji memorije.");

        p->podatak = n;
        p->sledeci = NULL;
    }
    /* dodavanje novog elementa u listu koja nije prazna */
    else
    {
        /* moramo da odemo do kraja liste, da bi na kraj nakacili novi element */
        Element *pom = p;
        while (pom->sledeci != NULL)
            pom = pom->sledeci;

        /* kreiramo novi element */
        pom->sledeci = (Element *)malloc(sizeof(Element));
        if (pom->sledeci == NULL)
            greska("Greska pri alokaciji memorije.");

        pom = pom->sledeci;
        pom->podatak = n;
        pom->sledeci = NULL;
    }

    /* ako je lista bila prazna, promenila se glava liste */
    return p;
}

/* funkcija za brisanje zadatog elementa iz liste */
Element *obrisi(Element *p, int vrednost)
{
    Element *prethodni, *trenutni;

    if (p == NULL)
        printf("Lista je prazna.\n");
    else
    {
        prethodni = NULL;
        trenutni = p;

        /* trazimo element za brisanje, a pamtimo prethodni cvor */
        while (trenutni != NULL && trenutni->podatak != vrednost)
        {
            prethodni = trenutni;
            trenutni = trenutni->sledeci;
        }

        if (trenutni == NULL)
        {
            printf("Element nije pronadjen.\n");
            return p;
        }
        else
        {
            /* nasli smo element, prespajamo pokazivace i oslobadjamo memoriju */
            prethodni->sledeci = trenutni->sledeci;
            free(trenutni);
        }
    }

    return p;
}

/* funkcija za umetanje novog elementa na zadatu poziciju u listu */
Element *umetni(Element *p, int redni_broj, int vrednost)
{
    Element *novi, *pomocni;

    if (redni_broj < 0 || redni_broj > duzina(p))
    {
        printf("Greska! Zadati element ne postoji.\n");
        return p;
    }

    novi = (Element *)malloc(sizeof(Element));
    if (novi == NULL)
        greska("Greska pri alokaciji memorije.");

    novi->podatak = vrednost;

    /* dodavanje na sam pocetak liste - menja se glava liste */
    if (redni_broj == 0)
    {
        novi->sledeci = p;
        p = novi;
    }
    else
    {
        pomocni = p;
        int i = 1;
        while (i < redni_broj)
        {
            i++;
            pomocni = pomocni->sledeci;
        }

        novi->sledeci = pomocni->sledeci;
        pomocni->sledeci = novi;
    }

    return p;
}

void stampaj_listu(Element *p)
{
    Element *pom = p;
    if (pom != NULL)
    {
        do
        {
            printf("%d\t", pom->podatak);
            pom = pom->sledeci;
        } while (pom != NULL);
        printf("\n");
    }
    else
        printf("Lista je prazna.\n");
}

int main()
{
    Element *glava = NULL;
    int n, x;

    printf("Unesi broj elemenata u listi: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Unesi %d. element: ", i + 1);
        scanf("%d", &x);
        glava = dodaj(glava, x);
    }

    printf("Kreirana lista je:\n");
    stampaj_listu(glava);

    printf("Dodavanje na prvo mesto u listi ...\n");
    glava = umetni(glava, 0, 10);
    stampaj_listu(glava);

    printf("Dodavanje na cetvrto mesto u listi ...\n");
    glava = umetni(glava, 3, 400);
    stampaj_listu(glava);

    return 0;
}