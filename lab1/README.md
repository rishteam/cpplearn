# Lab1

## Tasks

* Basic Function
  * 撰寫一個 class `IntPair` 用於儲存兩個整數
  * 提供 `.set(int, int);` 用於給值
    * `a.set(1, 2);`
  * 提供有參數的 constructor
    * `IntPair a(8, 7);`
  * 提供 `.print()` 用於輸出
    * `a.print()`
* 通過測試
* 分離 `IntPair` 之實作(implementation)與標頭(header)

> 出於練習目的，禁止使用 `std::pair`

* Example usage

```cpp
int main()
{
    IntPair p1;
    p1.set(1, 1);

    IntPair p2(2, 2);

    p1.print();
    p2.print();

    return 0;
}
```

* 正確的程式應輸出
  * Format: "Pair(%d, %d)"

```
Pair(1, 1)
Pair(2, 2)
```
