# cpp20-property
C#-like properties for C++20.

## Example usage

```cpp
#include <iostream>

#include <Propery.hpp>

class ProperyTest
{
public:
    zsl::Property<int> prop{m_something,
        {
            .get = [this](auto& var)
            {
                return var + 2;
            },
            .set = [this](auto& var, auto value)
            {
                var = value;
            }}};

private:
    int m_something = 0;
};

auto main(int argc, char** argv) -> int
{
    ProperyTest t;
    t.prop = 123;
    std::cout << t.prop;
    return 0;
}
```
