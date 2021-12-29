#include <iostream>

using namespace std;

/*  Questão 01
	Resposta: Compilation error
	Minha Resposta: Compilation error
*/
// class A{
// public:
// 	char c;
// };
// class B:A{}; // Precisaria especificar qual grupo de métodos/atributos quer importar
// 		    // e.g: class B:public A{};
// int main(void){
// 	B b;
// 	A a;
// 	a.c = b.c = '?';
// 	cout<<int(a.c-b.c)<<endl;
// 	return 0;
// }

/*  Questão 02
	Resposta: 4
	Minha Resposta: 4
*/
// class A{
// public:
// 	int x;
// 	void d(){
// 		x /= 2;
// 	}
// };
// class B:public A{
// public:
// 	int y;
// 	void d(){
// 		y /=4;
// 	}
// };
// int main(void){
// 	B b;
// 	b.x = b.y = 4;
// 	b.d();
// 	cout<<b.x/b.y<<endl;
// 	return 0;
// }

/*  Questão 03
	Resposta: 2
	Minha Resposta: 2
*/
// class A{
// public:
// 	int x;
// 	void d(){
// 		x /= 2;
// 	}
// };
// class B : public A{
// public:
// 	int y;
// 	void d(){
// 		A::d();
// 	}
// };
// int main(){
// 	B b;
// 	b.x = b.y = 4;
// 	b.d();
// 	cout<<b.y/b.x<<endl;
// }

/*  Questão 04
	Resposta: 4
	Minha Resposta: 4
*/
// class A{
// public:
// 	int work(){
// 		return 4;
// 	}
// };
// class B:public A{
// public:
// 	int relax(){
// 		return 2;
// 	}
// };
// class C:public A{
// public:
// 	int relax(){return 1;}
// };
// int main(){
// 	A *a0 = new A, *a1 = new B, *a2 = new C;
// 	cout<<a0->work() + static_cast<C*>(a2)->relax()/static_cast<B*>(a1)->relax()<<endl;
// 	return 0;
// }

/*  Questão 05
	Resposta: 2
	Minha Resposta: 2
*/
// class A{
// public:
// 	int p(void){return 2;}
// };
// class B:public A{
// public:
// 	int p(void){return 1;}
// };
// int main(void){
// 	A *a = new B;
// 	cout<<static_cast<A*>(a)->p()<<endl;
// 	return 0;
// }

/*  Questão 06
	Resposta: Compilation error
	Minha Resposta: Compilation error
*/
// void f(const int &v){
// 	++v; // Isto vai causar um error de conpilação, pois v é estático
// 	return v+1;
// }
// int main(void){
// 	int i=1, j=f(i);
// 	cout<<j-i<<endl;
// 	return 0;
// }

/*  Questão 07
	Resposta: 2
	Minha Resposta: 2
*/
// class A{
// 	friend class B;
// 	int a;
// public:
// 	A():a(1){}
// 	int f(){return a;}
// };
// class B{
// public:
// 	static void f(A& a){a.a++;}
// };
// int main(void){
// 	A a;
// 	B::f(a);
// 	cout<<a.f()<<endl;
// 	return 0;
// }

/*  Questão 08
	Resposta: 4
	Minha Resposta: 4
*/
// class A{
// 	friend void i(A*);
// 	int a;
// public:
// 	A():a(2){}
// 	int f(){
// 		return a;
// 	}
// };
// void i(A *a){
// 	a->a *= 2;
// }
// int main(void){
// 	A a;
// 	i(&a);
// 	cout<<a.f()<<endl;
// 	return 0;
// }

/*  Questão 09
	Resposta: Compilation error
	Minha Resposta: Compilation error
*/
// class A{
// 	friend void i(int);
// 	int a;
// public:
// 	A():a(4){}
// 	int f(){return a;}
// };
// void i(int a){

// 	a /= 2;
// }
// int main(void){
// 	A a;
// 	i(2);
// 	// i(a.a); // Essa linha vai causar erro de compilação, pois 'a' é privado
// 	cout<<a.f()<<endl;
// 	return 0;
// }

/*  Questão 10
	Resposta: 2
	Minha Resposta: 2
*/
// class B;
// class A{
// 	friend class B;
// 	int a;
// public:
// 	A():a(4){}
// 	void f(B& b, A& a);
// 	int out(void){return a;}
// };
// class B{
// 	friend class A;
// 	int b;
// public:
// 	B():b(2){}
// 	void f(A& a){
// 		a.a /= b;
// 	}
// };
// void A::f(B& b, A& a){
// 	b.f(*this);
// }
// int main(){
// 	A a;
// 	B b;
// 	a.f(b,a);
// 	cout<<a.out()<<endl;
// 	return 0;
// }






    // class X {
    // public:
    //     void shout() { cout << "X"; }
    // };
    // class Y : public X {
    // public:
    //     void shout() { cout << "Y"; }
    // };
   
    // int main() {
    //     X *x = new Y();
    //     static_cast<Y *>(x) -> shout();
    //     return 0;
    // }
 


    // class X {
    // public:
    //     virtual void shout() { cout << "X"; }
    // };
    // class Y : public X {
    // public:
    //     void shout() { cout << "Y"; }
    // };
    // class Z : public Y {
    // public:
    //     void shout() { cout << "Z"; }
    // };
   
    // int main() {
    //     Y *y = new Z();
    //     dynamic_cast<X *>(y) -> shout();
    //     return 0;
    // }
 

    //  class A {
    // public:
    //     A() : val(0) {}
    //     int val;
    //     void inc() { ++val; }
    // };
   
    // void Do(A a) {
    //     a.inc();
    // }
   
    // int main() {
    //     A a;
    //     Do(a);
    //     a.inc();
    //     cout << a.val;
    //     return 0;
    // }


    // class A {
    // public:
    //     A() : val(0) {}
    //     int val;
    //     int inc() { ++val; return val--; }
    // };
   
    // void Do(A *a) {
    //     a-> val = a->inc();
    // }
   
    // int main() {
    //     A a;
    //     Do(&a);
    //     cout << a.inc();
    //     return 0;
    // }


    // class A {
    // public:
    //     A() : val(0) {}
    //     int val;
    //     int inc() { ++val; return val--; }
    // };
   
    // void Do(A *a) {
    //     a-> val = a->inc();
    // }
   
    // int main() {
    //     A a;
    //     Do(&a);
    //     cout << a.inc();
    //     return 0;
    // }
 


    // class A {
    //     int *val;
    // public:
    //     A() { val = new int; *val = 0; }
    //     int get() { ++(*val); return *val; }
    // };
   
    // int main() {
    //     A a,b = a;
    //     cout << a.get();
    //     cout << b.get();
    //     return 0;
    // }


    class A {
        int *val;
    public:
        A() { val = new int; *val = 0; }
        A(A &a) { val = new int; *val = a.get(); }
        int get() { ++(*val); return *val; }
    };
   
    int main() {
        A a,b = a;
        cout << a.get() << b.get();
        return 0;
    }
 



















