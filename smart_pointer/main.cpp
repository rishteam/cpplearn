#include <bits/stdc++.h>
#include <fmt/printf.h>

#include <memory>

struct Foo
{
    std::string name;
    int year{}, month{}, day{};
    int id{rand()};

    Foo(const int id_=-1)
    {
        if(id_ != -1)
            id = id_;
        msg();
    }
    Foo(const std::string &name_) : name(name_)
    {
        msg();
    }

    void msg()
    {
        fmt::printf("ctor of Foo %d\n", id);
    }

    ~Foo()
    {
        fmt::printf("dtor of Foo %d\n", id);
    }

    void OMG()
    {
        throw 1;
    }
};

int main()
{
    srand(time(0));

    // The problem of raw pointers
    {
        try
        {
            Foo *f = new Foo();
            f->OMG();
            delete f; // this will never be executed if `f->OMG()` throws exception
        }
        catch(int i)
        {
            fmt::print("okay you just lost f\n");
        }
    }

    puts("");

    // The problem of raw pointers II
    {
        // 模擬 Library 會提供 Foo*
        std::vector<Foo*> fooList;
        auto GiveMeANewFoo = [&]() -> Foo* {
            Foo *n = new Foo();
            fooList.push_back(n);
            return n;
        };
        auto SomethingHappened = [&]() {
            for(auto &i : fooList)
                i->name = "123";
        };
        //
        Foo *f = GiveMeANewFoo();

        delete f; // 我到底能不能 delete?

        SomethingHappened(); // User after free
        std::cout << f->name << '\n';
    }

    puts("");

    {
        std::unique_ptr<Foo> a(new Foo(1));        
        std::unique_ptr<Foo> b = std::make_unique<Foo>(2);// prefer
    }

    puts("");

    {
        std::unique_ptr<Foo> c;
        {
            std::unique_ptr<Foo> b = std::make_unique<Foo>(1); //
            c = std::move(b);
        }
    }
}
