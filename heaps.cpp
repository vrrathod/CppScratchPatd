#include <queue>
#include <iostream>
 
using namespace std;
 
struct minCompare{
    bool operator() ( int i, int j){
        return i < j;
    }
};


struct maxCompare{
    bool operator() ( int i, int j){
        return i > j;
    }
};
 
int main(int argc, char const *argv[])
{
    priority_queue<int, std::vector<int>, minCompare> minHeap;
    priority_queue<int, std::vector<int>, maxCompare> maxHeap;
 
    int arr[] = {12,3,4,5,10,3};
    for (unsigned int i = 0; i < (sizeof(arr) / sizeof arr[0]); i++) {
        minHeap.push(arr[i]);
        maxHeap.push(arr[i]);
    }
    
    while ( !minHeap.empty()){
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;

    while ( !maxHeap.empty()){
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;

    return 0;
}