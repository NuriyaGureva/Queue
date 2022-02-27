
#include <iostream>
#include<queue>

using namespace std;


class Queue
{
    class Node
    {
        int Data;
        Node* pNext;    
        Node* pPrev;
     public:

         Node(int Data, Node*pNext=nullptr)
         {
             cout << " NConsructor:\t" << this << endl;
         }
         ~Node()
         {
             cout << "QDestructor:\t" << this << endl;
         }

         friend class Queue;
    }*Head,*Tail;
    size_t size;

public:
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

    Queue* create()
    {

        Queue* Temp = new Queue();

        Temp->Head= Temp->Tail = nullptr;

        return Temp;

    }

    void enQueue(Queue* Temp, int Data)
    {
        Node* New = new Node(Data);

        if (Temp->Tail==nullptr)
        {
            Temp->Head=Temp->Tail=New;
            return;
        }
        Temp->Tail->pNext = New;
        Temp->Tail = New;      
    }

    void deQueue(Queue* Temp)
    {
        if (Temp->Head == nullptr) return;


        Node* New = Temp->Head;
        delete (New);


        if (Temp->Head == nullptr)

            Temp->Tail = nullptr;
        
    }


};


int main()
{
    setlocale(LC_ALL,"");

    int n;
    queue <int> que({ 3,5,8,13,21 });
    que.push(10);
    cout <<"Первый элемент очереди\t"<< que.front()  <<'\n';
    cout <<"Последний элемент очереди\t"<<que.back() <<'\n';
    que.pop();
    cout <<"Размер очереди\t"<< que.size()<< '\n';
  

    if (que.empty())
        cout << "Очередь  пуста" << endl;
    else
        cout << "Очередь не пуста" << endl;

   
}

