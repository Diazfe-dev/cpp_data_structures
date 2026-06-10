#include <iostream>

template <typename TValue>
class IntSLLNode
{
public:
    IntSLLNode *next;
    TValue value;
    IntSLLNode() { next = 0; }
    IntSLLNode(TValue i, IntSLLNode<TValue> *n) : next(n), value(i) {}
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

    bool isEmpty() { return head == 0; }

    void insertHead(TValue value)
    {
        if (isEmpty())
        {
            head = tail = new IntSLLNode<TValue>(value, 0);
            head->next = head;
            return;
        }

        IntSLLNode<TValue> *newNode = new IntSLLNode<TValue>(value, head);
        tail->next = newNode;
        head = newNode;
    }

    void insertTail(TValue value)
    {
        if (isEmpty())
        {
            head = tail = new IntSLLNode<TValue>(value, 0);
            head->next = head;
            return;
        }

        IntSLLNode<TValue> *newNode = new IntSLLNode<TValue>(value, head);
        tail->next = newNode;
        tail = newNode;
    }

    void deleteFromHead()
    {
        if (isEmpty())
            return;

        if (head == tail)
        {
            delete head;
            head = tail = 0;
            return;
        }

        IntSLLNode<TValue> *temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }

    void deleteFromTail()
    {
        if (isEmpty())
            return;

        if (head == tail)
        {
            delete tail;
            head = tail = 0;
            return;
        }

        // Recorrer hasta el penúltimo nodo (no hay prev)
        IntSLLNode<TValue> *current = head;
        while (current->next != tail)
            current = current->next;

        delete tail;
        tail = current;
        tail->next = head;
    }

    bool isInList(TValue el)
    {
        if (isEmpty())
            return false;

        IntSLLNode<TValue> *current = head;
        do
        {
            if (current->getValue() == el)
                return true;
            current = current->getNext();
        } while (current != head);

        return false;
    }

    void iterate()
    {
        if (isEmpty())
            return;
        IntSLLNode<TValue> *current = head;
        do
        {
            std::cout << current->getValue() << std::endl;
            current = current->getNext();
        } while (current != head);
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
    return 0;
}
