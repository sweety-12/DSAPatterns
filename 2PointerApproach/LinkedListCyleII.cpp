Linked List Cycle II 
Platform: LeetCode 142 (Medium)

Problem Statement:
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
There is a cycle if some node in the list can be reached again by continuously following the next pointer.
Do not modify the linked list.

Examples:
Example 1:
3 → 2 → 0 → -4
    ↑            |
    └────────────┘

Input: head = [3,2,0,-4], pos = 1
Output: node at index 1 (value = 2)
Example 2:
1 → 2
↑       |
└───────┘

Input: head = [1,2], pos = 0
Output: node at index 0 (value = 1)
Example 3:
1 → null

Input: head = [1], pos = -1
Output: null (no cycle)

Constraints:

Number of nodes: 0 to 10⁴
-10⁵ <= Node.val <= 10⁵
pos is -1 or a valid index in the list


Expected Complexities:

Brute Force → O(n) time, O(n) space
Optimized → O(n) time, O(1) space


Brute force first, then optimized. 🔥

OPTIMIZED:

Node * detectCycle(Node * head){

    //edge case
    if(head == NULL || head ->next == NULL)  return NULL;
    
    Node * ans = NULL;

    Node * slow = head;
    Node * fast = head;

    while(fast != NULL && fast->next != NULL){

        slow = slow->next;
        fast = fast ->next ->next;

        if(slow == fast){
            ans = slow;
        }
    }

    return ans;
}
