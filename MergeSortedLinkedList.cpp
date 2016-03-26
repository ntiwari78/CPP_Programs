class Node
{
public:
    int data;
    Node* next;
};

/*
 Readjust source and detination in the following way:-
 source->destination->sourceNext
 Assert if source if NULL.
*/
void MoveNode(Node** destRef, Node** sourceRef)
{
    Node* newNode = *sourceRef; // the front source node
    assert(newNode != NULL);
    *sourceRef = newNode->next; // Advance the source pointer
    newNode->next = *destRef; // Link the old dest off the new node
    *destRef = newNode; // Move dest to point to the new node
}

/* Merge function takes two sorted linked list and returns the new list
 * which is merged of two in the increasing order. This method makes only
 * one pass through each list.
 * Return
 */
Node* Merge(Node* head1, Node* head2)
{
    Node head;          // Head node to hang the result on
    Node* tail = &head; // Points to the last result node
                               // so tail->next is the place to add
                               // new nodes to the head.
    dummy.next = NULL;
    while (1) {
        // if either list runs out, use the other list
        if (head1 == NULL) {
            tail->next = head2;
            break;
        }
        else if (head2 == NULL) {
            tail->next = head1;
            break;
        }
        if (head1->data <= head2->data) {
            MoveNode(&(tail->next), &head1);
        }
        else {
            MoveNode(&(tail->next), &head2);
        }
        tail = tail->next;
    }
    return(head.next);
}
