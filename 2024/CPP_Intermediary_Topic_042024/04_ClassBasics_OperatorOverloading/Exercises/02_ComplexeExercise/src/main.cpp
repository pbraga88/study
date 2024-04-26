// OperatorOverloadingExecise.cpp : Defines the entry point for the console application.
//


#define YAFFUT_MAIN

#include "yaffut.h"
#include "Complex.h"

FUNC(ComplexTest)
{
	const Complex a(1.0, 2.0);	//a should get the value (1.0, 2.0)

	YAFFUT_EQUAL(a.getReal(), 1.0);
	YAFFUT_EQUAL(a.getImag(), 2.0);

	Complex b(a); 			//b should get the value (1.0, 2.0)
	YAFFUT_EQUAL(b.getReal(), 1.0);
	YAFFUT_EQUAL(b.getImag(), 2.0);
	YAFFUT_EQUAL(a.getReal(), 1.0); // a should be unchanged
	YAFFUT_EQUAL(a.getImag(), 2.0);

	Complex c; 			//c should get the value (0.0, 0.0)
	YAFFUT_EQUAL(c.getReal(), 0.0);
	YAFFUT_EQUAL(c.getImag(), 0.0);

	b = 2 * a; 			//b should get the value (2.0, 4.0)
	YAFFUT_EQUAL(b.getReal(), 2.0);
	YAFFUT_EQUAL(b.getImag(), 4.0);
	YAFFUT_EQUAL(a.getReal(), 1.0); // a should be unchanged
	YAFFUT_EQUAL(a.getImag(), 2.0);

	double x = 3.0;
	c = x;			//c should get the value (3.0, 0.0)
	YAFFUT_EQUAL(c.getReal(), 3.0);
	YAFFUT_EQUAL(c.getImag(), 0.0);

	b = b * c; 			//b should get the value (6.0, 12.0)
	YAFFUT_EQUAL(b.getReal(), 6.0);
	YAFFUT_EQUAL(b.getImag(), 12.0);
	YAFFUT_EQUAL(c.getReal(), 3.0); // c should be unchanged
	YAFFUT_EQUAL(c.getImag(), 0.0);

	b = b + a; 			//b should get the value (7.0, 14.0)
	YAFFUT_EQUAL(b.getReal(), 7.0);
	YAFFUT_EQUAL(b.getImag(), 14.0);
	YAFFUT_EQUAL(a.getReal(), 1.0); // a should be unchanged
	YAFFUT_EQUAL(a.getImag(), 2.0);

	b = -b; 			//b should get the value (-7.0, -14.0)
	YAFFUT_EQUAL(b.getReal(), -7.0);
	YAFFUT_EQUAL(b.getImag(), -14.0);

	b = -c;				//b should get the value (-3.0, -0.0)
	YAFFUT_EQUAL(b.getReal(), -3.0);
	YAFFUT_EQUAL(b.getImag(), 0.0);
	YAFFUT_EQUAL(c.getReal(), 3.0); // c should be unchanged
	YAFFUT_EQUAL(c.getImag(), 0.0);
	
}

