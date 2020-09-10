#include <stdio.h>
#include "types.h"

//void day1() {
//    char descriptions[][50] = {
//        "Mitschrift",
//        "Kontoaufgabe",
//        "Messung",
//        "Messung (eigene Lsg)"
//    };
//    int laenge = sizeof(descriptions)/ sizeof(descriptions[0]);
//
//    switch (caseProgram(descriptions, laenge)){
//        case 1: day1Transcript(); day1(); break;
//        case 2: day1Konto(); day1(); break;
//        case 3: day1Messung1(); day1(); break;
//        case 4: day1Messung2(); day1(); break;
//        case 0: printf("\n--- exiting ---"); switchDay(); break;
//        default: printf("\nBitte ein Case angeben\n"); scanf("%*c"); day1(); break;
//    }


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

void day1Messung1() {
    // Lösung von/mit Mirek
    typedef struct {
        int stunde;
        int minute;
        int sekunde;
    } Uhrzeit;

    typedef struct {
        Uhrzeit zeit;
        char messungName[20];
        double messwert;
    } Messdaten;



    int stunde = 7;
    int minute = 48;
    int sekunde = 12;
    char messungName [] = "Messung #001";
    double messwert = 420.42;

    printf("%s", messungName);

    Uhrzeit zeitpunkt = {
    zeitpunkt.stunde = stunde,
    zeitpunkt.minute = minute,
    zeitpunkt.sekunde = sekunde
    };

    Messdaten messung1 = {
        messung1.zeit = zeitpunkt,
        strcpy(messung1.messungName, messungName),
        messung1.messwert = messwert
    };

    printf("Die %s hatte denn Wert %.2f um %d:%d:%d", messung1.messungName, messung1.messwert, messung1.zeit.stunde, messung1.zeit.minute, messung1.zeit.sekunde);

}

void day1Messung2() {
    /*
        Sie sollen eine Datenstruktur zur Speicherung von technischen Messdaten
        entwickeln.
        Der Ingenieur, der die Messungen durchführt, möchte folgende Daten
        ablegen: die Uhrzeit in Stunden, Minuten und Sekunden (wenn möglich
        einzeln, da dann die Auswertung einfacher ist), um welche Messung es sich
        gehandelt hat, z.B. Spannung, Druck, Temperatur oder andere. Er kann ihnen
        aber keine vollständige Auflistung nennen, da immer andere Messungen
        gewünscht werden und den gemessenen Wert, der immer eine Ganzzahl
        oder eine Gleitkommazahl ist.
        Speichern Sie eine Messung, in dem sie die Daten von der Konsole einlesen.
    */

    typedef struct {
        int stunden;
        int minuten;
        int sekunden;
    } zeit;

    typedef struct {
        zeit messZeit;
        char messGroesse[20];
        double messErgebnis;
    } messdaten;

    int MAX = 10;
    messdaten daten[MAX];
    int counter = 0;
    int breakout = 1;

    do {
        printf("\nGeben Sie den Zeitpunkt der Messung ein:");
        printf("\nStunden - ");
        fflush(stdin);
        scanf("%d", &daten[counter].messZeit.stunden);
        printf("Minuten - ");
        fflush(stdin);
        scanf("%d", &daten[counter].messZeit.minuten);
        printf("Sekunden - ");
        fflush(stdin);
        scanf("%d", &daten[counter].messZeit.sekunden);

        printf("\nUm welche Messgröße geht es?\n");
        fflush(stdin);
        scanf("%s", daten[counter].messGroesse);

        printf("\nWelches Ergebnis hat die Messung?\n");
        fflush(stdin);
        scanf("%lf", &daten[counter].messErgebnis);

        counter++;
        if (counter < MAX) {
            printf("\nFortfahren? (1 - ja / 0 - nein) \n");
            fflush(stdin);
            scanf("%d", &breakout);
        }
        else breakout = 0;

    } while (breakout != 0);

    for (int i = 0; i < counter; i++) {
        printf("\n\nMessung(%d)", i+1);
        printf("\nZeitpunkt der Messung: %d:%d:%d.", daten[i].messZeit.stunden, daten[i].messZeit.minuten, daten[i].messZeit.sekunden);
        printf("\nMessgroesse: %s"
               "\nMessergebnis: %.2lf",
               daten[i].messGroesse, daten[i].messErgebnis
        );
    }
}

void day1() {
    daily day[] = {
        "Exit Program", switchDay,
        "Mitschrift", day1Transcript,
        "Kontoaufgabe", day1Konto,
        "Messung", day1Messung1,
        "Messung (eigene Lsg)", day1Messung2,
    };
    int laenge = sizeof(day)/ sizeof(day[0]);

    caseProgram(day, laenge, day1);
}



