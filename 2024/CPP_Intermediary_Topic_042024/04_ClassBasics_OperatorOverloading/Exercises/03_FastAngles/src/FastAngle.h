#if !defined(FASTANGLE)
#define FASTANGLE

typedef unsigned short int uint16_t;
#include <iostream>

class FastAngle  
{
public:
	//constructors
	FastAngle(int a_Arg = 0) { m_Angle=static_cast<uint16_t>(a_Arg); }
	FastAngle(uint16_t a_Arg){ m_Angle=a_Arg; }
	//destructor
	virtual ~FastAngle() {}


	uint16_t get_mAngle() {return m_Angle;}

	//conversion: notice the 4 functions below are STATIC CLASS FUNCTIONS! They are like C-functions but within the namespace of the class name
	static FastAngle Deg2FastAngle(const int &a_NrDeg);		
	static FastAngle Deg2FastAngle(const float &a_NrDeg);
	static int   FastAngle2Deg(const FastAngle &a_Angle);
	static float FastAngle2Degf(const FastAngle &a_Angle);

	// Declare and define at least the operators required by main in homeExerciseLesson3.cpp
	// these are:
	// assignement operator=
	FastAngle& operator=(const FastAngle& rhs) {
		std::cout<<"rhs.m_Angle: "<<rhs.m_Angle<<std::endl;
		this->m_Angle = rhs.m_Angle;
		return *this;
	}
	// binary operator *	NOTE: multiply a FastAngle by an integer or float
	//						      it doesn't make sense to multiply an angle with an angle! (would give square angle)
	friend FastAngle operator*(const FastAngle& fa, int escalar);
	friend FastAngle operator*(const FastAngle& fa, float escalar);

	// binary operator +
	friend FastAngle operator+(const FastAngle& a, const FastAngle& b);
	// unary operator +=  
	// unary operator -=
	// unary operator *=    NOTE: multiply a FastAngle by an integer or float
	FastAngle operator*=(int escalar) {
		
	}

	// unary operator /=    NOTE: divide a FastAngle by an integer or float
	// binary operator <	(comparison)
	// binary operator >	(comparison)

	// also define the following 2 functions in FastAngle.cpp
	friend float cos(const FastAngle& a_Arg1);
	friend float sin(const FastAngle& a_Arg1);
	// tip: use a static table that contains a table of 512 cos values (floats)
	//	    initialize this table when it is first used.
	//		use the fastAngle's most significant 9 bits to index in the table
	//		calculate the sin by taking subtracting 90 degrees from the angle
	//		before indexing

	//if you like you can practice a bit more and define also the following operators
	// operator ==
	// operator !=

private:
	uint16_t m_Angle;
};

#endif // !defined(FASTANGLE)
