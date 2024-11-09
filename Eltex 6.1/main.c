#include "Person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    Node* head = NULL;
    int choice;
    do {
        printf("\n1. Add Person\n2. Delete Person\n3. Edit Person\n4. List Persons\n5. Exit\nChoose an option: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                Person person = addPerson();
                insert(&head,person);
                break;
            case 2:
                removeNode(&head);
                break;
            case 3:
                editPerson(head);
                break;
            case 4:
                printNode(head);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (choice != 5);

    return 0;
}
