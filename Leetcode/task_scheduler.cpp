#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// This code is a solution to the problem of finding the shortest subarray with a sum at least k.
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for(char task : tasks){
            freq[task - 'A']++;
        }
        sort(begin(freq), end(freq));
        int chunk = freq[25] - 1;
        int idel = chunk * n;

        for(int i = 24; i >= 0; i--) {
            idel -= min(chunk, freq[i]);
        }

        return tasks.size() + max(0, idel);
    }
};