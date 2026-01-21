#include <iostream>

using std::cout;
using std::endl;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *linkedListReversalIter(ListNode *head)
{
    ListNode *curr_node = head;
    ListNode *prev_node = nullptr;

    while (curr_node)
    {
        ListNode *next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }

    // pazimo da su zapravo i next, ali i curr_node ispali iz liste na kraju
    // prev_node drzi adresu glavu obrnute liste
    return prev_node;
}

ListNode *linkedListReversalRecursive(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *new_node = linkedListReversalRecursive(head->next);

    head->next->next = head;
    head->next = nullptr;

    return new_node;
}

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Test 1: 1 -> 2 -> 3 -> 4
    ListNode *a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    a->next->next->next = new ListNode(4);

    cout << "Original: ";
    printList(a);
    a = linkedListReversalIter(a);
    cout << "Reversed: ";
    printList(a);

    // Test 2: lista samo sa jednim elementom
    ListNode *b = new ListNode(10);
    cout << "Original: ";
    printList(b);
    b = linkedListReversalIter(b);
    cout << "Reversed: ";
    printList(b);

    // Test 3: prazna lista
    ListNode *c = nullptr;
    cout << "Original: ";
    printList(c);
    c = linkedListReversalIter(c);
    cout << "Reversed: ";
    printList(c);

    return 0;
}