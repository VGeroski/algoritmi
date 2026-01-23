#include <iostream>
#include <stack>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::vector;

string removeStars(string s)
{
    int n = s.size();
    if (n == 0)
        return "";

    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '*')
        {
            if (!st.empty())
                st.pop();
        }
        else
            st.push(s[i]);
    }

    int stack_size = st.size();
    string res(stack_size, ' ');
    for (int i = stack_size - 1; i >= 0; i--)
    {
        res[i] = st.top();
        st.pop();
    }

    return res;
}

int main()
{
    vector<string> tests = {
        "leet**cod*e",
        "erase*****",
        "abc",
        "a*b*c*",
        "****",
        "ab**cd*e"};

    for (auto &t : tests)
    {
        cout << "Ulaz: \"" << t << "\" -> Izlaz: \""
             << removeStars(t) << "\"" << endl;
    }

    return 0;
}