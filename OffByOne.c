/*
OffByOne.c
*/
#include <stdio.h>
#include <string.h>
void foo(const char* in)
{
char buf[64];
strncpy(buf, in, sizeof(buf));
buf[sizeof(buf)] = '\0'; //Оп!ля!ля! На один больше!
printf("%s\n", buf);
}
void bar(const char* in)
{
printf("Черт! Меня взломали!\n");
}
int main(int argc, char* argv[])
{
if(argc != 2)
{
printf("Использование: %s [string]\n", argv[0]);
return !1;
}
printf("Адрес foo %p, Адрес bar %p\n", foo, bar);
foo(argv[1]);
return 0;
}