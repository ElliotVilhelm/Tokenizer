#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H


#include <iostream>
using namespace std;

template<class T>
struct Node{


    Node(){
        Item = T();
        Next = this;
        Prev = this;
    }
    Node(T item)
    {
        Item = item;
        Next = this;
        Prev = this;
    }

    T Item;
    Node<T>* Next;
    Node<T>* Prev;
};

template<class T>
Node<T>* insertHead(T insertThis, Node<T>* &head)
{
    if(head == NULL)
    {
        head = new Node<T>(insertThis);
        return head;
    }

    Node<T>* newHead = new Node<T>;

    if(head->Next == head ) //if there is only one node
    {
        head->Prev = newHead;
        newHead->Next = head;
        newHead->Item = insertThis;

        newHead->Prev = head;
        head->Next = newHead;
        head = newHead;
        return head;
    }

    if(head->Next != head)
    {
        newHead->Next = head;
        newHead->Item = insertThis;
        head->Prev->Next = newHead;
        newHead->Prev = head->Prev;
        head->Prev = newHead;
        head = newHead;
        return head;
    }
}

template<class T>
Node<T>* Find(T FindThis, Node<T>* head)
{
    Node<T>* Walker = head;
    if(head == NULL)
        return NULL;
    if(head->Item == FindThis)
    {
        return head;
    }
    while(head->Prev != Walker)
    {
        if(Walker->Item == FindThis)
            return Walker;
        Walker = Walker->Next;
    }

    if(Walker->Item == FindThis)
        return Walker;

    else
        return NULL;

    cout<<endl<<endl;
}

template<class T>
Node<T>* insertAfter(T insertThis, Node<T>*& InsertHere)
{
    if(InsertHere == NULL)
    {
        cout<<"INSERTING HEAD"<<endl;
        return insertHead(insertThis, InsertHere);
    }

    Node<T>* NewNode = new Node<T>(insertThis);
    InsertHere->Next->Prev = NewNode;
    NewNode->Next = InsertHere->Next;
    NewNode->Prev = InsertHere;
    InsertHere->Next = NewNode;
    return NewNode;

}

template<class T>
Node<T>* insertBefore(T insertThis, Node<T>* InsertHere)
{
    if(InsertHere == NULL)
        throw 0;

    Node<T>* NewNode = new Node<T>(insertThis);
    NewNode->Next = InsertHere;
    InsertHere->Prev->Next = NewNode;
    NewNode->Prev = InsertHere->Prev;
    InsertHere->Prev = NewNode;
    return NewNode;
}

template<class T>
Node<T>* insertBeforeV2(T insertThis, Node<T>* InsertHere, Node<T>* &head)
{
    if(InsertHere == head)
        insertHead(insertThis, head);
    else{
        if(InsertHere == NULL)
            throw 0;

        Node<T>* NewNode = new Node<T>(insertThis);
        NewNode->Next = InsertHere;
        InsertHere->Prev->Next = NewNode;
        NewNode->Prev = InsertHere->Prev;
        InsertHere->Prev = NewNode;
        return NewNode;
    }

    // when inserting before the head our item ends up as the tail this is a error
    // I have not found an elegant solution to this as I have no way of comparing my
    // insertHere to check if it is my head ptr thus making me call insert head
    // ex: if(insertThis == head) insertHead(insertThis, head);

}

template<class T>
Node<T>* insertTail(T insertThis, Node<T>* &head)
{
    if(head == NULL)
        return insertHead(insertThis, head);
    else
    {

        return insertBefore(insertThis, head);
        //        head->Prev = insertAfter(insertThis, head->Prev);
        //        return head->Prev;
        //                return insertAfter(insertThis, head->Prev);
        //        return insertBeforeV2(insertThis, head, head);


    }
}

template<class T>
Node<T>* insertSorted(T insertThis, Node<T>* &head)
{
    Node<T>* Walker = head;
    if(head == NULL)
        return insertHead(insertThis, head);
    while(Walker != head->Prev)
    { if(insertThis > Walker->Item)
        {
            Walker = Walker->Next;
        }
        else
            if(insertThis <= Walker->Item)
            {
                return insertBeforeV2(insertThis, Walker, head);
            } }

    if(Walker == head->Prev)
    {
        if(insertThis <= Walker->Item)
            return insertBeforeV2(insertThis, Walker, head);
        else
            return insertTail(insertThis, head);
    }
}


template<class T>
Node<T>* CopyList(Node<T>* head)
{
    if(head == NULL)
        return NULL;
    Node<T>* NewList = new Node<T>(head->Item);
    Node<T>* Walker = head;

    Walker = Walker->Next;
    while(Walker != head)
    {
        insertTail(Walker->Item, NewList);
        Walker = Walker->Next;
    }
    return NewList;
}

template<class T>
Node<T>* SortList(Node<T>* head)
{
    Node<T>* SortedList = new Node<int>(head->Item);

    Node<T>* Walker = head;
    while(Walker != head->Prev)
    {
        cout<<endl<<Walker->Item;
        Walker = Walker->Next;
        insertSorted(Walker->Item, SortedList);
    }

    return SortedList;
}



template<class T>
T  RemoveTail(Node<T>* &head)
{
    Node<int>* Tail = head->Prev;
    if(head == NULL)
        return T();
    if(head == head->Prev)
    {
        T item = head->Item;
        RemoveHead(head);
        return item;
    }

    T item = Tail->Item;
    Tail->Prev->Next = head;
    Tail->Next->Prev = Tail->Prev;
    delete Tail;
    Tail = NULL;
    return item;
}

template<class T>
void  RemoveHead(Node<T>* &head)
{
    if(head == NULL)
        return;

    T item = head->Item;
    if(head == head->Prev)
    {

        delete head;
        head = NULL;

        //        return;


        //        head->Prev = NULL;
        //        head->Next = NULL;
        //        return item;
    }

    else
    {
        Node<T>* NewHead = head->Next;
        NewHead->Prev = head->Prev;
        head->Prev->Next = NewHead;
        delete head;
        head = NULL;
        head = NewHead;
        return;
    }
    //    return item;
}

template<class T>
void  RemoveAll(Node<T>* &head)
{
    while(head != NULL)
    {
        //        cout<<endl<<"removing..."<<endl;
        RemoveHead(head);
    }
//    delete head;
//    head = NULL;


}


template<class T>
Node<T>* Print(Node<T>* head)
{
    if(head != NULL)
    {
        //        cout<<endl<<"***Printing***"<<endl<<endl;
        Node<T>* Walker = head;
        int i = 0;
        while(head->Prev != Walker)
        {
            i++;
            if(i%2 == 0)
                cout<<"|"<<Walker->Item<<"|  ->"<<endl;
            else
                cout<<"|"<<Walker->Item<<"|  ->  ";

            Walker = Walker->Next;
        }
        cout<<"|"<<Walker->Item<<"|  ->  ";
        cout<<endl<<endl;
    }
    else
    {
        cout<<endl<<"nothing to print head is NULL"<<endl;
    }
    //    else
    //        throw 2;
}

template<class T>
int Length(Node<T>* head)
{

    if(head == NULL)
        return 0;
    Node<T>* Walker = head;
    int size = 0;
    while(Walker != head->Prev)
    {
        size++;
        Walker = Walker->Next;

    }
    size++;
    return size;
}



//template<class T>
#endif // DOUBLYLINKEDLIST_H
