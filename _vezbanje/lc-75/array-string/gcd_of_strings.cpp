#include <iostream>
#include <string>
#include <numeric>

using std::cout;
using std::endl;
using std::gcd;
using std::string;

string gcdOfStrings(string str1, string str2)
{
    // uslov da li uopste imamo gcd
    if (str1 + str2 != str2 + str1)
        return "";

    int gcd_len = gcd(str1.size(), str2.size());
    return str1.substr(0, gcd_len); // str[0 : gcd]
}

int main()
{
    cout << "Test 1: " << gcdOfStrings("ABCABC", "ABC") << endl;

    cout << "Test 2: " << gcdOfStrings("ABABAB", "ABAB") << endl;

    cout << "Test 3: " << gcdOfStrings("LEET", "CODE") << endl;

    cout << "Test 4: " << gcdOfStrings("AAAA", "AA") << endl;

    cout << "Test 5: " << gcdOfStrings("A", "A") << endl;
}