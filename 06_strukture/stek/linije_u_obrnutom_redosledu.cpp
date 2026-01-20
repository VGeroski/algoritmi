/**
 * Napisi program koji ispisuje sve linije koje se ucitavaju sa standardnog ulaza
 * u obrnutom redolsedu od redosleda ucitavanja.
 * 
 * Primer:
 * ulaz: zdravo, svete, dobar, dan
 * izlaz: dan, dobar, svete, zdravo
 */

#include <iostream>
#include <stack>
#include <string>

using std::stack;
using std::string;

int main()
{
    // mozemo ucitane linije da redjamo u stek, 
    // a onda samo da izlvlacimo iz steka pri ispisu na std izlaz
    stack<string> s;
    string linija;

    while(getline(std::cin, linija))
        s.push(linija);

    while (!s.empty())
    {
        std::cout << s.top() << std::endl;
        s.pop();
    }
}