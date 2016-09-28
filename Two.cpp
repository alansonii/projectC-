#include <stdio.h>
#include <stdlib.h>
int* IntVector;
void bar(void)
{
printf("Черт! Меня взломали!\n");
}
void InsertInt(unsigned long index, unsigned long value )
{
printf("Запись в память по адресу %p\n", &(IntVector[index]));
IntVector[index] = value;
}
bool InitVector(int size)
{
IntVector = (int*)malloc(sizeof(int)*size);
printf("Адрес переменной IntVector: %p\n", IntVector);
if(IntVector == NULL)
return false;
else
return true;
}
int main(int argc, char* argv[])
{
unsigned long index, value;
if(argc != 3)
{
printf("Использовано: %s [index] [value]\n");
return !1;
}
printf("Адрес функции bar %p\n", bar);
if(!InitVector(0xffff))
{
printf("Не могу инициализировать вектор!\n");
return !1;
}
index = atol(argv[1]);
value = atol(argv[2]);
InsertInt(index, value);
return 0;
}