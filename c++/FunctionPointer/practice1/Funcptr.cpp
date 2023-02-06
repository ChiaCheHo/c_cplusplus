#include <istream>
#include <cstdlib>
using namespace std;

typedef int(*CustomOperator)(int);

int power2( int v )
{
	return v * v;
}

// void custom_for_each( int *pArray, unsigned int size, int (*op)( int ) )
void custom_for_each( int *pArray, unsigned int size, CustomOperator op)
{
	for( unsigned int i = 0; i < size; ++ i )
		pArray[i] = (*op)( pArray[i] );
}

int main( int argc, char* argv[] )
{
	if ( argc != 2 ) {
        printf("usage: Enter a number...\n");
        return -1;
    }

	int size = atoi(argv[1]);
	int* pArray = new int[ size ];

	for( unsigned int i = 0; i < size; ++ i )
		pArray[i] = i;

	custom_for_each( pArray, size, &power2 );

	for( unsigned int i = 0; i < size; ++ i )
		printf( "%d,\n", pArray[i] );

	delete [] pArray;
	return 0;
}

// int main()
// {
//     printf("Hollo World~\n");
//     return 0;
// }