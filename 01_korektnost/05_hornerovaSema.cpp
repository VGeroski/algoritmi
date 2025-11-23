#include <iostream>

using namespace std;

int main()
{
    // n cifara u osnovi 10, s leva nadesno
    // koji je broj zapisan?

    // 1 2 5 1 4 -> 12514

    // Hornerova shema

    // gradimo postepeno cifru, medjurezultati:
    // 0 - pre petlje
    // 1
    // 12
    // 125
    // 1251
    // 12514

    int n;
    cin >> n;

    int broj = 0;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;

        // induktivni korak
        broj = 10 * broj + c;
    }

    cout << "vrednost broja: " << broj << '\n';
    
    return 0;
}