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

// --- 5 ---

char* strtrim(char *str)
{
    int l = (int)strlen(str);
    int low = 0;
    while (low < l && (str[low] <= 32 || str[low] >= 127))
    {
        low++;
    }
    if (low == l)
    {
        return NULL;
    }
    int high = l-1;
    while (str[high] <= 32 || str[high] >= 127)
    {
        high--;
    }
    char* new_str = (char*)malloc(s_char * (high - low + 1));
    if (new_str == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < high - low + 1; i++)
    {
        new_str[i] = str[low + i];
    }
    return new_str;
}

// --- 6 ---

char* strrmchar(char *str, char symbol)
{
    int l = (int)strlen(str);
    char* cpstr = (char*)malloc(s_char * l);
    if (cpstr == NULL)
    {
        return NULL;
    }
    memmove(cpstr, str, (size_t)l);
    int delta = 0;
    for (int i = 0; i < l; i++)
    {
        if (str[i] == symbol)
        {
            memmove(cpstr + i - delta, str + i + 1, (size_t)(l-i-1));
            delta++;
        }
    }
    char* new_str = (char*)malloc(s_char * (l - delta));
    if (new_str == NULL)
    {
        free(cpstr);
        return NULL;
    }
    memmove(new_str, cpstr, (size_t)(l-delta));
    free(cpstr);
    return new_str;
}

// --- 7 ---

size_t strcountchar(const char *str, char symbol)
{
    int l = (int)strlen(str);
    char* cpstr = (char*)malloc(s_char * l);
    if (cpstr == NULL)
    {
        return 0;
    }
    memcpy(cpstr, str, (size_t)l);
    size_t count = 0;
    char* pointer = strchr(cpstr, symbol);
    while (pointer != NULL)
    {
        count++;
        *pointer = (char)(symbol + 1);
        pointer = strchr(cpstr, symbol);
    }
    free(cpstr);
    return count;
}

// --- 8 ---

char* substr(const char *str, size_t pos, size_t count)
{
    size_t l = (size_t)strlen(str);
    size_t end_pos = pos + count;
    if (end_pos > l)
    {
        end_pos = l;
    }
    if (end_pos <= pos)
    {
        return NULL;
    }
    char* new_str = (char*)malloc(s_char * (end_pos - pos));
    if (new_str == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < (int)(end_pos - pos); i++)
    {
        new_str[i] = str[pos+i];
    }
    return new_str;
}

// --- 9 ---

int findlast(const char *str, char symbol)
{
    int l = (int)strlen(str);
    for (int i = l-1; i >= 0; i--)
    {
        if (str[i] == symbol)
        {
            return i;
        }
    }
    return -1;
}

int strfindlastof(const char *str, const char *symbols)
{
    int l = (int)strlen(symbols);
    int k = -1;
    int buff = 0;
    for (int i = 0; i < l; i++)
    {
        buff = findlast(str, symbols[i]);
        if (buff > k)
        {
            k = buff;
        }
    }
    return k;
}

// --- 10 ---

int to_valid(char c)
{
    if (c >= 65 && c <= 90)
    {
        return (int)c;
    }
    else if (c >= 97 && c <= 122)
    {
        return (int)(c - 32);
    }
    return 0;
}

int strispalindrome(const char *str)
{
    int l = (int)strlen(str);
    int p1 = 0;
    int p2 = l-1;
    while (p1 < p2)
    {
        if (!to_valid(str[p1]))
        {
            p1++;
        }
        else if (!to_valid(str[p2]))
        {
            p2--;
        }
        else
        {
            if (to_valid(str[p1]) != to_valid(str[p2]))
            {
                return 0;
            }
            else
            {
                p1++;
                p2--;
            }
        }
    }
    return 1;
}

