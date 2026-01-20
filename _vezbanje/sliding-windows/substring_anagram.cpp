#include <string>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int substringAnagrams(const string &s, const string &t)
{
    int len_s = s.size();
    int len_t = t.size();
    if (len_s < len_t)
        return 0;

    vector<int> expected_freqs(26, 0);
    vector<int> window_freqs(26, 0);

    // odredjujemo prvo frekvencije svih karaktera u t, da bismo imali posle za poredjenje
    for (char c : t)
        expected_freqs[c - 'a']++;

    int count = 0;
    int left = 0, right = 0;
    while (right < len_s)
    {
        // pre nego sto pomerimo prozor, dodajemo karakter u window_freq
        window_freqs[s[right] - 'a']++;

        if (right - left + 1 == len_t)
        {
            if (expected_freqs == window_freqs)
                count++;

            // postigli smo zeljeni prozor, skidamo karakter sa leve strane
            // i pomeramo prozor na desno
            window_freqs[s[left] - 'a']--;
            left++;
        }
        right++;
    }

    return count;
}

int main()
{
    cout << substringAnagrams("cbaebabacd", "abc") << endl;
    cout << substringAnagrams("abab", "ab") << endl;
    cout << substringAnagrams("abcdef", "gh") << endl;
    cout << substringAnagrams("aaabaa", "aaa") << endl;
    cout << substringAnagrams("ab", "abc") << endl;
    cout << substringAnagrams("abc", "abc") << endl;
    cout << substringAnagrams("aaaaa", "aa") << endl;
    cout << substringAnagrams("abcabc", "a") << endl;
    cout << substringAnagrams("", "a") << endl;
    cout << substringAnagrams("abc", "") << endl;

    return 0;
}