# P2-C-1
Second programming class during retraining

## What is it about?

- making school notes
- solving school tasks
- sharing and collaborating with class mates
- showcasing some of my Code in C

### Features

- Console Application
- Developed a way to integrate each single days separate projects into one single console application to have it more accessable

### Technologies

- ANSI C
- Code::Blocks 

---

## Small Feature showcase

Because i did not want a separate program / project for each and every new task, but rather have everything compact and easily accessable, i developed a way to write everything into a single project and switch between the days. This enables me to repetitively try functions with different inputs without having to start the program all over again.

At first i tryed an approach with a recursive call of a function asking the user for a decision on what day and then what function to call. This meant i had to repeat this pattern for every day and had a lot of repetetive code and a lot of additional code to type for each additional day and function.

```c
void switchCase() {
    int caseProgram;
    printf("\n\nWas moechtest du starten? \n"
           "Option (1): Tag 1\n"
           "Option (2): Tag 2\n"
           "Option (0): Exit Program\n\t");
    scanf("%d", &caseProgram);

    switch (caseProgram){
        case 1: day1(); switchCase(); break;
        case 2: day2(); switchCase(); break;
        case 0: printf("\n--- exiting ---"); break;
        default: printf("\nBitte ein Case angeben\n"); scanf("%*c"); switchCase(); break;
    }
}

// exemplary daily function
void day1() {
    int caseProgram;
    printf("\n\nWas moechtest du starten? \n"
           "Option (1): Tag 1 Mitschrift\n"
           "Option (2): Uebung 1\n"
           "Option (0): Exit Tag\n\t");
    scanf("%d", &caseProgram);

    switch (caseProgram){
        case 1: day1Mitschrift(); day1(); break;
        case 2: uebung1_1(); day1(); break;
        case 0: printf("\n--- exiting ---"); break;
        default: printf("\nBitte ein Case angeben\n"); scanf("%*c"); day1(); break;
    }
}
```

After i learned about structs and pointers i expanded upon this method and came up with the following way of handling the problem:

```c
typedef struct {
    char description[50];
    void (*function)();
} daily;

void switchDay() {
    daily day[] = {
        "Exit Program", exitProgram,
        "Tag 1", day1,
        "Tag 2", day2,
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

void day1() {
    daily day[] = {
        "Exit Program", switchDay,
        "Mitschrift", day1Transcript,
        "Übung 1", day1Konto,
    };
    int laenge = sizeof(day)/ sizeof(day[0]);

    caseProgram(day, laenge, day1);
}
```

Here the `caseProgram` function gets called by each day and expects an array of the `daily` structure. This contains a function and a matching description which gets displayed on the console and called depending on the user input. Additionally it gets a function pointer as an argument which gets called at the end to start the process all over again.