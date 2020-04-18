#include <bits/stdc++.h>
#include "mylist.h" 
using namespace std;

// Overload new and delete operator globally
void* operator new(size_t size)
{
    // std::cout << "> Alloc " << size << " bytes" << '\n';
    return malloc(size);
}

void operator delete(void *ptr, size_t size)
{
    // std::cout << "> Deleted " << ptr << " (" << size << " bytes)" << '\n';
    free(ptr);
}

template<typename T>
void printListPtr(mylist<T> &list, const string &name)
{
    cout << "mem of " << name << ": ";
    mylist_iterator h = list.begin(), e = list.end();
    while(h != e)
    {
        if(h != list.begin()) printf(" -> ");
        printf("%#p", h);
        h++;
    }
    printf(" -> nullptr (size=%d)\n", list.size());
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
    return o << f.a << ' ' << f.b << ' ' << std::string(f.c);
}

int main()
{
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
    //
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
    //
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
    //
    puts("\nTest for push_back() and pop_front()");
    {
        mylist<std::string> li;
        li.push_back("fuck");
        printListPtr(li, "li");
        li.push_back("you");
        printListPtr(li, "li");
        li.push_back("too");
        printListPtr(li, "li");

        li.pop_front();

        for(mylist<string>::iterator it = li.begin();
            it != li.end();
            it++)
        {
            cout << *it << '\n';
        }
    }
    //
    puts("\nTest for custom object");
    {
        mylist<foo> fooList;
        fooList.push_back(foo());
        fooList.push_back(foo(123, 1.23, "roy4801"));
        printListPtr(fooList, "fooList");

        for(auto it = fooList.begin(); it != fooList.end(); it++)
            printf("%d %f %s\n", it->a, it->b, it->c);

        fooList.pop_front();

        cout << "Front= " << fooList.front() << '\n';
        cout << "Back=  " << fooList.back() << '\n';
    }
}