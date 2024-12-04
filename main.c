#include <stdio.h>
#include <stdlib.h>
#include "lab2.h"

int main()
{
    char str[] = "Hello World!";
    char str2[] = "hello WORLD!";
    char str3[] = "Hello";
    char str4[] = "HAllo World!";
    char str5[] = "     Hello there!         ";
    char str12[] = "Was it a car or a cat I saw?";
    char* s1 = strtolower(str);
    char* s2 = strtoupper(str);
    char* s4 = strreverse(str);
    char* s5 = strtrim(str5);
    char* s6 = strrmchar(str, 'o');
    char* s7 = substr(str, 0, 4);
    char* s8 = substr(str, 6, 15);
    printf("1) %s\n", s1);
    printf("2) %s\n", s2);
    printf("3) %d %d %d\n", strcmp_insensitive(str, str2), strcmp_insensitive(str, str3), strcmp_insensitive(str, str4));
    printf("4) %s\n", s4);
    printf("5) %s\n", s5);
    printf("6) %s\n", s6);
    printf("7) %d %d\n", (int)strcountchar(str, 'o'), (int)strcountchar(str, 'x'));
    printf("8) %s %s\n", s7, s8);
    printf("9) %d %d %d\n", strfindlastof(str, "fenix"), strfindlastof(str, "log"), strfindlastof(str, "mix"));
    printf("10) %d %d\n", strispalindrome("Go hang a salami I'm a lasagna hog"), strispalindrome("Hello"));
    printf("11) %d %d\n", (int)strcountwords("Was it a car or a cat I saw?"), (int)strcountwords("      "));
    printf("12) ");
    size_t n;
    char** words = strtowords(str12, &n);
    for (int i = 0; i < (int)n; i++)
    {
        printf("%s;", words[i]);
    }
    printf("\n");
    printf("13) %d %d %d %d\n", strisipv4("192.168.1.0"), strisipv4("192.168.1.0/24"), strisipv4("192.168.0.256"), strisipv4("092.01.0.1"));
    size_t* counts = strcountchars(str);
    printf("14) %d\n", (int)counts['l']);
    free(s1);
    free(s2);
    free(s4);
    free(s5);
    free(s6);
    free(s7);
    free(s8);
    for (int i = 0; i < (int)n; i++)
    {
        free(words[i]);
    }
    free(words);
    free(counts);
    return 0;
}
