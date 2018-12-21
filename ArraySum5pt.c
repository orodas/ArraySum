//Oscar Rodas
//ArraySum5pt.c 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

int array [20000];
int sum;
void *runner(void *param);
clock_t t;
int main(void)
{
	t = clock();
	srand(time(NULL));
	
	pthread_t tid; /* the thread identifier */

	int j;
	for(j = 1; j < 5; j++)
	{
		pthread_create(&tid,NULL,runner,(void *)j);
	}
	
	
	int i;
	for(i = 0; i < 4000; i++)
	{
		array[i] = rand() % 201 - 100;
		//printf("array[%d] = %d\n", i, array[i]);
		sum += array[i];
	}

	pthread_join(tid,NULL);
	printf("sum = %d\n", sum);
	double time_taken = ((double)t)/CLOCKS_PER_SEC;			
	printf("I took %f seconds to execute \n", time_taken);
	return 0;
}

void *runner(void *param)
{
	int i;
	int lower = 4000 * (int)param;
	int upper = 4000 + lower;
	srand(time(NULL)+ upper);

	for(i = lower; i < upper; i++)
	{
		array[i] = rand() % 201 - 100;
		//printf("array[%d] = %d\n", i, array[i]);
		sum += array[i];
	}
	pthread_exit(0);
}