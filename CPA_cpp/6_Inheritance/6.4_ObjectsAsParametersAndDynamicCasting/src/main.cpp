#include <iostream>
#include <string>

using namespace std;

class Pet{
	protected:
		string name;
	public:
		void NameMe(string name){
			this->name = name;
		}
		void MakeSound(void){
			cout<<name<<" says: no comments"<<endl;
		}
};
