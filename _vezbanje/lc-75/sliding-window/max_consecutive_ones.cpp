#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::vector;

int longestOnes(vector<int> &nums, int k)
{
    int left = 0, num_of_zeros = 0, max_len = 0;

    for (int right = 0; right < nums.size(); right++)
    {
        // ako smo trenutno na nuli, povecavamo broj nula
        // prakticno preko broja nula pratimo da li da nastavljamo dalje
        // sa prosirivanjem prozora, ili sa pomeranjem
        if (nums[right] == 0)
            num_of_zeros++;

        // slajdujemo prozor sve dok broj nula ne bude jednak k
        // a ako nam je 0 na trenutnom broju (pre pomeranja) onda smanjujemo
        // broj nula, jer ce u sledecoj iteraciji da ispadne iz prozora
        while (num_of_zeros > k)
        {
            if (nums[left] == 0)
                num_of_zeros--;

            left++;
        }

        // azuriramo max_len ako smo naisli na veci segment
        max_len = max(max_len, right - left + 1);
    }

    return max_len;
}

int main()
{
    vector<int> nums1 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k1 = 2;
    cout << "Test 1: " << longestOnes(nums1, k1) << " (Ocekivano: 6)" << endl;

    vector<int> nums2 = {0, 0, 1, 1, 1, 0, 0};
    int k2 = 0;
    cout << "Test 2: " << longestOnes(nums2, k2) << " (Ocekivano: 3)" << endl;

    vector<int> nums3 = {1, 1, 1, 1};
    int k3 = 1;
    cout << "Test 3: " << longestOnes(nums3, k3) << " (Ocekivano: 4)" << endl;

    vector<int> nums4 = {0, 0, 0, 0};
    int k4 = 2;
    cout << "Test 4: " << longestOnes(nums4, k4) << " (Ocekivano: 2)" << endl;

    vector<int> nums5 = {1, 0, 1, 0, 1, 0, 1};
    int k5 = 1;
    cout << "Test 5: " << longestOnes(nums5, k5) << " (Ocekivano: 3)" << endl;

    return 0;
}