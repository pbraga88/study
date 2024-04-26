#include "FastAngle.h"
#include <iostream>
#include <math.h>

const float PIx2=6.283185307f;

FastAngle FastAngle::Deg2FastAngle(const int &a_NrDeg)
{
	FastAngle l_Result((a_NrDeg << 16) / 360);
	std::cout<<l_Result.m_Angle<<std::endl;
	return l_Result;
}
FastAngle FastAngle::Deg2FastAngle(const float &a_NrDeg)
{
	FastAngle l_Result(static_cast<uint16_t>((a_NrDeg * 65536.0f) / 360.0f));
	return l_Result;
}

int FastAngle::FastAngle2Deg(const FastAngle &a_Angle) {
	// convert back 
	int angle = (a_Angle.m_Angle * 360) >> 16;

	return static_cast<int>(angle);
}

float FastAngle::FastAngle2Degf(const FastAngle &a_Angle) {
	//((a_NrDeg * 65536.0f) / 360.0f)
	
	float angle = (a_Angle.m_Angle * 360.0F) / 65536.0f;
	return angle;
}

//all other methods are still to be defined

// Friend functions (operators)
FastAngle operator*(const FastAngle& fa, int escalar) {
		// convert the angle to do the multiplication
		int angle = (((fa.m_Angle * 360) >> 16) * escalar)%360;
		
		std::cout<<"angle: "<<angle<<std::endl;
		// Convet back to store in the object
		return FastAngle(static_cast<uint16_t>((angle << 16) / 360));
}

FastAngle operator*(const FastAngle& fa, float escalar) {
		// convert the angle to do the multiplication
		int angle = (((fa.m_Angle * 360) >> 16) * static_cast<int>(escalar))%360;
		
		std::cout<<"angle: "<<angle<<std::endl;
		// Convet back to store in the object
		return FastAngle(static_cast<uint16_t>((angle << 16) / 360));
}
FastAngle operator+(const FastAngle& a, const FastAngle& b) {
	return FastAngle(a.m_Angle + b.m_Angle);
}

// Friend functions (sen/cos)
float cos(const FastAngle& a_Arg1) {
	// std::cout<<"((a_Arg1.m_Angle * 360) >> 16) -> "<<((a_Arg1.m_Angle * 360) >> 16)<<std::endl;
	return cos(((a_Arg1.m_Angle * 360) >> 16));
}
float sin(const FastAngle& a_Arg1) {
	// std::cout<<"((a_Arg1.m_Angle * 360) >> 16) -> "<<((a_Arg1.m_Angle * 360) >> 16)<<std::endl;
	return sin(((a_Arg1.m_Angle * 360) >> 16));
}