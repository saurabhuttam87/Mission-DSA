#include <iostream>
#include <vector>
#include <numeric> 
using namespace std;
// Complete the candies function below.
long candies(int n, vector<int> arr) {
    vector<long> candies(n, 1);
    for(int i = 0; i < n-1; i++){
        if(arr[i] < arr[i+1]){
            candies[i+1] = candies[i]+1;
        }
    }
    for(int i = n-1; i >= 1; i--){
        if(arr[i-1] > arr[i] && candies[i-1] <= candies[i]){
            candies[i-1] = candies[i] + 1;
        }
    }
    return accumulate(candies.begin(), candies.end(), 0LL);
}