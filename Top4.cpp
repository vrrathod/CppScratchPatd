// FindHighestFour.cpp 
// 
 
#include <iostream>
#include <vector>
#include <list>
#include <limits>
#include <algorithm>
#include <iterator>

/*
 * generateValues() - This function provides abstraction to generate values.
 * It returns std::list<int> of values. Potentially this could be expanded to 
 * read file and generate list based on the values stored.
 *
 * @return std::list<int> - list of integer values
 */

std::list<int> generateValues()
{
    int array[] = { 1, 2,3,4,5,6,7,8,9,10,11,12,14,13,100,43, 53 };
    
    std::list<int> intList;
    
    int nLength = sizeof(array) / sizeof(array[0]);
    
    for(int i = 0; i < nLength; ++i)
        intList.push_back(array[i]);
    
    return intList;
}

/*
 * getHighestFour() - Given begin and end iterators, this function tries to find
 * four maximum values. It expects both these iterators to be std::list<int> 
 * iterators.
 * 
 * In case given list is empty, it shall return an empty vector.
 * In case given list contains less than 4 values, it shall return same number 
 * of values in decreasing value.
 * 
 * @param begin - std::list<int>::iterator. specifies initial position in the 
 *                given list.
 * @param end   - std::list<int>::const_iterator. specifies ending position in 
 *                the given list. It is defined as constant because we do not 
 *                intend to change it.
 *
 * requires  <vector>, <list>
 *
 * complexity : one loop from begin to end           => O(n)
 *              one comparison and 4 assignment      => O(N*5) @ worst case
 *              four comparison + 4+3+2+1 assignment => O(N*4 + 10) @ best case 
 *                                                      essentially k*(k+1)/2
 * space : const (4 variables)
 *
 * @return std::vector<int> - with 0th position being highest.
 */
std::vector<int> getHighestFour(std::list<int>::iterator begin,
                                std::list<int>::const_iterator end) {
    // counter - should keep track of number of values
    unsigned int uCounter = 0;
    
    // names specifies the role
    int nHighest = std::numeric_limits<int>::min();
    int nSecondToHighest = std::numeric_limits<int>::min();
    int nThirdToHighest = std::numeric_limits<int>::min();
    int nFouthToHighest = std::numeric_limits<int>::min();
    
    // iterate over list to find top 4 values
    while (begin != end) {
        if (*begin > nHighest) {
            nFouthToHighest  = nThirdToHighest;
            nThirdToHighest  = nSecondToHighest;
            nSecondToHighest = nHighest;
            nHighest = *begin;
        } else if (*begin > nSecondToHighest) {
            nFouthToHighest  = nThirdToHighest;
            nThirdToHighest  = nSecondToHighest;
            nSecondToHighest = *begin;
        } else if (*begin > nThirdToHighest) {
            nFouthToHighest  = nThirdToHighest;
            nThirdToHighest  = *begin;
        } else if (*begin > nThirdToHighest) {
            nFouthToHighest  = *begin;
        }
        uCounter++;
        begin++;
    }
    
    // create vector with appropriate number of values in descending order
    // i.e. 0th element being highest value and
    std::vector<int> vecHighestValues;
    if (uCounter > 0) vecHighestValues.push_back(nHighest);
    if (uCounter > 1) vecHighestValues.push_back(nSecondToHighest);
    if (uCounter > 2) vecHighestValues.push_back(nThirdToHighest);
    if (uCounter > 3) vecHighestValues.push_back(nFouthToHighest);
    
    return vecHighestValues;
}

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	std::list<int> listVal = generateValues();

	std::vector<int> highestFour = getHighestFour(listVal.begin(),
		listVal.end());

	std::copy(highestFour.begin(),
		highestFour.end(),
		std::ostream_iterator<int>(std::cout, " > ") );

	std::cout<<std::endl;

	return 0;
}

