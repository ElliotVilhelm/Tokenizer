#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
using namespace std;
struct Token
{
    Token();
    Token(char type, char* token);
    void Copy(char* source, char* destination);
    void Print();

    void Add(char addMe);

    void SetType(char type);
    char Type();




    int Length();

    bool Valid;

    int paragraphNumber;
    friend ostream& operator <<(ostream& os, const Token& PrintMe);




    //private:
    char TokenType;
    char* myToken;
};

#endif // TOKEN_H
