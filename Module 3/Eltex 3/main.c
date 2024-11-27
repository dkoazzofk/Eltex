#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LENGHT_STRUCT 2
#define MAX_LENGHT 30

typedef struct Person{
    int id;
    char name[MAX_LENGHT];
    char surname[MAX_LENGHT];
}person;

int userCount = 0;

void loadFromFile(person *user) {
    FILE *file = fopen("phonebook.txt", "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    userCount = 0;
    while (fscanf(file, "%d|%29[^|]|%29[^\n]\n",
                  &user[userCount].id,
                  user[userCount].name,
                  user[userCount].surname) == 3) {
        userCount++;
        if (userCount >= MAX_LENGHT_STRUCT)
            break;
    }

    fclose(file);
    printf("Data loaded from file.\n");
}


void saveToFile(person *user) {
    int fd = open("phonebook.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Failed to open file for saving");
        return;
    }

    for (int i = 0; i < userCount; i++) {
        char data[MAX_LENGHT * 3];
        snprintf(data, sizeof(data), "%d|%s|%s\n",
                user[i].id,
                user[i].name,
                user[i].surname);

        ssize_t bytes_written = write(fd, data, strlen(data));
        if (bytes_written < 0) {
            perror("Failed to write to file");
            close(fd);
            return;
        }
    }
    close(fd);
    printf("Data saved to file.\n");
}


void addPerson(person *user) {
    char buffer[MAX_LENGHT];
    getchar();
    printf("----------------------------------\n");

    printf("Enter which id you want: ");
    fgets(buffer, MAX_LENGHT, stdin);
    user[userCount].id = atoi(buffer);

    printf("Enter your name: ");
    fgets(user[userCount].name, MAX_LENGHT, stdin);
    user[userCount].name[strcspn(user[userCount].name, "\n")] = '\0';

    printf("Enter your surname: ");
    fgets(user[userCount].surname, MAX_LENGHT, stdin);
    user[userCount].surname[strcspn(user[userCount].surname, "\n")] = '\0';

    userCount++;
    printf("User was added.\n");
    printf("----------------------------------\n");
}


void trashDestroyer(person *user) {
    memset(user, 0, sizeof(person) * MAX_LENGHT_STRUCT);
    for (int i = 0; i < MAX_LENGHT_STRUCT; i++) {
        user[i].name[0] = '\0';
        user[i].surname[0] = '\0';
    }
}


int main(){
    int expression;
    person people[MAX_LENGHT];
    //trashDestroyer(people);
    loadFromFile(people);
    do
    {
        printf("-----Main Menu-----\n");
        printf("1. Add Person.\n");
        printf("2. Save to File.\n");
        printf("5. Exit.\n");
        printf("Choose an option.\n");
        scanf("%d",&expression);
        switch (expression)
        {
        case 1:
            addPerson(people);
            break;
        case 2:
            saveToFile(people);
            break;
        case 5:
            return 0;
        }
    } while (expression != 5);
    return 0;
}