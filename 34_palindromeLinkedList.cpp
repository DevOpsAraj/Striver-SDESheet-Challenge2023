// Code Studio - Palindrome Linked List

bool isPalindrome(LinkedListNode<int> *head)
{
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    LinkedListNode<int> *temp = slow;
    LinkedListNode<int> *prev = NULL;
    while (temp != NULL)
    {
        LinkedListNode<int> *next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    while (head != slow)
    {
        if (prev->data != head->data)
        {
            return false;
        }
        head = head->next;
        prev = prev->next;
    }
    return true;
}