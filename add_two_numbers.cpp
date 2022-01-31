/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL || l2 == NULL )  {
            return NULL;
        } else if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        }
        
        ListNode* l = new ListNode();
        ListNode* head = l;
        int c = 0;
        while( l1 != NULL || l2 != NULL ) {
            l->next = new ListNode();
            l = l->next;
            if (l1 != NULL && l2!= NULL) {
                int sum = l1->val + l2->val + c;
                c = sum/10;
                sum = sum%10;
                l1 = l1->next;
                l2 = l2->next;
                l->val = sum;
            } else if (l1 != NULL) {
                int sum = l1->val + c;
                c = sum/10;
                sum = sum%10;
                l1 = l1->next;
                l->val = sum;
            } else {
                int sum = l2->val + c;
                c = sum/10;
                sum = sum%10;
                l2 = l2->next;
                l->val = sum;
            }
        }
        if (c!=0) {
            l->next = new ListNode();
            l = l->next;
            l->val = c;
        }
        return head->next;
    }
};

// Time Complexity O(Length of longest linked list)