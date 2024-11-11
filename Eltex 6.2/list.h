#ifndef list_h
#define list_h
#define MAX_LENGHT 30

#include "Person.h"




Node* createNode(Person person);
void insert(Node** head, Person person);
void removeNode(Node** head);


#endif