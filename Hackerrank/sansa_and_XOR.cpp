#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Complete the sansaXor function below.
int sansaXor(vector<int> arr) {
    unsigned int l = arr.size()   ;
    int result = 0;
    if(l%2 == 0) return 0;
    for(unsigned int i = 0; i<l; i+=2)
        result ^= arr[i];
    return result   ;
}