//Elliot Pourmand - CS8
#include <iostream>
#include <fstream>
#include <map>
#include <string.h>
#include "Token.h"
#include "_Map.h"
#include "FTokenizer.h"

#include "Functors.h"

#include "_List.h"

#include "_Trio.h"

using namespace std;

int main()
{

    try
    {





 _Trio<int, int, int> tri;














//////////////// FTOKENIZE MAP /////////////////////////////////
////////////////////////////////////////////////////////////////

       typedef _Map<string, int, DUP_ADDEM<char, int> > Frequency;
        string fileName = "../sampletext";
        FTokenizer Z(fileName);
        Z.PrintInputText();


        map<string, int> myMap(Z.STDMAP());


        for(map<string, int>::const_iterator it = myMap.begin();
            it != myMap.end(); ++it)
        {
            std::cout << it->first << " |   ";// <</* it->second << "  "*/;
        }


//        _Map<string, int> myMap;
//        myMap = Z.TokenizedMap();
//        myMap.PrintMap();



//        _Map<string, int> myMap2;
//        myMap2 = myMap.SortedByValue();
//        myMap2.PrintMap();

////////////////////////////////////////////////////////////////






    }



    catch(int x)
    {
        if(x == 0)
            cout<<"*** NULL PTR IN INSERT FUNCTION ***"<<endl;
        if(x == 1)
            cout<<"*** HEAD IS NULL ***"<<endl;
        if(x == 2)
            cout<<endl<<"*** EMPTY LIST ****"<<endl;
    }

    cout<<endl<<"---- END ----"<<endl;

    return 0;
}
