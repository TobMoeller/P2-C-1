#include "types.h"

void intBubbleSort(int *, int);

void tauscheInt(int [], int, int);


void day8searchLinear() {
    /*
        Aufgabe 05_02_21
        Sie sollen eine Funktion …searchLinear(…) schreiben, die ein ungeordnetes Array vom Typ int als Parameter  und einen IntegerWert übergeben bekommt.
        Die Funktion soll eine Lineare Suche als Algorithmus verwenden und als Ergebnis eine 1 zurückgeben, wenn der IntegerWert im Array vorkommt, ansonsten eine 0.
    */
    int testArray[] = {1,6,7,45,25,5,4,17,9,64,43,8,1,5,64,88,135,14,13,43,74,12,-7,8};
    int erg, gesuchteZahl = -64;
    int arrayLenght = sizeof(testArray)/sizeof(testArray[0]);

    // Funktion
    int linearSearch(int searchArray[],int lenght,int zahl){
        for(int i=0;i<lenght || searchArray[i]==zahl;i++){
            if(searchArray[i]==zahl) return 1;
        }
        return 0;
    }

    erg = linearSearch(testArray,arrayLenght,gesuchteZahl);
    if(erg){
        printf("Die gesuchte Zahl %d wurde gefunden.", gesuchteZahl);
    } else {
        printf("Die gesuchte Zahl %d wurde nicht gefunden", gesuchteZahl);
    }
}


void day8sortVisualisation() {
    // Aufgabe 05_02_11
//    int testArray[] = {1,6,7,45,25,5,4,17,9,64,43,8,1,5,64,88,135,14,13,43,74,12,-7,8};
    int testArray[] = {12, 45, 234, 76, 2, 98, 3, 5, 9, 11, 6, 18};
    int laenge = sizeof(testArray)/ sizeof(testArray[0]);
    intBubbleSort(testArray, laenge);
}

void intBubbleSort(int *testArray, int laenge) {
    int weiter = 1, letzterIndex = 0;

    // Bubble Sort äußere Schleife
    while (weiter) {
        weiter = 0;
        letzterIndex++;
        // Bubble Sort innere Schleife
        for (int i = 0; i < laenge - letzterIndex; i++) {
            // Ausgabe vor Eintragstausch
            printf("\n\t(%d)ter Durchlauf\n\t(%d)te Operation\n", letzterIndex, i);
            for (int j = 0; j < laenge; j++) {
                if (j == i || j == i + 1) printf("(%d) ", testArray[j]);
                else printf("%d ", testArray[j]);
            }
            printf("\n");

            if (testArray[i] > testArray[i+1]) {
                int temp = testArray[i];
                testArray[i] = testArray[i+1];
                testArray[i+1] = temp;
                weiter = 1;
            }
            // Ausgabe nach Eintragstausch
            for (int j = 0; j < laenge; j++) {
                if (j == i || j == i + 1) printf("(%d) ", testArray[j]);
                else printf("%d ", testArray[j]);
            }
        }
    }
//    printf("\nNach %d Durchläufen:\n", letzterIndex-1);
//    for (int i = 0; i < laenge; i++) {
//        printf("%d ", testArray[i]);
//    }
}


void day8sortProzent() {
    // Aufgabe 05_02_13
    int array[][2] = {
        {1, 38},
        {2, 33},
        {3, 30},
        {4, 31},
        {5, 25},
    };
    int laenge = sizeof(array)/ sizeof(array[0]);

    // Funktion
    void sortProzente(int array[][2], int laenge) {
        int weiter = 1, letzterIndex = 0;

        // Ausgabe Array
        printf("\nVor Sortierung:\n");
        for (int i = 0; i < laenge; i++) {
            printf("\nGruppe: %d, Prozent: %d", array[i][0], array[i][1]);
        }
        // Bubble Sort äußere Schleife
        while (weiter) {
            weiter = 0;
            letzterIndex++;
            // Bubble Sort innere Schleife
            for (int i = 0; i < laenge - letzterIndex; i++) {
                if (array[i][1] > array[i+1][1]) {
                    int temp[2] = {0};
                    temp[0] = array[i][0];
                    temp[1] = array[i][1];
                    array[i][0] = array[i+1][0];
                    array[i][1] = array[i+1][1];
                    array[i+1][0] = temp[0];
                    array[i+1][1] = temp[1];
                    weiter = 1;
                }
//                printf("\n\nNach %d Durchläufen:\n", letzterIndex);
//                for (int i = 0; i < laenge; i++) {
//                    printf("\nGruppe: %d, Prozent: %d", array[i][0], array[i][1]);
//                }
            }
        }
        // Ausgabe Array nach Sortierung
        printf("\n\nNach %d Durchläufen:\n", letzterIndex);
        for (int i = 0; i < laenge; i++) {
            printf("\nGruppe: %d, Prozent: %d", array[i][0], array[i][1]);
        }
    }
    // Funktionsaufruf
    sortProzente(array, laenge);
}

void day8testFktn() {
    typedef struct {
        char string[30];
    } string;
    string testString0 = {"test"};
    string testString1;
    testString1 = (string) {.string = "testString1"};
    string testString2;
    testString2 = (string) {"testString1"};
    string testString3 = {0};
    printf("String0: %s\nString1: %s\nString2: %s\nString3: %s\n", testString0, testString1, testString2, testString3);
}

void day8quickSort() {
    int array[] = {12, 45, 234, 76, 2, 98, 3, 5, 9, 11, 6, 18};
    int laenge = sizeof(array)/ sizeof(array[0]);

    intQuickSort(array, 0, laenge-1);
    for (int i = 0; i < laenge; i++) printf("%d, ", array[i]);
}

void intQuickSort(int array[], int anfang, int laenge) {
    // unfertig
    int links = anfang, rechts = laenge;
    int pivot = links;
    while (links < rechts) {

        while (array[links] <= array[pivot]) links++;
        while (array[rechts] >= array[pivot]) rechts--;

        if (links < rechts) {
            tauscheInt(array, links, rechts);
        } else {
            tauscheInt(array, pivot, rechts);
            intQuickSort(array, anfang, rechts-1);
            intQuickSort(array, rechts+1, laenge);
        }
    }
}

void tauscheInt(int array[], int quelle, int ziel) {
    int temp = array[quelle];
    array[quelle] = array[ziel];
    array[ziel] = temp;
}

void day8() {
    daily day[] = {
        "Exit Program", switchDay,
        "Linear Search (05_02_21)", day8searchLinear,
        "Bubble Visualized (05_02_11)", day8sortVisualisation,
        "Sort Prozent (05_02_13)", day8sortProzent,
        "Testfunktion", day8testFktn,
        "Quicksort", day8quickSort,
    };
    int laenge = sizeof(day)/ sizeof(day[0]);

    caseProgram(day, laenge, day8);

}
