#include "Money.h"

Money::Money(int dollars, int cents) : dollars{dollars}, cents{cents} {}

Money::Money(int total) : dollars {total/100}, cents{total%100}  {}
   


//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE YOUR METHOD DEFINITIONS BELOW THIS LINE----
bool Money::operator==(const Money &rhs) const {
     return (dollars==rhs.dollars)&&(cents==rhs.cents);
}

bool Money::operator!=(const Money &rhs) const {
     return (dollars!=rhs.dollars)||(cents!=rhs.cents);
}

//----WRITE YOUR METHOD DEFINITIONS ABOVE THIS LINE----

