#include <bits/stdc++.h>
#include "mylist.h" 
using namespace std;

// Overload new and delete operator globally
void* operator new(size_t size)
{
    std::cout << "> Alloc " << size << " bytes" << '\n';
    return malloc(size);
}

void operator delete(void *ptr, size_t size)
{
    std::cout << "> Deleted " << ptr << " (" << size << " bytes)" << '\n';
    free(ptr);
}

template<typename T>
void printList(mylist<T> &list)
{
    mylist_iterator h = list.begin(), e = list.end();
    while(h != e)
    {
        if(h != list.begin()) printf(" -> ");
        printf("%#p", h);
        h++;
    }
    printf(" -> nullptr\nsize=%d\n", list.size());
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
    {
        mylist<std::string> li;
        li.push_back("fuck");
        printList<string>(li);
        li.push_back("you");
        printList<string>(li);
        li.push_back("too");
        printList<string>(li);

        li.pop_front();

        for(mylist<string>::iterator it = li.begin();
            it != li.end();
            it++)
        {
            cout << *it << '\n';
        }
    }

    for(int i = 0; i < 30; i++, putchar('-'));
    puts("");

    {
        mylist<foo> fooList;
        fooList.push_back(foo());
        fooList.push_back(foo(123, 1.23, "roy4801"));
        printList(fooList);

        for(auto it = fooList.begin(); it != fooList.end(); it++)
            printf("%d %f %s\n", it->a, it->b, it->c);

        fooList.pop_front();

        cout << "Front= " << fooList.front() << '\n';
        cout << "Back=  " << fooList.back() << '\n';
    }

    // auto b = li.begin();
    // auto e = li.end();

    // while(b != e)
    // {
    //     cout << *b << '\n';
    //     b++;
    // }
}