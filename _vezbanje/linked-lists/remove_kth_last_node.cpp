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

ListNode *removeKthLastNode(ListNode *head, int k)
{
    if (k <= 0)
        return head;

    // kreirati dummy cvor - ako cvor koji brisemo je bas head
    ListNode *dummy = new ListNode(0, head);

    ListNode *lead = dummy;
    ListNode *trail = dummy;
    for (int i = 0; i < k; i++)
    {
        lead = lead->next;

        // ako smo iskocili vec sad iz liste,
        // onda je k vece od duzine liste
        if (!lead)
        {
            delete dummy;
            return head;
        }
    }

    // pomeramo oba pokazivaca, sve dok lead ne pokazuje bas na poslednji element u listi
    while (lead->next)
    {
        lead = lead->next;
        trail = trail->next;
    }

    // uklanjanje cvora
    ListNode *to_delete = trail->next;
    trail->next = trail->next->next;
    delete to_delete;

    // dummy cvor je samo trenutno, brisemo ga iz memorije posto na ne treba vise
    ListNode *new_head = dummy->next;
    delete dummy;

    return new_head;
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
    // Test 1: 1 -> 2 -> 4 -> 7 -> 3
    ListNode *a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(4);
    a->next->next->next = new ListNode(7);
    a->next->next->next->next = new ListNode(3);

    cout << "Original: ";
    printList(a);

    int k = 2;
    a = removeKthLastNode(a, k);
    cout << "After removing " << k << "-th last node: ";
    printList(a);

    return 0;
}