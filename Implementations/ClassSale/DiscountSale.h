#include "Sale.h"

class DiscountSale: public Sale{
         public:
            DiscountSale();
            DiscountSale(double thePrice, double theDiscount);

            double getDiscount() const;
            void setDiscount(double theDiscount);

            double bill() const;

         private:
            double discount;
};

DiscountSale::DiscountSale() : discount(0){};

DiscountSale::DiscountSale(double thePrice, double theDiscount){
    Sale::setPrice(thePrice - theDiscount);
}

double DiscountSale::getDiscount() const{
    return discount;
}

void DiscountSale::setDiscount(double theDiscount){
    discount = theDiscount;
}

double DiscountSale::bill() const{
    double fraction = discount/100;
    return (1 - fraction)*getPrice();
}

