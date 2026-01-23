#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::vector;

int longestSubarray(vector<int> &nums)
{
    int left = 0, max_len = 0, num_of_zeros = 0;

    for (int right = 0; right < nums.size(); right++)
    {
        // povecavamo broj nula ako naidjemo
        if (nums[right] == 0)
            num_of_zeros++;

        // prozor pomeramo tek ako u prozoru imamo vise od jedne 0
        while (num_of_zeros > 1)
        {
            if (nums[left] == 0)
                num_of_zeros--;

            left++;
        }

        max_len = max(max_len, right - left);
    }

    return max_len;
}

int main()
{
    vector<vector<int>> tests = {
        {1, 1, 0, 1},
        {1, 1, 1},
        {0, 0, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 0, 1, 1, 1}
    };

    for (auto &t : tests)
    {
        cout << "Ulaz: ";
        for (int x : t)
            cout << x << " ";
        cout << " -> Izlaz: " << longestSubarray(t) << endl;
    }

    return 0;
}