#include <iostream>
#include <string>

using namespace std;

int main()
{
    // n     s           val(s)    2^i
    // 38    ""            0        1
    // 19    "0"           0        2
    // 9     "10"          2        4
    // 4     "110"         6        8
    // 2     "0110"        6       16
    // 1     "00110"       6       32
    // 0     "100110"     38       64

    // invarijnata:
    // n * 2^i + val(s) = n0 (n0 - polazna vrednost n)

    int n;
    cin >> n;

    string s = "";
    while (n > 0)
    {
        if (n % 2 == 0)
            s = "0" + s;
        else
            s = "1" + s;

        n = n / 2;
    }

    cout << "Binarni zapis unetog broja: " << s << '\n';

    return 0;
}