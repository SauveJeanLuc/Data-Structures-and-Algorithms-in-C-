#include<iostream>
using namespace std;
#define SIZE 5

int deQueue[10],front=-1,rear=-1;

void dequeue()
{
    front=-1;
    rear=-1;
}
void add_at_end(int item)
{
 
    if(rear >= SIZE-1)
    {
        cout<<"\n insertion is not posibble,overflow!!!!";
    }
    else
    {
        if(front==-1)
        {
            front++;
            rear++;
        }
        else
        {
            rear=rear+1;
        }
    deQueue[rear]=item;
    cout<<"\nInserted item is"<<deQueue[rear];
    }
}


void add_at_beginning(int item)
{
 
        if(front==-1)
        {
            front=0;
            deQueue[++rear]=item;
            cout<<"\n inserted element is"<<item;
        }
        else if(front != 0)
        {
            deQueue[--front]=item;
            cout<<"\n inserted element is"<<item;
        }
        else
        {
              cout<<"\n insertion is not posibble,overflow!!!";
        }
 
}
void display()
{
    if(front==-1)
    {
        cout<<"Dequeue is empty";
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<deQueue[i]<<" ";
        }
    }
}
void delete_from_front()
{
        if(front==-1)
        {
            cout<<"deletion is not possible::dequeue is empty";
            return;
        }
        else
        {
            cout<<"the deleted element is"<<deQueue[front];
            if(front==rear)
            {
                front=rear=-1;
                return;
            }
            else
                front=front+1;
        }
}

void delete_from_end()
{
        if(front==-1)
        {
            cout<<"deletion is not possible::dequeue is empty";
            return;
        }
        else
        {
            cout<<"the deleted element is"<<deQueue[rear];
            if(front==rear)
            {
                front=rear=-1;
            }
            else
                rear=rear-1;
        }
}

int main()
{
    int choice,item;
  
    do
    {

        cout<<endl <<"1. Insert at beginning";
        cout<<endl <<"2. Insert at end";
        cout<<endl <<"3. Display";
        cout<<endl <<"4. Delete from beginning";
        cout<<endl <<"5. Delete from back";
        cout<<endl <<"6. Exit";
        cout<<endl << "Enter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"enter the element to be inserted";
                          cin>>item;
                          add_at_beginning(item);
                          break;
            case 2:
            cout<<"enter the element to be inserted";
                         cin>>item;
                        add_at_end(item);
                        break;
            case 3:
            cout <<"\nElements\t\t\t: "; display();
                        break;
            case 4:
            cout <<"\tDelete at the beginning: \t\t\t: ";delete_from_front();
                        break;
            case 5:
            cout <<"\tDelete at the end: \t\t\t: ";delete_from_end();
                      break;
            case 6:
            exit(1);
                        break;
            csdefault:cout<<"invalid choice";
                    break;
        }
    }
    while(c!=7);
    
    return 0;
}

