/**
 * U nizu brojeva od 0 - n tacno jedan broj je izostavljen.
 * Napisi program koji, bez pamcenja elemenata niza,
 * ucitava brojeve sa ulaza i efikasno odredjuje koji broj nedostaje.
 *
 * Primer:
 * ulaz:
 * 5
 * 0 4 2 5 1
 *
 * izlaz: 3
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nedostajuciElement_v1()
{
    int n;
    cin >> n;
    vector<int> niz(n);
    for (int i = 0; i < n; cin >> niz[i++])
        ;

    // Jedno resenje bi mogla biti linearna petraga kroz niz
    // dok ne nadjemo prvi koji nedostaje
    for (int x = 0; x <= niz.size(); x++)
    {
        if (find(begin(niz), end(niz), x) == end(niz))
        {
            cout << "Nedostajuci element je: " << x << endl;
            break;
        }
    }
}

void nedostajuciElement_v2()
{
    int n;
    cin >> n;
    long long zbir = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        zbir += x;
    }

    // Drugi pristupe je da, posto zbir svih elemenata iz skupa {0, 1, 2, ..., n} moze da se odredi kao (n * (n + 1)) / 2
    // nedostajuci element mozemo da odredimo kao razliku zbira svih elemenata i zbira elemenata od ucitanih brojeva.
    long long zbir_svih = ((long long)n * (n + 1)) / 2;
    cout << "Nedostajuci element je: " << zbir_svih - zbir << endl;
}

int main()
{
    nedostajuciElement_v1();
    nedostajuciElement_v2();
}