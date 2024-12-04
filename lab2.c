#include <string.h>
#include <stdlib.h>
#include "lab2.h"

const int s_char = sizeof(char);

int abs(int x)
{
    if (x < 0)
    {
        return -x;
    }
    return x;
}

// --- 1 ---

char* strtolower(char *str)
{
    int l = (int)strlen(str);
    char* new_str = (char*)malloc(s_char * l);
    if (new_str == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < l; i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
        {
            new_str[i] = str[i] + 32;
        }
        else
        {
            new_str[i] = str[i];
        }
    }
    return new_str;
}

// --- 2 ---

char* strtoupper(char* str)
{
    int l = (int)strlen(str);
    char* new_str = (char*)malloc(s_char * l);
    if (new_str == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < l; i++)
    {
        if (str[i] >= 97 && str[i] <= 122)
        {
            new_str[i] = str[i] - 32;
        }
        else
        {
            new_str[i] = str[i];
        }
    }
    return new_str;
}

// --- 3 ---

int strcmp_insensitive(const char *str1, const char *str2)
{
    int l1 = (int)strlen(str1);
    int l2 = (int)strlen(str2);
    int swap = 0;
    if (l2 < l1)
    {
        swap = 1;
        l1 += l2;
        l2 = l1 - l2;
        l1 -= l2;
    }
    char c1, c2;
    for (int i = 0; i < l1; i++)
    {
        if (str1[i] >= 97 && str1[i] <= 122)
        {
            c1 = str1[i] - 32;
        }
        else
        {
            c1 = str1[i];
        }
        if (str2[i] >= 97 && str2[i] <= 122)
        {
            c2 = str2[i] - 32;
        }
        else
        {
            c2 = str2[i];
        }
        if (c1 != c2)
        {
            return abs(str1[i] - str2[i]);
        }
    }
    if (l1 == l2)
    {
        return 0;
    }
    if (swap)
    {
        return (int)str1[l1];
    }
    return (int)str2[l1];
}

// --- 4 ---

char* strreverse(char *str)
{
    int l = (int)strlen(str);
    char* new_str = (char*)malloc(s_char * l);
    if (new_str == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < l; i++)
    {
        new_str[i] = str[l-i-1];
    }
    return new_str;
}
