#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, const char * argv[] )
{
	FILE * out;
	char buffer[100];

	if ( !( out = fopen( argv[1], "w" ) ) ) {
		printf( "No puedo escribir el archivo %s\n", argv[1] );

		return -1;
	}

	do {
		printf("Ingrese una palabra:" );
		scanf("%99s", buffer);
		fputs( buffer, out );
		fputs("\n", out);
		printf("Grabada! Otra? (s/n)" );
		scanf("%1s", buffer);
	} while ( buffer[0] != 'n' );

	fclose( out );

	return 0;
}
