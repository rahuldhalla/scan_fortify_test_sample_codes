
#include <stdio.h>
#include <stdarg.h>

int writeformatted(char* buffer, int bufferSize, const char *format, ...)
{
    int len = 0;
    va_list arguments;
    va_start(arguments, format);
    len = vsnprintf(buffer, bufferSize, format, arguments);
    va_end(arguments);
    return len;
}

int main ()
{
    char buf[50];
    char s1[50] = "vsnprintf() Example Code";

    int len = writeformatted(buf, 50, "%s ", s1);

    printf("Content of array: %s \n", buf);
    printf("No. of characters in array: %d \n", len);

    return 0;
}
