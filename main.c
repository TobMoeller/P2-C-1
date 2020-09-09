#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    system("chcp.com 1252");
    system("cls");
    switchCase();
}


void switchCase() {
    int caseProgram;
    printf("\n\nWas moechtest du starten? \n"
           "Option (1): Tag 1\n"
           "Option (2): Tag 2\n"
           "Option (3): Tag 3\n"
           "Option (0): Exit Program\n\t");
    scanf("%d", &caseProgram);

    switch (caseProgram){
        case 1: day1(); switchCase(); break;
        case 2: day2(); switchCase(); break;
        case 3: day3(); switchCase(); break;
        case 0: printf("\n--- exiting ---"); break;
        default: printf("\nBitte ein Case angeben\n"); scanf("%*c"); switchCase(); break;
    }
}
