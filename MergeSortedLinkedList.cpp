class Node
{
public:
    int data;
    Node* next;
};

/*
 Readjust source and detination in the way which takes
 the node from the front of the source list and move it
 to the front of the destination list.
 Assert if source if NULL.
*/
void MoveNode(Node** destRef, Node** sourceRef)
{
    Node* tmpNode = *sourceRef; // the front source node
    assert(tmpNode != NULL);
    *sourceRef = tmpNode->next; // Advance the source pointer
    tmpNode->next = *destRef; // Link the old dest off the new node
    *destRef = tmpNode; // Move dest to point to the tmp node
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
    head.next = NULL;
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
