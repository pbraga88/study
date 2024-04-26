// #include "stdafx.h"
#include <string.h>
#include <iostream>

using namespace std;

// Rewrite the code and use delegated constructors and default-member initialization
// Note: For educational reasons: leave all DoInit(); in the current code

class ImageSensor
{
protected:
	void DoInit()
	{
		cout << "DOINIT initialisation: " << typeid(*this).name() << " with values height:" << height << " width:" << width << endl;
	}
public:
	ImageSensor(int aHeight, int aWidth)
		: height(aHeight)
		, width(aWidth)
	{
		DoInit();
	}

	ImageSensor() : ImageSensor(0, 0)
	{
		DoInit();
	}

	ImageSensor(int dimension[2]) : ImageSensor(dimension[0], dimension[1])
	{
		DoInit();
	}

	protected:
	int height;
	int width;
};

class ImageSensorWithGain : public ImageSensor
{
public:
	ImageSensorWithGain() : ImageSensorWithGain(0,0,1)//   ImageSensor(0, 0), gain(1)
	{
		DoInit();
	}

	ImageSensorWithGain(int aHeight, int aWidth) : ImageSensorWithGain(aHeight, aWidth, 1)
		// : ImageSensor(aHeight, aWidth)
		// , gain(1)
	{
		DoInit();
	}

	ImageSensorWithGain(int aHeight, int aWidth, int aGain) 
		: ImageSensor(aHeight, aWidth)
		, gain(aGain)
	{
		DoInit();
	}

private:
	int gain {0};

};

int main(int argc, char* argv[])
{
	(void)argc;
	(void)argv;
	ImageSensor a;
	ImageSensor b(2, 4);

	ImageSensorWithGain gainSensor1;
	ImageSensorWithGain gainSensor2(10, 20);
	ImageSensorWithGain gainSensor3(42, 42, 3);

	return 0;
}
