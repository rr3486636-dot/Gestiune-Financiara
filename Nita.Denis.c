#include <stdio.h>

#define ZILE 30
#define LUNGIME 100

/* Variabile globale: retin datele financiare pentru fiecare zi a lunii. */
float venituri[ZILE] = {0};
int alimente[ZILE] = {0};
float casa[ZILE] = {0};
float relaxare[ZILE] = {0};
char detaliiRelaxare[ZILE][LUNGIME] = {{0}};
int optiune, zi, categorie, sumaAlimente;
float suma;

/* Modulul de citire: permite adaugarea veniturilor si cheltuielilor pentru o zi aleasa. */
void citireDate(void) {
    printf("\nIntroduceti ziua (1-30): ");
    scanf("%d", &zi);

    if (zi < 1 || zi > ZILE) {
        printf("Zi invalida! Alegeti o zi intre 1 si 30.\n");
    } else {
        printf("\nCe doriti sa inregistrati?\n");
        printf("1. Venit\n");
        printf("2. Cheltuiala\n");
        printf("Alegeti: ");
        scanf("%d", &categorie);

        if (categorie == 1) {
            printf("Introduceti suma venitului: ");
            scanf("%f", &suma);
            if (suma >= 0) {
                venituri[zi - 1] += suma;
                printf("Venitul a fost inregistrat.\n");
            } else {
                printf("Suma nu poate fi negativa.\n");
            }
        } else if (categorie == 2) {
            printf("Tip cheltuiala:\n");
            printf("1. Alimente (A)\n");
            printf("2. Casa (C)\n");
            printf("3. Relaxare (R)\n");
            printf("Alegeti: ");
            scanf("%d", &categorie);

            switch (categorie) {
                case 1:
                    printf("Introduceti suma pentru alimente (numar intreg): ");
                    scanf("%d", &sumaAlimente);
                    if (sumaAlimente >= 0) {
                        alimente[zi - 1] += sumaAlimente;
                        printf("Cheltuiala pentru alimente a fost inregistrata.\n");
                    } else {
                        printf("Suma nu poate fi negativa.\n");
                    }
                    break;
                case 2:
                    printf("Introduceti suma pentru casa: ");
                    scanf("%f", &suma);
                    if (suma >= 0) {
                        casa[zi - 1] += suma;
                        printf("Cheltuiala pentru casa a fost inregistrata.\n");
                    } else {
                        printf("Suma nu poate fi negativa.\n");
                    }
                    break;
                case 3:
                    printf("Introduceti suma pentru relaxare: ");
                    scanf("%f", &suma);
                    if (suma >= 0) {
                        relaxare[zi - 1] += suma;
                        printf("Unde/ cum v-ati relaxat? ");
                        scanf(" %99[^\n]", detaliiRelaxare[zi - 1]);
                        printf("Cheltuiala pentru relaxare a fost inregistrata.\n");
                    } else {
                        printf("Suma nu poate fi negativa.\n");
                    }
                    break;
                default:
                    printf("Categorie invalida!\n");
            }
        } else {
            printf("Optiune invalida!\n");
        }
    }
}

/* Modulul de calcul si afisare: calculeaza veniturile, cheltuielile si soldul lunii. */
void afisareTotaluri(void) {
    float venitTotal = 0, cheltuieliTotal = 0, sold;
    int i;

    for (i = 0; i < ZILE; i++) {
        venitTotal += venituri[i];
        cheltuieliTotal += alimente[i] + casa[i] + relaxare[i];
    }

    sold = venitTotal - cheltuieliTotal;

    printf("\n--- Situatia financiara lunara ---\n");
    printf("Venit total: %.2f lei\n", venitTotal);
    printf("Cheltuieli totale: %.2f lei\n", cheltuieliTotal);
    printf("Sold final: %.2f lei\n", sold);

    if (sold >= 0) {
        printf("Situatie: sold pozitiv sau egal cu zero.\n");
    } else {
        printf("Situatie: cheltuielile depasesc veniturile.\n");
    }
}

/* Modulul de statistici: afiseaza cheltuielile cumulate pentru categoria aleasa. */
void statisticiCheltuieli(void) {
    int i;
    int totalAlimente = 0;
    float totalCasa = 0, totalRelaxare = 0;

    for (i = 0; i < ZILE; i++) {
        totalAlimente += alimente[i];
        totalCasa += casa[i];
        totalRelaxare += relaxare[i];
    }

    printf("\n--- Statistici pe categorii ---\n");
    printf("1. Alimente (A)\n");
    printf("2. Casa (C)\n");
    printf("3. Relaxare (R)\n");
    printf("Alegeti categoria: ");
    scanf("%d", &categorie);

    switch (categorie) {
        case 1:
            printf("Total cheltuit pe alimente: %d lei\n", totalAlimente);
            break;
        case 2:
            printf("Total cheltuit pentru casa: %.2f lei\n", totalCasa);
            break;
        case 3:
            printf("Total cheltuit pentru relaxare: %.2f lei\n", totalRelaxare);
            for (i = 0; i < ZILE; i++) {
                if (detaliiRelaxare[i][0] != '\0') {
                    printf("Ziua %d: %s\n", i + 1, detaliiRelaxare[i]);
                }
            }
            break;
        default:
            printf("Categorie invalida!\n");
    }
}

/* Modulul principal: afiseaza meniul si repeta executia pana la alegerea iesirii. */
int main(void) {
    do {
        printf("\n====== GESTIUNEA VENITURILOR SI CHELTUIELILOR ======\n");
        printf("1. Introducere date financiare\n");
        printf("2. Afisare venituri, cheltuieli si sold\n");
        printf("3. Statistici pe categorii\n");
        printf("0. Iesire\n");
        printf("Alegeti optiunea: ");
        scanf("%d", &optiune);

        switch (optiune) {
            case 1:
                citireDate();
                break;
            case 2:
                afisareTotaluri();
                break;
            case 3:
                statisticiCheltuieli();
                break;
            case 0:
                printf("Programul s-a incheiat. La revedere!\n");
                break;
            default:
                printf("Optiune invalida! Incercati din nou.\n");
        }
    } while (optiune != 0);

    return 0;
}
