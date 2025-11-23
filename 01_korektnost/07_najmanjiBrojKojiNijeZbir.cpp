#include <iostream>
#include <vector>

using namespace std;
// najmanji broj koji nije zbir elemenata skupa
// 1, 2, 3, 5, 14, 20, 27

// 6 => 1 + 2 + 3 (moze)
// 19 => 2 + 3 + 14 (moze)

// npr, ako su obradjeni 1, 2, 3
// razmatramo koje brojeve je moguce dobiti
// uvek mozemo da dobijemo 0 i zbir svih
// 0    ...     6

// sta dobijamo kada redom obradjujemo brojeve:
// 0                   [0-0]
// 0, 1                [0-1]
// 0, 1, 2, 3          [0-3]
// 0, 1, 2, 3, 4, 5, 6 [0-6]
// ...                 [0-11]
// ...                 [0-11] [14-25] (razbija se interval)
// zato sto su brojevi sortirani,
// sigurno ni ostali ne mogu da naprave zbir da daje 12

// pomocu prvih k elemenata niza mogu se dobiti svi zbirovi iz intervala
// [0, a0 + a1 + ... + ak-1]

int main()
{
    vector<int> niz = {1, 2, 3, 5, 14, 20, 27};
    int zbir = 0;
    for (int x : niz)
    {
        // [0,zbir] [x, zbir+x]
        // da li ostaje interval povezan
        if (x > zbir + 1)
            break;

        zbir += x;
    }

    cout << "Najmanji broj koji nije zbir elemenata skupa: " << zbir + 1 << endl;

    return 0;
}