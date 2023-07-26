#include <iostream>

void RemoveDups(char* str)
{
    char *p = str;
    while(*str != '\0')
    {
        if(*str != *(str + 1))
              *p++ = *str;
        ++str;
    }
    *p = '\0';
}

int main()
{
    char data[] = "AAA BBB  CCCABABBB  AAA";
    RemoveDups(data);
    std::cout << data << std::endl;
}
