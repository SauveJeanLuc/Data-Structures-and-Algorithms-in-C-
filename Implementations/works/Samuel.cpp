#include <iostream>
using namespace std;
  struct Node{
      string name;
      float price;
      string arrival;
      struct Node *next;
  };
  class Ticket
{ 
    public: 
    string geekname; 
     string name;
      float price;
      string arrival;
    // Member Functions() 
    void printname() 
    { 
       cout << "Geekname is: " << geekname; 
    } 
}; 
  void append(struct Node** head,string name,float price,string arrival)
  {
      struct Node* newNode = new Node;
      newNode -> price = price;
      newNode -> arrival = arrival;
      newNode -> name = name;
      newNode -> next = NULL;
      struct Node * last  = *head;
      if(*head == NULL)
      {
        *head = newNode;
        return;
      }
      while(last->next != NULL)
           last = last->next;
      last->next = newNode;
  }
  void displayList(struct Node *head)
  {
      struct Node *node = head;
      while(node != NULL)
      {
          cout << node-> name << "             ";
           cout << node-> price << "             ";
           cout << node-> arrival << "             ";
           cout<<"\n"; 
           node = node -> next;
      }
      if(node == NULL)
        cout<<"SORRY YOUR LIST IS EMPTY";
  }
int main()
{
struct Node* head = NULL;
append(&head,"KIGALI",150,"7:30 PM");
append(&head,"KIGALI",150,"7:30 PM");
append(&head,"KIGALI",150,"7:30 PM");
append(&head,"KIGALI",150,"7:30 PM");
cout << "HERE'S THE LIST "<<"\n";
displayList(head);
    return 0;
} 