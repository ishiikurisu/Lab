#ifndef JOE_STRING_H
#define JOE_STRING_H 0
#include <stdbool.h>

int strlen(char* s)
{
    int i = 0;
    if (s) while (s[i]) ++i;
    return i;
}

char* concat(char* string, char* to_add)
{
    char* new_str;
    int len;
    int i, j;

    len = strlen(string) + strlen(to_add);
    new_str = (char*) malloc(sizeof(char) * (len + 1));

    for (i = 0, j = 0; i < strlen(string); ++i, ++j)
        new_str[j] = string[i];
    for (i = 0; i <= strlen(to_add); ++i, ++j)
        new_str[j] = to_add[i];

    return new_str;
}

char* new_concat(char* to_hold, char* to_add)
{
    int l1 = strlen(to_hold);
    int l2 = strlen(to_add);
    int len = l1 + l2;
    char* new_str = malloc(sizeof(char) * (len + 1));
    
    memcpy(new_str, to_hold, l1);
    memcpy(new_str + l1, to_add, l2);

    new_str[len] = '\0';
    return new_str;
}

#define cat(A,B) ((A)=new_concat((A), (B)))

char* to_array(char ch)
{
    char* out = (char*) malloc(sizeof(char) * 2);
    out[0] = ch;
    out[1] = '\0';
    return out;
}

char* ctos(char ch)
{
    return to_array(ch);
}

char* int_to_string(int input)
{
    int size = 1;
    char* output = NULL;

    while ((input / (10 * size)) != 0)
        ++size;

    output = (char*) malloc(sizeof(char) * (1 + size));
    sprintf(output, "%d", input);

    return output;
}
char* itos(int number)
{
    return int_to_string(number);
}


char* substring(char* string, int start, int end)
{
    int i;
    int gap = end - start;
    char* sub = (char*) malloc(sizeof(char) * (gap + 1));

    for (i = 0; i < gap; ++i)
        sub[i] = string[start + i];
    sub[i] = '\0';

    return sub;
}

int equals(char* s1, char* s2)
{
    int output = 0;
    int len = strlen(s1);
    int i = -1;

    if (strlen(s1) == strlen(s2))
        for (i = 0; (i < len) && (s1[i] == s2[i]); ++i);
    if (i == len)
        output = 1;

    return output;
}

#define BIGGER  (+1)
#define SMALLER (-1)
#define EQUAL   (0)
#define EQUALS  (EQUAL)

int compare(char* s, char* t)
{
    if (t == NULL)
        return SMALLER;
    if (s == NULL)
        return BIGGER;

    int r  = 0;
    int i  = 0;
    int sl = strlen(s);
    int tl = strlen(t);


    while (i < sl && i < tl && r == 0)
        if (s[i] > t[i])
            r = BIGGER;
        else if (t[i] > s[i])
            r = SMALLER;
        else
            ++i;

    if (i < sl && i == tl)
        r = BIGGER;
    else if (i == sl && i < tl)
        r = SMALLER;

    return r;
}

bool whitespace(char c)
{
    if (c == ' ' || c == '\t' || c == '\n') {
        return true;
    }
    else {
        return false;
    }
}
char* tidy_string(char *str)
{
    int beg = 0;
    int end = strlen(str);

    while (whitespace(str[beg]))
        ++beg;

    while (whitespace(str[end]))
        --end;

    return substring(str, beg, end);
}

char last_char(char* string)
{ return string[strlen(string) - 1]; }

#endif
