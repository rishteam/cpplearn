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
    printf(" -> nullptr\n");
}

int main()
{
    mylist<std::string> li;
    li.push_back("fuck");
    printList<string>(li);
    li.push_back("you");
    printList<string>(li);
    li.push_back("too");
    printList<string>(li);

    printf("size=%d\n", li.size());
    
    for (auto &i : li)
        cout << i << '\n';
    
    li.pop_front();
    printList<string>(li);
    printf("size=%d\n", li.size());

    for (auto &i : li)
        cout << i << '\n';

    // auto b = li.begin();
    // auto e = li.end();

    // while(b != e)
    // {
    //     cout << *b << '\n';
    //     b++;
    // }
}