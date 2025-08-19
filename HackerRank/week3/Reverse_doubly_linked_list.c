DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode* current = llist;
    DoublyLinkedListNode* temp = NULL;

    // Traverse and swap next & prev for each node
    while (current != NULL) {
        // Swap prev and next
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to next node (which is prev now)
        current = current->prev;
    }

    // After loop, temp will point to the node before NULL
    if (temp != NULL) {
        llist = temp->prev; // new head
    }

    return llist;
}