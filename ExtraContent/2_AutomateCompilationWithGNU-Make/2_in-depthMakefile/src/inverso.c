#include <assert.h>

double inverso(int num){
	if(NDEBUG)
		assert(num != 0);

	return 1.0/num;
}