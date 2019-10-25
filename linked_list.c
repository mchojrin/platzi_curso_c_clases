#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int number;
	struct Node * next;
} NODE;

NODE * createNode( int number )
{
	NODE * newNode;

	newNode = malloc( sizeof(NODE) );
	newNode->next = NULL;
	newNode->number = number;

	return newNode;
}

int main( int argc, const char * arg[] )
{
	NODE * start = NULL, * current, *next;
	char goOn;
	int listSize = 0, number;

	do {
		printf( "La lista contiene %d nodos. Ingrese el siguiente numero (0 para finalizar)\n", listSize );
		scanf("%d", &number );
		if ( number ) {
			if ( !start ) {
				start = createNode( number );
				listSize++;
			} else {
				current = start;
				while ( current->next ) {
					current = current->next;
				}
				current->next = createNode( number );
				listSize++;
			}
			goOn = 1;
		} else {
			goOn = 0;
		}
	} while ( goOn );

	current = start;
	printf( "La lista contiene los numeros: \n" );
	while (current) {
		printf( "%d", current->number );
		printf( current->next ? ", " : "\n" );
		current = current->next;
	}

	do {
		printf( "¿Qué número desea eliminar? (0 para terminar): ");
		scanf( "%d", &number );
		if ( number ) {
			NODE * previous = NULL;
			current = start;

			while ( current ) {
				next = current->next;
				if ( current->number == number ) {
					free( current );
					if (  previous ) {
						previous->next = next;
						current = next;
					} else {
						start = current = next;
					}
				} else {
					previous = current;
					current = next;					
				}
			}
		}
	} while ( number );

	current = start;
	printf( "La lista contiene los numeros: \n" );
	while (current) {
		printf( "%d", current->number );
		printf( current->next ? ", " : "\n" );
		current = current->next;
	}

	printf( "Liberando!\n" );
	current = start;
	while (current) {
		next = current->next;
		free( current );
		current = next;
	}

	printf( "Todo liberado!\n" );

	return 0;
}
