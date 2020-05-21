#pragma once
namespace ext
{
char characterat(char* data, int position)
{
    return data[position-1];
}
char* append(char* data, char symbol)
{
    int size=strlen(data)+1;
    char *temp=new char[size+1];
    for(int i=0; i<size-1; i++)
    {
        temp[i]=data[i];
    }
    temp[size-1]=symbol;
     temp[size] = '\0';
    return temp;
}
char* concatenate(char* data1, char* data2)
{
        int size1=strlen(data1)+1;
        int size2=strlen(data2)+1;
        int size=size1 + size2 -1;
    char* data=new char [size];
    for(int i=0; i<size1; i++)
    {
        data[i]=data1[i];
    }
    for(int i=size1; i<size; i++)
    {
        data[i]=data2[i];
    }
    return data;
}
char*substring(char* data, int position)
{
    position++;
    int size=strlen(data)+1;
    char *data1=new char[size - position];
    for(int i=0; i<size; i++)
    {
        data1[i]=data[i+position];
    }
    return data1;
}
char* replacestring(char* data, char* search, char* replacement)
{
    int size=strlen(data)+1;
    int rsize=strlen(replacement)+1;
    int ssize=strlen(search)+1;
    char* data1=new char[size + rsize]
    
    char* k=strstr(data, search);
   int n = k+ssize+1;
    if (sszie >= rsize)
    {
        for (int i=0; i< rsize; i++)
        {
            data1[k+i] = replacement[i];
        }
    }
    else
    {
        for (int i=0; i< ssize; i++)
        {
            data1[k+i] = replacement[i];
        }
        for (int i=ssize+1; i< rsize; i++)
        {
            data1[n+i] = replacement[i];
        }
        data1=strncpy(data1, rsize);
        data1=concatenate(data1, substring(data1, rsize+1));
    }
    
}
