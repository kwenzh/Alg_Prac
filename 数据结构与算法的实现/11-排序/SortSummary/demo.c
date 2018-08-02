#include<stdio.h>

#include"KWENSORTTOOLS.h"


int main(void) {
	long before_time;
	long after_time;
	long total_Time;
	int i;
	const int randomDataCeil = 1000;
	const int randomDataLow = 1;
	const int array_length = 100000;
	int *array;

	for(i = 0; i < ALLSORT_LENGTH; i++) {
		array = createArray(array_length, randomDataCeil, randomDataLow);
		before_time = clock();
		allsort(array, array_length, i);
		after_time = clock();
		total_Time = after_time - before_time;
		printf("%d datas %s :  %ld.%03ld s\n",
		 array_length, sortName[i], total_Time / 1000, total_Time % 1000);
	}
	// showArray(array, array_length);

	kwen_free(array);

	return 0;
}
