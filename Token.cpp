#include "Token.h"

Token::Token()
{
    myToken = NULL;
}

Token::Token(char type, char *token)
{
    TokenType = type;
    myToken  = new char[100];
    Copy(token, myToken);
}



void Token::Copy(char *source, char *destination)
{
    while(*source != NULL)
    {
        *destination = *source;
        source++;
        destination++;
    }
    *destination = NULL;

}

void Token::Print()
{
    if(*myToken != NULL)
        cout<<endl<<"["<<myToken<<"]"<<endl;

}

void Token::Add(char addMe)
{

    if(myToken == NULL)
    {
        myToken  = new char[100];
        char* walker = myToken;
        *walker = addMe;
        walker++;
        *walker = NULL;
    }

    else
    {

        char* walker = myToken;

        while(*walker != NULL)
        {
            walker++;
        }

        *walker = addMe;
        walker++;
        *walker = NULL;
    }
}

void Token::SetType(char type)
{
    TokenType = type;
}

char Token::Type()
{
    return TokenType;
}

int Token::Length()
{
    char* walker = myToken;
    int size = 0;

    while(*walker != NULL)
    {
        size++;
        walker++;
    }
    return size;
}

ostream &operator <<(ostream &os, const Token& PrintMe)
{
    os << PrintMe.myToken << "  P :  "<<PrintMe.paragraphNumber;
}


