// C++ implementation of Dequeque using doubly linked list
#include <iostream>
using namespace std;
 

struct Node {
    int data;
    struct Node* next,*prev;
};
  

struct Dequeque {
    struct Node *front, *rear;
    int size;
};
  
// function to Check whether the Dequeque is empty or not
bool isEmpty(Dequeque* q)
{
    return (q->rear == NULL);
}
 
 
//function to insert at the front of Dequeque


void insertFront(Dequeque* q,int data)
{
    Node* newNode = new Node;
    newNode -> data = data;
    newNode -> next = NULL;
    
    if (newNode == NULL)
        cout << "OverFlow\n";
    else
    {
          if (q->front == NULL)
              q->front = q->rear = newNode;
 
        else
        {
            newNode->next = q->front;
            q->front->prev = newNode;
            q->front = newNode;
        }
 
       q-> size++;
    }
}
 


//Function to insert at the rear of Dequeque

void insertRear(Dequeque* q,int data)
{
    Node* newNode = new Node;
    newNode -> data = data;
    newNode -> next = NULL;

    if (newNode == NULL)
        cout << "OverFlow\n";
    else
    {
        // If dequeque is empty
        if (q->rear == NULL)
            q->front =q -> rear = newNode;

        // Inserts node at the rear end
        else
        {
            newNode->prev =q-> rear;
            q->rear->next = newNode;
            q-> rear = newNode;
        }
 
        q->size++;
    }
}



void deleteFront(Dequeque* q)
{

    if (isEmpty(q))
        cout << "UnderFlow\n";

    else
    {
        Node* temp = q->front;
        q->front = q->front->next;
 
        if (q->front == NULL)
            q->rear = NULL;
       
       q-> size--;
    }
}
 



void deleteRear(Dequeque* q)
{
    
    if (isEmpty(q))
        cout << "UnderFlow\n";
    else
    {
        Node* temp =  q->rear;
         q->rear = q->rear->prev;
 
        if ( q->rear == NULL)
             q->front = NULL;
        delete(temp);
 
        q->size--;
    }
}
 
 


int getFront(Dequeque* q)
{

    if (isEmpty(q))
        return -1;
    return q->front->data;
}
 


int getRear(Dequeque* q)
{

    if (isEmpty(q))
        return -1;
    return q->rear->data;
}
 

void display(Dequeque* q)
{
	cout<< "\n\t\t\t display elements : ";
	while(q->front != NULL)
	{
		cout<<q->front->data<<" ";
		q->front = q->front->next;	
	}
}


int main()
{
        Dequeque* q = new Dequeque;
        q->front = q->rear = NULL;

  int choice,item;
  
    do
    {
        
        cout<<endl<<" 1. Insert at beginning";
        cout<<endl<<" 2. Insert at end";
        cout<<endl<<" 3. Display";
        cout<<endl<<" 4. Get Front";
        cout<<endl<<" 5. Get Rear";
        cout<<endl<<" 6. Deletion from front";
        cout<<endl<<" 7. Deletion from rear";
        cout<<endl<<" 8 Exit";
        cout<<endl<<" Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"enter the element to be inserted: ";
                          cin>>item;
                          insertFront(q,item);
                          break;
            case 2:
            cout<<"enter the element to be inserted: ";
                         cin>>item;
                          insertRear(q,item);
                        break;
            case 3:
            cout <<endl<<"Elements\t\t\t: ";
			        display(q);
                        break;
            case 4:
            cout <<endl<<"Front Element\t\t\t: ";
			        cout <<"\n\t\t\t"<<  getFront(q);
                        break;
                       case 5:cout <<"\nRear Element\t\t\t: ";
			       cout<<"\n\t\t\t"<< getRear(q);
                        break;
                        
            case 6:
            cout <<endl<<"Delete at the front: \t\t\t: "; deleteFront(q);
                        break;
            case 7:
            cout <<endl<<"\tDelete at the rear: \t\t\t: "; deleteRear(q);
                      break;
            case 8:
            exit(1);
                        break;
            csdefault:cout<<"invalid choice";
                    break;
        }
    }
    while(choice!=7);
    
    return 0;
}

