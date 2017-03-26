#ifndef _MAP_H
#define _MAP_H

#include "_Pair.h"
#include "_List.h"
#include "Functors.h"
#include "_Stack.h"

template<class K, class V, typename DUP_POLICY = DUP_ADDEM<K, V> >
class _Map
{
public:

    typedef _Pair<K, V> PAIR;
    class _Iterator
    {
    public:
        friend class _Map;
        _Iterator()
        {

        }

        _Iterator(typename _List<PAIR>::_Iterator itr)
        {
            _itr = itr;
        }


        _Iterator Next()
        {

            _itr = _itr.Next();
        }

        _Iterator Prev()
        {
            _itr = _itr.Prev();
        }

        PAIR operator* ()
        {
            if(!isNull())
                return *_itr;
            else
            {
                cout<<endl<<"NULL DE-REFERNCE"<<endl;
                return PAIR();
            }
        }

        //Prefix increment operator
        _Iterator& operator++()
        {
            ++_itr;
        }

        //Postfix decrement
        _Iterator operator ++(int)
        {
            _itr++;
        }

        _Iterator operator--()
        {

            --_itr;
        }

        _Iterator operator--(int)
        {
            _itr--;
        }

        V operator[](K key)
        {
           // _Iterator itr = Find(key);
           // PAIR pair = *itr;
           // return pair._Value;
        }

        bool isNull()
        {
            return _itr.isNull();
        }




    private:
        typename _List<PAIR >::_Iterator _itr;
    };

    _Map();


    //BIG THREE
    //    _Map(_Map &CopyThis);
    //        _Map &operator =(const _Map& CopyMe);
    //    ~_Map();


    _Map(K Key, V Value);
    _Iterator Insert(K key, V value);
    _Iterator Insert(PAIR insertThis);

    _Iterator InsertTail(PAIR insertThis);
    _Iterator InsertTail(K key, V value);


    void SortedByValue();




    float LargestValue();
    _Iterator Find(K findThis);


    _Iterator Top();
    _Iterator Bottom();
    void PrintMap();

    _Iterator Begin();


private:
    _List<PAIR> _myList;

};


template<class K, class V, typename DUP_POLICY>
_Map<K, V, DUP_POLICY>::_Map()
{

}


template<class K, class V, typename DUP_POLICY>
_Map<K, V, DUP_POLICY>::_Map(K Key, V Value)
{
    PAIR Pair(Key, Value);
    _myList._insertHead(Pair);
}


template<class K, class V, typename DUP_POLICY>
void _Map<K, V, DUP_POLICY>::PrintMap()
{
    _myList._Print();
}

template<class K, class V, typename DUP_POLICY>
typename _Map<K, V, DUP_POLICY>::_Iterator _Map<K, V, DUP_POLICY>::Begin()
{
    return _myList._Top();
}

template<class K, class V, typename DUP_POLICY>
typename _Map<K, V, DUP_POLICY>::_Iterator _Map<K, V, DUP_POLICY>::Insert(PAIR insertThis)
{
    typename _List<PAIR>::_Iterator ListItr = _myList._Find(insertThis);
    if(ListItr.isNull())
        return _myList._insertSorted(insertThis);

    else
    {

        DUP_POLICY dup;
        dup(*ListItr, insertThis);
    }
}

template<class K, class V, typename DUP_POLICY>
typename _Map<K, V, DUP_POLICY>::_Iterator _Map<K, V, DUP_POLICY>::InsertTail(PAIR insertThis)
{

    typename _List<PAIR>::_Iterator ListItr = _myList._Find(insertThis);

    if(ListItr.isNull())
    {
        return _myList._insertTail(insertThis);

    }

    else
    {

        DUP_POLICY dup;
        dup(*ListItr, insertThis);
    }

}

template<class K, class V, typename DUP_POLICY>
typename _Map<K, V, DUP_POLICY>::_Iterator _Map<K, V, DUP_POLICY>::InsertTail(K key, V value)
{
    _Pair<K, V> insertThis(key, value);

    typename _List<PAIR>::_Iterator ListItr;
    ListItr = _myList._Find(insertThis);

        if(ListItr.isNull())
        {
            return _myList._insertTail(PAIR(key, value));

        }

        else
        {
            DUP_POLICY dup;
            dup(*ListItr, insertThis);
        }

}
template<class K, class V, typename DUP_POLICY>
void _Map<K, V, DUP_POLICY>::SortedByValue()
{
    _Map<K, V, DUP_POLICY> newMap;

    typename _List<PAIR>::_Iterator itr = _myList._Top();
    typename _List<PAIR>::_Iterator Walker = _myList._Top();
    PAIR PairHead = *itr; // head
    Walker++;
    PAIR walkerPair = *Walker;
    int i;


        if(walkerPair == PairHead)
        {
            newMap.Insert(PairHead);
            _myList.DeleteAll();
            *this = newMap;
            return;
        }

    i = LargestValue();

    Walker = _myList._Top();
    Walker++;
    walkerPair = *Walker;

    while(i != 0)
    {
        Walker = _myList._Top();
        Walker++;
        walkerPair = *Walker;
        bool head = false;
        while(PairHead._Key != walkerPair._Key )
        {

            if(PairHead._Value == i && head == false){

                newMap.InsertTail(PairHead);
                head = true;
                //                                break;
            }
            if(walkerPair._Value ==i)
            {
                newMap.InsertTail(walkerPair);

            }

            Walker++;
            walkerPair = *Walker;
        }
        i--;
    }

    ////////METHOD 1////////

    _myList.DeleteAll();
    *this = newMap;

    //////////METHOD 2//////
    //            return newMap;


}

template<class K, class V, typename DUP_POLICY>

float _Map<K, V, DUP_POLICY>::LargestValue()
{
    typename _List<PAIR>::_Iterator itr = _myList._Top();
    typename _List<PAIR>::_Iterator Walker = _myList._Top();
    PAIR PairHead = *itr; // head
    Walker++;
    PAIR walkerPair = *Walker;
    float i = PairHead._Value;

    while(PairHead._Key != walkerPair._Key )
    {

        if(walkerPair._Value > i)
        {
            i = walkerPair._Value;
        }
        Walker++;
        walkerPair = *Walker;
    }
    return i;
}


template<class K, class V, typename DUP_POLICY>
typename _Map<K, V, DUP_POLICY>::_Iterator _Map<K, V, DUP_POLICY>::Insert(K key, V value)
{
    _Iterator itr = Find(key);
    PAIR myPair(key, value);


    if(itr.isNull())
        return _myList._insertSorted(myPair);
    else
    {

        typename _List<PAIR>::_Iterator ListItr = _myList._Find(myPair);
        DUP_POLICY dup;
        dup(*ListItr, myPair);
    }
}

template<class K, class V, typename DUP_POLICY>
typename _Map<K, V, DUP_POLICY>::_Iterator _Map<K, V, DUP_POLICY>::Find(K findThis)
{
    if(_myList.Empty())
        return _Iterator();
    PAIR myPair(findThis, 1);
    return _Iterator(_myList._Find(myPair));

}

template<class K, class V, typename DUP_POLICY>
typename _Map<K, V, DUP_POLICY>::_Iterator _Map<K, V, DUP_POLICY>::Bottom()
{
    return _Iterator(_myList._Bottom());
}
#endif 
