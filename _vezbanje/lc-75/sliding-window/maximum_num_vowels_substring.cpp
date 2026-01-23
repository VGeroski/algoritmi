#include <iostream>
#include <string>

using std::string;
using std::max;
using std::cout;
using std::endl;

bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int maxVowels(string s, int k)
{
    // pratimo maks i trenutni broj samoglasnika
    int max_vowels = 0, current_vowels = 0;
    // postavljamo pocetni prozor
    for (int i = 0; i < k; i++)
        if (isVowel(s[i]))
            current_vowels++;

    max_vowels = current_vowels;

    for (int i = k; i < s.size(); i++)
    {
        // azuriramo broj pojavljivanja samoglasnika
        // ako je sa desne strane samoglasnik - povecavamo
        // ako je sa leve strane samoglasnik - smanjujemo
        // i je na desnoj granici pomerenog prozora
        if (isVowel(s[i])) current_vowels++;
        if (isVowel(s[i - k])) current_vowels--;

        max_vowels = max(max_vowels, current_vowels);
    }

    return max_vowels;
}

int main()
{
    cout << maxVowels("abciiidef", 3) << " (Ocekivano: 3)" << endl;
    cout << maxVowels("aeiou", 2) << " (Ocekivano: 2)" << endl;
    cout << maxVowels("leetcode", 3) << " (Ocekivano: 2)" << endl;
    cout << maxVowels("rhythms", 4) << " (Ocekivano: 0)" << endl;

    return 0;
}