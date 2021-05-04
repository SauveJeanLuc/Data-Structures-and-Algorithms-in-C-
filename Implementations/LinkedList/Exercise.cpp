#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
}*first = NULL;

void insertAtBeginning(int data){
    Node * newNode = new Node;
    newNode->data = data;
    newNode->next = first;
    first = newNode;
}

void insertToEnd(int data){
    Node * newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    Node * temp = first;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    
}

void insertInMiddle(int data){
    int position;
    cout << "Position: ";
    cin >> position;

    Node * newNode = new Node;
    newNode->data = data;

    Node * temp = first;

    for(int i=2; i<position; i++){
        if(temp->next != NULL){
            temp = temp->next;
        }
    }

    newNode->next = temp->next;
    temp->next = newNode;
}
void insert() {

    cout << "==========SINGLY LINKED LISTS==========" <<endl;
    cout << "||1. Insert at beginning             ||" <<endl;
    cout << "||2. Insert to the end               ||" <<endl;
    cout << "||3. Insert in the middle            ||" <<endl;
    cout << "=======================================" <<endl;


    int choice, data;

    cout << "Choice: ";
    cin >> choice;
    cout << "Enter your Data:";
    cin >> data;


    switch (choice)
    {
    case 1:
        insertAtBeginning(data);
        break;
    case 2:
        insertToEnd(data);
        break;
    case 3:
        insertInMiddle(data);
        break;
    default:
        break;
    }

}


void traverse(){
    Node * temp = first;
    while(temp!=NULL){
        cout << "Data: " << temp->data <<endl;
        temp = temp->next;
    }
}

void deleteFromBeginning(){
    first = first->next;
}

void deleteFromEnd(){
    Node * temp = first;
    while (temp->next->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

void deleteFromMiddle(){
    Node * temp = first;
    int position;

    cout << "Position: ";
    cin >> position;
    for(int i=2; i<position; i++){
        if(temp->next!=NULL){
            temp = temp->next;
        }
    }
}
void deleteNode(){

    cout << "==========SINGLY LINKED LISTS==========" <<endl;
    cout << "||1. Delete from beginning           ||" <<endl;
    cout << "||2. Delete from end                 ||" <<endl;
    cout << "||3. Delete from middle              ||" <<endl;
    cout << "=======================================" <<endl;

    int choice, data;

    cout << "Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        deleteFromBeginning();
        break;
    case 2:
        deleteFromEnd();
        break;
    case 3:
        deleteFromMiddle();
        break;
    default:
        break;
    }

}

Node * search(){

    int key;

    cout << "key: ";
    cin >> key;

    Node * current = first;

    while (current != NULL)
    {
        if(current->data == key){
            return current;
        }
            current = current->next;
    }
    return NULL;
}

Node * swap (Node * ptr1, Node  * ptr2){
    Node * tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

void sort(){
    Node ** head = &first;

    //Counting list size
    int count, swapped;
        while(first!=NULL){
            count++;
            first = first->next;
        }
    
    Node **h;

    for(int i=0; i <= count; i++){
            h = head;
            swapped = 0;

            for(int j = 0; j < count - i -1; j++){

                Node * p1 = *h;
                Node * p2 = p1->next;

                if(p1->data > p2->data)
                {
                    /*Update the link after swapping*/

                    *h = swap(p1,p2);
                    swapped = 1;
                }
                h = &(*h)->next;
            }

            if(swapped == 0)
                break;
    }
}

int main(){

  insert: cout << "==========SINGLY LINKED LISTS==========" <<endl;
    cout << "||1. Insert a new node               ||" <<endl;
    cout << "||2. Traverse the List               ||" <<endl;
    cout << "||3. Search for a node               ||" <<endl;
    cout << "||4. Delete a node                   ||" <<endl;
    cout << "||5. Concatinate two linked lists    || " <<endl;
    cout << "||6. Sort a list                     ||" <<endl;
    cout << "||7. Reverse a linked List           ||" <<endl;
    cout << "========================================" <<endl;

    int choice;
    cout << "Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        insert();
        goto insert;
        break;
    
    case 2:
        traverse();
        goto insert;
        break;

    case 3:
        search();
        goto insert;
        break;

    case 4:
        deleteNode();
        goto insert;
        break;

    case 5:
        insert();
        goto insert;
        break;

    case 6:
        sort();
        goto insert;
        break;

    case 7:
        insert();
        goto insert;
        break;

    default:
            cout << "==========SINGLY LINKED LISTS==========" <<endl;
            cout << "||                                   ||" <<endl;
            cout << "||Invalid Input :(, Please try again ||" <<endl;
            cout << "||                                   ||" <<endl;
            cout << "=======================================" <<endl;
            goto insert;
        break;
    }
}