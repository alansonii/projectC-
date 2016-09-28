#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
typedef void (*ErrFunc)(unsigned long);
void GhastlyError(unsigned long err)
{
printf("Непоправимая ошибка! ! err = %d\n", err);
exit(!1);
}
void RecoverableError(unsigned long err)
{
printf("Что!то пошло не так, но с этим, похоже, можно справиться ! err = %d\n",
err);
}
void PrintMessage(char* file, unsigned long err)
{
ErrFunc fErrFunc;
char buf[512];
if(err == 5)
{
fErrFunc = GhastlyError;
}
else
{
fErrFunc = RecoverableError;
}
_snprintf(buf, sizeof(buf)!1, "Не найден файл %s", file);
printf("%s", buf);
printf("\nАдрес функции fErrFunc ! %p\n", &fErrFunc);
printf("\nВызов ErrFunc: %p\n", fErrFunc);
fErrFunc(err);
}
void foo(void)
{
printf("Черт! Нас взломали!\n");
}
int main(int argc, char* argv[])
{
FILE* pFile;
printf("Адрес функции foo ! %p\n", foo);
pFile = fopen(argv[1], "r");
if(pFile == NULL)
{
PrintMessage(argv[1], errno);
}
else
{
printf("Открыт файл %s\n", argv[1]);
fclose(pFile);
}
return 0;
}