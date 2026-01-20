#include <vector>
#include <iostream>

using std::vector;
using std::swap;

// Trobojka
void podelaNiza(vector<int> &niz, int A, int B)
{
    int i = 0, l = 0;
    int n = niz.size();
    int d = n;

    while (i < d)
    {
        if (niz[i] < A)
        {
            // (0, A)
            swap(niz[i], niz[l]);
            i++;
            l++;
        } else if (niz[i] > B)
        {
            // (B, n)
            d--;
            swap(niz[i], niz[d]);
            // ne diramo i, posto smo prethodno smanjili d, opet je na i nepoznat element.
        }
        else
        {
            // [A, B]
            i++;
        }
    }
}

int main()
{
    vector<int> test1 = {1, 3, 5, 4, 8, 5, 7, 2, 3, 6};
    podelaNiza(test1, 3, 5);

    for (int el : test1)
        std::cout << el << " ";
    std::cout << std::endl;

    vector<int> test2 = {5, 1, 8, 6, 3, 9, 4, 2};
    podelaNiza(test2, 4, 7);

    for (int el : test2)
        std::cout << el << " ";
    std::cout << std::endl;

    return 0;
}