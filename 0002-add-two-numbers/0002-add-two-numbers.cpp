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
        ListNode* root = new ListNode(0);
        ListNode* tail = root;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int n1 = 0;
            if(l1 != nullptr){
                n1 = l1->val;
            }
            int n2 = 0;
            if(l2 != nullptr){
                n2 = l2->val;
            }
            int sum = n1+n2+carry;
            int rem = sum%10;
            carry = sum/10;

            ListNode* newNode = new ListNode(rem);
            tail->next = newNode;
            tail = tail->next;

            if(l1 != nullptr){
                l1 = l1->next;
            }
            else{
                l1 == nullptr;
            }

            if(l2 != nullptr){
                l2 = l2->next;
            }
            else{
                l2 == nullptr;
            }
        }

        ListNode* ans = root->next;
        delete root;
        return ans;
    }
};