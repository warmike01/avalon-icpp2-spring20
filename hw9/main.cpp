//работает или нет, не знаю, попытка отладки намертво повесила винду на час
#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
struct triangle
{
int a;
int b;
int c;
double thickness;
};
const int TRIANGLE_SIZE=sizeof(triangle);
int main()
{
    ifstream input;
    input.open("triangle.bin",iostream::binary);
   
    if (!input.is_open())
	{
		cerr << "Ввод не открыт! "; return 1;
    }
    triangle find;
    
    int id;
    cout << "Введите номер треугольника: "
    cin >> id;
    for(int i=0; i<id; i++){input.read(reinterpret_cast<triangle>(find), TRIANGLE_SIZE); }
    printf("A= %d, B= %d, C= %d, thickness= %d",triangle.a,triangle.b,triangle.c,triangle.thickness);
    return 0;
}

