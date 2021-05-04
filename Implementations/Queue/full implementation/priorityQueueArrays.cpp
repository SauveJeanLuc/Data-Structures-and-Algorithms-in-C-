/* 
 * C++ Program to Implement Priority Queue using arrays
 */
#include <iostream>
using namespace std;
 
#define MAX 5
 
void insert_by_priority(int);
void delete_by_priority(int);
void create();
void check(int);
void display_pqueue();
 
int priority_queue[MAX];
int front, rear;
 
int main()
{
    int dataFromUser, choice;
 
 	cout << endl;
    cout << "1 - Insert an element into queue"<<endl;
    cout << "2 - Delete an element from queue"<<endl;
    cout << "3 - Display queue elements"<<endl;
    cout << "4 - Exit";
 
    create();
 
    while (1)
    {
        cout <<endl << "Enter your choice : " ;    
        cin >> choice;
 
        switch (choice)
        {
        case 1: 
            cout <<endl << "Enter value to be inserted : ";
            cin >> dataFromUser;
            insert_by_priority(dataFromUser);
            break;
        case 2:
            cout <<endl << "Enter value to delete : ";
            cin >> dataFromUser;
            delete_by_priority(dataFromUser);
            break;
        case 3: 
            display_pqueue();
            break;
        case 4: 
            exit(0);
        default: 
            printf("\nChoice is incorrect, Enter a correct choice");
        }
    }
}
 
/* Function to create an empty priority queue */
void create()
{
    front = rear = -1;
}
 
/* Function to insert value into priority queue */
void insert_by_priority(int data)
{
    if (rear >= MAX - 1)
    {
        cout <<endl << "Queue overflow no more elements can be inserted" ;
        return;
    }
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        priority_queue[rear] = data;
        return;
    }    
    else
        check(data);
    rear++;
}
 
/* Function to check priority and place element */
void check(int data)
{
    int i,j;
 
    for (i = 0; i <= rear; i++)
    {
        if (data >= priority_queue[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                priority_queue[j] = priority_queue[j - 1];
            }
            priority_queue[i] = data;
            return;
        }
    }
    priority_queue[i] = data;
}
 
/* Function to delete an element from queue */
void delete_by_priority(int data)
{
    int i;
 
    if ((front==-1) && (rear==-1))
    {
        cout << "Queue is empty no elements to delete";
        return;
    }
 
    for (i = 0; i <= rear; i++)
    {
        if (data == priority_queue[i])
        {
            for (; i < rear; i++)
            {
                priority_queue[i] = priority_queue[i + 1];
            }
 
        priority_queue[i] = -99;
        rear--;
 
        if (rear == -1) 
            front = -1;
        return;
        }
    }
    
    cout <<endl << data <<"not found in queue to delete";
}
 
/* Function to display queue elements */
void display_pqueue()
{
    if ((front == -1) && (rear == -1))
    {
        cout <<endl << "Queue is empty";
        return;
    }
 
    for (; front <= rear; front++)
    {
        cout <<priority_queue[front];
    }
 
    front = 0;
}
