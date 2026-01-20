#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

vector<vector<int>> twoSumSortedAllPairs(vector<int> &nums, int start, int target)
{
    int n = nums.size();
    int l = start, d = n - 1;

    vector<vector<int>> pairs = {};

    while (l < d)
    {
        int sum = nums[l] + nums[d];
        if (sum == target)
        {
            pairs.push_back({nums[l], nums[d]});
            l++;

            // izbegavamo isto 'b'
            while (l < d && nums[l] == nums[l - 1])
                l++;
        }
        // ako je suma veca, pomeramo desni pokazivac
        else if (sum > target)
            d--;
        // ako je suma manja od cilja, pomeramo levi pokazivac
        else
            l++;
    }

    // ako do sad nismo izasli iz metode, nema para koji pravi sumu
    return pairs;
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    std::sort(nums.begin(), nums.end());
    int n = nums.size();

    vector<vector<int>> triplets = {};

    for (int i = 0; i < n; i++)
    {
        // preskacemo duplikate za 'a'
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        vector<vector<int>> all_pairs = twoSumSortedAllPairs(nums, i + 1, -nums[i]);
        for (auto &p : all_pairs)
            triplets.push_back({nums[i], p[0], p[1]});
    }

    return triplets;
}

void printResult(const vector<vector<int>> &res)
{
    cout << "[\n";
    for (const auto &t : res)
    {
        cout << "  { ";
        for (int x : t)
            cout << x << " ";
        cout << "}\n";
    }
    cout << "]\n";
}

int main()
{
    vector<vector<int>> tests = {
        {-1, 0, 1, 2, -1, -4},
        {0, 0, 0, 0},
        {-2, 0, 0, 2, 2},
        {3, -2, 1, 0},
        {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6},
        {-1, -1, -1, 2, 2},
        {1, 2, -2, -1},
        {-5, 2, 3, 0, 1, -1, -2}};

    for (int i = 0; i < tests.size(); i++)
    {
        cout << "Test " << i + 1 << ":\n";
        auto res = threeSum(tests[i]);
        printResult(res);
        cout << "----------------------\n";
    }

    return 0;
}