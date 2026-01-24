/**
 * Pretrazujemo sve podskupove brojeva od {0, 1, ..., n - 1}
 * Prosirujemo pretragu tako da je svaki cvor ujedno i podskup
 * Kada udjemo u cvor, hocemo da ga prosirimo na sve moguce nacine
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

void svi_podskupovi(vector<int> &skup, int n)
{
    // odmah ispisujemo (obradjujemo) cvor
    // cvor je zapravo skp, stablo ne postoji u memoriji
    obradi(skup);

    int pocetak = skup.empty() ? 0 : skup.back() + 1;
    for (int i = pocetak; i < n; i++)
    {
        skup.push_back(i);
        svi_podskupovi(skup, n);
        // pri povratku izbacujemo poslednji dodat element - vracamo se u nivo iznad
        skup.pop_back();
    }
}

void svi_podskupovi(int n)
{
    // koristimo vektor da opisemo stanje
    vector<int> skup;
    // mala optimizacija - skup moze da ima najvise n elemenata na kraju
    skup.reserve(n);

    svi_podskupovi(skup, n);
}

int main()
{
    int n;
    cin >> n;

    svi_podskupovi(n);

    return 0;
}