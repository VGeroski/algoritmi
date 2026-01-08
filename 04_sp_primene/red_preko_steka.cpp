/**
 * Implementirati red preko dva steka.
 */

#include <stack>
#include <iostream>

class queue
{
public:
    queue() {}

    void push(int x) { push_stack.push(x); }

    int pop()
    {
        if (pop_stack.empty())
        {
            while (!push_stack.empty())
            {
                pop_stack.push(push_stack.top());
                push_stack.pop();
            }
        }

        int res = pop_stack.top();
        pop_stack.pop();

        return res;
    }

private:
    std::stack<int> push_stack;
    std::stack<int> pop_stack;
};

int main()
{
    queue q;

    q.push(1);
    q.push(2);

    std::cout << q.pop() << std::endl;
    
    q.push(3);

    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;

    return 0;
}