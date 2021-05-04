#include <iostream>
using namespace std;


int front=-1;
int rear = -1;


void enqueue(int data, int queue[], int max){
	
	if(front==-1&&rear==-1){
		front =0;
		rear=0;
		queue[rear]=data;
	}
	else if((rear+1)%max == front){
		cout << "Overflow error";
	}
	else{
		rear = (rear+1) % max;
		queue[rear]= data;
	}
}

void dequeue( int queue[], int max){
	
	if(front == -1 && rear ==-1){
		cout << "Underflow error..";
	}
	else if(front==rear){
		cout << "The deleted element is "<<queue[rear];
		front = -1;
		rear = -1;
	}
	else{
		cout << "The dequeued element is "<<queue[front];
		front =(front+1)%max;
	}
	
}

void display( int queue[], int max){
	int i = front;
	if(front == -1 && rear == -1){
		cout << "Queue is empty";
	}
	else{
		cout << "Elements in Queue are: ";
		if(rear!=max-1 || front!=0 ){
					while(i <= rear){
						cout << queue[i];
						cout << "Element printed";
						i = (i+1) % max;
					}
		}
		else if(rear == max-1){

					while(i <= rear){
						cout << queue[i];
						i = i+1;
					}			
			
		}

	}
}

int main(){
	int max;
	cout << "Please enter the size of your queue:";
	cin >> max;
	int choice = 1, x;
	int queue[max];
	
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
	    		enqueue(x,queue,max);
	    		break;
	    	case 2:
	    		dequeue(queue,max);
	    		break;
	    	case 3:
	    		display(queue,max);
	    		break;
		} 
	}
	
	return 0;
}
