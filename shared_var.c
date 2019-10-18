#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main( int argc, const char * argv[] )
{
	int shared = 2;
	int pid = fork();
	
	if ( pid ) {
		shared = 1;
		printf( "Luke I am your father. My PID is %d and your PID is %d. shared = %d\n", getpid(), pid, shared );
		wait( NULL );
		printf( "I am your father again. shared = %d\n", 1 );
	} else {
		shared = 0;
		printf( "I am Luke. My PID is %d. shared = %d\n", getpid(), shared );
		sleep(2);
	}

	return 0;
}
