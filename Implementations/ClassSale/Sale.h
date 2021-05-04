#include <iostream>
using namespace std;

class Sale{

    private:
        double price;

    public:
        Sale();
        Sale(double thePrice);
        void setPrice(double thePrice);
        double getPrice() const;
        virtual double bill() const;
        double savings(const Sale& other) const;

};

Sale::Sale() : price(0){}

Sale::Sale(double thePrice){
    price = thePrice;
}

double Sale::getPrice() const{
    return price;
}

void Sale::setPrice(double thePrice){
    price: thePrice;
}

double Sale::bill() const{
    return price;
}

double Sale::savings(const Sale& other) const{
    return (bill()-other.bill());
}

bool operator < (const Sale& first, const Sale& second){
    return (first.bill()<second.bill());
}


