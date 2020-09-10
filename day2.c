#include <stdio.h>
#include "types.h"

//void day2() {
//    char descriptions[][50] = {
//        "Paketaufgabe",
//        "Kontoaufgabe Erweiterung",
//        "Inkassoaufgabe 04_02_12_V1"
//    };
//    int laenge = sizeof(descriptions)/ sizeof(descriptions[0]);
//
//    switch (caseProgram(descriptions, laenge)){
//        case 1: day2Paket(); day2(); break;
//        case 2: day2Konto(); day2(); break;
//        case 3: day2Inkasso(); day2(); break;
//        case 0: printf("\n--- exiting ---"); break;
//        default: printf("\nBitte ein Case angeben\n"); scanf("%*c"); day2(); break;
//    }
//}



void day2Paket() {
    /*
        Sie sollen ein Programm zur Definition einer Lieferung erstellen.
        Jede Lieferung umfasst nur ein Paket. Zu dem Paket ist das Gewicht und die Größe bekannt. Jede Lieferung besteht aus dem Paket, dem Lieferdatum und der Lieferadresse.
        Fragen Sie den Benutzer nach allen Daten einer Lieferung und speichern Sie die Daten in einer passenden Datenstruktur ab. Geben Sie anschließend alle Daten aus der Datenstruktur wieder auf der Console aus.
    */

    typedef struct {
        double laenge;
        double breite;
        double tiefe;
    } groesse;

    typedef struct {
        double gewicht;
        groesse paketGroesse;
    } paket;

    typedef struct {
        paket lieferpaket;
        char lieferdatum[20];
        char lieferadresse[50];
    } lieferung;

    int MAX = 10;
    lieferung lieferungen[MAX];
    int counter = 0;
    int breakout = 1;

    do {
        printf("\nGeben Sie die Informationen zu Ihrem Paket an:");
        printf("\nPaketgewicht - ");
        fflush(stdin);
        scanf("%lf", &lieferungen[counter].lieferpaket.gewicht);
        printf("Paketgröße (Länge Breite Tiefe) - ");
        fflush(stdin);
        scanf("%lf %lf %lf", &lieferungen[counter].lieferpaket.paketGroesse.laenge, &lieferungen[counter].lieferpaket.paketGroesse.breite, &lieferungen[counter].lieferpaket.paketGroesse.tiefe);

        printf("\nWann wird das Paket zugestellt?\n");
        fflush(stdin);
        scanf("%s", lieferungen[counter].lieferdatum);

        printf("\nWohin wird das Paket geliefert?\n");
        fflush(stdin);
        scanf("%s", lieferungen[counter].lieferadresse);

        counter++;
        if (counter < MAX) {
            printf("\nFortfahren? (1 - ja / 0 - nein) \n");
            fflush(stdin);
            scanf("%d", &breakout);
        }
        else breakout = 0;

    } while (breakout != 0);

    for (int i = 0; i < counter; i++) {
        printf("\n\nPaket(%d)"
               "\nPaketgewicht: %.2lf"
               "\nPaketgröße: L: %.2lf, B: %.2lf, T: %.2lf"
               "\nZustelldatum: %s"
               "\nZustellort: %s",
               i+1,
               lieferungen[i].lieferpaket.gewicht,
               lieferungen[i].lieferpaket.paketGroesse.laenge, lieferungen[i].lieferpaket.paketGroesse.breite, lieferungen[i].lieferpaket.paketGroesse.tiefe,
               lieferungen[i].lieferdatum,
               lieferungen[i].lieferadresse
        );
    }
}

void day2Konto() {
    /*
        Mitschrift Tag 2
        Ziel: Arrays von structures
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

    konto bank[100] = {};

    bank[0] = kt1;
    bank[1] = kt2;


    // Abbuchung
    double wert;
    printf("Wert eingeben: ");
    fflush(stdin);
    scanf("%lf", &wert);

    if (bank[0].stand + bank[0].dispo - wert >= 0) bank[0].stand -= wert;
    else printf("Dispo ist zu klein!\n");

    // Zubuchung
    bank[1].stand += wert;

    int i = 0;
    while (bank[i].nummer) {
        printf("Konto(%d):\tNummer: %d\tStand: %.2lf\tName: %s, %s\n",
               i, bank[i].nummer, bank[i].stand, bank[i].inhaber.nachname, bank[i].inhaber.vorname);
        i++;
    }

}

void day2Inkasso() {
    /*
        Sie sollen für das Inkassounternehmen SchlauUndListig GmbH & Co. Kg eine Software zur Verwaltung von Rechnungen erstellen.
        Eine Rechnung besteht aus einer Rechnungsnummer, einem Rechnungsdatum, einem Rechnungsbetrag, einem Rechnungsempfänger und der Information, ob die Rechnung schon bezahlt wurde oder nicht.
        Ihre Ansprechpartnerin des Unternehmens SchlauUndListig erzählt ihnen, dass sie zur Zeit ca. 100 Rechnungen betreuen.
        Sie möchte sich über die Software alle Rechnungen ausgeben lassen, die noch nicht bezahlt wurden. Optional möchte Sie einen Schwellwert angeben.
        Dann sollen nur Rechnungen gesucht werden, die noch nicht bezahlt wurden und deren Rechnungsbetrag größer oder gleich dem Schwellwert sind.
        Außerdem möchte Sie die Möglichkeit haben, eine Rechnung als bezahlt zu markieren. Dazu möchte Sie die Rechnungsnummer eingeben.
    */

    system("cls");
    typedef struct {
        char vorname[30];
        char nachname[30];
    } person;

    typedef struct {
        int rechnungsnummer;
        char rechnungsdatum[10];
        double rechnungsbetrag;
        person empfaenger;
        int bezahlt;
    } rechnung;

    rechnung rechnungen[100] = {0};
    rechnung rechnung1 = {1000, "2012-08-17", 1753.53, {"Günni", "Günsen"}, 0};
    rechnung rechnung2 = {1001, "2013-04-12", 23153.44, {"Astrid", "Arschtritt"}, 0};
    rechnung rechnung3 = {1002, "2011-05-27", 67213.32, {"Richard", "Rümmel"}, 1};
    rechnung rechnung4 = {1003, "2010-02-05", 507213.11, {"Uwe", "Ulrich"}, 1};
    rechnungen[0] = rechnung1;
    rechnungen[1] = rechnung2;
    // Alternative Zuweisung mit typecast
    rechnungen[2] = (rechnung) {1002, "2011-05-27", 67213.32, {"Richard", "Rümmel"}, 0};
    rechnungen[3] = (rechnung) {1003, "2010-02-05", 507213.11, {"Uwe", "Ulrich"}, 1};

    int exit = 1;
    do {
        printf("\nWas möchten Sie tun? \nOption (1) = Offene Rechnungen ausgeben\nOption (2) = Rechnung auf bezahlt setzen\nOption (0) = Programm Ende\n\t");
        fflush(stdin);
        scanf("%d", &exit);

        switch (exit) {
            case 1: {
                    double schwellenwert;
                    printf("\nBitte geben Sie einen Schwellenwert an (0 = kein Schwellenwert):");
                    fflush(stdin);
                    scanf("%lf", &schwellenwert);

                    system("cls");
                    printf("\nOffene Rechnungen:\n");
                    for (int i = 0; rechnungen[i].rechnungsnummer != 0; i++) {
                        if (!rechnungen[i].bezahlt && rechnungen[i].rechnungsbetrag >= schwellenwert) {
                            printf("\nRechnung(%d): Rechnungsnummer: %d vom %s\n"
                               "Empfänger: %s, %s\n"
                               "Betrag: %.2lf\n"
                               ,i ,rechnungen[i].rechnungsnummer, rechnungen[i].rechnungsdatum
                               ,rechnungen[i].empfaenger.nachname, rechnungen[i].empfaenger.vorname
                               ,rechnungen[i].rechnungsbetrag
                            );
                        }
                    }
                }
                break;
            case 2: {
                    int rechnungsnummer;
                    printf("\nBitte geben Sie die Rechnungsnummer ein, dessen Bezahltstatus Sie ändern möchten: ");
                    fflush(stdin);
                    scanf("%d", &rechnungsnummer);

                    //system("cls");
                    for (int i = 0; rechnungen[i].rechnungsnummer != 0; i++) {
                        if (rechnungen[i].rechnungsnummer == rechnungsnummer) {
                            if (rechnungen[i].bezahlt) rechnungen[i].bezahlt = 0;
                            else rechnungen[i].bezahlt = 1;
                            break;
                        }
                    }
                }
                break;
            default: break;
        }

    } while (exit);

}

void day2() {
    daily day[] = {
        "Exit Program", switchDay,
        "Paketaufgabe", day2Paket,
        "Kontoaufgabe Erweiterung", day2Konto,
        "Inkassoaufgabe 04_02_12_V1", day2Inkasso,
    };
    int laenge = sizeof(day)/ sizeof(day[0]);

    caseProgram(day, laenge, day2);
}

