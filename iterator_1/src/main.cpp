#include <bits/stdc++.h>
#include "mylist.h" 
using namespace std;

void* operator new(size_t size)
{
    std::cout << "Alloc " << size << " bytes" << '\n';
    return malloc(size);
}

void operator delete(void *ptr, size_t size)
{
    std::cout << "Deleted " << ptr << " (" << size << " bytes)" << '\n';
    free(ptr);
}

int main()
{
    mylist<std::string> li;
    li.push_back("fuck");
    li.push_back("you");
    li.push_back("too");

    // auto b = li.begin();
    // auto e = li.end();

    // while(b != e)
    // {
    //     cout << *b << '\n';
    //     b++;
    // }

    for(auto &i : li)
        cout << i << '\n';
}