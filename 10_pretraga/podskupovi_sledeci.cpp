/**
 * Pretrazujemo sve podskupove brojeva od {0, 1, ..., n - 1}
 * Pocinjemo od nekog stanja a onda ga prosirujemo sledecim korakom leksikografski.
 */

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void obradi(const vector<int> &skup)
{
    for (int x : skup)
        cout << x << " ";
    cout << endl;
}

bool sledeci(vector<int>&skup, int n)
{
    if (skup.empty())
    {
        skup.push_back(0);
        return true;
    }

    if (skup.back() < (n - 1))
    {
        skup.push_back(skup.back() + 1);
        return true;
    }

    skup.pop_back();

    if (skup.empty())
        return false;
        
    skup.back()++;
    return true;
}

void svi_podskupovi(int n)
{
    vector<int> skup;
    do
    {
        obradi(skup);
    } while (sledeci(skup, n));
}

int main()
{
    int n;
    cin >> n;

    svi_podskupovi(n);

    return 0;
}