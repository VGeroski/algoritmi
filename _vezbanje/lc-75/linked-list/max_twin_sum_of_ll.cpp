#include <iostream>

using std::cout;
using std::endl;
using std::max;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int pairSum(ListNode *head)
{
    // Prvo trazimo srednji cvor liste
    // mozemo da uradimo preko dva pokazivaca (brzi i spori)
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Sada mozemo da obrnemo drugi deo liste
    // tako da onda mozemo da idemo od pocetka liste
    // sa jedne strane i sa kraja drue strane i da pravimo sumu
    ListNode *prev = nullptr;
    while (slow)
    {
        ListNode *next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    // pravimo sumu
    ListNode *first = head;
    ListNode *second = prev;
    int max_sum = 0;
    while (second)
    {
        max_sum = max(max_sum, first->val + second->val);
        first = first->next;
        second = second->next;
    }

    return max_sum;
}

int main()
{
    // 4 -> 2 -> 2 -> 3
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);

    cout << "Max Twin Sum: " << pairSum(head) << endl;
    return 0;
}