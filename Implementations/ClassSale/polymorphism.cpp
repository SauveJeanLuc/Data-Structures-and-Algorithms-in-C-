#include "DiscountSale.h"
#include <iostream>
using namespace std;

int main(){

    Sale firstSale(1000);
    cout << "Billing 1 is: " << firstSale.bill() << endl;

    DiscountSale secondSale(1000, 2);
    cout << "Billing with discount: " << secondSale.bill() << endl;
    cout << "Total Savings: " << firstSale.savings(secondSale) << endl;
    return 0;
}
