#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>

template <class T>
class Linked_list
{
    struct Node
    {
        T data;
        Node *next;
        Node(T val) : data(val), next(nullptr) {}
    };
    Node *head;

public:
    Linked_list() : head(nullptr) {}
    Linked_list(const Linked_list<T> &ll) = delete;
    Linked_list &operator=(Linked_list const &) = delete;
    ~Linked_list();
    void insert(T data);
    void display(std::ostream &out = std::cout) const;
    bool find(T data);
    void remove(T data);
    template <class U>
    friend std::ostream &operator<<(std::ostream &os, const Linked_list<U> &ll);

private:
    // внутренняя функция поиска элемента для удаления
    struct Node *search(T n)
    {
        Node *node = head;
        while (node != nullptr)
        {
            if (node->data == n)
                return node;
            node = node->next;
        }

        std::cerr << "No such element in the list \n";
        return nullptr;
    }
};

// перегрузка оператора потока вывода для удобства отображения в консоли
template <class U>
std::ostream &operator<<(std::ostream &os, const Linked_list<U> &ll)
{
    ll.display(os);
    return os;
}

template <class T>
void Linked_list<T>::insert(T data)
{
    Node *t = new Node(data);
    Node *tmp = head;
    if (tmp == nullptr)
    {
        head = t;
    }
    else
    {
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = t;
    }
}

// чисто для удобства и наглядности добавил, странно что этого в тз не было!
template <class T>
inline void Linked_list<T>::display(std::ostream &out) const
{
    Node *node = head;
    while (node != nullptr)
    {
        out << node->data << " ";
        node = node->next;
    }
    out << '\n';
}

template <class T>
bool Linked_list<T>::find(T data)
{
    Node *current = head;

    while (current) {
        if (current->data == data) return true;
        current = current->next;
    }

    return false;
}

template <class T>
void Linked_list<T>::remove(T data)
{
    Node *node = search(data);
    Node *tmp = head;

    if (tmp == node)
    {
        head = tmp->next;
    }
    else if (node != nullptr)
    {
        while (node != nullptr)
        {
            if (tmp->next == node)
            {
                tmp->next = node->next;
                return;
            }
            tmp = tmp->next;
        }
        delete tmp;
    }
}

template <class T>
Linked_list<T>::~Linked_list()
{
    Node *tmp = nullptr;
    while (head)
    {
        tmp = head;
        head = head->next;
        delete tmp;
    }
    head = nullptr;
}

#endif


