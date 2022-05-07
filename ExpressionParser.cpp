#include <iostream>
#include <string>
#include <cstddef>

#include "Queue.hpp"
#include "ExpressionParser.hpp"

using namespace std;

Queue* ExpressionParser::Split(string str, string del)
{
    Queue *parsedQ = new Queue();
    string buffer = string();
    size_t len = str.length();

    for (size_t i = 0; i < len; i++)
    {
        if (len)
        {
           ; /* code */
        }
        
    }
    
}


/* OPACKO readline v C
char* read_line()
{
    char c = 0;
    char *data = NULL;
    size_t allocated = 1;
    size_t size = 0;
    //char *data = (char*)malloc(sizeof(char) * allocated);
    
    while (c = getchar() != EOF)
    {
        
        if (size + 1 >= allocated)
        {
            allocated *= 2;
            char* pOld = data;
            data = (char*)realloc(data, sizeof(char)*(allocated + 1));
            if (!data)
            {
                cout << "allocation failed\n";
                free(pOld);
            }
            
        }
        data[size++] = c;
        
    }
    if (!data)
    {
        char empty[] = {'\0'};
        return empty;
    }
    

    data[size] = 0;
    return data;
  
}
*/