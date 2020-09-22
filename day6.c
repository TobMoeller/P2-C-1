#include "types.h"
void day6laenge(char[][30], int);

void day6transcript() {
    /*
        Mitschrift
    */
    int normInt = 1409;
    int *zeigerAufInt;

    printf("int Werte\n");
    printf("normInt Wert:%d\n", normInt);
    printf("normInt Adresse:%p\n", &normInt);

    printf("Zeiger mit uninitialisierten \"Werten\"\n");
    printf("zeigerAufInt zeigt auf Adresse:%p\n", zeigerAufInt);
    printf("zeigerAufInt Adresse:%p\n", &zeigerAufInt);

    // Achtung: Zeiger nicht initialisiert -> Anzeige von zufälligen Werten oder Absturz
    // printf("zeigerAufInt Wert:%d\n", *zeigerAufInt);

    printf("Zeiger mit NULL initialisiert\n");
    zeigerAufInt=NULL;

    printf("zeigerAufInt zeigt auf Adresse:%p\n", zeigerAufInt);
    printf("zeigerAufInt Adresse:%p\n", &zeigerAufInt);

    // Achtung: Zeiger mit NULL initialisiert -> Versuch eines Zugriffs auf OS Speicher ->Absturz
    // printf("zeigerAufInt Wert:%d\n", *zeigerAufInt);

    printf("Zeiger mit Adresse von normInt\n");
    zeigerAufInt=&normInt;

    printf("zeigerAufInt zeigt auf Adresse:%p\n", zeigerAufInt);
    printf("zeigerAufInt Adresse:%p\n", &zeigerAufInt);
    printf("zeigerAufInt Wert:%d\n", *zeigerAufInt);

    printf("Zeiger auf ein char array\n");

    char *pCharArray = "Hallo!test\n";

    printf("pCharArray Inhalt:%s\n", pCharArray);
    printf("pCharArray[1] Inhalt:%c\n", pCharArray[1]);
    printf("pCharArray Adresse:%p\n", &pCharArray);

    // BÖSE! ;)
    // Zeiger verbiegen möglichst vermeiden!
    zeigerAufInt=pCharArray;
    printf("zeigerAufInt zeigt auf Adresse:%p\n", zeigerAufInt);
    printf("zeigerAufInt Adresse:%p\n", &zeigerAufInt);
    printf("zeigerAufInt d Wert:%d\n", *zeigerAufInt);
    printf("zeigerAufInt s Wert:%s\n", zeigerAufInt);
    printf("zeigerAufInt[2] Wert:%c\n", zeigerAufInt[1]); // springt (da int pointer) 4 byte weiter, gibt also o aus anstelle von a (1 byte weiter)
}

void day6pointerTest() {
    int b = 10;
    int *pb = &b;
    void *vb = &b;

    printf("\nAdresse &b: %p / %x / %X", &b, &b, &b);
    printf("\nAdresse &pb: %p / %x / %X", &pb, &pb, &pb);
    printf("\nAdresse &*pb: %p / %x / %X", &*pb, &*pb, &*pb);
    printf("\nAdresse pb: %p / %x / %X", pb, pb, pb);
    printf("\n%d", *((int*)vb));
}

void day6stringTest() {
    char texte[][30] = {"test1", "testitest", "testomatorat"};
    int laenge = sizeof(texte)/ sizeof(texte[0]);
    day6laenge(texte, laenge);
}

void day6laenge(char texte[][30], int laenge) {
    for (int i = 0; i < laenge; i++) {
        int stringlaenge = 0;
        while(texte[i][stringlaenge] != '\0') {
            stringlaenge++;
        }
        printf("\nDer %dte String hat die Länge: %d", i+1, stringlaenge);
    }
}

void day6pointerTest2() {
    double zahl = 15.3;
    double *pointerZahl = NULL;
    int array[] = {7, 8, 9, 19};
    printf("\nAdresse von Zeiger: %p", &pointerZahl);

    void testePointer(double *pointer) {
        if (pointer != NULL) {
            printf("\n%lf", *pointer);
        } else {
            printf("\n%p", &pointer);
        }
        printf("\nAdresse von Zeiger in fkt: %p", &pointer);
        printf("\nAdresse von Zeigerinhalt in fkt: %p", pointer);
//        int laenge = sizeof(*array)/ sizeof(*array[0]);
//        printf("\nLänge: %d", laenge);
    }
    testePointer(pointerZahl);
    pointerZahl = &zahl;
    testePointer(pointerZahl);
}

void day6stringTest2() {
    int array[] = {1, 2, 3, 4, 5};

    void laenge(int *array) {
        int laenge = sizeof(array)/ sizeof(array[0]);
        printf("Länge: %d", laenge);
    }
    laenge(array);
}

void day6charAufgabe() {
    char a = 'A', b = 'B';
    void charSwitch(char *alpha, char *beta) {
        char zeta = *alpha;
        *alpha = *beta;
        *beta = zeta;
    }
    charSwitch(&a, &b);
    printf("a: %c, b: %c", a, b);
}

void day6findeZeichen() {
    char text[50] = {0};
    int anzahlX = 0;
    printf("Text eingeben: ");
    scanf("%s", text);

    int findeZeichen(char *text, int *anzahlX) {
        int i;
        for (i = 0; text[i] != '\0'; i++) {
            if (text[i] == 'X' || text[i] == 'x') {
                (*anzahlX)++;
            }
        }
        return i;
    }

    int anzahlZeichen = findeZeichen(text, &anzahlX);
    printf("\nDer Text ist %d Zeichen lang und hat %d 'X'e.", anzahlZeichen, anzahlX);
}

void day6() {
    daily day[] = {
        "Exit Program", switchDay,
        "Tag 6 Mitschrift (Pointer)", day6transcript,
        "Tests zu Pointern", day6pointerTest,
        "String Test", day6stringTest,
        "Test zu Pointern 2", day6pointerTest2,
        "String Test 2", day6stringTest2,
        "charswitch Aufgabe (05_01_T1)", day6charAufgabe,
        "Finde Zeichen (05_01_13)", day6findeZeichen,
    };
    int laenge = sizeof(day)/ sizeof(day[0]);

    caseProgram(day, laenge, day6);

}
