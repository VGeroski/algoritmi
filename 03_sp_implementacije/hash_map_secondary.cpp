#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

/**
 * Hes tabela, sa podrskom za dodavanje i brisanje iz tabele.
 * Resavanje kolizije: Dvostruko hesiranje
 */

class hash_map
{
public:
    hash_map() {}

    hash_map(int x)
    {
        a.resize(x);
        size = x;
        secondary = size - 1;
    }

    // Dodajemo vrednost u tabelu
    // dvostruko hesiranje
    void add_value(int x)
    {
        // Racunamo gde element treba da se nalazi -> na poziciji x % size
        int pos = (x % size) % size;

        // Cuvamo obe funkcije, f(x) i g(x)
        int g_x = 1 + x % secondary;
        int h_x = x % size;

        // Ukoliko polje vec nije zauzeto
        if (a[pos].first == 0)
        {
            // Smestamo element u polje i oznacavamo da je polje zauzeto
            a[pos].second = x;
            a[pos].first = 1;
        }
        // Ako polje jeste zauzeto, pokusavamo da nadjemo prvo slobodno mesto
        else
        {
            // Ako postoji u mapi, nema ponovnog dodavanja
            if (a[pos].second == x)
                return;

            int i = 1;
            // Krecemo se kroz niz sve dok se ne vratrimo na poziciju od koje smo poceli
            while (i < size)
            {
                pos = (h_x + i * g_x) % size;

                if (a[pos].first == 0)
                {
                    // Smestamo element u polje i oznacavamo da je polje zauzeto
                    a[pos].second = x;
                    a[pos].first = 1;
                    break;
                }

                if (a[pos].second == x)
                    return;

                i++;
            }
        }
    }

    void remove_value(int x)
    {
        // Racunamo na kojoj poziciji moze da bude element
        int pos = (x % size) % size;

        // Cuvamo obe funkcije, f(x) i g(x)
        int g_x = 1 + x % secondary;
        int h_x = x % size;

        // Ukoliko na polju postoji element, oznacemo da polje uklonjeno
        if (a[pos].second == x && a[pos].first == 1)
            a[pos].first = -1;
        else
        {
            int i = 1;
            while (i < size)
            {
                pos = (h_x + i * g_x) % size;

                if (a[pos].second == x && a[pos].first == 1)
                {
                    a[pos].first = -1;
                    return;
                }
                i++;
            }
        }
    }

    // Meotoda za ispis mape
    void print_map()
    {
        for (const auto &pair : a)
        {
            if (pair.first == 1)
                std::cout << pair.second << std::endl;
            else
                std::cout << "-\n";
        }
    }

private:
    // Imamo niz parova koji na govori da li je pozicija zauzeta, prazna ili prazna nakon brisanja
    // Na poziciji nakon brisanja ne smemo da upisujemo, jer moze doci do duplikata
    // Tako da i kad se obrise element, nemamo nov prostor za upisivanje
    // Prazne pozicije ce biti oznacene sa 0, popunjene sa 1, a prazne nako brisanja sa -1
    std::vector<std::pair<int, int>> a;
    // velicina mape
    int size;
    // vrednost za sekundardnu funkciju
    int secondary;
};

int main()
{
    hash_map map(11);

    map.add_value(22);
    map.add_value(1);
    map.add_value(13);
    map.add_value(11);
    map.add_value(24);
    map.add_value(33);
    map.add_value(18);
    map.add_value(42);
    map.add_value(31);

    std::cout << "Map:\n";
    map.print_map();

    map.remove_value(11);
    std::cout << "Map after removing element 11:\n";
    map.print_map();

    return 0;
}