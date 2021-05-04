#include <iostream>
#include <cmath>
using namespace std;

struct Node{

    int exponent;
    int power;
    Node * next;

} *first;

void insertAtBeginning(int exponent, int power){
    Node * newNode = new Node;
    newNode->exponent = exponent;
    newNode->power = power;
    newNode->next = first;
    first = newNode;
}

void insertToEnd(int exponent, int power){
    Node * newNode = new Node;
    newNode->exponent = exponent;
    newNode->power = power;
    newNode->next = NULL;

    Node * temp = first;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    
}
void createPolynomial(){
 int degree; 
 cout << "What's the Degree of your polynomial? : ";
 cin >> degree;
 int count=degree, exponent, power;
  do
  {
      cout << "Enter exponent of the " << count << "th degree:    ";
      cin >> exponent;
      if(count == degree){
        insertAtBeginning(exponent, count);
      }
      else{
        insertToEnd(exponent, count);
      }

      count --;
  } while (count >= 0);
  

}

void displayPolynomial(){
    Node * temp = first;
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

int evaluatePolynomial(){
    int x, result=0;
    cout << "Enter value of x: ";
    cin >> x;

    Node * temp = first;
    while(temp!=NULL){
        cout << temp->exponent<<"*"<<"("<<x<<"^"<<temp->power<<")"<<endl;
        result += temp->exponent*( pow(x,temp->power) );
        cout << "Result for now: " << result <<endl;
        temp = temp->next;
    }

    displayPolynomial();
    cout << " =  "<< result <<endl;
    return result;
}

int main(){

int choice;

do{
    cout << "=================================" << endl;
    cout << "||      Polynomial Creater     ||" << endl;
    cout << "||      1.Create Polynomial    ||" << endl;
    cout << "||      2.Display Polynomial   ||" << endl;
    cout << "||      3.Evaluate Polynomial  ||" << endl;
    cout << "||      4.Exit                 ||" << endl;
    cout << "=================================" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        createPolynomial();
        break;
    case 2:
        displayPolynomial();
        cout <<endl;
        break;
    case 3: 
        evaluatePolynomial();
        break;
    default:
        cout << "Sorry Invalid input";
        break;
    }

}while (choice!=4);



}