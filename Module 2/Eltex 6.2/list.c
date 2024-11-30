#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>


Node* createNode(Person person){
    Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->person = person;
    newNode->prev = NULL;
    newNode->next = NULL;
    printf("HELLO");
    return newNode;
}

void insert(Node** head, Person person){
    Node* newNode = createNode(person);
    if (*head == NULL){
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current != NULL && current->person.id < person.id){
        current = current->next;
    }
    if (current == *head){
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    } else if (current == NULL){
        Node* last = *head;
        while (last->next != NULL){
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
    } else {
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }
}


void removeNode(Node** head){
    int id;
    Node* current = *head;
    printf("Enter ID to delete person: ");
    scanf("%d", &id);
    while (current != NULL && current->person.id != id){
        current = current->next;
    }
    if (current == NULL){
        return;
    }
    if (current == *head){
        *head = current->next;
        if (*head != NULL) (*head)->prev = NULL;
    } else {
        if (current->next != NULL){
            current->next->prev = current->prev;
        }
        if (current->prev != NULL){
            current->prev->next = current->next;
        }
    }
    free(current);
}