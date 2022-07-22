#include<bits/stdc++.h>
using namespace std;
  
  struct ListNode {
     int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
     ListNode* lcurrent;
        ListNode* lprev=NULL;
        ListNode* lnext;
    
        lcurrent = head;
           
        while(lcurrent!=NULL){  
            lnext=lcurrent->next;
            lcurrent->next=lprev;
            lprev=lcurrent;
            lcurrent=lnext;
        }
        return lprev;
    }
};