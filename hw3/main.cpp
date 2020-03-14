#include <iostream>
#include "Extention.hpp"
using namespace std;
using namespace ext;

int main()
{
    int table[10][12];
        for(int i=0; i<10; i++)
    {
        for(int j=0; j<12; j++)
        {
           table[i][j] =-1;
        }
    }
    for(int i=0; i<10; i++)
    {
        int k=GetRandomValue(0, 5);
        int l=GetRandomValue(k+2, 11);
        for(int j=k; j<=l; j++)
        {
            table[i][j]=GetRandomValue(1000, 100000);
            
        }
       
    }
    
        for(int i=0; i<10; i++)
    {
         for(int j=0; j<12; j++)
         {
        for(int k=0; k<12; k++)
        {
            if(table[i][k] > table [i][k+1]) {int temp=table[i][k]; table[i][k]=table[i][k+1]; table[i][k+1]=temp;}
        }
    }
    }
    int M[10]={0};
    for(int i=0; i<10; i++)
    {
          bool mcheck =false;
        for(int j=0; j<12; j++)
        {
          
            if (table[i][j] < 100) {table[i][j]=-1;}
            else
            {
                if(mcheck == false)
                {
                    if (j % 2 == 1) {M[i] = table[i] [(12 -j ) /2 +j ];}
                    else {M[i] = (table[i] [(12 -j) /2 +j] + table [i][(12 -j ) /2 +j -1]) /2;}
                     mcheck = true;
                }
            }
           cout << table[i][j] << ' ';
        }
        cout << "Медиана: "<< M[i] << endl;
    }
}
