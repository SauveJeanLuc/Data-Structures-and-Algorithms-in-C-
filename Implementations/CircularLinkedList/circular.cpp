#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
} *head = NULL;

void createCLL(int A[], int size){
    head = new Node;
    head->data = A[0];

    head->next = head;

    Node *t, *last;
    last = head;
    
    for(int i =1; i < size; i++){
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void insert_at_head(int value){

        Node *t = new Node;
        t->data = value;
        t->next = head;

        Node * p = head;

        while(p->next!=head){
            p = p->next;
        }

        p->next = t;
        head = t;
}

void insert_at_end(int value){

        Node *t = new Node;
        t->data = value;
        t->next = head;

        Node * p = head;

        while(p->next!=head){
            p = p->next;
        }

        p->next = t;
      
}

void delete_from_head(){

    Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = head->next;
    delete head;
    head = p->next;
    
}
void display(struct Node *hd){
    do{
            cout << hd->data << "\t";
            hd = hd ->next;
    }while (hd!=head);
}
int main(){

    int A[] = {30, 20, 40, 40, 50};
    createCLL(A,5);
    cout << "All Data: " << endl;
    display(head);
    insert_at_head(500);
    cout <<"ALL DATA After Inserting"<<endl;
    display(head);
    delete_from_head();
    cout <<"ALL DATA After Deleting"<<endl;
    display(head);
}