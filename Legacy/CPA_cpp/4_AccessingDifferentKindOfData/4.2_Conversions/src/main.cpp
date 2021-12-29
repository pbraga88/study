#include <iostream>

using namespace std;
/**************Implicit Convertion*********************/
// float g(void);
// int f(int x);

// int main(){
// 	int Int = 1;
// 	short Short = 2;
// 	long Long = 3;
// 	float Float = 4.0;
// 	double Double = 5.0;

// 	// example no. 1
// 	Int = Int + Short;
// 	// example no. 2
// 	if(Double)
// 	 Double--;
// 	// example no. 3
// 	Float = 1;
// 	// example no. 4
// 	f(Float);

// 	return 0;
// }
// // example no. 5
// float g(void) {
// 	return -1;
// }

// int f(int x) {
// 	return x;
// }
/******************************************************/

/**************Explicit Convertion(type casting)*******/
// int main(){
// 	float f = 3.21;
// 	double d = 1.23;
// 	int k = int(f) + (int)d;
// 	cout<<k<<endl;
// 	return 0;
// }
/******************************************************/

/**************Gains and losses*******/
#include  <iostream>
using namespace std; 
int main(void) { 
	// int i = 2147483647; 
	// short s = i; 
	// cout<<s<<endl;
	// if(i == s) 
	// 	cout << "equal" << endl; 
	// else 
	// 	cout << "not equal" << endl; 

	// float f = 1234.5678; 
	// double d = f;         
	// if(d == f) 
	// 	cout << "equal" << endl; 
	// else 
	// 	cout << "not equal" << endl;

	// double d = 123456.789012; 
	// float f = d; 
	// cout<<f<<endl;
	// if(d == f) 
	// 	cout << "equal" << endl; 
	// else 
	// 	cout << "not equal" << endl;

	// float f = 123.456;
	// float g = 1e100;
	// int i = f;
	// int j = g;        
	// cout << i << endl; 
	// cout << j << endl;

	int Int = 2;
	char Char = 3;
	short Short = 4;
	float Float = 5.6;
	Int = Short + Char + Float;
	cout << Int << endl;
	return 0; 
} 