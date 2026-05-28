Problem 4 — Palindrome Linked List (Easy)
Platform: LeetCode 234

Problem Statement:
Given the head of a linked list, return true if it is a palindrome, or false otherwise.

Examples:
Example 1:
1 → 2 → 2 → 1
Output: true
Example 2:
1 → 2 → 3
Output: false
Example 3:
1 → 2 → 1
Output: true

Constraints:

Number of nodes: 1 to 10⁵
0 <= Node.val <= 100


Expected Complexities:

Brute Force → O(n) time, O(n) space
Optimized → O(n) time, O(1) space


Hint — Algorithms needed (2 combined):
Step 1 → Find middle (slow/fast pointers)
Step 2 → Reverse second half
Step 3 → Compare both halves

////////////////////////////////////////////////////////////
OPTIMIZED : TC : O(n) and SC : O(1)

Node* reverse(Node* head){
Node* prev = NULL;
Node* cur = head;

while(cur != NULL){
Node* next = cur->next; // save
cur->next = prev; // flip
prev = cur; // move prev
cur = next; // move cur
}
return prev; // prev is new head
}

bool isPalindrome(Node * head) {
// bool istrue = true;

Node * slow = head;
Node * fast = head;

while(fast->next != NULL && fast->next->next != NULL) {

slow = slow->next;
fast = fast->next->next;
}

//SLOW IS AT MIDDLE
fast = slow->next;
slow = head;

//REVERSE THE 2ND HALF
fast = reverse(fast);

while(fast != NULL) {

if(slow->data != fast->data) {
return false;
}
slow = slow->next;
fast = fast->next;
}

return true;
}

TC : O(n) and SC : O(1)
