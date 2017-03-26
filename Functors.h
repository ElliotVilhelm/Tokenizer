#ifndef FUNCTORS_H
#define FUNCTORS_H

#include <iostream>
#include "_Pair.h"



template<typename K, typename V>
class DUP_ADDEM
{
public:

    typedef _Pair<K, V> PAIR;
    bool operator()(PAIR& left, PAIR& right)
    {
        left._Value += right._Value;
    }

};

template<typename K, typename V>
class DUP_NOTHING
{
public:
    typedef _Pair<K, V> PAIR;
    bool operator()(PAIR& left, PAIR& right)
    {

    }

};



#endif // FUNCTORS_H
