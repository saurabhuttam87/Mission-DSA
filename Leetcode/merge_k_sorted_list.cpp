#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
           vector<int>datas;
           for(ListNode* i:lists) {
            while(i) {
                datas.push_back(i->val);
                i=i->next;
            }
            
           }
           sort(datas.begin(),datas.end());
    
           ListNode* dummy = new ListNode(-1);
           ListNode*temp = dummy;
           for(int j:datas) {
            temp->next = new ListNode(j);
            temp = temp->next;
           } 
           return dummy->next;
        }
    };