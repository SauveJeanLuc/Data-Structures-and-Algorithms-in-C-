#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
struct Stop  {
    string stopname;
    float price;
    string arrival;
    struct Stop *next;
}*start;
void create(Stop array[],int length){
    struct Stop *lastStop;
    start = new Stop;
    start->stopname = array[0].stopname;
    start->arrival = array[0].arrival;
    start->price = array[0].price;
    start->next = NULL;
    lastStop = start;
    struct Stop *temporaryStop;
    for(int i=1; i<length; i++){
        temporaryStop = new Stop;
        temporaryStop->stopname = array[i].stopname;
        temporaryStop->price = array[i].price;
        temporaryStop->arrival = array[i].arrival;
        temporaryStop->next = NULL;
        lastStop->next= temporaryStop;
        lastStop = temporaryStop;
    }
}
void print(Stop *startPoint){
	int counter=0;
	cout<<"\tName\t\t\tPrice\t\t\tArrival Time\n";
	cout<<"       ----------------------------------------------------------------\n";
    while(startPoint !=NULL){
        cout<<"\t "<<startPoint->stopname<<"\t\t\t"<<startPoint->price<<"\t\t\t"<<startPoint->arrival<<endl<<endl;
        startPoint = startPoint->next;
        counter++;
    }
    cout<<"\n\n\tThere are "<<counter<<" stops"<<endl<<endl;
}
struct Stop *search(struct Stop *ptr, int key){
	while(ptr!=NULL){
		if(ptr->price==key){
			cout<<"\t"<<ptr->stopname<<"\t";
			cout<<ptr->price<<"\t";
			cout<<ptr->arrival<<endl;
			return ptr;
		}else{
			ptr=ptr->next;
		}
	}
	return NULL;
}

int max(struct Stop *ptr){
	int maximum;
	maximum = ptr->price;
	while(ptr!=NULL){
		if(maximum<ptr->price){
			maximum = ptr->price;
		}
		ptr=ptr->next;
	}
	return maximum;
}
int main(){
    Stop flightStops[5] = {
            {"Kigali", 150, "7:30 PM"},
            {"Entebbe", 300, "8:15 PM"},
            {"Bruxelles",800, "5:45 AM"},
            {"Newark", 2400, "4:00 PM"},
            {"Logan", 3600, "5:00 PM"}
    };
    create(flightStops,5);
    print(start);
    cout<<"\t Search results "<<endl;
    cout<<"\t******************"<<endl;
    search(start, 800);
    cout<<endl<<endl;
    cout<<"\tThe maximum price is "<<max(start)<<endl;
    return 0;
}
/////////////////////add a function to find the max price and another function to count number of stops 