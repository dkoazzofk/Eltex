#include "Person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void printNode(Node* head){
    Node* current = head;
    while (current != NULL){
        printf("ID: %d\nName: %s\nSurname: %s\nPhone: %s\nEmail: %s\nSocial Network: %s\n\n",
        current->person.id, current->person.name, current->person.surname, 
        current->person.phone, current->person.email, current->person.socialnetwork);
        current = current->next;
    }
}

Person addPerson() {
    Person person;
    printf("Enter ID: ");
    scanf("%d", &person.id);
    printf("Enter Name: ");
    scanf("%s", &person.name);
    printf("Enter Surname: ");
    scanf("%s", &person.surname);
    printf("Enter Phone: ");
    scanf("%s", &person.phone);
    printf("Enter Email: ");
    scanf("%s", &person.email);
    printf("Enter Social Network: ");
    scanf("%s", &person.socialnetwork);
    
    printf("Person added.\n");
    return person;
}

void editPerson(Node* head){
    int id;
    printf("Put ID to change: ");
    scanf("%d", &id);
    Node* current = head;
    while (current != NULL && current->person.id != id){
        current = current->next;
    }
    if (current == NULL){
        printf("Person not found");
    }
    printf("Editing person: %s %s", current->person.name, current->person.surname);

    char input[MAX_LENGHT];
    printf("Enter new phone (if needed): ");
    getchar();
    fgets(input, MAX_LENGHT, stdin);
    if (input[0] != '\n') {
        strncpy(current->person.phone, input, MAX_LENGHT);
        current->person.phone[strcspn(current->person.phone, "\n")] = '\0';
    }

    printf("Enter new email (if needed): ");
    fgets(input, MAX_LENGHT, stdin);
    if (input[0] != '\n') {
        strncpy(current->person.email, input, MAX_LENGHT);
        current->person.email[strcspn(current->person.email, "\n")] = '\0';
    }

    printf("Enter new social network (if needed): ");
    fgets(input, MAX_LENGHT, stdin);
    if (input[0] != '\n') {
        strncpy(current->person.socialnetwork, input, MAX_LENGHT);
        current->person.socialnetwork[strcspn(current->person.socialnetwork, "\n")] = '\0';
    }

    printf("Person updated.\n");
}