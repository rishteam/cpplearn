#pragma once

#include <iterator>
#include <cstddef>

#include <iostream>

// forward declaration
template <typename T> class mylist;
template <typename T> class mylist_iterator;

template<typename T>
class mylist_node
{
    friend class mylist<T>;
    friend class mylist_iterator<T>;
private:
    // ctor and dtor (only can call by mylist*<T>)
    mylist_node(const T& t, mylist_node<T> *next)
    :   elem(t),
        next(next)
    {
    }
    ~mylist_node()
    {
        delete next;
    }
    // data
    T elem;   // actual stored data
    mylist_node<T> *next; // pointer to next elem
};

template<typename T>
class mylist
{
public:
    typedef mylist_iterator<T> iterator;
    typedef size_t size_type;

public:
    mylist() = default;
    ~mylist()
    {
        delete head;
    }

    bool empty() const { return head == nullptr; }
    size_type size() const { return m_size; }
    void push_back(const T& elem);
    void pop_front();

    iterator begin()
    {
        return iterator(head);
    }
    iterator end()
    {
        return iterator(nullptr);
    }

public:
    // head and tail pointers of a linked-list
    mylist_node<T> *head = nullptr, *tail = nullptr;
    // size
    size_type m_size = 0;
};

template <typename T>
void mylist<T>::push_back(const T &elem)
{
    mylist_node<T> *newNode = new mylist_node<T>(elem, nullptr);
    // if head is nullptr (first push_back)
    if (!head)
        head = newNode;
    else
        tail->next = newNode; // Add the new node to original tail (before add a new node)
    // Set tail as the new node
    tail = newNode;
    // Update the size counter
    m_size++;
}

template <typename T>
void mylist<T>::pop_front()
{
    if(!head) return;
    // The order is important
    mylist_node<T> *del = head;
    head = head->next;   // maintain head pointer
    del->next = nullptr; // delete del only
    //
    if(!head)
        tail = nullptr;
    //
    delete del;
    m_size--;
}

//========================================================================
// mylist_iterator

template<typename T>
class mylist_iterator
{
    friend class mylist<T>;

public:
    typedef mylist_iterator<T> self_type;
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;
    typedef std::forward_iterator_tag iterator_category;
    typedef size_t difference_type;

public:
    reference operator*()
    {
        return ptr->elem;
    }
    const self_type& operator++() // prefix
    {
        assert(ptr != nullptr);
        ptr = ptr->next;
        return *this;
    }
    const self_type operator++(int) // suffix
    {
        assert(ptr != nullptr);
        self_type self = *this;
        ptr = ptr->next;
        return self;
    }
    bool operator!=(const self_type& other) const
    {
        return ptr != other.ptr;
    }
    bool operator==(const self_type& other) const
    {
        return !(ptr != other.ptr);
    }

private:
    mylist_node<T> *ptr = nullptr;
    // ctor
    mylist_iterator(mylist_node<T> *ptr_) :
        ptr(ptr_)
    {
    }
};