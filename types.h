#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED



#endif // MAIN_H_INCLUDED

typedef struct {
    char description[50];
    void (*function)();
} daily;

void switchDay();
