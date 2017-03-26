#ifndef LIST_H
#define LIST_H

#include "doublylinkedlist.h"


template<class T>
class _List
{
public:

    class _Iterator
    {
    public:
        friend class _List;
        _Iterator()
        {
            _position = NULL;
        }
        _Iterator(Node<T>* _pos)
        {
            _position = _pos;
        }

        _Iterator Next()
        {
            _position = _position->Next;
        }

        _Iterator Prev()
        {
            _position = _position->Prev;
        }

        _Iterator Current()
        {
            return _List::_Iterator (_position);
        }

        T& operator* ()
        {
            if(!isNull())
                return _position->Item;
        }

        //Prefix increment operator
        _Iterator& operator++()
        {
            _position = _position->Next;
            return *this;
        }

        //Postfix increment
        _Iterator operator ++(int)
        {
            _Iterator temp = *this;
            ++*this;
            return temp;

        }

        _Iterator& operator--()
        {
            _position = _position->Prev;
            return *this;
        }

        //Postfix increment
        _Iterator operator --(int)
        {
            _Iterator temp = *this;
            --*this;
            return temp;

        }




        bool isNull()
        {
            if(_position == NULL)
                return true;
            return false;
        }



    private:
        Node<T>* _position;
    };


    _List();
    _List(T X);



    _List(_List &CopyThis);
    ~_List();
    _List<T> &operator =(const _List& CopyMe);
    ostream& operator<< (T item);


    _Iterator _insertHead(T insertThis);
    _Iterator _insertAfter(_Iterator afterMe, T insertThis);
    _Iterator _insertSorted(T insertThis);
    _Iterator _insertTail(T insertThis);



    _Iterator _Find(T findMe);
    _Iterator _insertBefore(T insertThis);

    _Iterator _Top();
    _Iterator _Bottom();


    bool Empty();

    void _Print();
    void DeleteAll();


private:
    Node<T>* _head;




};

template<class T>
_List<T>::_List()
{
//     _head = new Node<T>;
    _head = NULL;

}

template<class T>
_List<T>::_List(T item)
{
    _head = new Node<T>(item);
}


//BIG THREE//

template<class T>
_List<T>::_List(_List &CopyThis)
{
//    RemoveAll(_head);
    _head = new Node<T>;
    _head = CopyList(CopyThis._head);
//    cout<<"\nDEBUG: _List Copy Constructor Called\n";
}

template<class T>
_List<T> &_List<T>::operator =(const _List &CopyMe)
{

    if(&CopyMe == this)
        return *this;

    RemoveAll(_head);
    _head = new Node<T>;
    _head = CopyList(CopyMe._head);
    return *this;
}
template<class T>
_List<T>::~_List()
{
    RemoveAll(_head);
//    cout<<"\n~_List Deconstructor fired\n";
}

template<class T>
typename _List<T>::_Iterator _List<T>::_Find(T findMe)
{
    return _Iterator(Find(findMe, _head));
}

template<class T>
typename _List<T>::_Iterator _List<T>::_insertHead(T insertThis)
{

    return _Iterator(insertHead(insertThis, _head));
}

template<class T>
typename _List<T>::_Iterator _List<T>::_insertAfter(_Iterator afterMe, T insertThis)
{
    if(_head == NULL)
        return _Iterator(insertHead(insertThis, _head));
    return _Iterator(insertAfter(insertThis, afterMe._position));

}

template<class T>
typename _List<T>::_Iterator _List<T>::_insertSorted(T insertThis)
{

    return _Iterator(insertSorted(insertThis, _head));
}

template<class T>
typename _List<T>::_Iterator _List<T>::_insertTail(T insertThis)
{
    insertTail(insertThis, _head);
}



template<class T>
typename _List<T>::_Iterator _List<T>::_insertBefore(T insertThis)
{
    return _Iterator(insertBefore(insertThis, _head));
}

template<class T>
void _List<T>::DeleteAll()
{
    ::RemoveAll(_head);
}

template<class T>
void _List<T>::_Print()
{
    ::Print(_head);

}

template<class T>
typename _List<T>::_Iterator _List<T>::_Top()
{
    return _Iterator(_head);
}

template<class T>
typename _List<T>::_Iterator _List<T>::_Bottom()
{
    return _Iterator(_head->Prev);
}

template<class T>
bool _List<T>::Empty()
{
    if(_head == NULL)
        return true;
    return false;
}

template<class T>
ostream &_List<T>::operator<<(T item)
{
    insertTail(item, _head);
}



#endif // LIST_H
