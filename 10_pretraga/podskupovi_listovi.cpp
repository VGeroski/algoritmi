/**
 * Pretrazujemo sve podskupove brojeva od {0, 1, ..., n - 1}
 * Prosirujemo pretragu tako da je svaki list ujedno i podskup
 * U ovoj verziji prvo dolazimo do listova, pa tek onda radimo ispis.
 * Samo su u listovima podskupovi.
 */

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void obradi(const vector<bool> &skup)
{
    for (int i = 0; i < skup.size(); i++)
        // samo i-ti element koji je true je aktivan (ukljucen) u podskup
        if (skup[i])
            cout << i << " ";
    cout << endl;
}

// preko broja k pratimo koliko treba da obradimo elemenata
void svi_podskupovi(vector<bool> &skup, int k, int n)
{
    // posto su samo u listovima podskupovi,
    // obradjujemo cvorove tek kad smo stigli do kraja
    if (k == n)
    {
        obradi(skup);
        return;
    }

    // imamo jedino dva moguca racvanja - 0 i 1
    skup[k] = false;
    svi_podskupovi(skup, k + 1, n);
    skup[k] = true;
    svi_podskupovi(skup, k + 1, n);
}

void svi_podskupovi(int n)
{
    // koristimo vektor da opisemo stanje
    vector<bool> skup(n);
    svi_podskupovi(skup, 0, n);
}

int main()
{
    int n;
    cin >> n;

    svi_podskupovi(n);

    return 0;
}