#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    // dati su poeni takmicara:
    // 62 95 55 83 98 55 72
    // odrediti koliko poena je imao drugi

    // mozemo da resimo sortiranjem, ali to je visak
    // jer nas interesuje samo drugi

    // da bismo znali ko je drugi, moramo da znamo i ko je prvi

    // hocemo da ucitavamo deo po deo bodova
    // i da odrzavamo ko je prvi i drugi od obradjenih

    // prvi    drugi
    //  95      62
    //  95      83   (kada ucitamo 83)
    //  98      95   (sada se pomera prvi, ali mora da se azurira i drugi)

    int n;
    cin >> n;

    int prvi, drugi;
    cin >> prvi >> drugi;
    if (prvi < drugi)
        swap(prvi, drugi);

    for (int i = 2; i < n; i++)
    {
        int x;
        cin >> x;

        // odrzavanje invarijante
        if (x > prvi)
        {
            drugi = prvi;
            prvi = x;
        }
        else if (x > drugi)
            drugi = x;
    }

    cout << "prvi i drugi takmicar: " << prvi << " " << drugi << endl;

    return 0;
}