// OperatorOverloading_FastAngle.cpp : Defines the entry point for the console application.
//

#include "FastAngle.h"
#include <iostream>
using namespace std;

int main(int argc, const char* argv[])
{
	(void)argc;
	(void)argv;
	FastAngle l_Angle;
	const FastAngle l_Angle30deg  = FastAngle::Deg2FastAngle(30);
	const FastAngle l_Angle60deg  = FastAngle::Deg2FastAngle(60);
	const FastAngle l_Angle70deg  = FastAngle::Deg2FastAngle(70);
	const FastAngle l_Angle210deg = FastAngle::Deg2FastAngle(210);
	const FastAngle l_Angle330deg = FastAngle::Deg2FastAngle(330);
	
	l_Angle = l_Angle70deg * 6;  //result should be about 70*6 = 420 = 60 degrees but not 100% accurate!
	cout << "70 deg * 6 = " << FastAngle::FastAngle2Deg(l_Angle) << " deg" << endl;

	cout << "cos 60deg  = " << cos(l_Angle60deg) << " and should be about 0.5" << endl;
	cout << "cos 30deg  = " << cos(l_Angle30deg) << " and should be about 0.86" << endl;
	cout << "sin 60deg  = " << sin(l_Angle60deg) << " and should be about 0.86" << endl;
	cout << "sin 30deg  = " << sin(l_Angle30deg) << " and should be about 0.5" << endl;

	cout << "cos 210deg = " << cos(l_Angle210deg) << endl;
	cout << "cos 330deg = " << cos(l_Angle330deg) << endl;
	cout << "sin 210deg = " << sin(l_Angle210deg) << endl;
	cout << "sin 330deg = " << sin(l_Angle330deg) << endl;

	l_Angle = l_Angle60deg + l_Angle70deg;
	cout << "60deg + 70 deg                    = " << FastAngle::FastAngle2Degf(l_Angle) <<"deg" << endl;
	l_Angle *= 8;
	// cout << "and that times 8 modulo 360       = " << FastAngle::FastAngle2Degf(l_Angle) <<"deg" << endl;
	// l_Angle /= 2;
	// cout << "and that divided by 2 modulo 360  = " << FastAngle::FastAngle2Degf(l_Angle) <<"deg" << endl;
	// l_Angle *= 2.5f;
	// cout << "and that times 2.5 modulo 360     = " << FastAngle::FastAngle2Degf(l_Angle) <<"deg" << endl;
	// l_Angle -= l_Angle210deg;
	// cout << "and that minus 210 deg modulo 360 = " << FastAngle::FastAngle2Degf(l_Angle) <<"deg" << endl;
	// l_Angle += l_Angle30deg;
	// cout << "and that plus 30 deg modulo 360   = " << FastAngle::FastAngle2Degf(l_Angle) <<"deg" << endl;

	// cout << "30 deg < 210 deg = " << ((l_Angle30deg < l_Angle210deg) ? "true": "false") << endl;
	// cout << "30 deg > 210 deg = " << ((l_Angle30deg > l_Angle210deg) ? "true": "false") << endl;
	// cout << "30 deg < (330+70) deg = " << ((l_Angle30deg < (l_Angle330deg+l_Angle70deg)) ? "true": "false") << endl;
	// cout << "60 deg < (330+70) deg = " << ((l_Angle60deg < (l_Angle330deg+l_Angle70deg)) ? "true": "false") << endl;
	return 0;
}

