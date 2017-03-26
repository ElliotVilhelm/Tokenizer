#ifndef _STACK_H
#define _STACK_H

#include "doublylinkedlist.h"
template<class T>
class _Stack
{
public:
    _Stack();
    _Stack(T item);

    // BIG THREE
    _Stack(_Stack<T>& CopyThis);
    ~_Stack();
    _Stack<T> &operator =(const _Stack<T>& CopyMe);


    ostream& operator<< (T item);
    void Push(T item);
    T Pop();
    bool IsEmpty();
    T Top();

    void PrintStack();

private:
    Node<T>* _head;



};

template<class T>
_Stack<T>::_Stack()
{
    _head = NULL;

}

template<class T>
_Stack<T>::_Stack(T item)
{
    _head = NULL;
    insertHead(item, _head);

}

template<class T>
_Stack<T>::_Stack(_Stack<T> &CopyThis)
{
    _head = CopyList(CopyThis._head);
}

template<class T>
_Stack<T>::~_Stack()
{

    RemoveAll(_head);
    cout<<endl<<"~_Stack() fired\n\n";
}

template<class T>


_Stack<T> &_Stack<T>::operator =(const _Stack<T> &CopyMe)
{
    if(&CopyMe == this)
        return *this;

    RemoveAll(_head);
    _head = CopyList(CopyMe._head);


}

template<class T>
ostream &_Stack<T>::operator<<(T item)
{
    insertTail(item);
}

template<class T>
void _Stack<T>::Push(T item)
{
    insertHead(item, _head);
}

template<class T>
T _Stack<T>::Pop()
{
    return RemoveHead(_head);
}

template<class T>
bool _Stack<T>::IsEmpty()
{
    if(_head == NULL)
        return true;
    return false;
}

template<class T>
T _Stack<T>::Top()
{
    return _head->Item;
}

template<class T>
void _Stack<T>::PrintStack()
{
    ::Print(_head);
}

#endif // _STACK_H

