/**
 * Dat je binarni string (niska karaktera koji se sastoji od 0 i 1).
 * Napisati program kojim se odredjuje broj segmenata (podstring uzastopnih elemenata),
 * duzine najmanje 2, koji pocinju i zavrsavaju se sa 1.
 *
 * Primer:
 * Ulaz: 010001001
 * Izlaz: 3 (podstringovi: 10001, 10001001, 1001)
 */

#include <iostream>
#include <string>

using std::string;

// Analiza svih segmenata
int broj1x1Podstringova(const string &s)
{
    int n = s.length();
    int br = 0;
    for (int i = 0; i < n - 1; i++)
    {
        // u spoljasnjoj petlji svaku jedinicu na koju naidjemo smatracemo kao pocetak segmenta
        // dok u unutrasnjoj petlji trazimo njen zavrsetak
        if (s[i] == '1')
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[j] == '1')
                {
                    br++;
                }
            }
        }
    }

    return br;
}

// Efikasnije resenje preko broja nacina da se izvuku dve jedinice u stringu
// Broj nacina da se iz skupa od n razlicitih brojeva izvuku dva broja je n * (n - 1) / 2,
// tako da ako je broj jedinica u stringu b onda dve jedinice mozemo izabrati na b * (b - 1) / 2 nacina.
int broj1x1Podstringova_brojanje(const string& s)
{
    int brJedinica = 0;
    for (char c : s)
    {
        if (c == '1')
        {
            brJedinica++;
        }
    }

    return brJedinica * (brJedinica - 1) / 2;
}

int main()
{
    std::cout << "Broj podstringova za: 010001001: " << broj1x1Podstringova("010001001") << std::endl;
    std::cout << "Broj podstringova za: 010001001 (brojanjem jedinica): " << broj1x1Podstringova("010001001") << std::endl;

    return 0;
}
