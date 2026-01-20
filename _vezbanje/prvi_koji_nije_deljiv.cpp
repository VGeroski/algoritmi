#include <iostream>
#include <vector>

using std::vector;

// Resenje preko binarne pretrage: Uslov da vazi monotonost, imamo prelomnu tacku
int prviKojiNijeDeljiv(const vector<int> &niz, int k)
{
    int n = niz.size();
    int l = 0, d = n - 1;

    // unutar [l, d] imamo elemente koji nisu ispitani
    // radimo proveru dok [l, d] nije prazan interval
    while (l <= d)
    {
        int s = l + (d - l) / 2;

        // ako potvrdimo da na s nije ili jeste deljiv, vazi uslov monotonosti
        if (niz[s] % k != 0)
            d = s - 1;
        else
            l = s + 1;
    }

    return l; // moze i d + 1, zato sto je na kraju l = d + 1
}

int main()
{
    vector<int> test1 = {2, 8, 6, 1, 7, 3, 5, 9, 11};

    int nijeDeljivIndex = prviKojiNijeDeljiv(test1, 2);

    std::cout << "Prvi koji nije deljiv sa 2 : " << test1[nijeDeljivIndex]
              << ", na indeksu: " << nijeDeljivIndex << std::endl;

    return 0;
}