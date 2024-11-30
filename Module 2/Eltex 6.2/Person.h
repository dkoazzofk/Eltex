#ifndef Person_h
#define Person_h
#define MAX_LENGHT 30

typedef struct Person{
    int id;
    char name[MAX_LENGHT];
    char surname[MAX_LENGHT];
    char phone[MAX_LENGHT];
    char email[MAX_LENGHT];
    char socialnetwork[MAX_LENGHT];
}Person;

typedef struct Node{
    struct Person person;
    struct Node* prev;
    struct Node* next;
}Node;

Node* createNode(Person person);
void insert(Node** head, Person person);
void removeNode(Node** head);
void printNode(Node* head);
Person addPerson();
void editPerson(Node* head);

#endif