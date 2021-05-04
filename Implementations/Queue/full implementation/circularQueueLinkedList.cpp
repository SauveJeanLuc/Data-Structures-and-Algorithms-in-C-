#include <iostream>
using namespace std;


struct Node{
	int data;
	Node *next;
};

Node *front = NULL;
//front->data = -1;
Node *rear = NULL;
//rear->data = -1;

//Insert element
void enqueue(int x){
	Node *newNode = new Node;
	newNode->data = x;
	newNode->next = 0;
	
	if(rear == NULL){
		front = rear = newNode;
		rear->next = front;
	}
	else{
		rear->next = newNode;
		rear = newNode;
		rear->next = front;
	}
}



void dequeue(){
	Node *temp;
	temp = front;
	if(front == NULL && rear == NULL){
		cout << "Queue is empty";
	}
	else if(front == rear){
		front = rear = NULL;
		delete(temp);
	}
	else{
		front = front->next;
		rear->next = front;
		delete(temp);
	}
}

void display(){
	
	Node *temp;
	temp = front;
	
	cout << "The elements in a Queue are:";
	if(front == NULL && rear == NULL){
		cout << "Queue is empty";
	}
	else{
		while(temp->next!=front){
			cout << temp->data;
			temp = temp->next;
		}
	}
}
int main(){
	
	int choice = 1, x;
	while(choice <4 && choice!=0){
		cout << endl;
		cout << " Press 1: Insert an element"<<endl;
		cout << " Press 2: Delete an element"<<endl;
		cout << " Press 3: Display all elements"<<endl;
		cout << " Enter your choice: ";
		cin >> choice;
	
	    switch(choice){
	    	case 1:
	    		cout << "Enter element which is to be inserted: ";
	    		cin >> x;
	    		enqueue(x);
	    		break;
	    	case 2:
	    		dequeue();
	    		break;
	    	case 3:
	    		display();
	    		break;
		} 
	}
	
	return 0;

	
}
