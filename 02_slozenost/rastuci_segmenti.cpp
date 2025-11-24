#include <iostream>
#include <vector>

using namespace std;

// Osnovna ideja ce nam biti da fiksiramo svaki levi kraj, i onda idemo dalje do kraja niza i brojimo koliko segmenata ima
// gde su elementi rastuci
int broj_rastucih_v1(const std::vector<int> &niz)
{
    // Na pocetku nema takvih segmenata
    int broj_rastucih = 0;

    int n = niz.size();

    // Ovde fiksiramo svaki levi kraj
    for (int i = 0; i < n; i++)
    {
        // Prolazimo dalje kroz niz od fiksirane pozicije
        for (int j = i + 1; j < n; j++)
        {
            // Proveravamo svaka 2 uzastopna elementa kako ne bismo narusili trazeni uslov
            if (niz[j] > niz[j - 1])
                broj_rastucih++;

            // Ako se desi da neka 2 elementa narusavaju uslov zadatka, samo izlazimo iz unutrasnje petlje i dobili smo broj segmenata
            // koji pocinju na poziciji i. Zatim cemo fiksirati naredni levi kraj
            else
                break;
        }
    }

    // Vracamo broj rastucih segmenata u nizu
    return broj_rastucih;
}

int broj_rastucih_v2(const std::vector<int> &niz)
{
    // Ukupan broj rastucih segmenata
    int broj_rastucih = 0;

    int n = niz.size();

    // Koliko trenutno ima rastucih elemenata, vazno je ovo staviti na 1 jer ako imamo 3 elementa uzastopno,
    // treba nam bas vrednost 3, a ne 2
    int trenutno_rastucih = 1;
    for (int i = 0; i < n - 1; i++)
    {
        // Ako za 2 uzastopna elementa vazi uslov, povecavamo broj trenutno rastucih
        if (niz[i] < niz[i + 1])
            trenutno_rastucih++;

        // Ako ne vazi, znaci da smo razbili uslov, i sad treba krenuti u potragu od pozicije i
        else
        {
            // Ukupan broj rastucih podsegmenata u nizu od n elemenata gde su svi rastuci je n * (n - 1) / 2
            broj_rastucih += trenutno_rastucih * (trenutno_rastucih - 1) / 2;

            // Vracamo vrednost trenutno_rastucih na pocetnu vrednost
            trenutno_rastucih = 1;
        }
    }

    // Vazno je i na kraju dodati broj rastucih segmenata koji se zavrsavaju na krajnjoj poziciji. Kako se za poslednju iteraciju
    // ne ulazi u else, nikada se nece azurirati broj segmenata
    broj_rastucih += trenutno_rastucih * (trenutno_rastucih - 1) / 2;

    return broj_rastucih;
}

int main()
{
    std::vector<int> niz = {5, 1, 3, 4, -2, 10};

    std::cout << broj_rastucih_v1(niz) << "\n";

    std::cout << broj_rastucih_v2(niz) << "\n";

    return 0;
}