// Code Studio - Copy List with Random Pointer

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    unordered_map<LinkedListNode<int> *, LinkedListNode<int> *> map;
    LinkedListNode<int> *temp = head;

    while (temp != NULL)
    {
        map[temp] = new LinkedListNode<int>(temp->data);
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL)
    {
        map[temp]->next = map[temp->next];
        map[temp]->random = map[temp->random];
        temp = temp->next;
    }

    return map[head];
}