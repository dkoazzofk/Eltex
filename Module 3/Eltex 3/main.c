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

void saveToFile(person *user){
    const char *filename = "person.txt";
    int fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1){
        perror("Cant open file.\n");
        return;
    }
    write(fd, &userCount, sizeof(int));
    write(fd, user, sizeof(person) * userCount);
    close(fd);
    printf("User saved.\n");
}

void loadFromFile(person *user){
    int fd = open("person.txt",O_RDONLY);
    if (fd == -1){
        perror("Error opening file.\n");
        return;
    }
    read(fd, &userCount, sizeof(int));
    read(fd, user, sizeof(person) * userCount);
    close(fd);
    printf("Data loaded from file.\n");
}

void addPerson(person *user) {
    getchar();
    char buffer[MAX_LENGHT];
    printf("----------------------------------\n");
    printf("Enter which id you want: ");
    read(STDIN_FILENO, buffer, MAX_LENGHT);
    user[userCount].id = atoi(buffer);

    printf("Enter your name: ");
    read(STDIN_FILENO, user[userCount].name, MAX_LENGHT);
    user[userCount].name[strcspn(user[userCount].name, "\n")] = '\0';

    printf("Enter your surname: ");
    read(STDIN_FILENO, user[userCount].surname, MAX_LENGHT);
    user[userCount].surname[strcspn(user[userCount].surname, "\n")] = '\0';

    userCount++;
    printf("User was added.\n");
    printf("----------------------------------\n");
}

void trashDestroyer(person *user){
    memset(user, 0, sizeof(person) * MAX_LENGHT);
    for(int i = 0; i < MAX_LENGHT; i++){
        user[i].name[0] = '\0';
        user[i].name[0] = '\0';
        user[i].surname[0] = '\0';
    }
}

int main(){
    int expression;
    person people[MAX_LENGHT];
    trashDestroyer(people);
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
