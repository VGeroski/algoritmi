/**
 * U nizu brojeva od 0 do n tacno jedan broj je izostavljen. Napisi program koji, bez pamcenja elemenata niza,
 * ucitava brojeve sa ulaza i efikasno odredjuje koji broj nedostaje.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

// Linearna pretraga: Pretrazimo niz gde su smesteni elementi (mada se narusava uslov zadatka) 
// i onda na prvi koji naidjemo da nije u nizu, prijavimo da nedostaje.
void nedostajuciBrojLinearno(const vector<int>& niz)
{
    int n = niz.size();
    
    for (int i = 0; i <= n; i++)
    {
        if (find(begin(niz), end(niz), i) == end(niz))
        {
            std::cout << "Nedostaje: " << i << std::endl;
            break;
        }
    }
}

// Preko zbira elemenata: Zbir svih elemenata iz skupa {0, 1, 2 ..., n} je n * (n + 1) / 2. 
// Nedostajuci element je dakle jednak razlici zbira po formuli i realnog zbira ucitanih brojeva.
void nedostajuciBrojZbirElemenata(long long zbirUcitanih, int brojElemenata)
{
    long long zbirSvih = ((long long)brojElemenata * (brojElemenata + 1)) / 2;
    std::cout << "Nedostaje: " << zbirSvih - zbirUcitanih << std::endl;
}

int main()
{
    int n;
    std::cin >> n;

    vector<int> a(n);
    long long zbir = 0;
    for (int i = 0; i < n; i++)
    {
        // pamtimo niz samo da bi imali za linearnu pretragu, 
        // inace bi mogao zbir direktno preko ucitanog broja
        std::cin >> a[i];
        zbir += a[i];
    }

    nedostajuciBrojLinearno(a);

    nedostajuciBrojZbirElemenata(zbir, n);

    return 0;
}