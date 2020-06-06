#include <iostream>

using namespace std;

/********Friend Class*********/
// class A{
// 	friend class B;
// 	friend class C;
// private:
// 	int field;
// protected:
// 	void print(){cout<<"It's a secret, that field = "<<field<<endl;}
// };
// class C{
// public:
// 	void DoIt(A& a){
// 		a.print();
// 	}
// };
// class B{
// public:
// 	void DoIt(A& a, C& c){
// 		a.field = 111;
// 		c.DoIt(a);
// 	}
// };
// int main(){
// 	A a;
// 	B b;
// 	C c;

// 	b.DoIt(a, c);

// 	return 0;
// }
/*****************************/

/*********Friend Function*********/
class A;

class C{
public:
	void dec(A& a);
};

class A{
	friend class B;
	friend void C::dec(A&); // Member function
	friend void DoIt(A&);	// Global function
private:
	int field;
protected:
	void print(){
		cout<<"It's a secret, that field = "<<field<<endl;
	}
};

class B{
public:
	void DoIt(A& a){
		a.print();
	}
};

void C::dec(A& a){
	a.field--;
}

void DoIt(A& a){
	a.field = 99;
}

int main(){
	A a;
	B b;
	C c;

	DoIt(a);
	b.DoIt(a);

	c.dec(a);
	b.DoIt(a);

	return 0;
}

/*********************************/