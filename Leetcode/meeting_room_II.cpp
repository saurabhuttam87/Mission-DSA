#include <vector>
#include <algorithm> 
using namespace std;
// This code is a solution to the problem of finding the minimum number of meeting rooms required to hold all meetings without overlap.

class Solution {
public:
   
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = 1000010; 
        vector<int> countDelta(n); 
       
        for (auto &interval : intervals) {
            ++countDelta[interval[0]]; 
            --countDelta[interval[1]]; 
        }

        
        for (int i = 0; i < n - 1; ++i) {
            countDelta[i + 1] += countDelta[i];
        }

        
        return *max_element(countDelta.begin(), countDelta.end()); 
    }
};