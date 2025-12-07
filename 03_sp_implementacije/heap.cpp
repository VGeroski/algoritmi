#include <iostream>
#include <vector>

class heap
{
public:
    heap() {}

    // Funkcija za zamene mesta dve promenljive
    void swap(int &x, int &y)
    {
        int tmp = x;
        x = y;
        y = tmp;
    }

    // Dodavanje elementa u max-hip strukturu
    void add_element(int x)
    {
        // Dodavanje se vrsi tako sto se element doda na kraj niza (skroz desno u hipu)
        // a zatim se po potrebi "penje" dok ne dodje do pozicije da ne narusava hip svojstva
        array.push_back(x);

        // pocetna pozicija
        int i = array.size() - 1;

        // pozicija roditelja
        int parent = (i - 1) / 2;

        // trazimo poziciju za novi element, penjemo ga uz stablo,
        // sve dok postoji neki roditelj koji je manji od novog elementa
        while (array[i] > array[parent] && i != 0)
        {
            // zamena mesta
            swap(array[i], array[parent]);

            // azuriramo pozicije roditelja i elementa koji se penje
            i = (i - 1) / 2;
            parent = (i - 1) / 2;
        }
    }

    int take_root()
    {
        int root = array[0];

        // menjamo mesta korenu i poslednjem elementu u nizu (krajnje desni element u stablu)
        swap(array[0], array[array.size() - 1]);

        array.pop_back();

        // izbacili smo koren, ali sada se mozda narusila osobina hip strukture.
        // Potrebno je da novi koren "spustimo" niz stablo, da osobina ostane ista.
        // trazimo veci od dva naslednika, i menjamo ukoliko mesta ukoliko smo naisli na veceg naslednika

        int i = 0, greater, greater_index;
        if (array[2 * i + 1] > array[2 * i + 2])
        {
            greater = array[2 * i + 1];
            greater_index = 2 * i + 1;
        }
        else
        {
            greater = array[2 * i + 2];
            greater_index = 2 * i + 2;
        }

        // element nam je vrednost koje se spusta niz hip
        int element = array[i];

        while (element < greater && i < array.size())
        {
            swap(array[i], array[greater_index]);

            i = greater_index;
            element = array[i];

            // ukoliko se desi da element nema ni jednog naslednika, onda je on na svojoj poziciji
            if (2 * i + 1 >= array.size())
                break;

            // ukoliko element ima samo jednog naslednika, onda razmatramo samo levog naslednika
            if (2 * i + 2 >= array.size())
            {
                greater = array[2 * i + 1];
                greater_index = 2 * i + 1;
            }
            // ukoliko element ima oba naslednika, trazimo veci
            else if (array[2 * i + 1] > array[2 * i + 2])
            {
                greater = array[2 * i + 1];
                greater_index = 2 * i + 1;
            }
            else
            {
                greater = array[2 * i + 2];
                greater_index = 2 * i + 2;
            }
        }

        return root;
    }

    void print_heap()
    {
        for (int x : array)
            std::cout << x << " ";
        std::cout << std::endl;
    }

private:
    std::vector<int> array;
};

int main()
{
    heap h;

    h.add_element(4);
    h.add_element(2);
    h.add_element(3);
    h.add_element(8);
    h.add_element(1);
    h.add_element(5);
    h.add_element(6);

    h.print_heap();

    std::cout << "Root: " << h.take_root() << std::endl;
    std::cout << "Heap after root removal: ";
    h.print_heap();

    return 0;
}