#include <iostream>

int minNiza(int a[], int n)
{
    int min = a[0];
    for (int i = 1; i < n; i++)
        min = std::min(a[i], min);

    return min;
}

int minNiza_r(int a[], int n)
{
    if (n == 1)
        return a[0];
    
    int min = minNiza_r(a, n - 1);
    return std::min(a[n - 1], min);
}

int main()
{
    int a[] = {3, 5, 4, 1, 6, 2, 7};
    int n = sizeof(a) / sizeof(a[0]);

    std::cout << "Minimum (iterativno): " << minNiza(a, n) << std::endl;
    std::cout << "Minimum (rekurzivno): " << minNiza_r(a, n) << std::endl;

    return 0;
}