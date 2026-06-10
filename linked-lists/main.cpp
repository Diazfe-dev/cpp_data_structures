#include <iostream>
#include <cassert>

template <typename TValue>
class IntSLLNode
{
private:
public:
    IntSLLNode<TValue> *next;
    TValue value;

    IntSLLNode()
    {
        next = 0;
    }
    IntSLLNode(TValue i, IntSLLNode<TValue> *n)
    {
        value = i;
        next = n;
    }
    ~IntSLLNode() {}

    TValue getValue() { return value; }
    IntSLLNode<TValue> *getNext() { return next; }
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

    void addToHead(TValue value)
    {
        IntSLLNode<TValue> *newNode = new IntSLLNode<TValue>(value, head);
        head = newNode;
        if (tail == 0)
            tail = head;
    }

    void addToTail(TValue value)
    {
        IntSLLNode<TValue> *newNode = new IntSLLNode<TValue>(value, 0);
        if (tail != 0)
            tail->next = newNode;
        if (head == 0)
            head = tail;

        tail = newNode;
    }

    void deleteFromHead()
    {
        assert(head != 0);
        IntSLLNode<TValue> *temp = head;
        head = head->next;
        delete temp;
        if (head == 0)
            tail = 0;
    }

    void deleteFromTail()
    {
        IntSLLNode<TValue> *temp = head;

        while (temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = 0;
    }

    void deleteNode(int el)
    {
        if (head != 0)
        {
            if (head == tail && el == head->getValue())
            {
                delete head;
                head = tail = 0;
            }
            else if (el == head->getValue())
            {
                IntSLLNode<TValue> *temp = head;
                head = head->getNext();
                delete temp;
            }
            else
            {
                IntSLLNode<TValue> *pred, *temp;
                for (
                    pred = head, temp = head->getNext();
                    temp != 0 && (temp->getValue() != el);
                    pred = temp, temp = temp->getNext())
                    ;
                if (temp != 0)
                {
                    pred->next = temp->getNext();
                    if (temp == tail)
                    {
                        tail = pred;
                    }
                    delete temp;
                }
            }
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
    IntSLList<int> list = IntSLList<int>();
    list.addToHead(1);
    list.addToTail(3);
    list.addToHead(4);
    list.addToTail(2);
    list.iterate();

    std::cout << "-----------------" << std::endl;

    list.deleteFromHead();
    list.iterate();
    std::cout << "-----------------" << std::endl;

    list.deleteFromTail();
    list.iterate();
    return 0;
}