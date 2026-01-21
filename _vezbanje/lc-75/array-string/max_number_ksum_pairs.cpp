#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout;
using std::endl;
using std::unordered_map;
using std::vector;

int maxOperations(vector<int> &nums, int k)
{
    // cuvamo vrednost i broj pojavjivanja
    unordered_map<int, int> freq;

    int max_operations = 0;
    for (int x : nums)
    {
        int complement = k - x;
        if (freq[complement] > 0)
        {
            // mozemo da napravimo zbir koji je jedan k
            max_operations++;
            freq[complement]--;
        }
        else
            freq[x]++;
    }

    return max_operations;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 4};
    int k1 = 5;
    cout << "Test 1: " << maxOperations(nums1, k1) << " (Expected: 2)" << endl;

    vector<int> nums2 = {3, 1, 3, 4, 3};
    int k2 = 6;
    cout << "Test 2: " << maxOperations(nums2, k2) << " (Expected: 1)" << endl;

    vector<int> nums3 = {2, 2, 2, 2};
    int k3 = 4;
    cout << "Test 3: " << maxOperations(nums3, k3) << " (Expected: 2)" << endl;

    vector<int> nums4 = {1, 5, 1, 5};
    int k4 = 6;
    cout << "Test 4: " << maxOperations(nums4, k4) << " (Expected: 2)" << endl;

    return 0;
}