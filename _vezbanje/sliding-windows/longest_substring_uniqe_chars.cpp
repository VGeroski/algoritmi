#include <unordered_set>
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::max;
using std::string;
using std::unordered_set;

int longestSubstringWithUniqueChars(const string &s)
{
    unordered_set<char> set;

    int max_len = 0;
    int left = 0, right = 0;
    while (right < s.size())
    {
        while (set.count(s[right]))
        {
            set.erase(s[left]);
            left++;
        }

        int temp_window_size = right - left + 1;
        max_len = max(max_len, temp_window_size);

        set.emplace(s[right]);
        right++;
    }

    return max_len;
}

int main()
{
    cout << longestSubstringWithUniqueChars("abcabcbb") << endl;
    cout << longestSubstringWithUniqueChars("bbbbb") << endl;
    cout << longestSubstringWithUniqueChars("pwwkew") << endl;
    cout << longestSubstringWithUniqueChars("") << endl;
    cout << longestSubstringWithUniqueChars("a") << endl;
    cout << longestSubstringWithUniqueChars("au") << endl;
    cout << longestSubstringWithUniqueChars("dvdf") << endl;
    cout << longestSubstringWithUniqueChars("abba") << endl;
}