#include <iostream>

using std::cout;
using std::endl;

int getNextNum(int x)
{
    int next_num = 0;
    while (x > 0)
    {
        // uzimamo cifru po cifru
        int digit = x % 10;
        x /= 10; // ostatak

        next_num += digit * digit;
    }

    return next_num;
}

bool isHappyNumber(int n)
{
    if (n <= 0)
        return false;

    int slow = n;
    int fast = n;

    while (true)
    {
        slow = getNextNum(slow);
        fast = getNextNum(getNextNum(fast));

        // ako ne postoji ciklus, dolazimo do 1, n je happy num
        if (fast == 1)
            return true;
        // ako se otkrije ciklus, onda n nije happy num
        else if (fast == slow)
            return false;
    }
}

int main()
{
    // ---------- Test 1: happy number ----------
    int n1 = 19;
    cout << "19 -> " << isHappyNumber(n1) << endl;

    // ---------- Test 2: not happy number ----------
    int n2 = 2;
    cout << "2 -> " << isHappyNumber(n2) << endl;

    // ---------- Test 3: happy number ----------
    int n3 = 1;
    cout << "1 -> " << isHappyNumber(n3) << endl;

    // ---------- Test 4: happy number ----------
    int n4 = 7;
    cout << "7 -> " << isHappyNumber(n4) << endl;

    // ---------- Test 5: not happy ----------
    int n5 = 20;
    cout << "20 -> " << isHappyNumber(n5) << endl;

    return 0;
}