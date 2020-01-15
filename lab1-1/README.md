# Lab1-1

## Tasks

* Basic Function
  * 撰寫一個 class `Point` 用於儲存三維座標
  * 提供有參數的 constructor
    * `Point a(1, 2, 3);`
  * 提供 Copy constructor
  * 提供 `.set(int, int);` 用於給值
    * `a.set(1, 2, 3);`
  * 提供 `.print()` 用於輸出
    * `a.print()`
  * 提供 `operator+=` 以及 `operator+`

    ```cpp
    Point a(1, 2, 3), b(4, 5, 6);
    Point c = a + b;
    Point d;
    d += Point(1, 2, 3);
    ```

* 通過測試
* 分離 `Point` 之實作(implementation)與標頭(header)

* Example usage

```cpp
int main()
{
    Point p1;
    p1.set(1, 1, 1);
    Point p2(2, 2, 2);

    p1.print();
    p2.print();

    Point p3 = p1 + p2;
    p3.print();

    Point p4;
    p4 += p2;

    p4.print();

    return 0;
}
```

* 正確的程式應輸出
  * Format: "Point(%d, %d, %d)"

```
Point(1, 1, 1)
Point(2, 2, 2)
Point(3, 3, 3)
Point(2, 2, 2)
```

## Testing

* 執行測試

```
$ make test
```
