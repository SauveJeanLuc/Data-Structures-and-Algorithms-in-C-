#include <iostream>
using namespace std;
class AirTicket
{
    public:
        string name = "AirTicket";
};
int main(){
    AirTicket ticket;
    cout << "Hello world .. " << ticket.name;
    return 0;
}