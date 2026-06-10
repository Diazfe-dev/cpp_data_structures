#include <iostream>
#include <vector>

#define maxSize 50

template <typename TValue>
class Queue
{
    int front;
    int rear;
    int size;
    int max;
    TValue queue[maxSize];

private:
public:
    Queue();
    ~Queue();

    void clear();

    bool isEmpty();
    bool isFull();

    TValue getFront();
    void enqueue(TValue el);
    TValue dequeue();
};

template <typename TValue>
Queue<TValue>::Queue()
{
    size = 0;
    max = maxSize;
    rear = front = -1;
}

template <typename TValue>
Queue<TValue>::~Queue()
{
}

template <typename TValue>
void Queue<TValue>::clear()
{
    if (!isEmpty())
    {
        front = rear = -1;
        size = 0;
    }
}

template <typename TValue>
bool Queue<TValue>::isEmpty()
{
    if (front == rear)
    {
        return true;
    }
    return false;
}

template <typename TValue>
bool Queue<TValue>::isFull()
{
    if (rear == max - 1)
    {
        return true;
    }
    return false;
}

template <typename TValue>
TValue Queue<TValue>::getFront()
{
    if (!isEmpty())
        return queue[front + 1];
}

template <typename TValue>
void Queue<TValue>::enqueue(TValue el)
{
    if (!isFull())
    {
        queue[++rear] = el;
        size++;
    }
}

template <typename TValue>
TValue Queue<TValue>::dequeue()
{
    if (!isEmpty())
    {
        size--;
        return queue[++front];
    }
}

int main()
{
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    std::cout << "Front element: " << std::to_string(q.getFront()) << std::endl;
    std::cout << "Dequeue element: " << std::to_string(q.dequeue()) << std::endl;
    std::cout << "Front element: " << std::to_string(q.getFront()) << std::endl;
    std::cout << "Dequeue element: " << std::to_string(q.dequeue()) << std::endl;
    std::cout << "Front element: " << std::to_string(q.getFront()) << std::endl;


    return 0;
}
