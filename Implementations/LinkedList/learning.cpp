#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
}*first = NULL;

void create(int A[], int n) {

    struct Node *last;
    first = new Node;

    first->data = A[0];
    first->next = NULL;
    last = first;

    Node *t;

    for(int i = 1; i<n; i++){
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }

}

void display(Node * pFirst){

    while(pFirst!=NULL){
        cout << "Data: " << pFirst->data <<endl;
        pFirst = pFirst->next;
    }
}
int main(){

    int years[] = {
        2000,
        2002,
        2003,
        2007
    };

    Node *first;

    create(years,4);
    display(::first);

}