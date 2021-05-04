#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

struct Node {

    string name;
    float price;
    time_t arrival;

    struct Node *next;
};

class linked_list
{
    private:
        Node *head, *tail;
    public:
        linked_list()
        {
            head = NULL;
            tail = NULL;
        }
        
        void add_node(string name, float price, time_t arrival)
        {
            Node * tmp = new Node;
            tmp->name = name;
            tmp->price = price;
            tmp->arrival = arrival;
            tmp->next = NULL;

            if(head == NULL)
            {
                head = tmp;
                tail = tmp;
            }
            else{
                tail ->next = tmp;
                tail = tail->next;
            }
        }

        void display(){
            Node* ptr;
            ptr = head;
            string timePeriod;
            cout <<setw(20)<<"Name"<<setw(20)<<"Price"<<setw(20)<<"Arrival" << endl;
            while ( ptr != NULL)
            {   
                tm *ltm = localtime(&ptr->arrival);
                if(ltm->tm_hour < 12){
                    timePeriod = "am";
                }
                cout <<setw(20)<<ptr->name << setw(20) << ptr->price << setw(20) << ltm->tm_hour << ":"<<ltm->tm_min<<" "<<timePeriod<<endl;
                ptr = ptr->next;
            }
            
        }
};

int main(){

    linked_list flight;
    flight.add_node("Ouagadougu",500.4,time(0));
    flight.add_node("Kigali",530.4,time(0));
    flight.add_node("Tanzania",430.4,time(0));

    flight.display();
}