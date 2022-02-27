
#include <iostream>
#include<queue>
#define tab "\t"
using namespace std;


class Queue
{
    class Element
    {
        int Data;
        Element* pNext;    
     public:

         Element(int Data, Element*pNext=nullptr)
         {
             this->Data = Data;
             this->pNext = pNext;
             cout << " NConsructor:\t" << this << endl;
         }
         ~Element()
         {
             cout << "QDestructor:\t" << this << endl;
         }

         friend class Queue;
    }*Head,*Tail;

public:
    size_t size;

    Queue()
    {
        Head = Tail = nullptr;
        size = 0;

        cout << " QConsructor:\t" << this << endl;
    }
    ~Queue()
    {
      
        cout << "QDestructor:\t" << this << endl;
    }
 
    void enqueue(int Data)
    {
        Element* New = new Element(Data);

        if (Tail == nullptr)
        {
            Head = Tail = New;
            size++;
            return;
        }

        Tail->pNext = New;
        Tail = New;
        size++;
    }

    void dequeue()
    {
        if (Head == nullptr) return;

        Head = Head->pNext;
        size--;
    }


    void print()const
    {
        cout << "Количество элементов списка: " << size << endl;
        for (Element* Temp = Head; Temp; Temp = Temp->pNext)
            cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
    }
};


int main()
{
    setlocale(LC_ALL,"");

    Queue que;

    que.enqueue(111);
    cout << "Размер очереди\t" << que.size << '\n';
    que.enqueue(222);
    cout << "Размер очереди\t" << que.size << '\n';
    que.enqueue(333);
    cout << "Размер очереди\t" << que.size << '\n';

    que.print();
    que.dequeue();
    cout << "Размер очереди\t" << que.size << '\n';
    que.print();
}

