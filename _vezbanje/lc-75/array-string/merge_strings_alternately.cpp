#include <iostream>
#include <string>

using std::cout;
using std::string;

string mergeAlternately(string word1, string word2)
{
    int w1_len = word1.size();
    int w2_len = word2.size();
    string result;
    result.resize(w1_len + w2_len);

    int i = 0, j = 0, k = 0;
    while (i < w1_len || j < w2_len)
    {
        if (i < w1_len)
            result[k++] = word1[i++];
        if (j < w2_len)
            result[k++] = word2[j++];
    }

    return result;
}

int main()
{
    string merged = mergeAlternately("abc", "pqr");
    cout << "Test 1: " << merged << "\n";

    merged = mergeAlternately("ab", "pqrs");
    cout << "Test 2: " << merged << "\n";

    merged = mergeAlternately("abcd", "pq");
    cout << "Test 3: " << merged << "\n";

    return 0;
}