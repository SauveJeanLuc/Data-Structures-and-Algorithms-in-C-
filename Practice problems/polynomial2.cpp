#include <iostream>
#include <cmath>
using namespace std;

struct Node{

    int exponent;
    int power;
    Node * next;

}; 
// *first, *second;

void insertAtBeginning(Node** first, int exponent, int power){
    Node * newNode = new Node;
    newNode->exponent = exponent;
    newNode->power = power;
    newNode->next = *first;
    *first = newNode;
}

void insertToEnd(Node** first,int exponent, int power){
    Node * newNode = new Node;
    newNode->exponent = exponent;
    newNode->power = power;
    newNode->next = NULL;

    Node * temp = *first;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    
}
void createPolynomial(Node** first){
 int degree; 
 cout << "What's the Degree of your polynomial? : ";
 cin >> degree;
 int count=degree, exponent, power;
  do
  {
      cout << "Enter coefficient of the " << count << "th degree:    ";
      cin >> exponent;
      if(count == degree){
        insertAtBeginning(first,exponent, count);
      }
      else{
        insertToEnd(first,exponent, count);
      }

      count --;
  } while (count >= 0);
  

}

void displayPolynomial(Node** first){
    Node * temp = *first;
    int degree = temp->power;
    while(temp!=NULL){
        cout << temp->exponent<<"X^"<<degree;
        if (temp->next!=NULL)
        {
           cout<<" + ";
        }
        temp = temp->next;
        degree--;
    }
    
}

int evaluatePolynomial(Node** first){
    int x, result=0;
    cout << "Enter value of x: ";
    cin >> x;

    Node * temp = *first;
    while(temp!=NULL){
        cout << temp->exponent<<"*"<<"("<<x<<"^"<<temp->power<<")"<<endl;
        result += temp->exponent*( pow(x,temp->power) );
        cout << "Result for now: " << result <<endl;
        temp = temp->next;
    }

    displayPolynomial(first);
    cout << " =  "<< result <<endl;
    return result;
}

int addPolynomials(Node** first, Node** second){
    Node *tempOne = *first;
    Node *tempTwo = *second;
    //Determine which polynomial has the largest degree
    if(tempOne->power < tempTwo->power){
        tempOne = *second;
        tempTwo = *first;
    }

    int degree = tempOne->power;
    while(tempOne!=NULL){
        if(tempOne->power > tempTwo->power){
                cout << tempOne->exponent<<"X^"<<degree;
                if (tempOne->next!=NULL)
                {
                cout<<" + ";
                }
                tempOne = tempOne->next;
                degree--;
        }
        else{
                cout << tempOne->exponent + tempTwo->exponent<<"X^"<<degree;
                if (tempOne->next!=NULL)
                {
                cout<<" + ";
                }
                tempOne = tempOne->next;
                tempTwo = tempTwo->next;
                degree--;
        }
    }

    cout <<endl;
}

int main(){

int choice;
Node *first = new Node;
first = NULL;
Node *second = new Node;
second = NULL;
do{
    cout << "=================================" << endl;
    cout << "||      Polynomial Creater     ||" << endl;
    cout << "||      1.Create Polynomial    ||" << endl;
    cout << "||      2.Display Polynomial   ||" << endl;
    cout << "||      3.Evaluate Polynomial  ||" << endl;
    cout << "||      4.Add two Polynomial   ||" << endl;
    cout << "||      5.Exit                 ||" << endl;
    cout << "=================================" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        createPolynomial(&first);
        break;
    case 2:
        displayPolynomial(&first);
        cout <<endl;
        break;
    case 3: 
        evaluatePolynomial(&first);
        break;
    case 4:
    cout << "CREATING your First Polynomial"<<endl;
        createPolynomial(&first);
    cout <<endl<<"CREATING your Second Polynomial"<<endl;
        createPolynomial(&second);
    cout << "Your first Polynomial: "<<endl;
        displayPolynomial(&first);
    cout <<endl << "Your second Polynomial: "<<endl;
        displayPolynomial(&second);
    cout <<endl<<"Sum of your Polynomials:"<<endl;
        addPolynomials(&first,&second);
        break;
    case 5:
        return 0;
    break;
    default:
        cout << "Sorry Invalid input";
        break;
    }

}while (choice!=5);



}