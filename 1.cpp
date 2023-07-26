#include <iostream>


int main()
{
    int x;
    std::cin >> x;
    for(int i = 0; i < 32; ++i)
    {
        if(x & (1 << i)) std::cout << 1;
	else std::cout << 0;
    }
    std::cout << std::endl;
}
