#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
    int value;
    int row_position;
    int column_postion;
    struct Node *next;
};

void create_new_node(struct Node** start, int non_zero_element,
                     int row_index, int column_index )
{
    struct Node *temp, *r;
    temp = *start;
    if (temp == NULL)
    {
       
        temp = (struct Node *) malloc (sizeof(struct Node));
        temp->value = non_zero_element;
        temp->row_position = row_index;
        temp->column_postion = column_index;
        temp->next = NULL;
        *start = temp;
 
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
 
        // Create new node dynamically
        r = (struct Node *) malloc (sizeof(struct Node));
        r->value = non_zero_element;
        r->row_position = row_index;
        r->column_postion = column_index;
        r->next = NULL;
        temp->next = r;
 
    }
}


void createSparceMatrix(Node ** start, int numberOfRows, int numberOfColumns){
    int numberOfNonZeroElements,columnIndexInRow, value;
 
    for (int i = 0; i < numberOfRows; i++){
    
        cout << "Enter Number of non-zero elements for row number " <<i+1<<endl;
        cin >> numberOfNonZeroElements;
        for (int j = 0; j < numberOfNonZeroElements; j++){
    columnIndex:    cout << "Column Index in row: ";
                    cin >> columnIndexInRow;
                    cout << "value: ";
                    cin >> value;
                    if (value != 0 && columnIndexInRow<numberOfColumns){
                        create_new_node(start, value, i, columnIndexInRow);
                    }
                    else{
                        goto columnIndex;
                    }             
        }
    }

}



void PrintMatrix(Node** start, int numberOfRows, int numberOfColumns){
    
    cout << "========Your Matrix====="<<endl;
   
    Node *temp = *start;

        for (int i = 0; i < numberOfRows; i++){

            for (int j = 0; j < numberOfColumns; j++){

                if(temp->row_position == i && temp->column_postion == j){
                    cout << temp->value << " ";
                    if(temp->next!=NULL){
                        temp = temp->next;   
                    }
                } 
                else{
                    cout << "0 ";
                }

           
            }
            cout <<endl;
        }

        cout << "========================"<<endl;
        

}

void addSparceMatrix(Node** startOne,Node** startTwo,int numberOfRows, int numberOfColumns){

    cout << "========Your Matrix====="<<endl;
   
    Node *temp = *startOne;
    Node *tempTwo = *startTwo;

        for (int i = 0; i < numberOfRows; i++){

            for (int j = 0; j < numberOfColumns; j++){

                if( (temp->row_position == i && temp->column_postion == j) && (tempTwo->row_position == i && tempTwo->column_postion == j) ){
                    cout << temp->value+tempTwo->value << " ";
                    if(temp->next!=NULL || tempTwo->next!=NULL){
                        temp = temp->next;   
                        tempTwo = tempTwo->next;
                    }
                } 
                else if( (temp->row_position == i && temp->column_postion == j) ){
                    cout << temp->value << " ";
                    if(temp->next!=NULL){
                        temp = temp->next;   
                    }
                }
                else if( (tempTwo->row_position == i && tempTwo->column_postion == j) ){
                    cout << tempTwo->value << " ";
                    if(tempTwo->next!=NULL){
                        tempTwo = tempTwo->next;   
                    }
                }
                else{
                    cout << " 0 ";
                }
           
            }
            cout <<endl;
        }

        cout << "========================"<<endl;
}
 
 
int main(){
int choice, numberOfRows, numberOfColumns;
struct Node* start = NULL;
struct Node* startOne = NULL;
struct Node* startTwo = NULL;
do{
    cout << "=================================" << endl;
    cout << "||  Sparce Matrix Manipulator  ||" << endl;
    cout << "||   1.Create Sparce Matrix    ||" << endl;
    cout << "||   2.Display Sparce Matrix   ||" << endl;
    cout << "||   3.Add two Sparce Matrices ||" << endl;
    cout << "||   4.Exit                    ||" << endl;
    cout << "=================================" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "How many rows does your matrix have: ";
        cin >> numberOfRows;
        cout << "How many columns does your matrix have: ";
        cin >> numberOfColumns;
        createSparceMatrix(&start,numberOfRows,numberOfColumns);
        break;
    case 2:
        PrintMatrix(&start,numberOfRows,numberOfColumns);
        break;
    case 3: 
        cout << "How many rows will your matrices have: ";
        cin >> numberOfRows;
        cout << "How many columns will your matrices have: ";
        cin >> numberOfColumns;
        cout << "For first Matrix:  "<<endl;
        createSparceMatrix(&startOne,numberOfRows,numberOfColumns);
        cout << "For second Matrix:  "<<endl;
        createSparceMatrix(&startTwo,numberOfRows,numberOfColumns);
        addSparceMatrix(&startOne, &startTwo, numberOfRows, numberOfColumns);
        break;
    
    case 4:
        return 0;
        break;
    default:
        cout << "Sorry Invalid input";
        break;
    }
}while (choice!=4);
 
    return 0;
}