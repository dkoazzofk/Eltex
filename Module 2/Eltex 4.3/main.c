#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGHT 30

typedef struct Person {
    int id;
    char name[MAX_LENGHT];
    char surname[MAX_LENGHT];
    char phone[MAX_LENGHT];
    char email[MAX_LENGHT];
    char socialnetwork[MAX_LENGHT];
} Person;

typedef struct Node {
    Person person;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(Person person) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->person = person;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, Person person) {
    if (root == NULL) {
        return createNode(person);
    }
    if (person.id < root->person.id) {
        root->left = insert(root->left, person);
    } else if (person.id > root->person.id) {
        root->right = insert(root->right, person);
    }
    return root;
}

Node* search(Node* root, int id) {
    if (root == NULL || root->person.id == id) {
        return root;
    }
    if (id < root->person.id) {
        return search(root->left, id);
    }
    return search(root->right, id);
}

void postOrderTravel(Node* root) {
    if (root != NULL) {
        postOrderTravel(root->left); 
        postOrderTravel(root->right);
        printf("ID: %d\nName: %s\nSurname: %s\nPhone: %s\nEmail: %s\nSocial Network: %s\n\n",
        root->person.id, root->person.name, root->person.surname, root->person.phone, root->person.email, root->person.socialnetwork);
    }
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int id) {
    if (root == NULL) {
        return root;
    }
    if (id < root->person.id) {
        root->left = deleteNode(root->left, id);
    } else if (id > root->person.id) {
        root->right = deleteNode(root->right, id);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->person = temp->person;
        root->right = deleteNode(root->right, temp->person.id);
    }
    return root;
}

void addPerson(Node** root) {
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
    
    *root = insert(*root, person);
    printf("Person added.\n");
}

void deletePerson(Node** root) {
    int id;
    printf("Enter ID of person to delete: ");
    scanf("%d", &id);
    *root = deleteNode(*root, id);
    printf("Person deleted.\n");
}

void editPerson(Node* root) {
    int id;
    printf("Enter ID of person to edit: ");
    scanf("%d", &id);
    Node* node = search(root, id);
    if (node == NULL) {
        printf("Person not found.\n");
        return;
    }
    printf("Editing person: %s %s\n", node->person.name, node->person.surname);

    printf("Enter new phone (if needed): ");
    char input[MAX_LENGHT];
    getchar();
    fgets(input, MAX_LENGHT, stdin);
    if (input[0] != '\n') {
        strncpy(node->person.phone, input, MAX_LENGHT);
        node->person.phone[strcspn(node->person.phone, "\n")] = '\0';
    }

    printf("Enter new email (if needed): ");
    fgets(input, MAX_LENGHT, stdin);
    if (input[0] != '\n') {
        strncpy(node->person.email, input, MAX_LENGHT);
        node->person.email[strcspn(node->person.email, "\n")] = '\0';
    }

    printf("Enter new social network (if needed): ");
    fgets(input, MAX_LENGHT, stdin);
    if (input[0] != '\n') {
        strncpy(node->person.socialnetwork, input, MAX_LENGHT);
        node->person.socialnetwork[strcspn(node->person.socialnetwork, "\n")] = '\0';
    }

    printf("Person updated.\n");
}

void listPersons(Node* root) {
    if (root == NULL) {
        printf("No contacts found.\n");
    } else {
        printf("Contacts:\n");
        postOrderTravel(root);
    }
}

int main() {
    Node* root = NULL;
    int choice;
    do {
        printf("\n1. Add Person\n2. Delete Person\n3. Edit Person\n4. List Persons\n5. Exit\nChoose an option: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                addPerson(&root);
                break;
            case 2:
                deletePerson(&root);
                break;
            case 3:
                editPerson(root);
                break;
            case 4:
                listPersons(root);
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
