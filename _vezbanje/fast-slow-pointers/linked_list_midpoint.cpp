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

ListNode *linkedListMidpoint(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    // ---------- Test 1: prazna lista ----------
    ListNode *t1 = nullptr;
    ListNode *mid = linkedListMidpoint(t1);
    cout << "Test 1 (prazna lista): "
         << (mid ? mid->val : -1) << endl;

    // ---------- Test 2: jedan cvor ----------
    ListNode *t2 = new ListNode(10);
    mid = linkedListMidpoint(t2);
    cout << "Test 2 (1 cvor): "
         << (mid ? mid->val : -1) << endl;

    // ---------- Test 3: neparna duzina ----------
    // 1 -> 2 -> 3 -> 4 -> 5
    ListNode *t3 = new ListNode(1);
    t3->next = new ListNode(2);
    t3->next->next = new ListNode(3);
    t3->next->next->next = new ListNode(4);
    t3->next->next->next->next = new ListNode(5);

    mid = linkedListMidpoint(t3);
    cout << "Test 3 (neparna duzina): "
         << (mid ? mid->val : -1) << endl;

    // ---------- Test 4: parna duzina ----------
    // 1 -> 2 -> 3 -> 4
    ListNode *t4 = new ListNode(1);
    t4->next = new ListNode(2);
    t4->next->next = new ListNode(3);
    t4->next->next->next = new ListNode(4);

    mid = linkedListMidpoint(t4);
    cout << "Test 4 (parna duzina): "
         << (mid ? mid->val : -1) << endl;

    return 0;
}