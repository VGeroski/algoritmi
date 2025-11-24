#include <iostream>
using namespace std;

int main()
{
    int a, b, k;
    cin >> a >> b >> k;

    // [a, b]
    int brojDeljivih = 0;
    for (int i = a; i <= b; i++)
        if (i % k == 0)
            brojDeljivih++;

    cout << "Broj deljivih za dati interval je: " << brojDeljivih << endl;

    // uvek cemo u nekom segmentu da imamo deljiv broj sa k, na k-tom koraku
    int deljivDoB = b / k +1;
    int deljivDoA = (a - 1) / k + 1;
    if (a > 0)
        cout << "Broj deljivih za dati interval je (brze): " << deljivDoB - deljivDoA << endl;
    else
        cout << "Broj deljivih za dati interval je (brze): " << deljivDoB << endl;

    return 0;
}