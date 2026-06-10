#include <iostream>

template <typename TValue>
class Stack
{
private:
    TValue stack[100];
    int maxSize;
    int top;

public:
    Stack()
    {
        maxSize = 100;
        top = -1;
    }
    ~Stack() {}

    void push(TValue el)
    {
        if (!isFull())
            stack[++top] = el;
        else
            std::cout << "Stack overflow (full)" << std::endl;
    };

    TValue pop()
    {
        if (!isEmpty())
            return stack[top--];

        std::cout << "Stack underflow (empty)" << std::endl;
        return TValue{};
    };

    TValue getTop()
    {
        if (!isEmpty())
            return stack[top];

        std::cout << "Stack is empty" << std::endl;
        return TValue{};
    };

    int getCurrentSize()
    {
        return top + 1;
    };

    bool isEmpty()
    {
        if (top == -1)
            return true;
        return false;
    };
    bool isFull()
    {
        if (top == maxSize - 1)
            return true;
        return false;
    };
};

int main()
{
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << "Top element: " << stack.getTop() << std::endl;
    std::cout << "Current size: " << stack.getCurrentSize() << std::endl;
    stack.pop();
    std::cout << "Popped element: " << std::endl;
    std::cout << "Top element: " << std::to_string(stack.getTop()) << std::endl;
    return 0;
}
