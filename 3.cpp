#include <stdio.h>
#include <iostream>
#include <string>
 
struct ListNode {
 ListNode* prev = nullptr; // указатель на предыдущий элемент списка, либо `nullptr` в случае начала списка
 ListNode* next = nullptr;
 ListNode* rand = nullptr; // указатель на произвольный элемент данного списка, либо `nullptr`
 std::string data; // произвольные пользовательские данные
};
 
 
class List final{
public:
 void Serialize(FILE* file) // сохранение списка в файл, файл открыт с помощью `fopen(path, "wb")`
 {
     ListNode *p = head;
     fwrite(&count, sizeof(int), 1, file);
     while(p != nullptr)
     { 
	 size_t n = p->data.size();
	 fwrite(&n, sizeof(n), 1, file);
         fwrite(p->data.c_str(), 1, n, file);
	 p = p->next;
     }
 }
 void Deserialize(FILE* file)// восстановление списка из файла, файл открыт с помощью `fopen(path, "rb")`
 {
     size_t sz{};
     fread(&sz, sizeof(int), 1, file);
     for(int i = 0; i < sz; ++i)
     {
	 size_t n{};
	 fread(&n, sizeof(n), 1, file);
	 char ar[n + 1]{};
	 fread(ar, 1, n, file);
         push_back(ar);
     }
 }
 void push_back(const std::string& data)
 {
     ++count;
     ListNode *newNode = new ListNode();
     newNode->data = std::move(data);
     if(head == nullptr)
     {
         head = newNode;
	 tail = newNode;
     }
     else 
     { 
	 ListNode *t = tail;
	 tail->next = newNode;
         tail = newNode;
	 tail->prev = t;
     }
 }
 void push_front(const std::string& data)
 {
     ++count;
     ListNode *newNode = new ListNode();
     newNode->data = std::move(data);
     if(head == nullptr)
     {
         head = newNode;
         tail = newNode;	 
     }
     else
     {
         ListNode *t = head;
	 newNode->next = head;
	 t->prev = newNode;
	 head = newNode;
     }
 }
 
 void pop_back()
 {
     --count;
     ListNode *last = tail;
     tail = tail->prev;
     delete last;
 }
 void pop_front()
 {
     --count;
     ListNode *first = head;
     head = head->next;
     delete first;
 }
 
 void printf()
 {
    ListNode *p = head;
    while(p != nullptr)
    {
        std::cout << p->data << std::endl;
	p = p->next;
    }
 }
 void printb()
 {
     ListNode *p = tail;
     while( p != nullptr)
     {
        std::cout << p->data << std::endl;
	p = p->prev;
     }
 
 }
 ~List()
 {
     while(head != nullptr)
     {
         ListNode *t = head;
	 head = head->next;
	 delete t;
     }
 }
private:
 ListNode* head = nullptr;
 ListNode* tail = nullptr;
 int count = 0;
};
 
int main()
{
    List list;
    list.push_back("Ivan");
    list.push_back("Igor");
    list.push_back("C++");
    list.pop_back();
    list.push_front("C#");
    list.push_front("Salem");
    list.push_back("Saber games");
    list.pop_front();
    list.printf();
    FILE *pfile;
    pfile= fopen("log.bin", "wb");
    list.Serialize(pfile);
    fclose(pfile);
    List list1;
    pfile = fopen("log.bin", "rb");
    list1.Deserialize(pfile);
    list1.printb();
    fclose(pfile);
 
}
