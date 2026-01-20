/**
 * Pregledac pamti istoriju posecenih sajtova i korisinik ima mogucnost
 * da se vraca unatrag na sajtove koje je ranije posetio. Napisati program koji
 * simulira istoriju pregledaca tako sto se ucitavaju adrese posecenih sajtova, a
 * kada se ucita red u kome pise 'back' pregledac se vraca na poslednju posecenu stranicu.
 * Ispisati sve stranice koje je korisnik posetio.
 *
 * Primer:
 * ulaz:                            izlaz:
 * http://www.google.com,           - http://www.google.com
 * http://www.rts.rs,               - http://www.rts.rs
 * back,                            - http://www.google.com
 * http://www.petlja.org,           - http://www.petlja.org
 * http://www.matf.bg.ac.rs,        - http://www.matf.bg.ac.rs
 * back,                            - http://www.petlja.org
 * back,                            - http://www.google.com
 * back,                            - -
 * back                             - -
 */

#include <iostream>
#include <string>
#include <stack>

using std::stack;
using std::string;

int main()
{
    stack<string> istorija;
    string linija;

    while (getline(std::cin, linija))
    {
        if (linija == "back")
        {
            if (!istorija.empty())
                istorija.pop();
            if (!istorija.empty())
                std::cout << istorija.top() << std::endl;
            else
                std::cout << "-" << std::endl;
        }
        else
        {
            std::cout << linija << std::endl;
            istorija.push(linija);
        }
    }
}