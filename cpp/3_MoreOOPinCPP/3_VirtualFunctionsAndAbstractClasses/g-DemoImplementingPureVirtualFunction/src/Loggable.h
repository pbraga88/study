#pragma once
#include <string>

using namespace std;

// Pure virtual class, representing the
// "loggable" capability

class Loggable
{
	public:
		virtual void log(const string &message) const = 0;
};