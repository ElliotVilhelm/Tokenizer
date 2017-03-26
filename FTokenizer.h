#ifndef FTOKENIZER_H
#define FTOKENIZER_H
#include "Token.h"
#include "_Map.h"
#include "_List.h"
#include "Functors.h"

#include "_Pair.h"


#include <map>
#include <iostream>


using namespace std;


class FTokenizer
{
public:
    FTokenizer();

    FTokenizer(char *input);
    FTokenizer(string fileName);


    void PrintInputText();

    _List<Token> TokenizedList();
    _Map<string, int, DUP_ADDEM<string, int> > TokenizedMap();


    map<string, int> STDMAP();




    Token NextToken();
    Token GetToken(char* &input);


    bool Empty();
    void Copy(char *source);

    _Map<int, int> randomMap();


private:
    char* _myInput;
    string _fileName;


    //State Machine
    void S6(char* input, Token &T); // spaces only
    void S5(char* input, Token &T); // punctuation only
    void S4(char* input, Token &T);
    void S2(char* input, Token &T);
    void S3(char* input, Token &T);
    void S1(char* input, Token &T);



};




_Map<int, int> FTokenizer::randomMap()
{
    _Map<int, int> map;
    map.Insert(5, 5);
    map.PrintMap();
    return map;
}




FTokenizer::FTokenizer()
{
    _myInput = NULL;
}

FTokenizer::FTokenizer(char *input)
{

    _myInput = new char[5000000000];
    Copy(input);
}

FTokenizer::FTokenizer(string fileName)
{
    _fileName = fileName;

}

void FTokenizer::PrintInputText()
{
    
    string line2;
    ifstream myFile;
    myFile.open(_fileName);


    if(myFile.is_open())
    {
        cout<<endl<<"Input Text :"<<endl;
        while(getline(myFile, line2))
        {
            cout<<line2;

        }
    }
    myFile.close();
}

bool FTokenizer::Empty()
{
    if(_myInput == NULL)
        return true;
    return false;

}



void FTokenizer::Copy(char *source)
{
    char* walker = _myInput;

    while(*source != NULL)
    {

        cout<<*source;
        *walker = *source;
        source++;
        walker++;
    }
    *walker = NULL;
}





void FTokenizer::S1(char *input,Token &T)
{
    switch(tolower(*input))
    {
    //alpha
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
        T.SetType('a');
        T.Add(*input);
        input++;
        S4(input, T);
        break;

    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        T.SetType('n');
        T.Add(*input);
        input++;
        S2(input, T);
        break;

    case '!':
    case '?':
    case '.':
    case '-':
    case ',':
    case ';':
        T.SetType('z');
        T.Add(*input);
        input++;
        S5(input, T);
        break;

    case ' ':
        T.SetType('s');
        T.Add(*input);
        input++;
        S6(input, T);
        break;
    case NULL:
        break;
    default:
        T.SetType('x');
        T.Add(*input);
        input++;
        break;
    }
}

void FTokenizer::S2(char *input,Token &T)

{
    switch(tolower(*input))
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '.':
    case '-':
        T.SetType('n');
        T.Add(*input);
        input++;
        S2(input, T);
        break;
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
        T.Add(*input);
        input++;
        S4(input, T);
        break;
    case NULL:
        break;
    case ' ':
        break;
    default:
        break;
    }

}

void FTokenizer::S3(char*input, Token &T)
{

    switch(tolower(*input))
    {
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
    case '-':
    case '.':
        T.Add(*input);
        input++;
        S4(input, T);
        break;

    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        T.Add(*input);
        input++;
        S3(input, T);
        break;
    case NULL:
        break;
    case ' ':
        break;
    default:
        break;
    }
}

void FTokenizer::S4(char *input, Token &T)
{
    switch(tolower(*input))
    {
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '-':
        T.Add(*input);
        input++;
        S4(input, T);
        break;
    case NULL:
        break;
    case ' ':
        break;

    default:
        break;
    }
}

void FTokenizer::S5(char *input, Token &T)
{
    switch(tolower(*input))
    {
    case '!':
    case '?':
    case '.':
    case ',':
    case ';':
    case '-':
        T.SetType('z');
        T.Add(*input);
        input++;
        S5(input, T);
        break;
    }
}

void FTokenizer::S6(char *input, Token &T)
{
    switch(tolower(*input))
    {
    case ' ':
        T.SetType('s');
        T.Add(*input);
        input++;
        S5(input, T);
        break;
    }
}

Token FTokenizer::GetToken(char* &input)
{
    char token[100] = "";
    Token Test;

    S1(_myInput, Test);

    if(Test.Type() == 'n')
    {
        //        cout<<"Number Token:";
        return Test;
    }
    if(Test.Type() == 'a')
    {
        //        cout<<"Alpha Token:";
        return Test;
    }
    if(Test.Type() == 'z')
    {
        //        cout<<"Punctuation Token:";
        return Test;
    }
    if(Test.Type() == 's')
    {
        //        cout<<"Space Token:";
        return Test;
    }

    if(Test.Type() == 'x')
    {
        //        cout<<"Unknown Token:";
        return Test;
    }



}

Token FTokenizer::NextToken()
{
    if(*_myInput == NULL)
        return Token('0', "");

    Token Next = GetToken(_myInput);
    //    Next.Print();
    Next.Length();
    _myInput += Next.Length();
    return Next;
}


_List<Token> FTokenizer::TokenizedList()
{
    char* str = "";

    Token X('a', str);

    _List<Token> myList(X);
    ifstream myFile;

    myFile.open(_fileName);

    string line;

    _List<Token>::_Iterator itr = myList._Top();
    if(myFile.is_open())
    {

        while(!myFile.eof())
        {

            getline(myFile, line);
            char tab2[10000];
            strcpy(tab2, line.c_str());
            _myInput = tab2;
            while(!Empty())
            {
                Token Next = NextToken();
                if(Next.Type() == '0')
                    break;
                if(Next.Type() == 'a')
                {

                    myList._insertAfter(itr, Next);
                }

            }

        }

    }

    myList._Print();
    return myList;
}

_Map<string, int, DUP_ADDEM<string, int> > FTokenizer::TokenizedMap()
{

    _Map<string, int, DUP_ADDEM<string, int> > myMap;// = new _Map<string, int, DUP_ADDEM<string, int> >();

int s =0;


    char* str = "";
    ifstream myFile;

    myFile.open(_fileName);

    string line;

    if(myFile.is_open())
    {
        while(!myFile.eof())
        {
            getline(myFile, line);
            char tab2[100000];
            strcpy(tab2, line.c_str());
            _myInput = tab2;
            while(!Empty())
            {
                Token Next = NextToken();
                if(Next.Type() == '0')
                    break;
                if(Next.Type() == 'a')
                {

                    myMap.Insert(Next.myToken, 1);
                    cout<<s<<endl;
                    s++;
                }
            }
        }
    }

    cout<<endl<<endl;
//    myMap.PrintMap();
    return myMap;

}

map<string, int> FTokenizer::STDMAP()
{

    map<string, int> myMap;// = new map<string, int, DUP_ADDEM<string, int> >();

int s =0;


    char* str = "";
    ifstream myFile;

    myFile.open(_fileName);

    string line;

    if(myFile.is_open())
    {
        while(!myFile.eof())
        {
            getline(myFile, line);
            char tab2[100000];
            strcpy(tab2, line.c_str());
            _myInput = tab2;
            while(!Empty())
            {
                Token Next = NextToken();
                if(Next.Type() == '0')
                    break;
                if(Next.Type() == 'a')
                {

                    myMap.insert(pair<string, int>(Next.myToken, 1));
                    cout<<s<<endl;
                    s++;
                }
            }
        }
    }

    cout<<endl<<endl;
    return myMap;

}


#endif // FTOKENIZER_H
