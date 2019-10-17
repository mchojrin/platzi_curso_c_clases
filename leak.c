#include <stdio.h>
#include <stdlib.h>

int main()
{
	char * p = NULL;

	for ( int i = 0; i < 10; i++ ) {
		printf( "%d - Alocando 50 chars\n", i );
		if ( p ) {
			free( p );
		}
		p = malloc( sizeof(char) * 50 );
	}

	printf( "Terminado!\n" );
	free( p );
}
