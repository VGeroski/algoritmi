#include <iostream>

long long maksimalniPrinos(long long a, long long b, long long c)
{
    long long maksPovrsina = a * (b + c);
    for (long long i = 1; i <= c; i++)
    {
        maksPovrsina = std::max(maksPovrsina, (a + i) * (b + c - i));
    }

    return maksPovrsina;
}

// povrsina je najveca ukoliko su stranice iste, odnosno kod kvadrata
// ako ne mozemo da napravimo kvdrat, onda barem rasporedjujemo c da bude najpribliznije tome
long long maksimalniPrinosFormula(long long a, long long b, long long c)
{
    if (a > b)
        std::swap(a, b);
    if (c <= b - a)
        a += c;
    else
    {
        long long preostalo = c - (b - a);
        a = b + preostalo / 2;
        b = b + (preostalo + 1) / 2;
    }

    return a * b;
}

int main()
{
    std::cout << "Max prinos za 5, 10, 3: " << maksimalniPrinos(5, 10, 3) << std::endl;
    std::cout << "Max prinos za 9, 10, 4: " << maksimalniPrinos(9, 10, 4) << std::endl;
    std::cout << "Max prinos za 14, 17, 5: " << maksimalniPrinos(14, 17, 5) << std::endl;

    std::cout << "Max prinos (formula) za 5, 10, 3: " << maksimalniPrinosFormula(5, 10, 3) << std::endl;
    std::cout << "Max prinos (formula) za 9, 10, 4: " << maksimalniPrinosFormula(9, 10, 4) << std::endl;
    std::cout << "Max prinos (formula) za 14, 17, 5: " << maksimalniPrinosFormula(14, 17, 5) << std::endl;
}