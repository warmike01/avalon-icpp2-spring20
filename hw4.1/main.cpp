#include <stdio.h>
#include <climits>
#include <cfloat>
int main()
{
    printf("Тип переменной     |Размер,| Значение\t\t\t| Количество \n");
    printf("\t           | байт  | Минимальное  | Максимальное| значимых бит\n");
    printf("bool \t\t   | \t %d |\t%s|%s|%d\n",sizeof(bool),"true","false",1);
    printf("unsigned short     |   \t %d |\t%d|%d|%d\n",sizeof(unsigned short),0,USHRT_MAX,sizeof(unsigned short)*8);
    printf("short \t\t   | \t %d |\t%d|%d|%d\n",sizeof(short),SHRT_MIN,SHRT_MAX,sizeof(short)*8);
    printf("unsigned \t   | \t %d |\t%d|%u|%d\n",sizeof(unsigned),0,UINT_MAX,sizeof(unsigned)*8);
    printf("int \t\t   | \t %d |\t%d|%d|%d\n",sizeof(int),INT_MIN,INT_MAX,sizeof(int)*8);
    printf("unsigned long      | \t %d |\t%d|%lu|%d\n",sizeof(unsigned long),0,ULONG_MAX,sizeof(unsigned long)*8);
    printf("long \t\t   | \t %d |\t%ld|%ld|%d\n",sizeof(long),LONG_MIN,LONG_MAX,sizeof(long)*8);
    printf("unsigned long long | \t %d |\t%d|%llu|%d\n",sizeof(unsigned long long),0,ULLONG_MAX,sizeof(unsigned long long)*8);
    printf("long long \t   | \t %d |\t%lld|%lld|%d\n",sizeof(long long),0,LLONG_MAX,sizeof(long long)*8);
    printf("char \t\t   | \t %d |\t%d|%d|%d\n",sizeof(char),CHAR_MIN,CHAR_MAX,sizeof(char)*8);
    printf("float \t\t   | \t %d |\t%f|%f|%d\n",sizeof(char),FLT_MIN,FLT_MAX,sizeof(float)*8);
    printf("double \t\t   | \t %d |\t%f|%ef|%d\n",sizeof(char),DBL_MIN,DBL_MAX,sizeof(double)*8);
}
