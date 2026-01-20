#include <iostream>
#include <vector>

using std::vector;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int n = numbers.size();
    int l = 0, d = n - 1;

    while (l < d)
    {
        int sum = numbers[l] + numbers[d];
        if (sum == target)
            return {l, d};

        // ako je suma veca, pomeramo desni pokazivac
        if (sum > target)
            d--;
        // ako je suma manja od cilja, pomeramo levi pokazivac
        else if (sum < target)
            l++;
    }

    // ako do sad nismo izasli iz metode, nema para koji pravi sumu
    return {};
}

int main()
{
    vector<int> test = {-5, -2, 3, 4, 6};
    vector<int> result = twoSum(test, 7);

    std::cout << "Trazenu sumu mozemo napraviti preko elemenata iz niza na pozicijama: "
              << result[0] << " i " << result[1] << std::endl;

    return 0;
}