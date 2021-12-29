#pragma once

// Pure virtual class, representing the 
// "freezable" capability

class Freezable
{
	public:
		virtual void freeze() = 0;
		virtual void unfreeze() = 0;
};