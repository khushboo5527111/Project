SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* prev = NULL;
    SinglyLinkedListNode* current = llist;
    SinglyLinkedListNode* next = NULL;

    while (current != NULL) {
        next = current->next;   // store next
        current->next = prev;   // reverse the link
        prev = current;         // move prev one step ahead
        current = next;         // move current one step ahead
    }
    return prev;  // new head of reversed list
}