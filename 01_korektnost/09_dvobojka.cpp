#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void podelaNiza(vector<int> &niz)
{
    // pppp?????nnnnnn
    //     l   d

    // odrzavamo uslov tako da vazi
    // [0, l) - parni
    // [l, d] - jos uvek nisu ispitani
    // [d, n) - neparni

    int n = niz.size();
    int l = 0, d = n - 1;
    
    // sve dok ima nepoznatih elemenata 
    while (l < d)
    {
        // ako je na mestu l paran, ostavljamo ga na svom mestu 
        // i pomeramo se na naredni element
        if (niz[l] % 2 == 0)
            l++;
        // ako je na mestu d neparan, ostavljamo ga na svom mestu
        // i pomeramo se na prethodni element
        else if (niz[d] % 2 != 0)
            d--;
        // na mestu l je neparan, na mestu d je paran
        // zamenjujemo im mesta i pomeramo se sa oba kraja
        else
            swap(niz[l++], niz[d--]);
    }
}

int main()
{
    vector<int> niz = {5, 1, 8, 6, 3, 9, 4, 2};

    podelaNiza(niz);

    for (int i = 0; i < niz.size(); i++)
        cout << niz[i] << " ";

    cout << '\n';

    return 0;
}