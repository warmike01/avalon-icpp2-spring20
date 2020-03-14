#include <iostream>
using namespace std;
int main()
{
  
    int weight=0;
    int base;
    cout << "10 или 13? ";
    cin >> base;
    if (base == 13)
    {
          char ISBN[14];
    cout << ("Введите ISBN: ");
    for(int i=0; i<13; i++)
    {
        cin >> ISBN[i+1];
        ISBN[i+1]-=48;
        if(i!=12)
        {
        if(i%2 == 0) {weight += ISBN[i+1];}
        else {weight += ISBN[i+1]*3;}
        }
    }
    weight = weight % 10;
    for(int i =0;weight++;i++){if (weight % 10 ==0) {weight=i+1; break;};}
    if(ISBN[13]==weight) {cout << "ISBN действителен ";}
    else  {cout << "ISBN недействителен ";}
    }
    else
    {
         char ISBN[11];
         for (int i=0; i<10; i++)
         {
                     cin >> ISBN[i+1];
                     if (ISBN [i+1] != 'X') {ISBN[i+1]-=48;}
                      if(i!=9)
                        {
                            weight += ISBN[i+1] * (10-i);
                        }
         }
         weight = weight % 11;
         for(int i =0;weight++;i++){if (weight % 11 ==0) {weight=i+1; break;};}
         if(ISBN[10]==weight || (weight == 10 && ISBN[10] == 'X') ) {cout << "ISBN действителен ";}
         else  {cout << "ISBN недействителен ";}
    }
}

