#include <bits/stdc++.h>
using namespace std;
#include "point.h"

void testPointSet(int a, int b, int c)
{
    Point t;
    t.set(a, b, c);
    t.print();
}

void testPointConstruct(int a, int b, int c)
{
    Point t(a, b, c);
    t.print();
}

void testPointAdd(const Point &a, const Point &b)
{
    Point t = a + b;
    t.print();
}

void testPointAddEqual(const Point &a, const Point &b)
{
    Point t;
    t += a;
    t += b;
    t.print();
}

int main()
{
    int a, b, c, d, e, f;

    // Test set func
    freopen("test_set.in", "r", stdin);
    freopen("test_set.out", "w", stdout);
    while (~scanf("%d %d %d", &a, &b, &c))
    {
        testPointSet(a, b, c);
    }
    // Test constructor
    freopen("test_c.in", "r", stdin);
    freopen("test_c.out", "w", stdout);
    while(~scanf("%d %d %d", &a, &b, &c))
    {
        testPointConstruct(a, b, c);
    }
    // Test add
    freopen("test_add.in", "r", stdin);
    freopen("test_add.out", "w", stdout);
    while (~scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f))
    {
        testPointAdd(Point(a, b, c), Point(d, e, f));
    }
    // Test add equal
    freopen("test_ae.in", "r", stdin);
    freopen("test_ae.out", "w", stdout);
    while (~scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f))
    {
        testPointAddEqual((Point){a, b, c}, (Point){d, e, f});
    }
}