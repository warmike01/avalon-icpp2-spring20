#include <fstream>
using namespace std;
int main()
{
    fstream input;
    input.open("tickets.txt",iostream::in); 
    fstream lucky;
    lucky.open("lucky.txt",iostream::out); 
    fstream unlucky;
    unlucky.open("unlucky.txt",iostream::out); 
    int l=0; int ul=0; //билет счастливый, если сумма чётных цифр равна сумме нечётных
    bool end=false;
    do
    {
        char number[6];
        for(int i=0; i<6; i++) {input >> number[i];number[i]-=48;}
        if(number[0]+number[2]+number[4] == number[1]+number[3]+number[5]  )
        {
            l++;
            for(int i=0; i<6; i++)
        {
            number[i]+=48;lucky << number[i];
        }
                    lucky << '\n';
        }
        else
        {
            ul++;
             for(int i=0; i<6; i++)
        {
            number[i]+=48;unlucky << number[i];
        }
        unlucky << '\n';
        }
    if (input.eof() ) {end=true;}
    } while(!end);
    return 0;
}
