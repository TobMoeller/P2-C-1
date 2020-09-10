#include "types.h"

void day5() {
    daily day[] = {
        "Exit Program", switchDay,
    };
    int laenge = sizeof(day)/ sizeof(day[0]);

    caseProgram(day, laenge, day5);
}
