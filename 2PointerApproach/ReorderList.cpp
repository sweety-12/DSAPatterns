Problem 5 — Reorder List (Medium)
Platform: LeetCode 143

Problem Statement:
Given the head of a linked list:
L0 → L1 → L2 → ... → Ln-1 → Ln
Reorder it to:
L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ...
Do not modify node values — only change pointers.

Examples:
Example 1:
Input:  1 → 2 → 3 → 4
Output: 1 → 4 → 2 → 3
Example 2:
Input:  1 → 2 → 3 → 4 → 5
Output: 1 → 5 → 2 → 4 → 3

Constraints:

Number of nodes: 1 to 5 × 10⁴
1 <= Node.val <= 1000


This problem uses EVERYTHING from Phase 3:
Step 1 → Find middle        (slow/fast pointers)
Step 2 → Reverse 2nd half   (reverse function)
Step 3 → Merge both halves  (two pointer merge)

////////////////////////////////////////////////////////////

Node * reorderList(Node * head){

//Edge case
if(head == NULL ) return NULL;
if(head->next == NULL) return head;

//FIND MIDDLE
Node* slow = head;
Node* fast = head;

while(fast != NULL && fast->next != NULL) {
slow = slow->next;
fast = fast->next->next;
}

//REVERSE
Node* prev = NULL;
Node* curr = slow->next;

while(curr != NULL) {
Node* next = curr->next;
curr->next = prev;
prev = curr;
curr = next;
}
//TILL HERE SLOW->NEXT IS NOW NULL AND FAST IS AT LAST NODE(start of 2nd half)
//REORDER
slow = head;
while(slow != NULL && prev != NULL) {

Node* temp1 = slow->next;
slow->next = prev;

Node* temp2 = prev->next;
prev->next = temp1;

slow = temp1;
prev = temp2;


}
slow->next = NULL; //NEED TO END THE REORDERED LINKEDLIST

return head;
}
