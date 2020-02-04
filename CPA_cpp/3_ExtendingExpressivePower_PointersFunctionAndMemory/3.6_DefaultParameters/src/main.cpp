#include <iostream>
#include <string>

using namespace std;

void good_morning(string morning = "Good morning!", int qty = 1) {
	while(qty){
		cout << morning << endl;
		qty--;
	}
}

void my_func(string greet, int val = 1) {
	do{
		cout << greet << endl;
		val--;
	}
	while(val);

}

int main(){

	good_morning();
	good_morning("Hey there!");
	good_morning("Hey you!", 2);

	my_func("Hi!");
	my_func("Hi!", 10);

	return 0;
}