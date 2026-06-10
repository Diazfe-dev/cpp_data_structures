#include <iostream>

template <typename TValue>
class IntSLLNode
{
private:
public:
    IntSLLNode *prev;
    IntSLLNode *next;
    TValue value;
    IntSLLNode() { next = prev = 0; }
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

    bool isEmpty() { return head == 0; }

    void insertHead(TValue value)
    {
        // If the list is empty, we need to initialize head and tail to the new node
        if (isEmpty())
        {
            head = tail = new IntSLLNode<TValue>(value, 0, 0);
            head->next = head; // Point next to itself to maintain circular structure
            head->prev = head; // Point prev to itself to maintain circular structure
            return;
        }

        // If the list is not empty, we need to insert the new node before the current head and update the tail's next pointer
        IntSLLNode<TValue> *newNode = new IntSLLNode<TValue>(value, head, tail);
        head->prev = newNode; // Update the current head's prev pointer to the new node
        tail->next = newNode; // Update the tail's next pointer to the new node
        head = newNode;       // Update head to the new node
    }

    void insertTail(TValue value)
    {
        if (isEmpty())
        {
            head = tail = new IntSLLNode<TValue>(value, 0, 0);
            head->next = head;
            head->prev = head;
            return;
        }

        IntSLLNode<TValue> *newNode = new IntSLLNode<TValue>(value, head, tail);
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }

    void deleteFromHead()
    {
        // If the list is empty, we cannot delete anything
        if (isEmpty())
            return;

        // If the list has only one node, we need to delete it and set head and tail to null
        if (head == tail) // un solo nodo
        {
            delete head;
            head = tail = 0;
            return;
        }

        // If the list has more than one node, we need to delete the head and update the head pointer and the tail's next pointer
        IntSLLNode<TValue> *temp = head;
        head = head->next; // Update head to the next node
        head->prev = tail; // Update the new head's prev pointer to the tail
        tail->next = head; // Update the tail's next pointer to the new head
        delete temp;
    }

    void deleteFromTail()
    {
        // If the list is empty, we cannot delete anything
        if (isEmpty())
            return;

        // If the list has only one node, we need to delete it and set head and tail to null
        if (head == tail)
        {
            delete tail;
            head = tail = 0;
            return;
        }

        // If the list has more than one node, we need to delete the tail and update the tail pointer and the head's prev pointer
        IntSLLNode<TValue> *temp = tail;
        tail = tail->prev; // Update tail to the previous node
        tail->next = head; // Update the new tail's next pointer to the head
        head->prev = tail; // Update the head's prev pointer to the new tail
        delete temp;
    }

    bool isInList(TValue el)
    {
        IntSLLNode<TValue> *temp;

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

    void iterateReverse()
    {
        if (isEmpty())
            return;
        IntSLLNode<TValue> *current = tail;
        do
        {
            std::cout << current->getValue() << std::endl;
            current = current->getPrev();
        } while (current != tail);
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
    list.iterateReverse();
}
