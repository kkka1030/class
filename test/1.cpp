#include <iostream>

template <typename T>
class SingleLinkedList
{
private:
    class Node
    {
        private:
            T data;
            Node* next = nullptr;
            Node(T _val){data = _val;}

            friend class SingleLinkedList<T>;
    };
    Node* head = nullptr;
    int size = 0;
    Node* currentPos = nullptr;
public:
    SingleLinkedList(){}; 
    SingleLinkedList(std::initializer_list<T> _l);
    void printList() const;

};

template <typename T>
SingleLinkedList<T>::SingleLinkedList(std::initializer_list<T> _l)
{
    for (auto i = _l.begin();i != _l.end(); ++i )
    {
        Node* newNode = new Node(*i);
        if (head == nullptr)
        {
            head = newNode;
            currentPos = head;
        }
        else
        {
            currentPo->next = newNode;
            currentPos = newNode;
        }
        ++size;
    }   
}

template <typename T>
void SingleLinkedList<T>::printList()
{
    Node* p =head;
    while (p!=nullptr)
    {
        std::cout<< p->data << "\t";
        p=p->next;
        std::cout<<std::endl;
    }
}