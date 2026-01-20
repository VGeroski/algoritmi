#include <iostream>
#include <vector>

using std::cout;
using std::max;
using std::min;
using std::vector;

int largestContainer(const vector<int> &heights)
{
    int l = 0, d = heights.size() - 1;
    int p = 0, pmax = 0;

    while (l < d)
    {
        // uzimamo manju visunu da se voda ne bi prosula
        p = (d - l) * min(heights[l], heights[d]);
        pmax = max(p, pmax);

        if (heights[l] < heights[d])
            l++;
        else if (heights[l] > heights[d])
            d--;
        else
        {
            l++;
            d--;
        }
    }

    return pmax;
}

int main()
{
    cout << "Max voda: " << largestContainer({}) << "\n";
    cout << "Max voda: " << largestContainer({1}) << "\n";
    cout << "Max voda: " << largestContainer({0, 1, 0}) << "\n";
    cout << "Max voda: " << largestContainer({3, 3, 3, 3}) << "\n";
    cout << "Max voda: " << largestContainer({1, 2, 3}) << "\n";
    cout << "Max voda: " << largestContainer({3, 2, 1}) << "\n";
}