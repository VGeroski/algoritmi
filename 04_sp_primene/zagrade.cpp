/**
 * Neka je dat izraz koji se sastoji samo od ( i ). Proveriti da li su zagrade ispravno uparene.
 * Npr izraz ( ( ) ( ) ) je ispravan, dok izraz ( ( ) ) ) nije.
 */

#include <iostream>
#include <stack>
#include <string>

int main()
{
    // stek za karakter po karakter iz izraza
    std::stack<char> s;

    // niz karaktera koji predstavlja izraz
    std::string expression;
    std::cin >> expression;

    // Prolazimo kroz sve karaktere u izrazu
    for (char c : expression)
    {
        if (c == '(')
            s.push(c);
        else if (c == ')')
        {
            // Ako je stek prazan, a naisli smo na zatvorenu zagradu ->
            // zagrade nisu balansirane
            if (s.empty())
            {
                std::cout << "Nisu balansirane!\n";
                return 0;
            }

            // ako stek nije prazan, samo skinemo element sa steka
            s.pop();
        }
    }

    std::cout << (s.empty() ? "Balansirane zagrade!\n" : "Nisu balansirane!\n");

    return 0;
}