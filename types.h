#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <string.h>

typedef struct {
    char description[50];
    void (*function)();
} daily;


void switchDay();
void caseProgram(daily [], int, void (*)());


#endif // MAIN_H_INCLUDED


