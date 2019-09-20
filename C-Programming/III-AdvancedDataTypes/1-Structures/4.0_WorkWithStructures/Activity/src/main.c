#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

/* function prototypes */
void printDate(struct date);
void readDate(struct date *);
struct date advanceDay(struct date); 

int main(void) {
	struct date today, tomorrow;
	readDate(&today);
	printDate(today);
	tomorrow = advanceDay(today);
	printDate(tomorrow);
	return 0;
}

/* add your function definitions here */
void printDate(struct date data) 
{
	printf("%.02d/%.02d/%.02d\n", data.month, data.day, data.year);
}

void readDate(struct date *data)
{
	scanf("%d", &data->year);
	scanf("%d", &data->month);
	scanf("%d", &data->day);
}

struct date advanceDay(struct date data) 
{
	int qty_dias;
	if (data.month == 1 || data.month == 3 || data.month == 5 ||  \
		data.month == 7 || data.month == 8 || data.month == 10 || \
		data.month == 12) {
		qty_dias = 31;
	}
	else if(data.month == 4 || data.month == 6 || data.month == 9 || \
		    data.month == 11) {
		qty_dias = 30;
	}
	else {
		qty_dias = 28;
	}

	if (qty_dias == 31 && data.day == 31) {
		if (data.month == 12) {
			data.day = 1;
			data.month = 1;
			data.year += 1;
		}
		else {
			data.day = 1;
			data.month += 1;
		}
	}
	else if (qty_dias == 30 && data.day == 30 ) {
		data.day = 1;
		data.month += 1;
	}
	else if (qty_dias == 28 && data.day == 28 ) {
		data.day = 1;
		data.month += 1;
	}

	else {
		data.day += 1;
	}

	return data;
}