# Producer Consumer Problem


## Introduction
	The Producer Consumer Problem is a famous problem related to synchronization in Operating System. Here there are n producers and m consumers who are operating on a buffer. We have to avoid race conditions, to ensure integrity of the data. I have done this by using Mutex Lock. We simulate this by using threads in POSIX. I have written my code in OS X, however there shouldn't be much difference in Ubuntu as well.

	I have searched the Internet for a solution which offers multiple producers and multiple consumers, and I was unable to find it, this is my implementation.

[Wiki](https://en.wikipedia.org/wiki/Producer–consumer_problem)

## How to run.

	Compile the producer_consumer.c program. and link -lpthread
	To run it pass the no_of_producer and no_of_consumer as command line inputs.

	eg. ./producer_consumer no_of_producer no_of_consumer	-lpthread

	I have assumed a constant buffer of size 10. // this can be changed by changing MAX value in the code.