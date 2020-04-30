#include <iostream>
#include <string>

using namespace std;

int main(){
	/****************Concatenate Strings**********************/
	// string the_good = "Jekyll", the_bad = "hyde";
	// cout<<the_good + " & " + the_bad<<endl;
	// cout<<the_bad + " & " + the_good<<endl;
	/*********************************************************/

	/****************Concatenate Literals**********************/
	// string String = "A";
	// String = String + "B";
	// String = "Z" + String;
	// cout<<String<<endl;

	/* Concatenando com '+=' */
	// string String = "Ser";
	// String += " ou não ser!";
	// cout<<String<<endl;
	/**********************************************************/

	/****************Input Strings*****************************/
	// string LineOfTypes;
	// getline(cin, LineOfTypes);
	// cout<<LineOfTypes<<endl;
	/**********************************************************/

	/********************String Comparison*********************/
	string first, second;
	getline(cin, first);
	getline(cin, second);

	if(first.compare(second) == 0)
		cout<<"equal"<<endl;
	else if(first.compare(second) > 0)
		cout<<"first"<<endl;
	else
		cout<<"second"<<endl;
	/**********************************************************/	
	return 0;
}