#include <unordered_map>
#include <vector>
#include <iostream>

using std::cout;
using std::unordered_map;
using std::vector;

vector<int> pairSumUnsorted(const vector<int> &nums, int target)
{
    unordered_map<int, int> num_map; // { vrednost: indeks }

    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];
        if (num_map.count(complement))
            return {num_map[complement], i};

        num_map.insert({nums[i], i});
    }

    return {};
}

void printResult(const vector<int> &res)
{
    if (res.empty())
    {
        cout << "No pair found\n";
        return;
    }
    cout << "Indices: " << res[0] << ", " << res[1] << "\n";
}

int main()
{
    vector<int> nums1 = {2, 7, 11, 15};
    printResult(pairSumUnsorted(nums1, 9));

    vector<int> nums2 = {3, 3};
    printResult(pairSumUnsorted(nums2, 6));

    vector<int> nums3 = {-1, -2, -3, -4, -5};
    printResult(pairSumUnsorted(nums3, -8));

    vector<int> nums4 = {0, 4, 3, 0};
    printResult(pairSumUnsorted(nums4, 0));

    vector<int> nums5 = {1, 2, 3};
    printResult(pairSumUnsorted(nums5, 7));

    vector<int> nums6 = {10, -2, 8, 1, -6};
    printResult(pairSumUnsorted(nums6, 4));

    vector<int> nums7 = {5};
    printResult(pairSumUnsorted(nums7, 10));

    vector<int> nums8 = {};
    printResult(pairSumUnsorted(nums8, 0));
}