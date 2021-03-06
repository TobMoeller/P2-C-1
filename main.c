#include "types.h"


void exitProgram();
void day1();
void day2();
void day3();
void day4();
void day5();
void day6();
void day7();
void day8();
void day12();
void day13();
void day14();

int main(void)
{
    system("chcp.com 1252");
    system("cls");
    switchDay();
}


void switchDay() {
//    char descriptions[][50] = {"Tag1", "Tag2", "Tag3", "Tag4", "Tag5"};
//    int laenge = sizeof(descriptions)/ sizeof(descriptions[0]);

//    switch (caseProgram(descriptions, laenge)){
//        case 1: day1(); switchCase(); break;
//        case 2: day2(); switchCase(); break;
//        case 3: day3(); switchCase(); break;
//        case 4: day4(); switchCase(); break;
//        case 5: day5(); switchCase(); break;
//        case 0: printf("\n--- exiting ---"); break;
//        default: printf("\nBitte ein Case angeben\n"); scanf("%*c"); switchCase(); break;
//    }
    daily day[] = {
        "Exit Program", exitProgram,
        "Tag 1", day1,
        "Tag 2", day2,
        "Tag 3", day3,
        "Tag 4", day4,
        "Tag 5", day5,
        "Tag 6", day6,
        "Tag 7", day7,
        "Tag 8", day8,
        "Tag 12", day12,
        "Tag 13", day13,
        "Tag 14", day14,
    };
    int laenge = sizeof(day)/ sizeof(day[0]);

    caseProgram(day, laenge, switchDay);
}

void caseProgram(daily day[], int laenge, void (*function)()) {
    int caseProgram;

    printf("\n\nWas moechtest du starten?");
    for (int i = 1; i < laenge; i++) {
        printf("\nOption (%d): %s", i, day[i].description);
    }
    printf("\nOption (0): Exit Program\n\t");
    scanf("%d", &caseProgram);

    day[caseProgram].function();
    function();
}

void exitProgram() {
    exit(0);
}
