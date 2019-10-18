#include <stdio.h>
#include <stdlib.h>

int main( int argc, const char * argv[] )
{
	FILE * fp = fopen( argv[1], "r" );
	char c;

	while ( ( c = fgetc( fp ) ) != EOF ) {
		printf( "%c", c );
	}

	fclose(fp);

	return 0;
}
