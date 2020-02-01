#include <iostream>
#include <stdio.h>

//[°C] = ([°F] − 32) × 5 ⁄ 9

using namespace std;

float (*my_func_ptr)(float)=NULL;
float convert_to_celsius(float fahr);

int main() {
	float temp;
	my_func_ptr = convert_to_celsius;
	cout<<"Temperature in Fahrenheit? "<<endl;
	cin>>temp;

	cout << "The conversion to Celsiud is: " << my_func_ptr(temp) << endl;

	return 0;
}

float convert_to_celsius(float fahr){
	return (((fahr - 32)*5)/9);
}