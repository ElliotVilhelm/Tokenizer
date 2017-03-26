#ifndef _PAIR_H
#define _PAIR_H
#include <iostream>


using namespace std;

template<typename K, typename V>
class _Pair
{
public:
    typedef _Pair<K, V> PAIR;

    _Pair();
    _Pair(K key, V value);

    void PrintPair();

    template<typename KK, typename VV>
    friend ostream& operator <<(ostream& os, const _Pair<KK, VV>& pair);

    K _Key;
    V _Value;

};






template<typename KK, typename VV>
ostream &operator <<(ostream &os, const _Pair<KK, VV>& pair)
{
    os <<"Key:"<<pair._Key<<"  Value:"<<pair._Value;
    return os;
}


template<typename K, typename V>
_Pair<K, V>::_Pair()
{
    _Key = K();
    _Value = V();

}

template<typename K, typename V>
_Pair<K, V>::_Pair(K key, V value)
{

    _Key = key;
    _Value = value;
}

template<typename K, typename V>
void _Pair<K, V>::PrintPair(){
    cout<<"Key:"<<_Key<<"  Value: "<<_Value<<"-->";
}


template<typename K, typename V>
bool operator <(_Pair<K, V> left, _Pair<K, V> right)
{
//    if(left._Value < right._Value)
        if(left._Key < right._Key)
        return true;
    return false;
}


template<typename K, typename V>
bool operator >(_Pair<K, V> left, _Pair<K, V> right)
{
//    if(left._Value > right._Value)
    if(left._Key > right._Key)
        return true;
    return false;
}

template<typename K, typename V>
bool operator <=(_Pair<K, V> left, _Pair<K, V> right)
{
//    if(left._Value <= right._Value)
    if(left._Key <= right._Key)
        return true;
    return false;
}


template<typename K, typename V>
bool operator >=(_Pair<K, V> left, _Pair<K, V> right)
{
//    if(left._Value >= right._Value)
    if(left._Key >= right._Key)
        return true;
    return false;
}
template<typename K, typename V>
bool operator ==(_Pair<K, V> left, _Pair<K, V> right)
{
    if(left._Key == right._Key)
        return true;
    return false;
}

template<typename K, typename V>
bool operator !=(_Pair<K, V> left, _Pair<K, V> right)
{
    if(left._Key != right._Key)
        return true;
    return false;
}

#endif // _PAIR_H
