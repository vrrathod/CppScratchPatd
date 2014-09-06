#include <iostream>
#include <array>
#include <ctime>

using namespace std;

class fibonacci;

static fibonacci *g_fiboPtr = NULL;

class fibonacci
{
	fibonacci() {
		arrNumbers[0] = 1;
		arrNumbers[1] = 1;
	}
	
	fibonacci( fibonacci& );
	void operator = ( fibonacci& );


	array<unsigned int, 100> arrNumbers;
public:
	// ~fibonacci() {}

	static fibonacci* getSingleton() {
		// static fibonacci *g_fiboPtr;
		if( !g_fiboPtr ) {
			g_fiboPtr = new fibonacci();
		}
		return g_fiboPtr;
	}

	static void cleanup() {
		if( g_fiboPtr ) {
			delete g_fiboPtr;
			g_fiboPtr = NULL;
		}
	}

	unsigned int getNthFibo(unsigned int n) {
		if ( 100 < n ) {
			cout << "we limit it to 100" << endl;
			return 0;
		}
		// cout << "id : " << n << endl;
		if( n < arrNumbers.size() && 0 != arrNumbers[n] ) {
			return arrNumbers[n];
		} else {
			unsigned int value = getNthFibo(n-1) + getNthFibo(n-2);
			arrNumbers[n] = value;
			return arrNumbers[n];
		}
	}
};

int fibo(int n) {
	// cout <<  n << endl;
	if( 0 == n || 1 == n ) {
		return 1;
	} else {
		return fibo(n-1) + fibo(n-2);
	}
}
int main (int argc, char** argv) {
	clock_t start, end;

	int i = 90;
	// for( int i = 0; i < 35; ++i) {
		cout << endl << " index " << i << "--";
		start = clock();
		fibonacci* f = fibonacci::getSingleton();
		cout << hex << "[ " << f->getNthFibo(i) << " ] " << dec;
		// f.getNthFibo(i);
		end = clock();
		cout << end - start << "--";

		start = clock();
		cout << endl << hex << "[ " << f->getNthFibo(10) << "]" ;
		end = clock();
		cout << end - start << "--" << endl;

		// start = clock();
		// // fibo(fiboNumber) ;
		// cout <<  "[ " << hex << fibo(i) << dec << " ] ";
		// end = clock();
		// cout << end - start;
	// }

	cout << endl << endl;
	return 0;
}