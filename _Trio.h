#ifndef TRIO_H
#define TRIO_H

#include <iostream>
#include <iomanip>

using namespace std;

template<typename K, typename V, typename R>
class _Trio
{
public:
    _Trio();

    _Trio(K key, V value, R ratio);
    void PrintTrio();


    template<typename KK, typename VV, typename RR>
    friend ostream& operator <<(ostream& os, const _Trio<KK, VV, RR>& trio);

    K _Key;
    V _Value;
    R _Ratio;
};


template<typename K, typename V, typename R>
_Trio<K, V, R>::_Trio()
{

}

template<typename KK, typename VV, typename RR>
ostream &operator <<(ostream &os, const _Trio<KK, VV, RR>& trio)
{
    os <<"Key:"<<trio._Key<<"  Value:"<<trio._Value;
    cout<<"  Ratio:"<<setprecision(5)<< showpoint << fixed<<trio._Ratio;
    return os;
}



template<typename K, typename V, typename R>
_Trio<K, V, R>::_Trio(K key, V value, R ratio)
{
    _Key = key;
    _Value = value;
    _Ratio = ratio;
}

template<typename K, typename V, typename R>
void _Trio<K, V, R>::PrintTrio()
{

}
template<typename K, typename V, typename R>
bool operator ==(_Trio<K, V, R> left, _Trio<K, V, R> right)
{
    if(left._Key == right._Key)
        return true;
    return false;
}

#endif // TRIO_H
