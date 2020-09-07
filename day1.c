#include <stdio.h>

void day1() {
    int caseProgram;
    printf("\n\nWas moechtest du starten? \n"
           "Option (1): Hallo Welt\n"
           "Option (2): Kontoaufgabe\n"
           "Option (0): Exit Program\n\t");
    scanf("%d", &caseProgram);

    switch (caseProgram){
        case 1: day1Transcript(); day1(); break;
        case 2: day1Konto(); day1(); break;
        case 0: printf("\n--- exiting ---"); break;
        default: printf("\nBitte ein Case angeben\n"); scanf("%*c"); day1(); break;
    }
}

void day1Transcript() {
    // learning about structures
    struct buch{
        char titel[100];
        int auflage;
        char isbn[100];
        float preis;
        char verlag[100];
    };
    struct buch buch1 = {
        "Grundlagen der funktionalen Programmierung",
        1994,
        "978-3-519-02137-7",
        49.95,
        "Teubner"
    };
    printf("Buch1: \n%s\n%d\n%s\%f\n%s", buch1.titel, buch1.auflage, buch1.isbn, buch1.preis, buch1.verlag);
}

void day1Konto() {
    /*
        Die Familie Meiser hat 2 Bankkonten, die in einem Programm verwaltet werden
        sollen. Für jedes Konto soll die Kontonummer, der Kontostand und das
        Dispolimit angegeben werden. Das Kont1 hat die Kontonummer 12345, einen
        Kontostand von 1450,34€ und ein Dispo von 4500,00 €.. Konto2 hat die
        Kontonummer 54321, einen Kontostand von -125,09 € und ein Dispo von
        350,00 €.
        Definieren Sie eine C-Datenstruktur, um die Daten zu verwalten.
        Das Programm soll
        – vom Konto1 300,00€ abheben. Geben Sie anschließend auf der Konsole den
        neuen Kontostand aus.
        – auf das Konto2 300,00€ einzahlen. Geben Sie anschließend den neuen
        Kontostand an.
    */

    typedef struct {
        char vorname[50];
        char nachname[50];
    } person;

    typedef struct {
        int nummer;
        person inhaber;
        double stand;
        double dispo;
    } konto;

    konto kt1 = {12345, {"Günni", "Günther"}, 1450.34, 4500};
    konto kt2 = {54321, {"Ganno", "Gauner"}, -125.09, 350};

    // Abbuchung
    double wert;
    printf("Wert eingeben: ");
    fflush(stdin);
    scanf("%lf", &wert);
    printf("\nwert: %f\n", wert);

    printf("Konto1: %.2f\n", kt1.stand);
    if (kt1.stand + kt1.dispo - wert >= 0) kt1.stand -= wert;
    else printf("Dispo ist zu klein!\n");
    printf("Konto1: %.2f\n", kt1.stand);

    // Zubuchung
    printf("Konto2: %.2f\n", kt2.stand);
    kt2.stand += wert;
    printf("Konto2: %.2f\n", kt2.stand);

    // Inhaber ausgeben
    printf("Inhaber von Konto %d: %s %s\n", kt1.nummer, kt1.inhaber.vorname, kt1.inhaber.nachname);
    printf("Inhaber von Konto %d: %s %s\n", kt2.nummer, kt2.inhaber.vorname, kt2.inhaber.nachname);
}
