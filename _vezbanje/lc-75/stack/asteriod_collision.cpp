#include <iostream>
#include <stack>
#include <vector>

using std::cout;
using std::endl;
using std::stack;
using std::vector;

vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> ast;
    for (int i = 0; i < asteroids.size(); i++)
    {
        int a = asteroids[i];
        // pretpostavimo da trenutni 'a' asteroid nije raznet
        bool destroyed = false;

        // do kolizije moze da dodje kada je stek nije prazan,
        // trenutni asteroid je negativan, a prvi na steku pozitivan
        while (!ast.empty() && a < 0 && ast.top() > 0)
        {
            if (ast.top() < -a)
            {
                // eksplodira asteroid na steku
                ast.pop();
            }
            else if (ast.top() == -a)
            {
                // ako su isti, oba nestaju
                ast.pop();
                destroyed = true;
                break;
            }
            else
            {
                // ako smo stigli ovde, trenutni asteroid je manji od onog na steku
                // pa samo je trenutni asteroid unisten
                destroyed = true;
                break;
            }
        }

        if (!destroyed)
            ast.push(a);
    }

    vector<int> result(ast.size());
    for (int i = ast.size() - 1; i >= 0; i--)
    {
        result[i] = ast.top();
        ast.pop();
    }
    return result;
}

void printVec(const vector<int> &v)
{
    cout << "[ ";
    for (int x : v)
        cout << x << " ";
    cout << "]";
}

int main()
{
    vector<vector<int>> tests = {
        {5, 10, -5},
        {8, -8},
        {10, 2, -5},
        {-2, -1, 1, 2},
        {1, -2, -2, -2},
        {2, -1, -2}};

    for (auto &t : tests)
    {
        printVec(t);
        cout << " -> ";
        printVec(asteroidCollision(t));
        cout << endl;
    }

    return 0;
}