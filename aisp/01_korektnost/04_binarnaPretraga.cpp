#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int prviKojiNijeDeljiv(const vector<long long> &a, long long k)
{
    // - u intervalu pozicija [0, l) su elementi koji ne zadovoljavaju uslov
    // - u intervalu pozicija [l, d] su elementi ciji status nije poznat
    // - u intervalu pozicija [d, n) su elementi koji zadovoljavaju uslov
    int n = a.size();
    int l = 0, d = n - 1;
    while (l <= d)
    {
        int s = l + (d - l) / 2;
        if (a[s] % k != 0)
            d = s - 1;
        else
            l = s + 1;
    }

    // za ovako postavljene invarijante, na kraju ce da vazi
    // d = l - 1, tako da je trazeni el na d + 1 ili l.
    return l;
}

int main()
{
    vector<long long> niz = {210, 2310, 390, 30, 510, 66, 6, 138, 46, 106, 59, 17, 23};
    int index = prviKojiNijeDeljiv(niz, 10);
    cout << "Prvi koji nije deljiv sa 10: " << niz[index] << '\n';

    return 0;
}