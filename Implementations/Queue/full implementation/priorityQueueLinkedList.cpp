#include <iostream>
using namespace std;
 
struct Node
{
    int data;
 
    // Lower values illustartes higher priority
    int priority;
 
    struct Node* next;
 
};
 

Node* newNode(int d, int p)
{
    Node* temp = new Node;
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;
 
    return temp;
}
 
// Returns the value found at head
int peek(Node** head)
{
    return (*head)->data;
}
 
// Removes the element with the highest priority form the list
void pop(Node** head)
{
    Node* temp = *head;
    (*head) = (*head)->next;
    delete(temp);
}
 
// Function to push according to priority
void push(Node** head, int d, int p)
{
    Node* start = (*head);
 
    // Create new Node
    Node* temp = newNode(d, p);
 
    // Special Case: The head of list has
    // lesser priority than new node. So
    // insert newnode before head node
    // and change head node.
    if ((*head)->priority > p)
    {
         
        // Insert New Node before head
        temp->next = *head;
        (*head) = temp;
    }
    else
    {
         
        // Traverse the list and find a
        // position to insert new node
        while (start->next != NULL &&
            start->next->priority < p)
        {
            start = start->next;
        }
 
        // Either at the ends of the list
        // or at required position
        temp->next = start->next;
        start->next = temp;
    }
}
 
// Function to check is list is empty
int isEmpty(Node** head)
{
    return (*head) == NULL;
}

void display(Node* head){

        while (head != NULL)
        {
        	cout << " "<< peek(&head);
            head = head->next;
        }

}
 
// Driver code
int main()
{
 	int choice, dataFromUser, priority;
 	cout << endl;
    cout << "1 - Insert an element into queue"<<endl;
    cout << "2 - Delete an element from queue"<<endl;
    cout << "3 - Display queue elements"<<endl;
    cout << "4 - Exit";
 
 	Node *pq = NULL;
 	
    while (1)
    {
        cout <<endl << "Enter your choice : " ;    
        cin >> choice;
 
        switch (choice)
        {
        case 1: 
            cout <<endl << "Enter value to be inserted : ";
            cin >> dataFromUser;
            cout <<endl << "Enter value for priority : ";
            cin >> priority;
            if(isEmpty(&pq)){
              	pq = newNode(dataFromUser, priority);
			}
			else{
              push(&pq, dataFromUser, priority);				
			}

            break;
        case 2:
            cout <<endl << "Enter value to delete : ";
			pop(&pq);
            break;
        case 3: 
			display(pq);
            break;
        case 4: 
            exit(0);
            break;
        default: 
            cout <<"Choice is incorrect, Enter a correct choice";
        }
    }


    return 0;
}
