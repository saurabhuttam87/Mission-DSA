#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// Complete the highestValuePalindrome function below.
string highestValuePalindrome(string s, int n, int k) {
    std::vector<int> unsatisfied_indexes;
    for(int i=0; i<n/2; ++i) {
        if(s[i] != s[n-i-1]) {
            unsatisfied_indexes.push_back(i);
        }
    }
    
    if(unsatisfied_indexes.size() > k) {
        return "-1";
    }
    
    for(int i=0; i<unsatisfied_indexes.size(); ++i) {
        int first_index = unsatisfied_indexes[i];
        int second_index = n-unsatisfied_indexes[i]-1;
        if(s[first_index] > s[second_index]) {
            s[second_index] = s[first_index];
        } else {
            s[first_index] = s[second_index];
        }
    }
    
    int changes_left = k-unsatisfied_indexes.size();
    
    for(int i=0; i<s.size() && (changes_left > 0); ++i) {
        int first_index = i;
        int second_index = n-i-1;
        
        if(s[first_index] != '9') {
            auto iter = std::find(unsatisfied_indexes.begin(),
            unsatisfied_indexes.end(), i);
            if(iter != unsatisfied_indexes.end()) {
                --changes_left;
            } else { 
                if(changes_left < 2) {
                    break;
                }
                changes_left-=2;
            }
            s[first_index] = '9';
            s[second_index] = '9';
        }
    }
    if(k%2==1 && (changes_left >= 1) && (s[n/2] != '9')) {
        s[n/2] = '9';
        --changes_left;
    }
    
    return s;
}