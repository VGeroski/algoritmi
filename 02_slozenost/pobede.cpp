#include <iostream>
#include <vector>

int najduza_serija_v1(const std::vector<int> &rezultati)
{
    // pomocna prpmenljiva da oznacimo da li su u segmentu sve pobede
    bool sve_pobede;
    // pocetno maksimalan broj pobeda je nula, pa vremenom azuriramo vrednost po potrebi
    int max_pobeda = 0;
    // duzina vektora
    int n = rezultati.size();

    // Razmatramo sve moguce segmente svih mogucih duzina
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Pretpostavimo da u segmentu ima samo pobeda
            sve_pobede = true;

            // prolazimo kroz svaki moguci segment i proveravamo da li su u njemu sve pobede
            for (int k = i; k <= j; k++)
            {
                // cim naidjemo na rez koji nije pobeda, menjamo pretpostavljenu varijablu
                if (rezultati[k] == -1)
                {
                    // cim nisu sve pobede u segmentu, odmah izlazimo iz petlje
                    sve_pobede = false;
                    break;
                }
            }

            // Nakon sto smo izasli iz segmenta (prosli kroz ceo jer su sve bile pobede ili naisli na poraz pa breakovali)
            // proverimo prvo da li su u segmentu bile sve pobede,
            // i ako jesu da li je duzina segmenta duza od do sada maksimalnog niza pobeda
            if (sve_pobede && j - i + 1 > max_pobeda)
                // azuriramo vrednost max pobeda ukoliko smo naisli na veci segment
                max_pobeda = j - i + 1;
        }
    }

    return max_pobeda;
}

int najduza_serija_v2(const std::vector<int> &rezultati)
{
    // Na pocetku, maksimalan broj pobeda tima je 0, a kako vreme bude prolazilo, azuriracemo ovu vrednost po potrebi
    int max_pobeda = 0;
    // Duzinu vektora cuvamo u promenljivoj
    int n = rezultati.size();

    int i, j;
    // Fiksiramo levi kraj niza
    for (i = 0; i < n; i++)
    {
        // I od njega prolazimo kroz sve podnizove dok god imamo seriju pobeda
        for (j = i; j < n; j++)
        {
            // Ako naidjemo na neki rezultat koji nije pobeda, dosli smo do kraja podniza u kome su bile sve pobede
            if (rezultati[j] == -1)
            {
                // Odmah izlazimo iz petlje, jer smo ustanovili da je tim izgubio j-tu utakmicu (j-tu u odnosu na pocetak segmenta i)
                break;
            }
        }

        // Ako je duzina segmenta u kome je tim pobedjivao veca od max_pobeda, azuriramo vrednost max_pobeda
        if (j - i > max_pobeda)
        {
            max_pobeda = j - i;
        }
    }

    // Vracamo najduzi niz pobeda u nizu
    return max_pobeda;
}

int najduza_serija_v3(const std::vector<int> &rezultati)
{
    int max_pobeda = 0;
    int n = rezultati.size();

    int trenutno_pobeda = 0;
    int i = 0;
    while (i < n)
    {
        // Ako je jos jedna pobeda, samo uvecavamo trenutne pobede
        if (rezultati[i] == 1)
            trenutno_pobeda++;
        // ako je tim izgubio, proveravamo da li treba da azuriramo max pobeda i
        // resetujemo trenutno pobeda brojac
        else
        {
            if (trenutno_pobeda > max_pobeda)
                max_pobeda = trenutno_pobeda;

            trenutno_pobeda = 0;
        }

        i++;
    }

    // Ovo je vrlo vazna provera!!! 
    // Ako se desi da je najduzi niz pobeda na kraju samog niza, ako nemamo ovu proveru, desice se da
    // ne dobijemo tacan rezultat. Zapravo nikada necemo uci u else granu i azurirati max_pobeda.
    if (trenutno_pobeda > max_pobeda)
        max_pobeda = trenutno_pobeda;

    return max_pobeda;
}

int main()
{
    std::vector<int> rezultati = {1, -1, 1, -1, 1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    std::cout << najduza_serija_v1(rezultati) << "\n";

    std::cout << najduza_serija_v2(rezultati) << "\n";

    std::cout << najduza_serija_v3(rezultati) << "\n";

    return 0;
}