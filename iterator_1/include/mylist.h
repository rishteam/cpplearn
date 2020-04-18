#pragma once

#include <iterator>
#include <cstddef>
#include <initializer_list>

#include <iostream>

// forward declaration
template <typename T> class mylist;
template <typename T> class mylist_iterator;

//========================================================================
// mylist_node: a wrapper for store the actuall data and pointer
//
template<typename T>
class mylist_node
{
    friend class mylist<T>;
    friend class mylist_iterator<T>;
    // only can call by friend
private:
    // ctor and dtor
    mylist_node(const T& t, mylist_node<T> *next=nullptr, mylist_node<T> *prev=nullptr)
    :   elem(t),
        next(next),
        prev(prev)
    {
    }
    ~mylist_node()
    {
        // printf("Destruct mylist_node: %p\n", this);
        delete next;
    }
    // data
    T elem;   // actual stored data
    mylist_node<T> *next=nullptr; // pointer to next elem
    mylist_node<T> *prev=nullptr; // pointer to previous elem
};

//========================================================================
// mylist: a single linked list that imitating std::forward_list
// NAIVE implementation shits in time complexity just for learning
//
template<typename T>
class mylist
{
public:
    typedef mylist<T> self_type;
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;
    typedef mylist_iterator<T> iterator;
    typedef size_t size_type;

    // ctor and dtor
    mylist() = default;
    ~mylist()
    {
        // printf("Destruct mylist\n");
        delete head;
    }
    // Copy ctor
    mylist(mylist &other);
    // Initializer list
    mylist(std::initializer_list<value_type> list);

    // Operators
    self_type& operator=(self_type& other)
    {
        clear();
        for(auto &i : other)
            push_back(i);
        return *this;
    }

    // Capacity
    bool empty() const { return head == nullptr; }
    size_type size() const { return m_size; }

    // Modifiers
    void push_back(const T& elem);
    void push_front(const T& elem);
    void pop_back();
    void pop_front();
    //
    void clear() { delete head; head = tail = nullptr; m_size = 0; }

    // Element access
    reference front() { return head->elem; }
    reference back() { return tail->elem; }

    // Iterators
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
    size_type m_size = 0;
};

// Copy ctor
template <typename T>
mylist<T>::mylist(mylist &other)
{
    // printf("mylist<T>::mylist(mylist &other)\n");
    for(auto &i : other)
        push_back(i);
}

// Initializer_list ctor
template<typename T>
mylist<T>::mylist(std::initializer_list<T> list)
{
    // printf("mylist<T>::mylist(std::initializer_list<T> list)\n");
    for(auto &i : list)
        push_back(i);
}

template <typename T>
void mylist<T>::push_back(const T& elem)
{
    puts("push_back");
    //
    mylist_node<T> *newNode = new mylist_node<T>(elem, nullptr, tail);
    // if it's first node
    if(!tail)
        head = tail = newNode;
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    // Update the size counter
    m_size++;
}

template<typename T>
void mylist<T>::push_front(const T& elem)
{
    puts("push_front");
    //
    mylist_node<T> *newNode = new mylist_node<T>(elem, head, nullptr);
    // if it's first node
    if(!head)
        head = tail = newNode;
    else
    {
        head->prev = newNode;
        head = newNode;
    }
    // Update the size counter
    m_size++;
}

template<typename T>
void mylist<T>::pop_back()
{
    puts("pop_back");
    //
    if(!tail) return;
    //
    mylist_node<T> *del = tail;
    // if tail have previous node
    if(tail->prev)
    {
        tail = tail->prev;
        tail->next = nullptr;
    }
    else // if only one node
        head = tail = nullptr;
    // delete the node
    del->next = del->prev = nullptr;
    delete del;
    m_size--;
}

template <typename T>
void mylist<T>::pop_front()
{
    puts("pop_front");
    //
    if(!head) return;
    //
    mylist_node<T> *del = head;
    // if head have next node
    if(head->next)
    {
        head = head->next;
        head->prev = nullptr;
    }
    else // if only one node
        head = tail = nullptr;
    // delete the node
    del->next = del->prev = nullptr;
    delete del;
    m_size--;
}

//========================================================================
// mylist_iterator: a iterator wrapper for mylist_node
//
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

    reference operator*()
    {
        return ptr->elem;
    }
    pointer operator->()
    {
        return &(ptr->elem);
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

    pointer getPtr() const
    {
        return &(ptr->elem);
    }

private:
    mylist_node<T> *ptr = nullptr;
    // ctor
    mylist_iterator(mylist_node<T> *ptr_) :
        ptr(ptr_)
    {
    }
};