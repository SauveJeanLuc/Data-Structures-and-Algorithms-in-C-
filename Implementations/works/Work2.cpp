#include<iostream>
using namespace std;
struct stop
{
    string name;
    int price;
    string arrival_time;
    struct stop *next;
}*first_node;
void create(stop A[], int n){
    struct stop *last_node;
    first_node = new stop;
    first_node->name = A[0].name;
    first_node->price = A[0].price;
    first_node->arrival_time = A[0].arrival_time;
    first_node->next = NULL;
    last_node = first_node;
    int i;
    struct stop *t;
    for (i = 1; i < n; i++)
    {
        t= new stop;
        t = new stop;
        t->name = A[i].name;
        t->price = A[i].price;
        t->arrival_time = A[i].arrival_time;
        t->next = NULL;
        last_node->next = t;
        last_node = t;
    }
}
void Display(struct stop *p) {
        cout << "Name\t\tPrice\t\tArrival time";
    while(p!=NULL)    {
        cout << "\n";
        cout << p->name << "\t\t";
        cout << p->price << "\t\t";
        cout << p->arrival_time;
        p=p->next;
    }
}

struct stop * Search(struct stop *p, int key){
     
    while(p!=NULL)    {
        if(p->price == key){
            return p;
        }        
        else{
            p = p->next;
            
        }
    }
    return NULL;
}


int main() {
    stop flight [5] = {
        {"Kigali", 150, "7:30 PM"},
        {"Entebbe", 300, "8:15 PM"},
        {"Bruxelles", 800, "5:45 AM"},
        {"Newark", 1400, "4:00 PM"},
        {"Logan", 1600, "5:00 PM "},
    };
    create(flight, 5);
    Display(first_node);
    stop *searched = Search(first_node,300);
    cout <<endl << "Name of the Searched Stop: " << searched->name <<", Time: "<< searched->arrival_time << endl;
    return 0;
}