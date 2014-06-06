
#include <iostream>

using namespace std;

int main( int argc, char** argv ) {
  
  int a[5][5] = {
    { 1, 2, 3, 4, 5 },
    { 6, 7, 8, 9, 10},
    { 11, 12, 13, 14, 15},
    { 16, 17, 18, 19, 20},
    { 21, 22, 23, 24, 25},
  };
  
  int rows = 3; // number of rows to print
  int columns = 5; // number of columns to print
  
  int counter = 0;
  int maxCount = rows * columns;
  
  int loweri=0; int upperi=rows;
  int lowerj=0; int upperj=columns;
  int i = loweri;
  int j = lowerj;
  do {
    
    for( ; j < upperj && counter < maxCount; j++, counter++ ) {
      cout << " " << a[i][j] << " ";
    }
    
    cout<< flush;
    j--; loweri++;
    
    for( i++ ; i < upperi  && counter < maxCount; ++i, counter++ ) {
      cout << " " << a[i][j] << " ";
    }
    
    cout<< flush;
    i--; upperj--;
    
    for( j--; j >= lowerj  && counter < maxCount; j--, counter++ ) {
      cout << " " << a[i][j] << " ";
    }
    
    cout<< flush;
    j++; upperi--;
    
    for( i--; i >= loweri  && counter < maxCount; i--, counter++ ) {
      cout << " " << a[i][j] << " ";
    }
    
    lowerj++;i++;j++;
    
    cout<< flush;
    
  } while ( counter < maxCount );
  
  cout << endl;
}
