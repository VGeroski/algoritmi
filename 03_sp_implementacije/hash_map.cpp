#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

/**
 * Hes tabela, sa podrskom za dodavanje i brisanje iz tabele.
 * Resavanje kolizije: ulancavanje
 */

class hash_map
{
public:
    hash_map() {}

    hash_map(int x)
    {
        a.resize(x);
        size = x;
    }

    // Dodajemo vrednost u tabelu
    // metod ulancavanja
    void add_value(int x)
    {
        // Racunamo gde element treba da se nalazi -> na poziciji x % size
        int pos = x % size;

        // Proveravamo da li element vec postoji u listi
        auto index = std::find(a[pos].begin(), a[pos].end(), x);

        // dodajemo vrednost na kraj liste ukoliko vrednost vec ne postoji
        if (index == a[pos].end())
            a[pos].push_back(x);
    }

    void remove_value(int x)
    {
        // Racunamo na kojoj poziciji moze da bude element
        int pos = x % size;

        // Ukoliko se nalazi u list, brisemo element
        a[pos].remove(x);
    }

    // Meotoda za ispis mape
    void print_map()
    {
        for (const auto &list : a)
        {
            std::cout << "- ";
            auto begin = list.begin();
            auto end = list.end();

            // necemo ispis strelice za poslednji element zato ovde snizavamo iterator
            end--;
            while (begin != end)
            {
                std::cout << *begin << " -> ";
                begin++;
            }
            // ispis poslednjeg kojeg smo gore namerno preskocili
            std::cout << *begin << std::endl;
        }
    }

private:
    // Imamo vektor listi, posto koristimo ulancavanje
    // Svali element liste liste treba da bude nova lista koja ce se ulancavati
    std::vector<std::list<int>> a;
    // velicina mape
    int size;
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