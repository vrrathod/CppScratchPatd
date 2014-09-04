#include <iostream>
#include <array>
#include <ctime>

using namespace std;

class fibonacci
{
	fibonacci() {
		arrNumbers[0] = 1;
		arrNumbers[1] = 1;
	}
	
	fibonacci( fibonacci& );
	void operator = ( fibonacci& );


	array<int, 35> arrNumbers;
public:
	// ~fibonacci() {}

	static fibonacci* getSingleton() {
		static fibonacci *g_fiboPtr;
		if( !g_fiboPtr ) {
			g_fiboPtr = new fibonacci();
		}
		return g_fiboPtr;
	}

	int getNthFibo(int n) {
		// cout << "id : " << n << endl;
		if( n < arrNumbers.size() && 0 != arrNumbers[n] ) {
			return arrNumbers[n];
		} else {
			int value = getNthFibo(n-1) + getNthFibo(n-2);
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

	for( int i = 0; i < 35; ++i) {
		cout << endl << " index " << i << "--";
		start = clock();
		fibonacci* f = fibonacci::getSingleton();
		cout <<  "[ " << f->getNthFibo(i) << " ] ";
		// f.getNthFibo(i);
		end = clock();
		cout << end - start << "--";

		start = clock();
		// fibo(fiboNumber) ;
		cout <<  "[ " << fibo(i) << " ] ";
		end = clock();
		cout << end - start;
	}

	cout << endl << endl;
	return 0;
}