#include <iostream>
#include <iomanip>
using namespace std;

// int function_activation_count {0};

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE THE FUNCTION PROTOTYPE BELOW THIS LINE----
// double penny_amount {0.01};

double a_penny_doubled_everyday(int days, double p_amount = 0.01);//----WRITE THE FUNCTION PARAMETER LIST WITHIN THE PARENTHESES

//----WRITE THE FUNCTION PROTOTYPE ABOVE THIS LINE----
//----DO NOT MODIFY THE CODE BELOW THIS LINE----

void amount_accumulated(int n) {
    // int n = 2;
//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE THE FUNCTION CALL BELOW THIS LINE----
    double total_amount = a_penny_doubled_everyday(n);
//----WRITE THE FUNCTION CALL ABOVE THIS LINE----
//----DO NOT MODIFY THE CODE BELOW THIS LINE----
    cout <<  "If I start with a penny and doubled it every day for "<<n<<" days, I will have $" << setprecision(10) << total_amount <<endl;;
}

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE THE FUNCTION DEFINITION BELOW THIS LINE----

double a_penny_doubled_everyday(int days, double p_amount) {//----WRITE THE FUNCTION PARAMETER LIST WITHIN THE PARENTHESES
    // function_activation_count++;
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE THE FUNCTION BODY BELOW THIS LINE----

    return (days<=1) ? p_amount : a_penny_doubled_everyday(days-1, p_amount*2);
    //----WRITE THE FUNCTION BODY ABOVE THIS LINE----
    //DO NOT MODIFY THE CODE BELOW THIS LINE----
}

// int test_function_activation_count() {
//     return function_activation_count;
// }


int main(int argc, char **argv) {
    amount_accumulated(atoi(argv[1]));

    return 0;
}