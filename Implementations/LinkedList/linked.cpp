#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};
struct Node* first = NULL;

void Create(int A[], int n){

    struct Node * last;

    first = (struct Node*) malloc (sizeof(struct Node));
    
}