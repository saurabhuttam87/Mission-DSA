#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// The function pylons calculates the minimum number of power plants needed to cover all houses in a given array.
int pylons(int k, vector<int> arr) {
    int need_power = 0;
    int count = 0;
    
    while (need_power < arr.size()){
        bool plant_not_found = true;
        for(auto i = k-1; i >= -k+1 ; i--){
            
            if ((need_power + i < arr.size()) &&  (need_power + i >= 0) and (arr[need_power+i] == 1)){
                count += 1;
                need_power += k + i;
                plant_not_found = false; 
                break; 
            }
        }
        
        if (plant_not_found) return -1; 
    }
    return count; 
}