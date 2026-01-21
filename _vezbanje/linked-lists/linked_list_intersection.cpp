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

ListNode *linkedListIntersection(ListNode *headA, ListNode *headB)
{
    ListNode *ptrA = headA;
    ListNode *ptrB = headB;

    while (ptrA != ptrB)
    {
        // Obilazimo list A -> list B
        // polazimo od ptrA, a onda nastavljamo obilazak od headB
        ptrA = ptrA ? ptrA->next : headB;

        // Obilazimo list B -> list A
        ptrB = ptrB ? ptrB->next : headA;
    }

    // u ovom trenutku ili ptrA i ptrB pokazuju na isti cvor, ili su oba null
    return ptrA;
}

int main()
{

    // ---------- Test 1: presek na sredini ----------
    ListNode *c1 = new ListNode(3);
    ListNode *c2 = new ListNode(4);
    c1->next = c2;

    // A: 1 -> 2 -> 3 -> 4
    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(2);
    a1->next = a2;
    a2->next = c1;

    // B: 9 -> 3 -> 4
    ListNode *b1 = new ListNode(9);
    b1->next = c1;

    ListNode *res = linkedListIntersection(a1, b1);
    cout << "Test 1: " << (res ? res->val : -1) << endl; // 3

    // ---------- Test 2: nema preseka ----------
    ListNode *x1 = new ListNode(1);
    x1->next = new ListNode(2);

    ListNode *y1 = new ListNode(3);
    y1->next = new ListNode(4);

    res = linkedListIntersection(x1, y1);
    cout << "Test 2: " << (res ? res->val : -1) << endl; // -1

    // ---------- Test 3: presek na pocetku (head) ----------
    ListNode *h1 = new ListNode(7);
    h1->next = new ListNode(8);

    res = linkedListIntersection(h1, h1);
    cout << "Test 3: " << (res ? res->val : -1) << endl; // 7

    // ---------- Test 4: jedna lista je prazna ----------
    res = linkedListIntersection(nullptr, h1);
    cout << "Test 4: " << (res ? res->val : -1) << endl; // -1

    return 0;
}