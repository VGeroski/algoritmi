#include <iostream>
#include <string>
#include <cctype>

using std::cout;
using std::isalnum;
using std::string;

bool isPalidnromeValid(const string &s)
{
    int l = 0, d = s.size() - 1;

    while (l < d)
    {
        // preskoci karaktere koji nisu alfanumericke
        while (l < d && !isalnum(static_cast<unsigned char>(s[l])))
            l++;

        while (l < d && !isalnum(static_cast<unsigned char>(s[d])))
            d--;

        if (s[l] != s[d])
            return false;

        l++;
        d--;
    }

    return true;
}

int main()
{
    cout << isPalidnromeValid("a man, a plan, a canal: panama") << "\n";
    cout << isPalidnromeValid("race a car") << "\n";
    cout << isPalidnromeValid(" ") << "\n";
    cout << isPalidnromeValid("0P") << "\n";
    cout << isPalidnromeValid("ana voli milovana") << "\n";
    cout << isPalidnromeValid("12.02.2021") << "\n";
}