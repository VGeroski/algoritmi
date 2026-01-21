#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string reverseWords(string s)
{
    int n = s.size();
    string result;

    // pocinjemo od kraja stringa
    int i = n - 1;
    while (i >= 0)
    {
        // cistimo beline ako postoje pre reci
        while (i >= 0 && s[i] == ' ')
            i--;

        // mozda smo ispali iz stringa ako je belina bila i na samom pocetku stringa
        if (i < 0)
            break;

        // preko j pokazivaca trazimo gde pocinje rec
        int j = i;
        while (j >= 0 && s[j] != ' ')
            j--;

        // dodajemo razmak samo izmedju vec postojecih reci, ne i na pocetak
        if (!result.empty())
            result.push_back(' ');

        result.append(s.substr(j + 1, i - j));

        // priprema za novu iteraciju
        i = j - 1;
    }

    return result;
}

int main()
{
    cout << reverseWords("the sky is blue") << endl;
    cout << reverseWords("  hello world  ") << endl;
    cout << reverseWords("a") << endl;
    cout << reverseWords("   ") << endl;
    cout << reverseWords("  Bob    Loves  Alice   ") << endl;
}