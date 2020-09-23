#include "types.h"
#include <time.h>

#define maxarray 50

void day13arrayAusgabe(int [][maxarray], int, int);
void day13minMax(int [][maxarray], int, int, int *, int *);
void day13anzahlExtrem(int [][maxarray], int, int, int *, int *);
void day13durchschnitt(int [][maxarray], int, int);


void day13test() {
    char test[] = "t eSs3 +STi";

    printf("%s", strlwr(test));
}



void day13arrayAufgabe() {
    int laenge1 = 10, laenge2 = 50;
    int messwerte[laenge1][laenge2];
    srand(time(NULL));

    // Besetzen des Arrays
    for (int i = 0; i < laenge1; i++) {
        for (int j = 0; j < laenge2; j++) {
            messwerte[i][j] = rand() % 10;
        }
    }

    // Array Ausgabe
    day13arrayAusgabe(messwerte, laenge1, laenge2);

    // Finden und Ausgabe des Min und Max Werts
    int min = messwerte[0][0], max = messwerte[0][0];
    day13minMax(messwerte, laenge1, laenge2, &min, &max);

    // Finden Anzahl und Indizes der Extremwerte
    day13anzahlExtrem(messwerte, laenge1, laenge2, &min, &max);

    // Finden und Ausgabe der Reihen- und Gesamtdurchschnitte
    day13durchschnitt(messwerte, laenge1, laenge2);
}

void day13arrayAusgabe(int array[][maxarray], int laenge1, int laenge2) {
    for (int i = 0; i < laenge1; i++) {
        printf("\n");
        for (int j = 0; j < laenge2; j++) {
            printf("%d ", array[i][j]);
        }
    }
}

void day13minMax(int messwerte[][maxarray], int laenge1, int laenge2, int *min, int *max) {
    for (int i = 0; i < laenge1; i++) {
        for (int j = 1; j < laenge2; j++) {
            if (messwerte[i][j] > *max) *max = messwerte[i][j];
            else if (messwerte[i][j] < *min) *min = messwerte[i][j];
        }
    }
    printf("\n\nMax: %d, Min: %d\n", *max, *min);
}

void day13anzahlExtrem(int messwerte[][maxarray], int laenge1, int laenge2, int *min, int *max) {
    int anzahlMax = 0, anzahlMin = 0;
    int indexMax[100][2];
    int indexMin[100][2];

    for (int i = 0; i < laenge1; i++) {
        for (int j = 0; j < laenge2; j++) {
            if (messwerte[i][j] == *max) {
                indexMax[anzahlMax][0] = i;
                indexMax[anzahlMax][1] = j;
                anzahlMax++;
            } else if (messwerte[i][j] == *min) {
                indexMin[anzahlMin][0] = i;
                indexMin[anzahlMin][1] = j;
                anzahlMin++;
            }
        }
    }


    // Ausgabe der Extremwerte mit zugehörigen Indexen
    printf("\nMaximaler Wert %d kommt %d mal vor an den Indexen:\n", *max, anzahlMax);
    for (int i = 0; i < anzahlMax; i++) {
        printf("[%d][%d], \n", indexMax[i][0], indexMax[i][1]);
    }

    printf("\n\nMinimaler Wert %d kommt %d mal vor an den Indexen:\n", *min, anzahlMax);
    for (int i = 0; i < anzahlMin; i++) {
        printf("[%d][%d], \n", indexMin[i][0], indexMin[i][1]);
    }
}

void day13durchschnitt(int messwerte[][maxarray], int laenge1, int laenge2) {
    int sum = 0;
    for (int i = 0; i < laenge1; i++) {
        int sumCurrent = 0;
        for (int j = 0; j < laenge2; j++) {
            sumCurrent += messwerte[i][j];
        }
        sum += sumCurrent;
        printf("\nDurchschnitt über Reihe %d: %.2lf", i, (double) sumCurrent / (double) laenge2);
    }
    printf("\n\nDurchschnitt über alle: %.2lf", sum / (double)(laenge1 * laenge2));
}



void day13lkw() {
    /*
        Erstellen Sie ein Programm, um einen LKW zu verwalten.
        Der LKW hat eine maximale Ladekapazität in Kg, einen Fahrzeughalter und eine Leistung in Kilowatt.

        Der Benutzer soll die Möglichkeit haben, den LKW bis zur maximalen Ladekapazität zu beladen,
        den LKW zu verkaufen und damit einen neuen Halter einzutragen und den LKW  zu tunen bzw. zu drosseln.

        Pseudo:
            program lkw {
                struct lkw {
                    geladen
                    maxKapazität
                    halter
                    leistung
                }
                lkw LKW = {lkwdaten}

                do {
                    Eingabe(Nutzerwunsch)
                    switch(Nutzerwunsch)
                    case 1:
                        LKW = beladen(LKW)
                    case 2:
                        LKW = verkaufen(LKW)
                    case 3:
                        LKW = tunen(LKW)
                    case 4:
                        Nutzerwunsch = "aufhören"
                } while (Nutzerwunsch != "aufhören")
            }

            beladen(LKW) {
                Eingabe(ladung)
                if (LKW.geladen + ladung <= LKW.kapazität) {
                    LKW.geladen += ladung
                } else {
                    Ausgabe("Die Ladung ist zu groß")
                }
                Rückgabe(LKW)
            }

            verkaufen(LKW) {
                Eingabe(neuerHalter)
                LKW.halter = neuerHalter
                Rückgabe(LKW)
            }

            tunen(LKW) {
                Eingabe(leistungsänderung)
                if (LKW.leistung + leistungsänderung > 0) {
                    LKW.leistung += leistungsänderung
                } else {
                    Ausgabe("Die Drosselung ist zu stark")
                }
                Rückgabe(LKW)
            }
    */
    typedef struct {
        char vorname[30];
        char nachname[30];
    } lkwHalter;

    typedef struct {
        int geladen;
        int maxKapazitaet;
        lkwHalter halter;
        int leistung;
    } lkw;

     lkw beladen(lkw LKW) {
        int ladung;
        printf("\nLadung eingeben:");
        scanf("%d", &ladung);
        if (LKW.geladen + ladung <= LKW.maxKapazitaet) LKW.geladen += ladung;
        else printf("Ladung ist zu groß");
        return LKW;
     }

     lkw verkaufen(lkw LKW) {
        char vorname[30];
        char nachname[30];
        printf("\n Vorname neuer Halter:");
        scanf("%s", vorname);
        printf("\n Nachname neuer Halter:");
        scanf("%s", nachname);
        strcpy(LKW.halter.vorname, vorname);
        strcpy(LKW.halter.nachname, nachname);
        printf("\nNeuer Halter: %s, %s", LKW.halter.nachname, LKW.halter.vorname);
        return LKW;
     }

     lkw tunen(lkw LKW) {
        int leistungsAenderung;
        printf("\nLeistungstuning / -drosselung eingeben:");
        scanf("%d", &leistungsAenderung);
        if (LKW.leistung + leistungsAenderung >= 0) LKW.leistung += leistungsAenderung;
        else printf("\nDie Drosselung ist zu stark.");
        return LKW;
     }


    lkw LKW = {0, 15000, {"Max", "Mustermann"}, 250};
//    printf("\nNeuer Halter: %s, %s", LKW.halter.nachname, LKW.halter.vorname);
    int aufhoeren = 0;
    do {
        int nutzerwunsch;
        printf("\nWas möchten Sie tun?");
        scanf("%d", &nutzerwunsch);

        switch(nutzerwunsch) {
        case 1:
            LKW = beladen(LKW);
            break;
        case 2:
            LKW = verkaufen(LKW);
            break;
        case 3:
            LKW = tunen(LKW);
            break;
        default:
            aufhoeren = 1;
        }


    } while (!aufhoeren);
}


void day13() {
    daily day[] = {
        "Exit Program", switchDay,
        "Tag 13 Testprogramm", day13test,
        "Tag 13 Arrayaufgabe", day13arrayAufgabe,
        "Tag 13 LKW", day13lkw,
    };
    int laenge = sizeof(day)/ sizeof(day[0]);

    caseProgram(day, laenge, day13);

}
