#include <iostream>

template <typename TValue>
class IntSLLNode
{
private:
public:
    IntSLLNode *prev;
    IntSLLNode *next;
    TValue value;
    IntSLLNode() { next, prev = 0; }
    IntSLLNode(TValue i, IntSLLNode<TValue> *n, IntSLLNode<TValue> *p) : prev(p), next(n), value(i) {}
    ~IntSLLNode() {}
    TValue getValue() { return value; }
    IntSLLNode<TValue> *getNext() { return next; }
    IntSLLNode<TValue> *getPrev() { return prev; }
};

template <typename TValue>
class IntSLList
{
private:
    IntSLLNode<TValue> *head;
    IntSLLNode<TValue> *tail;

public:
    IntSLList()
    {
        head = 0;
        tail = 0;
    }

    ~IntSLList() {}

    void insertHead(TValue value)
    {
        IntSLLNode<TValue> *newNode = new IntSLLNode<TValue>(value, head, 0);
        if (head != 0)
            head->prev = newNode;
        head = newNode;
        if (tail == 0)
            tail = head;
    }

    void insertTail(TValue value)
    {
        IntSLLNode<TValue> *newNode = new IntSLLNode<TValue>(value, 0, tail);
        if (tail != 0)
            tail->next = newNode;
        tail = newNode;
        if (head == 0)
            head = tail;
    }

    void deleteFromHead()
    {
        if (head != 0)
        {
            IntSLLNode<TValue> *temp = head;
            head = head->next;
            if (head != 0)
                head->prev = 0;
            else
                tail = 0;
            delete temp;
        }
    }

    void deleteFromTail()
    {
        if (tail != 0)
        {
            IntSLLNode<TValue> *temp = tail;
            tail = tail->prev;
            if (tail != 0)
                tail->next = 0;
            else
                head = 0;
            delete temp;
        }
    }

    bool isInList(TValue el)
    {
        IntSLLNode<TValue> *temp;
        for (
            temp = head;
            temp != 0 && !(temp->getValue() == el);
            temp = temp->getNext())
            ;

        return temp != 0;
    }

    void iterate()
    {
        IntSLLNode<TValue> *current = head;
        while (current != 0)
        {
            std::cout << current->getValue() << std::endl;
            current = current->getNext();
        }
    }
};

int main()
{
    IntSLList<int> list;
    list.insertHead(1);
    list.insertHead(2);
    list.insertTail(3);
    list.iterate();
    std::cout << "-----------------" << std::endl;
    list.deleteFromHead();
    list.iterate();
    std::cout << "-----------------" << std::endl;
    list.deleteFromTail();
    list.iterate();
    std::cout << "-----------------" << std::endl;
    return 0;
}
