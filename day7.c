#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#include <stdlib.h>
#include "types.h"

int day7berechneString(char *, int *);

void day7stringRechnen() {
    /*
        Sie sollen eine Funktion berechneToInt schreiben, die eine Zeichenkette als Eingabe erhält. Die Zeichenkette hat folgendes Format:
        Eine positive Ganzzahl gefolgt von einem + oder einem – und wieder einer positiven Ganzzahl.
        z.B:

        1	3	2	4	+	3	2	5	6	\0

        Wenn das Format nicht eingehalten wurde, dann soll als Ergebnis eine 0 zurückgegeben werden. Beispielsweise, wenn ein Buchstabe in der Zeichenkette vorkommt, oder ein falscher Operator.
        Wenn das Format eingehalten wurde, dann soll eine 1 zurückgegeben werden. Außerdem soll das Ergebnis der Rechnung in der Zeichenkette als Zahl zur Verfügung gestellt werden (im Beispiel: 4580).
    */
    char formel[50] = {0};
    int ergebnis = 0, rueckgabe;

    printf("Bitte Formel eingeben: ");
    scanf("%s", formel);

    rueckgabe = day7berechneString(formel, &ergebnis);
    printf("\nErgebnis: %d, Rückgabe (0 = Fehler): %d", ergebnis, rueckgabe);

}

int day7berechneString(char *formel, int *ergebnis) {
    int posOperator = 0;

    for (int i = 0; formel[i] != '\0'; i++) {
        // Ausbrauch bei falschem Zeichen
        if ((formel[i]-48 < 0 || formel[i]-48 > 9) && formel[i] != '+' && formel[i] != '-') return 0;
        // Herausschreiben der Operatorposition
        if (formel[i] == '+' || formel[i] == '-') posOperator = i;
    }

    // Zahl herausziehen mit strtol (!! endpointer nicht 100% verstanden)
    int zahl1 = strtol(formel, NULL, 10);
    printf("\nZahl1: %d", zahl1);
    int zahl2 = strtol(&formel[posOperator+1], NULL, 10);
    printf("\nZahl2: %d", zahl2);

    // Berechnung des Ergebnisses
    if (formel[posOperator] == '+') *ergebnis = zahl1 + zahl2;
    else if (formel[posOperator] == '-') *ergebnis = zahl1 - zahl2;

    return 1;
}


void day7testfktn() {
    // Testen von strtol funktionalität (Bsp: https://en.cppreference.com/w/c/string/byte/strtol)
    // parsing with error handling
    const char *p = "10 200000000000000000000000000000 30 -40 junk";
    printf("Parsing '%s':\n", p);

    for (;;)
    {
        // errno can be set to any non-zero value by a library function call
        // regardless of whether there was an error, so it needs to be cleared
        // in order to check the error set by strtol
        errno = 0;
        char *end;
        const long i = strtol(p, &end, 10);
        if (p == end)
            break;

        const bool range_error = errno == ERANGE;
        printf("Extracted '%.*s', strtol returned %ld.", (int)(end-p), p, i);
        p = end;

        if (range_error)
            printf(" Range error occurred.");

        putchar('\n');
    }

    printf("Unextracted leftover: '%s'\n\n", p);

    // parsing without error handling
    printf("\"1010\" in binary  --> %ld\n", strtol("1010", NULL, 2));
    printf("\"12\"   in octal   --> %ld\n", strtol("12",   NULL, 8));
    printf("\"A\"    in hex     --> %ld\n", strtol("A",    NULL, 16));
    printf("\"junk\" in base-36 --> %ld\n", strtol("junk", NULL, 36));
    printf("\"012\"  in auto-detected base --> %ld\n", strtol("012",  NULL, 0));
    printf("\"0xA\"  in auto-detected base --> %ld\n", strtol("0xA",  NULL, 0));
    printf("\"junk\" in auto-detected base --> %ld\n\n\n", strtol("junk", NULL, 0));
    char *test = "1234+5678";
    char *testptr;
    void testftk(char *test, char *testptr) {
        printf("\"1234\" in auto-detected base --> %ld\n", strtol(test, NULL, 10));
        printf("%s\n", test);
        printf("\"1234\" in auto-detected base --> %ld\n", strtol(&test[5], NULL, 10));
        printf("%s\n", test);
        printf("\"1234\" in auto-detected base --> %ld\n", strtol(test, &testptr, 10));
        printf("%s\n", test);
        printf("\"1234\" in auto-detected base --> %ld\n", strtol(&test[5], NULL, 10));
        printf("%s\n", test);
    }
    testftk(test, testptr);
}

void day7buchhaltung() {
    typedef struct {
        int id;
        char name[50];
        double gehalt;
    } mitarbeiter;

    mitarbeiter firma[] = {
        {1, "Günther", 2500},
        {2, "Maritha", 3500},
        {3, "Jürgen", 3750.50},
        {4, "Manfred", 5438.28},
    };
    int laengeFirma = sizeof(firma)/ sizeof(firma[0]);

    void mitarbeiterAusgeben(mitarbeiter *firma, int laengeFirma) {
        for (int i = 0; i < laengeFirma; i++) {
            printf("\nMitarbeiter ID(%d)\nName: %s\nGehalt: %.2lf\n"
                   , firma[i].id, firma[i].name, firma[i].gehalt);
        }
    }

    void mitarbeiterAnpassen(mitarbeiter *firma, int laengeFirma) {
        int id;
        double gehalt;
        printf("\nWelchen Mitarbeiter möchten Sie anzeigen?\n");
        scanf("%d", &id);
        for (int i = 0; i < laengeFirma; i++) {
            if (firma[i].id == id)
                printf("\nMitarbeiter ID(%d)\nName: %s\nGehalt: %.2lf\n"
                       , id, firma[i].name, firma[i].gehalt);
        }
        printf("\nWie hoch soll das neue Gehalt sein?\n");
        scanf("%lf", &gehalt);
        for (int i = 0; i < laengeFirma; i++) {
            if (firma[i].id == id) {
                firma[i].gehalt = gehalt;
                printf("\nMitarbeiter ID(%d) -> Neues Gehalt: %.2lf\n"
                       , id, firma[i].gehalt);
            }
        }
    }

    int weiter = 1;
    do {
        printf("\nWas möchten Sie tun?\n(1) Mitarbeiter anzeigen\n(2) Mitarbeiter anpassen\n(0) Programm beenden\n ");
        scanf("%d", &weiter);
        switch(weiter) {
        case 0:
            printf("\nAuf Wiedersehen!"); break;
        case 1:
            mitarbeiterAusgeben(firma, laengeFirma); break;
        case 2:
            mitarbeiterAnpassen(firma, laengeFirma); break;
        default:
            printf("\nIhre Eingabe war nicht korrekt."); break;
        }
    } while (weiter);
}


void day7() {
    daily day[] = {
        "Exit Program", switchDay,
        "Berechne String", day7stringRechnen,
        "strtol tests", day7testfktn,
        "Buchhaltung (05_01_T2)", day7buchhaltung,
    };
    int laenge = sizeof(day)/ sizeof(day[0]);

    caseProgram(day, laenge, day7);

}
