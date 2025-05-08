#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Function to find the size of the largest subset of s such that the sum of any two numbers in the subset is not divisible by k
// The function takes an integer k and a vector of integers s as input
int nonDivisibleSubset(int k, vector<int> s) {
    vector<int> r(k);
    for (size_t i = 0; i < s.size(); i++) {
        r[s[i] % k]++;
    }
    r[k/2] = (k % 2 == 0) ? 1 : r[k/2];
    int c = (r[0] > 0) ? 1 : 0;
    for (size_t i = 1; i < k/2 + 1; i++) {
        c += (r[i] >= r[k-i]) ? r[i] : r[k-i];
    }
    return c;
}