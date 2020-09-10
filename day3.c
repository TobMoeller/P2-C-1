#include "types.h"

int day3BeispielFkt(int, char);

//void day3() {
//    char descriptions[][50] = {
//        "Mitschrift",
//        "Quersumme"
//    };
//    int laenge = sizeof(descriptions)/ sizeof(descriptions[0]);
//
//    switch (caseProgram(descriptions, laenge)){
//        case 1: day3Transcript(); day3(); break;
//        case 2: day3Quersumme(); day3(); break;
////        case 3: day3Inkasso(); day3(); break;
////        case 4: day3Messung2(); day3(); break;
//        case 0: printf("\n--- exiting ---"); break;
//        default: printf("\nBitte ein Case angeben\n"); scanf("%*c"); day3(); break;
//    }
//}


void day3Transcript() {
    printf("%c, %c, %c, %d", 257, 256+48, 256+65, 9%10);
    printf("\nreturn: %c", day3BeispielFkt('A', 0));
    printf("\nreturn: %c", day3BeispielFkt(0, 'A'));
}

int day3BeispielFkt(int a, char b) {
    printf("\n%d\t%c", a, b);
    return a + b;
}

void day3Quersumme() {
    /*
        Sie bekommen die Aufgabe, die Quersumme einer Zahl zu berechnen.
        Da diese Funktionalität mehrfach im Projekt benötigt wird, sollen Sie eine
        Funktion erstellen. Als Eingabe erhalt sie eine Ganzzahl (Integer) als Ergebnis
        soll sie die Quersumme zurück geben.
    */

    int zahl;
    printf("Zahl für Quersumme: ");
    scanf("%d", &zahl);
    printf("mod %d", zahl % 9);
    printf("\nEinfache  Quersumme: %d", berechneQuersumme(zahl));
    printf("\nIterative Quersumme: %d", berechneIterativeQuersumme(zahl));
    printf("\nIterative Quersumme2: %d", berechneIterativeQuersumme2(zahl));
}

int berechneQuersumme(int zahl) {
    int quersumme = 0;
    while(zahl != 0) {
        quersumme += zahl % 10;
//        printf("\nzahl1: %d", zahl);
        zahl /= 10;
//        printf("\nzahl2: %d", zahl);
    }
    return quersumme;
}

int berechneIterativeQuersumme(int zahl) {
    int quersumme = 0;
    while(zahl != 0) {
        while(zahl != 0) {
            quersumme += zahl % 10;
//            printf("\nzahl1: %d", zahl);
            zahl /= 10;
//            printf("\nzahl2: %d", zahl);
        }
        if (quersumme > 9) {
            zahl = quersumme;
            quersumme = 0;
        }
    }
    return quersumme;
}

int berechneIterativeQuersumme2(int zahl) {
    while(zahl >= 10) zahl = zahl / 10 + zahl % 10;
    return zahl;
}



//
//Q(Q(Q(1245)) + Q(8)) = Q(1245+8) = Q(1253) = Q(11) = 2
//Q(Q(12) + Q(8))
//Q(3+8)
//Q(11) = 2
//
//12458 = 20  12450 +8
//1+2+4+5+8   1245+8
//1+2+5+3     125+3
//1+2+8       12+8
//2+0         2+0
//2

void day3() {
    daily day[] = {
        "Exit Program", switchDay,
        "Mitschrift", day3Transcript,
        "Quersumme", day3Quersumme,
    };
    int laenge = sizeof(day)/ sizeof(day[0]);

    caseProgram(day, laenge, day3);
}
