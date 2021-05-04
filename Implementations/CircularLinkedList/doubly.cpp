#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}*head=NULL;
void createDLL(int A[],int size){
    head=new Node;
    head->data=A[0];
    head->prev=head->next=NULL;
    Node *t, *last;
    last=head;
    int i;
    for(i=1;i<size;i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        t->prev = last->next;
        last->next=t;
        last=t;
    }
}
void display(struct Node *hd){
    do{
        cout<<hd->data<<"\t";
        hd=hd->next;
    }while(hd);
}
void insertAtHead(int value){
    Node *t=new Node;
    t->data=value;
    t->next=head;
    t->prev=NULL;
    head->prev = t;
    head=t;
}

void insertAfterAGivenNode(int key, int data){
        Node *t = new Node;
        t->data = data;
        Node *p = new Node;
        p = head;

        while (p->data!=key)
        {
            p = p->next;   
        }

        t->next = p->next;
        t->prev = p;
        p->next->prev = t;
        p->next = t;
    
}

void insertAtEnd(int value){
    Node *t = new Node;
    t->data = value;
    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = t;
    t->prev = p;
    t->next = NULL;
    
}
int main(){
    int A[] = {30, 20, 50, 60,0};
    createDLL(A,5);
    cout<<"All data : " ;
    display(head);
    cout<<endl;
    insertAtHead(5);
    cout<<"all data after inserting at head: ";
    display(head);
    insertAtEnd(5675);
    cout<<endl;
    cout<<"all data after inserting at End: ";
    display(head);
    cout<<endl;
    insertAfterAGivenNode(30,4000);
    cout<<"all data after inserting at a given node: ";
    display(head);
    
    cout<<endl;
    return 0;
}