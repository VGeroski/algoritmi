#include <vector>
#include <iostream>

/**
 * Stek struktura. Podrzava dve osnovne operacije
 * dodavanje na vrh steka i skidanje sa steka.
 */
class stack
{
public:
    // podrazumevani konstruktor
    // Na pocetku je stek prazan
    stack()
    {
        num_of_elements = 0;
    }

    // Dodavanje elementa na vrh steka
    void add_to_top(int x)
    {
        // obzirom da mi odrzavamo interno niz kao stek
        // dodavanje na stek znaci dodavanje na kraj niza
        vector.push_back(x);
        num_of_elements++;
    }

    // Uzimanje elemnta sa vrha steka
    int take_from_top()
    {
        // uzimamo element sa kraja niza i uklanjamo iz niza
        int x = vector.back();
        vector.pop_back();
        num_of_elements--;

        return x;
    }

    // pomocna metoda za ispis steka
    void print_stack()
    {
        // Treba da ispisemo elemente odozgo nadole
        // pa zato ispisujemo niz obrnutim redom
        auto rbegin = vector.rbegin();
        auto rend = vector.rend();

        while (rbegin != rend)
        {
            // iterator je pokazivac, potrebno je da ga dereferenciramo
            std::cout << *rbegin << " ";

            // pomeramo se
            rbegin++;
        }
    }

private:
    int num_of_elements;
    std::vector<int> vector;
};

int main()
{
    stack s;

    s.add_to_top(5);
    s.add_to_top(7);
    s.add_to_top(9);
    s.add_to_top(13);
    s.add_to_top(4);
    s.add_to_top(2);

    std::cout << "Elements: ";
    s.print_stack();
    std::cout << std::endl;

    std::cout << "Top element: " << s.take_from_top() << std::endl;

    std::cout << "Elements: ";
    s.print_stack();
    std::cout << std::endl;

    return 0;
}