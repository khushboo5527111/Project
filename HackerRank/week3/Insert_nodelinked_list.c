SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    // Create new node
    SinglyLinkedListNode* new_node = create_singly_linked_list_node(data);

    // Case 1: insert at head
    if (position == 0) {
        new_node->next = llist;
        return new_node;
    }

    // Case 2: traverse to position-1
    SinglyLinkedListNode* current = llist;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    // Insert node
    if (current != NULL) {
        new_node->next = current->next;
        current->next = new_node;
    }

    return llist;
}
