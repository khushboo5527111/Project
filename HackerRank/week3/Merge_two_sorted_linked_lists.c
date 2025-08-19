SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    // If one list is empty, return the other
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    SinglyLinkedListNode* mergedHead = NULL; 
    SinglyLinkedListNode* tail = NULL;

    // Pick the smaller head first
    if (head1->data <= head2->data) {
        mergedHead = head1;
        head1 = head1->next;
    } else {
        mergedHead = head2;
        head2 = head2->next;
    }
    tail = mergedHead;

    // Traverse both lists and merge
    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    if (head1 != NULL) {
        tail->next = head1;
    } else {
        tail->next = head2;
    }

    return mergedHead;
}