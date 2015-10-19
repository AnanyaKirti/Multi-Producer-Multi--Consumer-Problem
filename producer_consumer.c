/**********************
**	Ananya Kirti
**	Vamsi 
**********************/


#include <stdio.h>		// Standard Input-Output
#include <stdlib.h>		// Standard Functoins

#include <pthread.h>	// Threading Library


#define BUFFER 100		// Max BufferSize 
int buffer = 0;

pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;	// mutex lock to avoid race conditions

void *producer(void *vargp){						// Producer Thread Function
	int my = (int)vargp;
	while(1){
		pthread_mutex_lock(&mutex);		// Check if resource is free.
		if(buffer < BUFFER){			// Check if the buffer is not full.
			buffer++;
			printf("Buffer Incremented^ \tby Thread: %d \tCurrent Size: %d\n",my,buffer );
			//sleep(1);
		}
		else{
			printf("Buffer OVERFLOW \t\t\tCurrent Size: %d\n",buffer );
		}
		pthread_mutex_unlock(&mutex);	// free the resource.
	}
	return NULL;
}

void *consumer(void *vargp){						// Consumer Function
	int my = (int)vargp;
	while(1){
		pthread_mutex_lock(&mutex);		// Check if resource is free.
		if(buffer > 0){					// Check if the buffer is not full.
			buffer--;
			printf("Buffer Decremented \tby Thread: %d \tCurrent Size: %d\n",my,buffer );
			// sleep(1);
		}
		else{
			printf("Buffer UNDERFLOW \t\t\tCurrent Size: %d\n",buffer );
		}
		pthread_mutex_unlock(&mutex);	// free the resource.
	}
	return NULL;
}

int main(int argc, char const *argv[]){
	// command line input.
	const int no_of_producers = atoi(argv[1]);
	const int no_of_consumer = atoi(argv[2]);

	pthread_t ptid[no_of_producers], ctid[no_of_consumer];






	int i ;
	for (i = 0; i < no_of_producers; ++i){
		pthread_create(&ptid[i], NULL, producer, (void *)i);		// initialise all the threads.
	}

	for (i = 0; i < no_of_consumer; ++i){
		pthread_create(&ctid[i], NULL, consumer, (void *)i);		// initialise all the threads.
	}
	




	for (i = 0; i < no_of_producers; ++i){
		pthread_join(ptid[i], NULL);
	}
	
	for (i = 0; i < no_of_consumer; ++i){
		pthread_join(ctid[i], NULL);
	}



	return 0;
}