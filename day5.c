#include "types.h"
#include <math.h>
typedef struct {
    int maxLast;
    int maxPalette;
    int geladen;
    int geladenPalette;
} lkw;

void ladungVerteilen(int[][3], lkw[], int, int);

void day5kreis() {
    double radius;
    printf("\nKreisradius eingeben: ");
    scanf("%lf", &radius);
    double day5kreisFlaeche(double radius) {
        return (pow(radius, 2) * M_PI);
    }
    double day5kreisUmfang(double radius) {
        return (2 * radius * M_PI);
    }

    printf("\nKreisflaeche: %.2lf\nKreisumfang: %.2lf\n", day5kreisFlaeche(radius), day5kreisUmfang(radius));
}


void day5ladungsliste() {
    int ladungsliste[12][3] = {
        {800,0,12340},{700,0,12341},{900,0,12342},
        {700,0,12343},{1000,0,12344},{1100,0,12345},
        {600,0,12346},{888,0,12347},{1200,0,12348},
        {500,0,12349},{400,0,12350},{1400,0,12351}
    };
    int laenge = sizeof(ladungsliste) / sizeof(ladungsliste[0]);

    lkw lkws[10] = {0};
    int laengeLkw = sizeof(lkws) / sizeof(lkws[0]);
    printf("LaengeLKW: %d", laengeLkw);
    ladungVerteilen(ladungsliste, lkws, laenge, laengeLkw);
}


int lkwAbfragen(lkw lkws[], int aktuellerLkw) {
    // nächster LKW mit Abfrage zu Traglast
    aktuellerLkw++;
    printf("\n\nBitte geben Sie die maximale Traglast von LKW (ID %d) in kg und Paletten an: ", aktuellerLkw+1);
    scanf("%d %d", &lkws[aktuellerLkw].maxLast, &lkws[aktuellerLkw].maxPalette);
    printf("\nGespeichert: %d kg %d Paletten\n-------------\n", lkws[aktuellerLkw].maxLast, lkws[aktuellerLkw].maxPalette);
    // Gibt den neuen LKW zurück
    return aktuellerLkw;
}


void ladungVerteilen(int ladungsliste[][3], lkw lkws[], int laenge, int laengeLkw) {
    // Initialisierung mit neuem lkw
    int aktuellerLkw = lkwAbfragen(lkws, -1);
    for (int i = 0; i < laenge; i++) {
        // Prüfung, ob noch ein LKW übrig ist
        if (aktuellerLkw < laengeLkw) {
            // wenn der lkw voll ist, wird nach neuem lkw gefragt
            if (lkws[aktuellerLkw].geladen + ladungsliste[i][0] > lkws[aktuellerLkw].maxLast
                || lkws[aktuellerLkw].geladenPalette + 1 > lkws[aktuellerLkw].maxPalette) {
                printf("\n\n-------------\nDer LKW (ID %d) ist voll.\nGeladen: %d Paletten mit insg. %d kg", aktuellerLkw+1, lkws[aktuellerLkw].geladenPalette, lkws[aktuellerLkw].geladen);
                aktuellerLkw = lkwAbfragen(lkws, aktuellerLkw);
            }
            // packt den LKW in die Ladungsliste und die Ladung in den LKW
            ladungsliste[i][1] = aktuellerLkw+1;
            lkws[aktuellerLkw].geladen += ladungsliste[i][0];
            lkws[aktuellerLkw].geladenPalette ++;
            // Gibt den Teil der aktuellen Ladungsliste aus
            printf("\n\nPalette: %d\nGewicht: %d, LKW: %d, Palette: %d", i+1, ladungsliste[i][0], ladungsliste[i][1], ladungsliste[i][2]);
        } else {
            printf("\n-------------\nKeine LKWs mehr vorhanden.\n-------------\n");
            break;
        }
    }
}


void day5() {
    daily day[] = {
        "Exit Program", switchDay,
        "Kreisaufgabe (04_04_21)", day5kreis,
        "LKW Ladungsliste (04_04_T2)", day5ladungsliste,
    };
    int laenge = sizeof(day)/ sizeof(day[0]);

    caseProgram(day, laenge, day5);
}
