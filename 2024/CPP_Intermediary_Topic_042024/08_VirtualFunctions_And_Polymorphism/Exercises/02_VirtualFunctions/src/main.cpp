// VirtualFunctions.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
#include <iostream>
#include <stddef.h>
#include <functional>

class Base1 {
public:
	virtual void f1() {std::cout << "Base1::f1()\n";};
	virtual void f2() {std::cout << "Base1::f2()\n";};
	int member_base1;
	char *member_char;
};

class Base2 {
public:
	virtual void g1() {std::cout << "Base2::g1()\n";};
	virtual void g2() {std::cout << "Base2::g2()\n";};
	int member_base2;
};

class Derived : public Base1, public Base2 {
public:
	void f1() {std::cout << "Derived::f1()\n";};
	virtual void g2() {std::cout << "Derived::g2()\n";}; // Added by me
	virtual void h1(int a) {std::cout << "Derived::h1() with " << a << "\n";};

	int member_derived;
};

int main(int argc, char* argv[])
{
	(void)argc;
	(void)argv;

	// Multiple Inheritance with virtual functions
	Derived* pObjectDerived = new Derived();

	// Run the example and understand the following memory layout
	// // Memory Layout of object Derived
	// std::cout << "SizeOf(Derived)         = " << sizeof(Derived) << std::endl;
	// std::cout << "Offset Base1::member_base1     = " << offsetof(Derived, member_base1) << std::endl;
	// std::cout << "Offset Base1::member_char1     = " << offsetof(Derived, member_char) << std::endl;
	// std::cout << "Offset Base2::member_base2     = " << offsetof(Derived, member_base2) << std::endl;
	// std::cout << "Offset Derived::member_derived = " << offsetof(Derived, member_derived) << std::endl;

	// // Use disassembly view to show display the offsets in the vtable
	// // Understand the location of the functions in the vtable
	// pObjectDerived->f1();
	// pObjectDerived->f2();
	// pObjectDerived->g1();
	// pObjectDerived->g2();

	// // Where is Derived:h1() function stored in the vtable
	pObjectDerived->h1(10);


#ifdef WIN32 // Not Portable between compilers
	// Calling Entry from vtable
	// DO NOT USE IN PRODUCTION CODE, ACTUALLY NEVER DO THIS
	int* ptemp = reinterpret_cast<int*>(pObjectDerived);
	int* pvtbl = reinterpret_cast<int*>(*reinterpret_cast<int*>(pObjectDerived));

	typedef void(__thiscall *FunctionPtrType)(Derived*, int);
	FunctionPtrType  pfFunction = (FunctionPtrType)(pvtbl[2]);

	pfFunction(pObjectDerived, 10);
#endif

	Base1* pBase1 = dynamic_cast<Base1*>(pObjectDerived);
	pBase1->f1();
	pBase1->f2();

	Base2* pBase2 = dynamic_cast<Base2*>(pObjectDerived);
	pBase2->g1();
	pBase2->g2();

	// Can you explain these pointers
	std::cout << "pObjectDerived = " << pObjectDerived << std::endl;
	
	std::cout << "pBase1         = " << pBase1 << std::endl;
	std::cout << "member_base1   = " << &pBase1->member_base1 << std::endl;
	std::cout << "member_char    = " << &pBase1->member_char << std::endl;

	std::cout << "pBase2         = " << pBase2 << std::endl;
	std::cout << "member_base2   = " << &pBase2->member_base2 << std::endl;

	std::cout << "member_derived = " << &pObjectDerived->member_derived << std::endl;

	// Derived* pD = dynamic_cast<Derived*>(pBase1);
	// pD->f1();

	// Base1* baseptr = dynamic_cast<Base1*>(pBase1);
	// baseptr->f1();
	return 0;
}