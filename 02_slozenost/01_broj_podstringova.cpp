/**
 * Dat je binarni string. Napisati program kojim se odredjuje broj segmenata (podstring uzastopnih elemenata),
 * duzine najmanje 2 koji zapocinju i zavrsavaju se 1.
 *
 * Primer:
 * ulaz: 010001001
 * 
 * izlaz: 3
 */

#include <iostream>
#include <string>

using namespace std;

int brojPodstringova_v1(const string &s)
{
    // Analiziramo sve segmente. U spoljasnjoj petlji analiziramo jedan po jedan karakter.
    // Svaku jedinicu na koju naidjemo (za svako i takvo da je s_i == 1), razmatramo kao pocetak segmenta.
    // U unutrasnjoj petlji (brojacem od od i + 1 do kraja stringa) trazimo jedinicu kojom se string zavrsava.
    // Za svaku jedinicu pronadjenu u unutrasnjoj petlji (svako j takvo da je s_j == 1) uvecavamo broj segmenata.

    int n = s.length();
    int br = 0;

    for (int i = 0; i < n - 1; i++)
    {
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

int brojPodstringova_v2(const string &s)
{
    // Svaki segment koji pocinje i zavrsava se jedinicom definisan je pozicijama dve jedinice u stringu.
    // Zato je ukupan broj trazenih segmenata jedank broju nacina da se izaberu dve razlicite jedinice u stringu.
    // Ako je ukupan broj jedinica u string b onda dve jedinice mozemo izabrati na (b * (b - 1)) / 2 nacina.

    int brojJedinica = 0;
    for (char c : s)
    {
        if (c == '1')
            brojJedinica++;
    }

    return brojJedinica * (brojJedinica - 1) / 2;
}

int main()
{
    string primer = "010001001";

    cout << "Broj podstringova (ispitan svaki segment): " << brojPodstringova_v1(primer) << "\n";

    cout << "Broj podstringova (brojanje jedinica): " << brojPodstringova_v2(primer) << "\n";
}