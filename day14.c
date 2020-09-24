#include "types.h"
#include <ctype.h>
#include <math.h>

typedef struct {
    char loginname[50];
    int pin;
} Passwort;

void day14satzbau(char *);
int day14findAllChr(char *, char);
int day14hash(int);
int day14loginCheck(char *, int, Passwort *, int);


void day14deutschUnterricht() {
    /*
        Unterrichtsaufgabe
        Gegeben sei folgender Satz:
        "Wir lernen gemeinsam für die Bausteinprüfung 'Grundlagen der Programmierung - Teil 2'"

        Aufgabe: Schreiben Sie eine FUnktion, die diese Zeichenkette als Parameter erhält und alle Vokale durch X ersetzt,
        alle Umlaute durch Y ersetzt und alle großgeschriebenen Konsonanten durch _ (Unterstrich) ersetzt.
        Das Ergebnis soll im Hauptprogramm aufgerufen werden.
    */
    char satz[] = "Wir lernen gemeinsam für die Bausteinprüfung 'Grundlagen der Programmierung - Teil 2'";
//    int laenge = strlen(satz);
    printf("\nAlter Satz: %s\n", satz);
    day14satzbau(satz);
    printf("\nNeuer Satz: %s\n", satz);

}

void day14satzbau(char *satz) {
    for (int i = 0; satz[i] != '\0'; i++) {
        char c = tolower(satz[i]); // zur Prüfung wenn Groß/Kleinschreibung irrelevant ist
        if (c == 'ä' || c == 'ö' || c == 'ü') { // Umlaute
            satz[i] = 'Y';
        } else if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') { // Vokale
            satz[i] = 'X';
        } else if (isupper(satz[i])) { // große Konsonanten
            satz[i] = '_';
        }
    }
}


void day14findChr() {
    /*
        05_01_11
        Sie erhalten die Aufgabe eine Funktion int findAllChr(char eingabe[], char zeichen),
        dass alle Vorkommen des Zeichens in der Zeichenkette sucht und als Ergebnis zurück liefert.
        Wird das Zeichen in der Zeichenkette nicht gefunden, so soll 0 zurückgegeben werden.
    */
    char zeichenkette[100];
    char zeichen;
    printf("Zeichenkette eingeben:");
    fflush(stdin);
    scanf("%[^\n]s", zeichenkette);
    printf("Gesuchtes Zeichen eingeben:");
    fflush(stdin);
    scanf("%c", &zeichen);
    printf("\nDas Zeichen %c kommt %d mal vor.", zeichen, day14findAllChr(zeichenkette, zeichen));

}

int day14findAllChr(char *zeichenkette, char zeichen) {
    int zaehler = 0;
    for (int i = 0; zeichenkette[i] != '\0'; i++) {
        if (zeichenkette[i] == zeichen) zaehler++;
    }
    return zaehler;
}




void day14login() {
    /*
        05_02_23
        Sie sollen eine Funktion …login(…) schreiben, die überprüft, ob die LoginDaten korrekt sind.
        Die LoginDaten bestehen aus einem Loginnamen und einer Pin. Der Projektleiter hat ihnen mitgeteilt, dass die Pin über einen Hashwert verschlüsselt abgelegt ist.

        Die Hashfunktion hat folgenden Aufbau:
        Der ganzzahlige Anteil von (1000 *  Nachkommaanteil( pin * (Wurzel(5) – 1) / 2))

        Beispiel: Pin = 6161
        Der ganzzahlige Anteil von (1000 *  Nachkommaanteil( 6161 * (Wurzel(5) – 1) / 2)) =
        Der ganzzahlige Anteil von (1000 *  Nachkommaanteil(3807,707405)) =
        Der ganzzahlige Anteil von (1000 *  0,707405) =
        Der ganzzahlige Anteil von (707,405) = 707

        Die vorhanden LoginDaten sind in einem Array vom Typ einer Struktur Passwort abgelegt. Die Struktur Passwort besteht aus dem Loginname und der verschlüsselten pin.
    */

    Passwort loginDaten[10];
    int laenge = sizeof(loginDaten) / sizeof(loginDaten[0]);

    // Array mit Daten befüllen
    for (int i = 0; i < laenge; i++) {
        char temp[50] = "name";
        temp[4] = i + 48; // name0, name1, name2...
//        printf("Login: %s, Pin: %d", temp, i+i*10+i*100+i*1000);
        strcpy(loginDaten[i].loginname, temp);
        loginDaten[i].pin = day14hash(i+i*10+i*100+i*1000); // Pins: 0, 1111, 2222, 3333
    }

    // Schleife mit Eingabe der Nutzerdaten
    int success = 0;
    do {
        char userNick[50];
        int userPin;
        printf("\n\nSuperdupersicherer Login:\nNick:");
        fflush(stdin);
        scanf("%s", userNick);
        printf("\nPIN:");
        scanf("%d", &userPin);

        // Prüfung der Logindaten
        if (day14loginCheck(userNick, userPin, loginDaten, laenge)) {
            success = 1;
            printf("\nHerzlich Willkommen!");
        } else printf("\n!! Falsche Logindaten !!\n");
    } while(!success);

}

// Bildet Hashwert aus Pin
int day14hash(int pin) {
    double zahl = pin * (sqrt(5)-1) / 2;
    zahl -= (int) zahl;
//    printf(", Speicher: %d\n", (int) (zahl * 1000));
    return (int) (zahl * 1000);
}

// Prüft die eingegebenen Logindaten gegen die gespeicherten Daten
int day14loginCheck(char *userNick, int userPin, Passwort *loginDaten, int laenge) {
    for (int i = 0; i < laenge; i++) {
//        printf("\nlogin: %s, hash: %d", loginDaten[i].loginname, loginDaten[i].pin);
        if (!strcmp(userNick, loginDaten[i].loginname)) { // wenn der usernick identisch zu loginname ist
            if (day14hash(userPin) == loginDaten[i].pin) { // wenn der hinterlegte hash zum hash der eingegebenen Pin passt
                return 1; // erfolgreicher login
            }
        }
    }
    return 0; // Falls der Login nicht hinterlegt ist oder das passwort falsch ist
}





void day14() {
    daily day[] = {
        "Exit Program", switchDay,
        "Deutschunterricht", day14deutschUnterricht,
        "Zeichenkette (05_01_11)", day14findChr,
        "Login (05_02_23)", day14login,
    };
    int laenge = sizeof(day)/ sizeof(day[0]);

    caseProgram(day, laenge, day14);

}
