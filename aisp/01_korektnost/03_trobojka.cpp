#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::swap;
using std::vector;

// funkcija organizuje elemente vektora tako da se prvo nalaze elementi
// za koje vazi da su iz intervala (-Inf, A), nakon toga dolaze
// elementi iz intervala [A, B], i nakon toga elementi iz intervala
// (B, Inf)
void podelaNiza(vector<int> &niz, int A, int B)
{
    // - u intervalu pozicija [0, l) su elementi iz intervala (-Inf, A)
    // - u intervalu pozicija [l, i) su elementi iz intervala [A, B]
    // - u intervalu pozicija [i, d) su jos neispitani elementi
    // - u intervalu pozicija [d, n) su elementi iz intervala (B, Inf)
    // postavljamo pocetne uslove tako da vazi invarijanta
    int l = 0, i = 0, d = niz.size();

    // <<<<<<<=======??????>>>>>>
    //        l      i     d

    // dok god postoje neispitani elementi
    while (i < d)
    {
        if (niz[i] < A)
            // menjamo tekuci element sa prvim elementom iz intervala [A, B]
            swap(niz[i++], niz[l++]);
        else if (niz[i] <= B)
            // tekuci element ostaje na svom mestu
            i++;
        else
            // menjamo tekuci element sa poslednjim neispitanim
            swap(niz[i], niz[--d]);
    }
}

int main()
{
    vector<int> niz = {5, 1, 8, 6, 3, 9, 4, 2};
    int A = 4, B = 7;

    podelaNiza(niz, A, B);

    for (int i = 0; i < niz.size(); i++)
        cout << niz[i] << " ";

    cout << '\n';

    return 0;
}