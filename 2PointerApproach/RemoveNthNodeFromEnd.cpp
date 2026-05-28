Problem 3 — Remove Nth Node From End (Medium)
Platform: LeetCode 19

Problem Statement:
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Examples:
Example 1:
1 → 2 → 3 → 4 → 5
              ↑
         remove 2nd from end

Output: 1 → 2 → 3 → 5
Example 2:
1
remove 1st from end

Output: null
Example 3:
1 → 2
remove 2nd from end (remove 1)

Output: 2

Constraints:

Number of nodes: 1 to 30
0 <= Node.val <= 100
1 <= n <= size of list


Expected Complexities:

Brute Force → O(n) time, O(1) space (two pass)
Optimized → O(n) time, O(1) space (one pass) ← this is the goal

////////////////////////////////////////////////////////////

OPTIMIZED :

Node * removeNode(Node * head, int n){

if(head == NULL) return NULL;

Node * slow = head;
Node * fast = head;

//STEP 1
while(n>0) {
fast = fast->next;
n--;
}

if(fast == NULL) return head->next;

//STEP 2
while(fast->next != NULL) {
slow = slow->next;
fast = fast->next;
}

//STEP 3
//SLOW IS AT THE NODE WHOSE NEXT IS TO BE DELETED
Node * temp = slow->next;
slow ->next = slow->next->next;
delete(temp);

return head;

}
