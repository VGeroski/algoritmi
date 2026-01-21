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

bool linkedListLoop(ListNode *head)
{
    if (!head)
        return false;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    // ispali smo iz liste, nema ciklusa
    return false;
}

int main()
{
    // ---------- Test 1: prazna lista ----------
    ListNode *t1 = nullptr;
    cout << "Test 1 (prazna lista): " << linkedListLoop(t1) << endl; // 0

    // ---------- Test 2: bez ciklusa ----------
    ListNode *t2 = new ListNode(1);
    t2->next = new ListNode(2);
    t2->next->next = new ListNode(3);
    cout << "Test 2 (bez ciklusa): " << linkedListLoop(t2) << endl; // 0

    // ---------- Test 3: ciklus u sredini ----------
    ListNode *t3 = new ListNode(1);
    ListNode *t3_2 = new ListNode(2);
    ListNode *t3_3 = new ListNode(3);
    ListNode *t3_4 = new ListNode(4);
    t3->next = t3_2;
    t3_2->next = t3_3;
    t3_3->next = t3_4;
    t3_4->next = t3_2; // ciklus počinje na t3_2
    cout << "Test 3 (ciklus u sredini): " << linkedListLoop(t3) << endl;

    // ---------- Test 4: ciklus na head ----------
    ListNode *t4 = new ListNode(10);
    ListNode *t4_2 = new ListNode(20);
    t4->next = t4_2;
    t4_2->next = t4; // ciklus na head
    cout << "Test 4 (ciklus na head): " << linkedListLoop(t4) << endl;

    // ---------- Test 5: single-node ciklus ----------
    ListNode *t5 = new ListNode(42);
    t5->next = t5; // self loop
    cout << "Test 5 (ciklus sa jednim elementom): " << linkedListLoop(t5) << endl;

    return 0;
}