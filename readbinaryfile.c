#include <stdio.h>
#include <stdlib.h>

struct person {
	char name[100];
	unsigned int age;
};

int main( int argc, const char * argv[] )
{
	FILE * in;
	char buffer[100];

	if ( argc < 2 ) {
		printf( "Indique el nombre del archivo de entrada\n" );

		return -1;
	}

	if ( !( in = fopen( argv[1], "r" ) ) ) {
		printf( "No puedo leer en el archivo %s\n", argv[1] );

		return -2;
	}

	struct person p;

	while ( fread( &p, sizeof( struct person ), 1, in ) ) {
		printf( "%s tiene %d anios\n", p.name, p.age );
	}
	fclose( in );

	return 0;
}
