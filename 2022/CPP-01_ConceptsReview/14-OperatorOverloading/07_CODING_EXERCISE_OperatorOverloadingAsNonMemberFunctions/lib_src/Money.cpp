#include "Money.h"

Money::Money(int dollars, int cents) : dollars{dollars}, cents{cents} {}

Money::Money(int total) : dollars {total/100}, cents{total%100}  {}
   

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE YOUR METHOD DEFINITIONS BELOW THIS LINE----
Money operator+(const Money &lhs, const Money &rhs) {
     int dollars_to_cents = (lhs.dollars + rhs.dollars) * 100;
     int total_cents = dollars_to_cents + (lhs.cents + rhs.cents);
     
     Money temp(total_cents);
     return temp;
}


//----WRITE YOUR METHOD DEFINITIONS ABOVE THIS LINE----