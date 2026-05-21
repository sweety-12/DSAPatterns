Problem 1 — Linked List Cycle (Easy)
The setup: You're given the head of a linked list. Determine if the list has a cycle in it.
A cycle means some node's next pointer points back to a previous node — so traversal never ends.
Example:
1 → 2 → 3 → 4
        ↑       |
        └───────┘
→ Returns True
1 → 2 → 3 → null
→ Returns False

Your tool: Floyd's Cycle Detection (Fast/Slow pointers)

slow moves 1 step
fast moves 2 steps
If there's a cycle, they will eventually meet
If fast hits null → no cycle

////////////////////////////////////////////////////////////

BRUTE FORCE : Traverse the linkedlist and simultaneously check whether the element is present in the map if not store it. if found return true;
TC : O(n) and SC : O(n)

bool detectCycle(Node * head){

    Node * temp = head;

    unordered_set<Node*> st;

    while(temp != NULL){

        if(st.find(temp) != st.end()){
            return true;
        }

        st.insert(temp);
        temp = temp->next;
    }

    return false;
}
