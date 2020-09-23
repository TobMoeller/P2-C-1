#include "types.h"

double day12berechneZinsen(double, double);
double day12berechneAufpreis(char [], int);

void day12NSD() {
    double geldbetrag, zinssatz;
    int anzahlJahre;
    printf("\nBitte Geldbetrag eingeben: ");
    scanf("%lf", &geldbetrag);
    printf("\nBitte Zinssatz eingeben: ");
    scanf("%lf", &zinssatz);
    printf("\nBitte Anzahl Jahre eingeben: ");
    scanf("%d", &anzahlJahre);

    int i = 1;
    while (i <= anzahlJahre) {
        double zinsen = day12berechneZinsen(geldbetrag, zinssatz);
        geldbetrag = geldbetrag + zinsen;
        i = i + 1;
    }
    printf("\nGeldbetrag nach %d Jahren: %.2lf", anzahlJahre, geldbetrag);
}

double day12berechneZinsen(double betrag, double zins) {
    double zinsen = betrag * zins / 100;
    return zinsen;
}



void day12PAP() {
    double artikelpreis, aufpreis;
    int anzahl;
    char verpackung[50];
    printf("\nBitte Artikelpreis eingeben: ");
    scanf("%lf", &artikelpreis);
    printf("\nBitte Anzahl Artikel eingeben: ");
    scanf("%d", &anzahl);
    fflush(stdin);
    printf("\nBitte Verpackung(sart) eingeben: ");
    scanf("%s", verpackung);

    aufpreis = day12berechneAufpreis(verpackung, anzahl);
    double endpreis = artikelpreis * anzahl + aufpreis;
    printf("\nGesamt Artikelpreis: %.2lf", endpreis);
}

double day12berechneAufpreis(char verpackung[], int anzahl) {
    double preis;
    if (anzahl < 30 && strcmp(strlwr(verpackung), "speziell") == 0) {
        preis = 3;
    } else {
        preis = 0;
    }
    return preis;
}



void day12() {
    daily day[] = {
        "Exit Program", switchDay,
        "Aufgabe nach NSD Diagramm", day12NSD,
        "Aufgabe nach PAP Diagramm", day12PAP,
    };
    int laenge = sizeof(day)/ sizeof(day[0]);

    caseProgram(day, laenge, day12);

}
