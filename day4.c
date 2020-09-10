#include "types.h"

int day4umsaetzeBerechnen(int [], int, int);
void day4program1array(int, int []);
void day4program1arrayCpy(int, int [], int []);
void day4test2(char [][50], int);

//void day4() {
//    char descriptions[][50] = {
//        "Mitschrift",
//        "Array reverse (04_04_12/13)",
//        "Tag 4 test"
//    };
//    int laenge = sizeof(descriptions)/ sizeof(descriptions[0]);
//
//    switch (caseProgram(descriptions, laenge)){
//        case 1: day4transcript(); day4(); break; //break;
//        case 2: day4program1(); day4(); break;
//        case 3: day4test(); day4(); break;
//        case 0: printf("\n--- exiting ---"); break;
//        default: printf("\nBitte ein Case angeben\n"); scanf("%*c"); day4(); break;
//    }
//}

void day4transcript() {
    /*
        Array als Parameter und Funktionsprototypen
    */
    int umsaetze[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
//    printf("%d, %d", sizeof(int), sizeof(umsaetze));
    printf("Umsätze: %d", day4umsaetzeBerechnen(umsaetze, 1, 12));
}

int day4umsaetzeBerechnen(int umsaetze[], int start, int ende) {
    int umsatz = 0;
    while (start-1 < ende) {
        umsatz += umsaetze[start-1];
        start++;
    }
    printf("sizeof: %d", sizeof(umsaetze)/sizeof(umsaetze[0]));
    return umsatz;
}

void day4program1() {
    /*
        Schreiben Sie eine Funktion reverse(Parameterliste), die ein Arrays vom Typ int erhält und die Reihenfolge der Werte im Array umdreht.
        z.B
        {1	2	3	4	5}
        wird zu
        5	4	3	2	1
    */
    int array[] = {1, 2, 3, 4, 5};
    int laenge = sizeof(array)/sizeof(array[0]);
    int array2[laenge];
    day4program1arrayCpy(laenge, array, array2);

    printf("\nAufgabe 04_04_13 (cpyArray):\nArray1: ");
    for (int i = 0; i < laenge; i++) {
        printf("%d ", array[i]);
    }
    printf("\nArray2: ");
    for (int i = 0; i < laenge; i++) {
        printf("%d ", array2[i]);
    }
    day4program1array(laenge, array);

    printf("\nAufgabe 04_04_12 (reverseArray):\nArray1: ");
    for (int i = 0; i < laenge; i++) {
        printf("%d ", array[i]);
    }
}

void day4program1array(int laenge, int array[]) {
    // testweise berechnung der arraygröße des übergebenen arrays/pointers
    int groesse = sizeof(*&array);
    printf("\n\tTestweise Berechnung der Länge (in fkt): %d, Länge(in \"main\"): %d\n", groesse, laenge);
    printf("\nPointer Adresse array: %d\n", (void*)array);

    for (int i = 0; i < laenge/2; i++) {
        int temp1 = array[i];
        array[i] = array[laenge-1-i];
        array[laenge-1-i] = temp1;
    }
}

void day4program1arrayCpy(int laenge, int quelle[], int ziel[]) {
    for (int i = 0; i < laenge; i++) {
        ziel[i] = quelle[i];
    }
}

void day4test() {
    char tag[][50] = {"test1", "test2", "test3"};
    int laenge = sizeof(tag)/ sizeof(tag[0]);
    printf("%d", laenge);

    day4test2(tag, laenge);
}

void day4test2(char tag[][50], int laenge) {
    for (int i = 0; i < laenge; i++) printf("\n%s", tag[i]);
}

void day4() {
    daily day[] = {
        "Exit Program", switchDay,
        "Mitschrift", day4transcript,
        "Array reverse (04_04_12/13)", day4program1,
        "Tag 4 test", day4test,
    };
    int laenge = sizeof(day)/ sizeof(day[0]);

    caseProgram(day, laenge, day4);
}
