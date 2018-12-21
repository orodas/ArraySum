//Oscar Rodas
//ArraySum.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
clock_t t;
int main(void)
{
	t = clock();
	int i;
	int array [20000];
	srand(time(NULL));
	int sum = 0;
	for(i = 0; i < 20000; i++)
	{
		array[i] = rand() % 201 - 100;
		//printf("array[%d] = %d\n", i, array[i]);
		sum += array[i];
	}
	printf("sum = %d\n", sum);
	double time_taken = ((double)t)/CLOCKS_PER_SEC;			
	printf("I took %f seconds to execute \n", time_taken);
	return 0;
}