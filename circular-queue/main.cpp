#include <iostream>
#include <vector>

#define maxSize 5

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
    front = 0;
    rear = -1;
}

template <typename TValue>
Queue<TValue>::~Queue()
{
}

template <typename TValue>
void Queue<TValue>::clear()
{
    front = 0;
    rear = -1;
    size = 0;
}

template <typename TValue>
bool Queue<TValue>::isEmpty()
{
    return size == 0;
}

template <typename TValue>
bool Queue<TValue>::isFull()
{
    return size == max;
}

template <typename TValue>
TValue Queue<TValue>::getFront()
{
    if (!isEmpty())
        return queue[front];

    std::cout << "Queue is empty" << std::endl;
    return TValue{};
}

template <typename TValue>
void Queue<TValue>::enqueue(TValue el)
{
    if (!isFull())
    {
        rear = (rear + 1) % max;
        queue[rear] = el;
        size++;
        return;
    }

    std::cout << "Queue overflow (full)" << std::endl;
}

template <typename TValue>
TValue Queue<TValue>::dequeue()
{
    if (!isEmpty())
    {
        TValue value = queue[front];
        front = (front + 1) % max;
        size--;
        return value;
    }

    std::cout << "Queue underflow (empty)" << std::endl;
    return TValue{};
}

int main()
{
    Queue<int> q;
    q.enqueue(11);
    q.enqueue(12);
    q.enqueue(13);
    q.enqueue(14);
    q.enqueue(15);
    q.enqueue(16);
    std::cout << "Front element: " << std::to_string(q.getFront()) << std::endl;
    std::cout << "Dequeue element: " << std::to_string(q.dequeue()) << std::endl;
    q.enqueue(16);

    return 0;
}
