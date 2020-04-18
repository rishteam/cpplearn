#include <iostream>
#include "mylist.h" 
using namespace std;

#define NEW_VERBOSE 0
#define DELETE_VERBOSE 1

// Overload new and delete operator globally
void* operator new(size_t size)
{
#if NEW_VERBOSE
    std::cout << "> Alloc " << size << " bytes" << '\n';
#endif
    return malloc(size);
}

void operator delete(void *ptr) noexcept
{
#if DELETE_VERBOSE
    std::cout << "> Deleted " << ptr  << '\n';
#endif
    free(ptr);
}

void operator delete(void *ptr, size_t size) noexcept
{
#if DELETE_VERBOSE
    std::cout << "> Deleted " << ptr << " (" << size << " bytes)" << '\n';
#endif
    free(ptr);
}

template<typename T>
void printListPtr(mylist<T> &list, const string &name)
{
    cout << "mem of " << name;
    printf(" (size=%zu): ", list.size());
    int check = 0;
    mylist_iterator h = list.begin(), e = list.end();
    while(h != e)
    {
        if(h != list.begin()) printf(" -> ");
        printf("%p", h.getPtr());
        h++;
        check++;
    }
    if(check)
        printf(" -> ");
    printf("nullptr\n");
}

template<typename T>
void printList(mylist<T> &list)
{
    for(auto &i : list)
        cout << i << ' ';
    puts("");
}

// Custom object test
struct foo
{
    int a = 87;
    float b = 8.7;
    char c[30] = "fuck you";

    foo() = default;
    foo(int a_, float b_, const char c_[])
    {
        a = a_;
        b = b_;
        strncpy(c, c_, 30);
    }

    friend ostream &operator<<(ostream &o, const foo &f);
};

ostream& operator<<(ostream &o, const foo &f)
{
    return o << "( " << f.a << ' ' << f.b << ' ' << std::string(f.c) << " )";
}

int main()
{
#if 1
    puts("Test for initializer_list ctor");
    {
        // 這三種初始化方式都是可以接受的
        mylist<int> a = {1, 2, 3, 4};
        mylist<int> b({1, 2, 3, 4});
        mylist<int> c{1, 2, 3, 4};    // since c++11 uniform initialization
        
        for(auto &i : a)
            printf("%d ", i);
        puts("");
    }
#endif
    //
#if 1
    puts("\nTest for copy ctor");
    {
        mylist<int> tmp = {1, 2, 3};
        // 這兩種初始化方式都是可以接受的
        // 都會呼叫 mylist<T>::mylist(std::initializer_list<T> list)
        mylist<int> aa(tmp);
        mylist<int> bb = tmp;

        printList(aa);
        printListPtr(tmp, "tmp");
        printListPtr(aa, "aa");
    }
#endif
    //
#if 1
    puts("\nTest for assignment operator");
    {
        mylist<int> copy;
        {
            mylist<int> tmp = {1, 2, 3};
            copy = tmp;
        }

        for(auto &i : copy)
            printf("%d ", i);
        puts("");
    }
#endif
    //
#if 1
    puts("\nTest for push_back() and pop_back()");
    {
        mylist<std::string> li;
        li.push_back("fuck");
        printListPtr(li, "li");
        li.push_back("you");
        printListPtr(li, "li");
        li.push_back("too");
        printListPtr(li, "li");

        for(int i = 0; i < 3; i++)
        {
            li.pop_back();
            printListPtr(li, "li");
            printList(li);
        }
    }
#endif
    //
#if 1
    puts("\nTest for push_front() and pop_front()");
    {
        mylist<std::string> li;
        li.push_front("fuck");
        printListPtr(li, "li");
        li.push_front("you");
        printListPtr(li, "li");
        li.push_front("too");
        printListPtr(li, "li");
        printList(li);

        for (int i = 0; i < 3; i++)
        {
            li.pop_front();
            printListPtr(li, "li");
            printList(li);
        }
    }
#endif
    //
#if 1
    puts("\nTest for mixed");
    {
        mylist<std::string> li;
        li.push_front("fuck");
        printListPtr(li, "li");
        li.push_front("you");
        printListPtr(li, "li");
        li.push_front("too");
        printListPtr(li, "li");
        printList(li);
        
        li.pop_front();
        printListPtr(li, "li");
        printList(li);

        li.pop_back();
        printListPtr(li, "li");
        printList(li);

        li.push_front("AAA");
        printListPtr(li, "li");
        printList(li);

        li.push_back("BBB");
        printListPtr(li, "li");
        printList(li);
    }
#endif
    //
#if 1
    puts("\nTest for custom object");
    {
        mylist<foo> fooList;
        fooList.push_back(foo());
        fooList.push_back(foo(123, 1.23, "roy4801"));

        printList(fooList);
        printListPtr(fooList, "fooList");

        fooList.pop_front();

        printList(fooList);
        printListPtr(fooList, "fooList");

        fooList.push_back(foo(8787, 3.14, "fuck you"));
        
        printList(fooList);
        printListPtr(fooList, "fooList");

        cout << "Front= " << fooList.front() << '\n';
        cout << "Back=  " << fooList.back() << '\n';
    }
#endif
}