/**
 * Neka je dat izraz koji se sastoji od svih zagrada ()[]{}.
 * Proveriti da li su zagrade ispravno uparene.
 * Npr izraz ( [ ( ) ] { } ) je ispravan, dok izraz ( { ) ] ) nije.
 */

#include <iostream>
#include <stack>
#include <string>

bool is_bracket_matched(char open_br, char closed_br)
{
    return (open_br == '(' && closed_br == ')') || (open_br == '[' && closed_br == ']') || (open_br == '{' && closed_br == '}');
}

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
        if (c == '(' || c == '[' || c == '{')
            s.push(c);
        else if (c == ')' || c == ']' || c == '}')
        {
            if (s.empty() || !is_bracket_matched(s.top(), c))
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