// C++ implementation of Deque using
// doubly linked list
#include <iostream>

 
using namespace std;
 

  
struct Node {
    int data;
    struct Node* next,*prev;
};
  

struct Deque {
    struct Node *front, *rear;
    int Size;
};
  
//Check if the Deque is empty
bool isEmpty(Deque* q)
{
    return (q->rear == NULL);
}
 
 
//Function to insert at the front of Deque
/*
                   STEPS:
                   1. FIRST ALLOCATE THE MEMORY AND INSERT THE DATA IN THE NEW NODE.
                   2. CHECK THE OVERFLOW , IF THE ALLOCATED MEMORY STILL NULL.
                   3. CHECK IF THE FRONT IS NULL MEANING NO ELEMENTS ARLEADY THERE.
                   4. IF NULL MAKE THE NEW NODE TO BE THE FIRST ONE. JUST TURN THE DEQUE -> FRONT POINTER TO POINT TO THE NEWLY CREATED NODE.
                   5. IF NOT NULL LET THE NEW NODE -> NEXT POINT TO THE EXISTING FRONT , THEN LET THE FRONT -> PREV POINT TO THE NEW NODE AND THEN MAKE THE FRONT TO BE THE NEW NODE.
                   6. DONE ....

*/

void insertFront(Deque* q,int data)
{
    Node* newNode = new Node;
    newNode -> data = data;
    newNode -> next = NULL;
    // If true then new element cannot be added
    // and it is an 'Overflow' condition
    if (newNode == NULL)
        cout << "OverFlow\n";
    else
    {
        // If deque is empty
          if (q->front == NULL)
              q->front = q->rear = newNode;
 
        // Inserts node at the front end
        else
        {
            newNode->next = q->front;
            q->front->prev = newNode;
            q->front = newNode;
        }
 
        // Increments count of elements by 1
       q-> Size++;
    }
}
 


//Function to insert at the REAR of Deque
/*
                   STEPS:
                   1. ALLOCATE THE SPACE FOR THE NEW NODE
                   2. CHECK THE OVERFLOW , IF THE ALLOCATED MEMORY STILL NULL.
                   3. CHECK IF THE REAR IS NULL MEANING NO ELEMENTS ARLEADY THERE.
                   4. IF NULL MAKE THE NEW NODE TO BE THE FIRST ONE. JUST TURN THE DEQUE -> FRONT AND DEQUEU-> REAR POINTER TO POINT TO THE NEWLY CREATED NODE.
                   5. IF NOT NULL LET THE NEW NODE -> PREV POINT TO THE EXISTING REAR , THEN LET THE REAR -> NEXT POINT TO THE NEW NODE AND THEN MAKE THE FRONT TO BE THE NEW NODE.
                   6. DONE ....

*/


void insertRear(Deque* q,int data)
{
    Node* newNode = new Node;
    newNode -> data = data;
    newNode -> next = NULL;
    // If true then new element cannot be added
    // and it is an 'Overflow' condition
    if (newNode == NULL)
        cout << "OverFlow\n";
    else
    {
        // If deque is empty
        if (q->rear == NULL)
            q->front =q -> rear = newNode;

        // Inserts node at the rear end
        else
        {
            newNode->prev =q-> rear;
            q->rear->next = newNode;
            q-> rear = newNode;
        }
 
        q->Size++;
    }
}


//Function to DELETE at the FRONT of Deque
/*
                   STEPS:
                   1. CHECK THE UNDERFLOW , if the DQUEU -> FRON IS NULL .
                   2. LET THE DEQUEU -> FRONT POINT TO THE NEXT ELEMENT
                   3. IF THE WAS THE LAST , LET ALSO THE REAR POINT TO NULL , BECAUSE IT WAS STILL POINTING TO THE LAST ELEMENT.
                   4. DONE ....

*/



void deleteFront(Deque* q)
{

    // 'Underflow' condition
    if (isEmpty(q))
        cout << "UnderFlow\n";

    else
    {
        Node* temp = q->front;
        q->front = q->front->next;
 
        // If only one element was present
        if (q->front == NULL)
            q->rear = NULL;
       
//        delete(temp);
 
        // Decrements count of elements by 1
       q-> Size--;
    }
}
 


//Function to DELETE at the REAR of Deque
/*
                   STEPS:
                   1. CHECK THE UNDERFLOW , if the DQUEU -> REAR IS NULL .
                   2. LET THE DEQUEU -> REAR POINT TO THE PREVIOUS ELEMENT
                   3. IF THE WAS THE ONLY REMAINING , MEANING THAT THE FIRST- ALSO PIOINT TO IT , SO LET THE DEQUE-> FRONT = NULL
                   4. DONE ....

*/


void deleteRear(Deque* q)
{
    //
    // 'Underflow' condition
    if (isEmpty(q))
        cout << "UnderFlow\n";
    else
    {
        Node* temp =  q->rear;
         q->rear = q->rear->prev;
 
        // If only one element was present
        if ( q->rear == NULL)
             q->front = NULL;
//        else
//             q->rear->next = NULL;
        delete(temp);
 
        // Decrements count of elements by 1
        q->Size--;
    }
}
 
 


int getFront(Deque* q)
{
    // If deque is empty, then returns
    // garbage value
    if (isEmpty(q))
        return -1;
    return q->front->data;
}
 


int getRear(Deque* q)
{
    // If deque is empty, then returns
    // garbage value
    if (isEmpty(q))
        return -1;
    return q->rear->data;
}
 

void traverse(Deque* q)
{
	cout<< "\n\t\t\t TRAVERSE ELELMENTS : ";
	while(q->front != NULL)
	{
		cout<<q->front->data<<" ";
		q->front = q->front->next;	
	}
}


int main()
{
        Deque* q = new Deque;
        q->front = q->rear = NULL;

  int c,item;
  
    do
    {
        cout<<"\n\n\t\t\t\t DEQUE \t\t\t\t\n";
        cout<<"\n 1_insert at beginning";
        cout<<"\n 2_insert at end";
        cout<<"\n 3_display";
        cout<<"\n 4_Get Front";
        cout<<"\n 5_Get Rear";
        cout<<"\n 6_deletion from front";
        cout<<"\n 7_deletion from rear";
        cout<<"\n 8_exit";
        cout<<"\n enter your choice";
        cin>>c;
        switch(c)
        {
            case 1:cout<<"enter the element to be inserted";
                          cin>>item;
                          insertFront(q,item);
                          break;
            case 2:cout<<"enter the element to be inserted";
                         cin>>item;
                          insertRear(q,item);
                        break;
            case 3:cout <<"\nElements\t\t\t: ";
			        traverse(q);
                        break;
            case 4:cout <<"\nFront Element\t\t\t: ";
			        cout <<"\n\t\t\t"<<  getFront(q);
                        break;
                       case 5:cout <<"\nRear Element\t\t\t: ";
			       cout<<"\n\t\t\t"<< getRear(q);
                        break;
                        
            case 6:cout <<"\tDelete at the front: \t\t\t: "; deleteFront(q);
                        break;
            case 7:cout <<"\tDelete at the rear: \t\t\t: "; deleteRear(q);
                      break;
            case 8:exit(1);
                        break;
            csdefault:cout<<"invalid choice";
                    break;
        }
    }
    while(c!=7);
    
    return 0;
}

