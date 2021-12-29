#include <stdio.h>

#define TRACE_LOG(fmt, args...) fprintf(stdout, fmt, ##args)

int main()
{
	int i=1;
	char * text_log = "Sample macro";
	TRACE_LOG("%s \n", text_log);
	TRACE_LOG("%d %s \n", i, text_log);
	return 0;

	return 0;
}