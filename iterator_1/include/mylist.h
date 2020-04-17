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
    typedef size_type size_t;

public:
    mylist()
    {
    }
    ~mylist()
    {
        delete head;
    }

    bool empty() const { return head == nullptr; }
    size_type size() const { return size; }
    void push_back(const T& elem)
    {
        std::cout << "Push back:" << elem << '\n';
        mylist_node<T> *newNode = new mylist_node<T>(elem, nullptr);
        // if head is nullptr (first push_back)
        if (!head)
            head = newNode;
        else
            tail->next = newNode; // Add the new node to previous tail
        // Set tail as the new node
        tail = newNode;
    }

    iterator begin()
    {
        return iterator(head);
    }
    iterator end()
    {
        return iterator(nullptr);
    }

private:
    // head and tail pointers of a linked-list
    mylist_node<T> *head = nullptr, *tail = nullptr;
    // size
    size_type size = 0;
};

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

private:
    mylist_node<T> *ptr;
    // ctor
    mylist_iterator(mylist_node<T> *ptr_) :
        ptr(ptr_)
    {
    }
};