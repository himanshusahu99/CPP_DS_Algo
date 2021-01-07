node* appendK(node *head,int k){
    node *oldHead = head;
    node *fast = head;
    node *slow = head;
    for(long i=0;i < k && fast->next!=NULL ;i++){
        fast = fast->next;
    }
    while(fast->next!=NULL && fast!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    node *newHead = slow->next;
    slow->next = NULL;
    fast->next = oldHead;
    return newHead;
}