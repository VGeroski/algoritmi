#include <iostream>
#include <vector>
#include <climits>

using std::cout;
using std::endl;
using std::vector;

bool increasingTriplet(vector<int> &nums)
{
    int first = INT_MAX;
    int second = INT_MAX;

    // potrebno je da odrzavamo prvi i srednji element
    // ako nadjemo treci koji je veci od oba, nasli smo trojku
    for (int x : nums)
    {
        if (x <= first)
            first = x;
        else if (x <= second)
            second = x;
        else
            return true;
    }
    return false;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    cout << increasingTriplet(a) << " (Ocekivano: 1)" << endl;

    vector<int> b = {5, 4, 3, 2, 1};
    cout << increasingTriplet(b) << " (Ocekivano: 0)" << endl;

    vector<int> c = {2, 1, 5, 0, 4, 6};
    cout << increasingTriplet(c) << " (Ocekivano: 1)" << endl;

    vector<int> d = {1, 1, 1, 1};
    cout << increasingTriplet(d) << " (Ocekivano: 0)" << endl;
}