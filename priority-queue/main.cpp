#include <iostream>

#define maxSize 5

typedef enum
{
    LOW = 0,
    MEDIUM = 1,
    HIGH = 2
} Priority;

template <typename TValue>
struct Element
{
    TValue data;
    Priority priority;
};

template <typename TValue>
class PriorityQueue
{

private:
    int front;
    int rear;
    int size;
    int max;
    Element<TValue> elements[maxSize];

public:
    PriorityQueue();
    ~PriorityQueue();

    void clear();

    bool isEmpty();
    bool isFull();

    TValue getFront();
    void enqueue(TValue el, Priority priority);
    TValue dequeue();
};

template <typename TValue>
PriorityQueue<TValue>::PriorityQueue()
{
    front = 0;
    rear = -1;
    size = 0;
    max = maxSize;
}

template <typename TValue>
PriorityQueue<TValue>::~PriorityQueue()
{
}

template <typename TValue>
void PriorityQueue<TValue>::clear()
{
    front = 0;
    rear = -1;
    size = 0;
}

template <typename TValue>
bool PriorityQueue<TValue>::isEmpty()
{
    return size == 0;
}

template <typename TValue>
bool PriorityQueue<TValue>::isFull()
{
    return size == max;
}

template <typename TValue>
TValue PriorityQueue<TValue>::getFront()
{
    if (isEmpty())
    {
        std::cout << "Priority queue is empty" << std::endl;
        return TValue{};
    }

    return elements[front].data;
}

template <typename TValue>
void PriorityQueue<TValue>::enqueue(TValue el, Priority priority)
{
    if (isFull())
    {
        std::cout << "Priority queue is full" << std::endl;
        return;
    }

    Element<TValue> newElement;
    newElement.data = el;
    newElement.priority = priority;

    rear++;
    elements[rear] = newElement;

    int i = rear;
    while (i > front && elements[i - 1].priority < elements[i].priority)
    {
        Element<TValue> temp = elements[i - 1];
        elements[i - 1] = elements[i];
        elements[i] = temp;
        i--;
    }

    size++;
}

template <typename TValue>
TValue PriorityQueue<TValue>::dequeue()
{
    if (isEmpty())
    {
        std::cout << "Priority queue is empty" << std::endl;
        return TValue{};
    }

    TValue value = elements[front].data;
    for (int i = front; i < rear; i++)
    {
        elements[i] = elements[i + 1];
    }

    rear--;
    size--;
    return value;
}

int main()
{
    PriorityQueue<int> pq;

    pq.enqueue(10, LOW);
    pq.enqueue(20, HIGH);
    pq.enqueue(30, MEDIUM);
    std::cout << "Front element: " << std::to_string(pq.getFront()) << std::endl;
    std::cout << "Dequeue element: " << std::to_string(pq.dequeue()) << std::endl;
    std::cout << "Front element: " << std::to_string(pq.getFront()) <<  std::endl;
    std::cout << "Dequeue element: " << std::to_string(pq.dequeue()) << std::endl;
    std::cout << "Front element: " << std::to_string(pq.getFront()) << std::endl;
    std::cout << "Dequeue element: " << std::to_string(pq.dequeue()) << std::endl;  
    std::cout << "Front element: " << std::to_string(pq.getFront()) << std::endl;
    return 0;
}
