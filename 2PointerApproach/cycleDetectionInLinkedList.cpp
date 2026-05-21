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

Now you may be having a question, Storing nodes in set, what if the elements are repeated. Will this solution still works so yes it will work, 
coz storing node * means we are storing a address of that node not data/value.

What You Are Storing

You are storing:

Node*

which means:

memory addresses of nodes

NOT node values.

Example

Suppose linked list is:

1 -> 2 -> 1 -> NULL

Here values repeat:

1 appears twice

BUT these are different nodes in memory.

Memory View
Node A -> val = 1
Node B -> val = 2
Node C -> val = 1

Addresses:

A = 0x100
B = 0x200
C = 0x300

Even though values are same:

A != C

because addresses differ.

So This Is SAFE
unordered_set<Node*> st;

because set compares pointers (addresses).

This Would Be WRONG
unordered_set<int> st;

////////////////////////////////////////////////////////////

OPTIMIZED APPROACH(Floyd's Algorithm) :
TC : O(n) and SC : O(1)

bool detectCycle(Node* head){

    //edge case
    if(head == NULL || head ->next == NULL)  return false;  /

    Node * slow = head;
    Node * fast = head;

    while( fast != NULL && fast->next != NULL){

        fast = fast->next->next;
        slow = slow->next;
        
        if(slow == fast) return true;
        
    }

    return false;
}

