#include <vector>
#include <iostream>

/**
 * Red struktura. Podrzava dve osnovne operacije
 * dodavanje na kraj reda i skidanje sa pocetka reda.
 */
class queue
{
public:
    // podrazumevani konstruktor
    // Na pocetku je red prazan
    queue()
    {
        num_of_elements = 0;
    }

    // Dodavanje elementa na kraj reda
    void push(int x)
    {
        // obzirom da mi odrzavamo interno niz kao red
        // dodavanje u red znaci dodavanje na kraj niza
        vector.push_back(x);
        num_of_elements++;
    }

    // Uzimanje elemnta sa pocetka reda
    int pop()
    {
        // skidamo sa pocetka reda, odnosno sa pocetka niza
        int x = vector.front();
        vector.erase(vector.begin());
        num_of_elements--;

        return x;
    }

    // pomocna metoda za ispis reda
    void print_queue()
    {
        for (int x : vector)
            std::cout << x << " ";
        std::cout << std::endl;
    }

private:
    int num_of_elements;
    std::vector<int> vector;
};

int main()
{
    queue q;

    q.push(5);
    q.push(7);
    q.push(9);
    q.push(13);
    q.push(4);
    q.push(2);

    std::cout << "Elements: ";
    q.print_queue();

    std::cout << "First element: " << q.pop() << std::endl;

    std::cout << "Elements: ";
    q.print_queue();

    return 0;
}