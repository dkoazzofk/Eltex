#include <stdio.h>
#include <string.h>
#define MAX_LENGHT_STRUCT 2
#define MAX_LENGHT 30

typedef struct Person{
    int id;
    char name[MAX_LENGHT];
    char surname[MAX_LENGHT];
    char phone[MAX_LENGHT];
    char email[MAX_LENGHT];
    char socialnetwork[MAX_LENGHT];
}person;

int userCount = 0;


void addPerson(person *user){
    printf("----------------------------------\n");
    printf("Enter your name: ");
    scanf("%s",user[userCount].name);
    printf("Enter your surname: ");
    scanf("%s",user[userCount].surname);
    printf("Enter your phone: ");
    scanf("%s",user[userCount].phone);
    printf("Enter your email: ");
    scanf("%s",user[userCount].email);
    printf("Enter your socialnetwork: ");
    scanf("%s",user[userCount].socialnetwork);

    userCount++;
    printf("User was added.\n");
    printf("----------------------------------\n");
}

void delete(person people[]){
    char input[MAX_LENGHT];
    printf("Enter surname which person you want to delete: \n");
    scanf("%s", &input);
    for(int i = 0; i<userCount;i++){
        if(strcmp(people[i].surname, input) == 0){
            strcpy(people[i].name, "");
            strcpy(people[i].surname, "");
            strcpy(people[i].phone, "");
            strcpy(people[i].email, "");
            strcpy(people[i].socialnetwork, "");

            for (int j = i; j < userCount - 1; j++) {
                people[j] = people[j + 1];
            }
            userCount--;
            printf("User deleted.\n");
        }
    }
}

void editPerson(person people[]){
    char lastName[MAX_LENGHT];
    printf("Put surname: ");
    scanf("%s", lastName);
    getchar();
        for(int i = 0; i < MAX_LENGHT; i++){
        if(strcmp(people[i].surname, lastName) == 0){
            printf("Editing person: %s %s \n", people[i].name, people[i].surname);
            printf("Enter new phone(if needed): \n");
            getchar();
            char input[MAX_LENGHT];
            fgets(input, MAX_LENGHT, stdin);
            if(input[0] != '\n'){
                strncpy(people[i].phone, input, MAX_LENGHT);
                people[i].phone[strcspn(people[i].phone, "\n")] = '\0';
            }
            
            printf("Enter new email(if needed): \n");
            fgets(input, MAX_LENGHT, stdin);
            if (input[0] != '\n') {
                strncpy(people[i].email, input, MAX_LENGHT);
                people[i].email[strcspn(people[i].email, "\n")] = '\0';
            }
            
            printf("Enter new socialnetwork(if needed): \n");
            fgets(input, MAX_LENGHT, stdin);
            if(input[0] != '\n'){
                strncpy(people[i].socialnetwork, input, MAX_LENGHT);
                people[i].socialnetwork[strcspn(people[i].socialnetwork, "\n")] = '\0';
            }
            
            printf("Person updated.\n ");
        }
    }
}

void trashDestroyer(person people[]){
    memset(people, 0, sizeof(person) * MAX_LENGHT);
    for(int i = 0; i < MAX_LENGHT; i++){
        people[i].name[0] = '\0';
        people[i].name[0] = '\0';
        people[i].surname[0] = '\0';
        people[i].phone[0] = '\0';
        people[i].socialnetwork[0] = '\0';
        people[i].email[0] = '\0';
    }
}

void listPerson(person people[]){

    for (int i = 0; i < userCount; i++) {
        printf("\nContact %d:\n", i + 1);
        printf("First Name: %s\n", people[i].name);
        printf("Last Name: %s\n", people[i].surname);
        printf("Phone: %s\n", people[i].phone);
        printf("Email: %s\n", people[i].email);
        printf("Social Network: %s\n", people[i].socialnetwork);
    }
}

int main(){
    int expression;
    person people[MAX_LENGHT];
    trashDestroyer(people);
    do
    {
        printf("-----Main Menu-----\n");
        printf("1. Add Person.\n");
        printf("2. Delete Person.\n");
        printf("3. Edit Person.\n");
        printf("4. List Person.\n");
        printf("5. Exit.\n");
        printf("Choose an option.\n");
        scanf("%d",&expression);
        switch (expression)
        {
        case 1:
            addPerson(people);
            break;
        case 2:
            delete(people);
            break;
        case 3:
            editPerson(people);
            break;
        case 4:
            listPerson(people);
            break;
        case 5:
            return 0;
        }
    } while (expression != 5);
    return 0;
}