/*You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
*/


  //Definition for singly-linked list.
  struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* l3 = new ListNode();
            ListNode* l4 = l3;
            int total=0 , carry = 0 ;
    
            while (l1 || l2 || carry ){
                total = carry;
                if(l1){
                    total +=l1 ->val;
                    l1= l1 ->next;
                }
                if(l2){
                    total += l2 -> val;
                    l2 = l2->next;
                }
    
                int num = total %10;
                carry = total/10;
                l3 -> next = new ListNode(num);
                l3 = l3->next;
            }     
            ListNode* result = l4 -> next;
            delete l4; 
            return result;  
        }
    };