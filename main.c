#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX_TASKS 100
#define MAX_LENGTH 50

struct Task {
    char description[MAX_LENGTH];
    int completed;
};

struct Task tasks[MAX_TASKS];
int numTasks = 0;

void addTask(char description[]) {
    if (numTasks < MAX_TASKS) {
        strcpy(tasks[numTasks].description, description);
        tasks[numTasks].completed = 0;
        numTasks++;
    } else {
        printf("Cannot add more tasks. Task list is full.\n");
    }
}

void viewTasks() {
    char ch;

    printf("Tasks:\n");
    for (int i = 0; i < numTasks; i++) {
        printf("%d. %s - %s\n", i + 1, tasks[i].description, tasks[i].completed ? "Completed" : "Not completed");
    }

    printf("Press a key to go back to the main menu");
    ch = _getch();
}

void completeTask(){

    int choice;
    char ch;

    printf("Tasks:\n");
    for (int i = 0; i < numTasks; i++) {
        printf("%d. %s\n", i + 1, tasks[i].description);
    }
    printf("Which task have you completed?");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= numTasks) {

        int index = choice - 1;

        tasks[index].completed = 1; // Assuming 1 indicates completed, and 0 indicates not completed

        printf("Task \"%s\" marked as completed.\n", tasks[index].description);

        printf("Press a key to go back to the main menu");
        ch = _getch();
    } else {
        printf("Invalid task number. Please enter a valid task number.\n");
    }


}

int main() {
    char description[MAX_LENGTH];
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Complete Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task description: ");
                scanf(" %[^\n]", description);
                addTask(description);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                completeTask();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}