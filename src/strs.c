#include <stdio.h>

#include "strs.h"

// squeeze: delete all c from s
void squeeze(char s[], int c)
{
  int i, j;
  for (i = j = 0; s[i] != '\0'; ++i)
  {
    if (s[i] != c)
    {
      s[j++] = s[i];
    }
  }
  s[j] = '\0';
}

// strcat: concatenate t to end of s; s must be big enough
void my_strcat(char s[], char t[])
{
  int i, j;
  i = j = 0;
  while (s[i] != '\0') // find end of s
  {
    ++i;
  }
  while ((s[i++] = t[j++]) != '\0') // copy t
  {
  }
}

// Exercise 2-4. page 48
void squeeze_str(char s[], char e[])
{
  int i, j;
  for (i = j = 0; s[i] != '\0'; ++i)
  {
    int keep = 1;
    for (int k = 0; e[k] != '\0'; ++k)
    {
      if (s[i] == e[k])
      {
        keep = 0;
        break;
      }
    }
    if (keep)
    {
      s[j++] = s[i];
    }
  }
  s[j] = '\0';
}

// Exercise 2-5. page 48
// Exercise 5-6. page 107
// modified to use pointer arithmetic
int any(const char *s, const char *t)
{
  for (const char *p = s; *p; ++p)
  {
    for (const char *q = t; *q; ++q)
    {
      if (*p == *q)
      {
        return (int)(p - s);
      }
    }
  }
  return -1;
}

// Exercise 4-1. page 71
// strrindex returns the position of the rightmost occurrence of t in s, or -1
// if there is none. This implementation is a trivial modification of strindex
// to just continue searching even after finding a match on the left, and keeps
// track of the rightmost one found. This could be improved by starting from
// the end of the string and returning the first match.
// Exercise 5-6. page 107
// modified to use pointer arithmetic
int strrindex(const char *s, const char *t)
{
  int i_max = -1;
  const char *sstart = s;

  for (; *s; ++s)
  {
    const char *j, *k;
    for (j = s, k = t; *k && *j == *k; ++j, ++k)
    {
    }
    if (k > t && *k == '\0')
    {
      i_max = (int)(s - sstart);
    }
  }
  return i_max;
}

// Exercise 5-3. page 107
void strcat_ptr(char *s, const char *t)
{
  while (*s)
  {
    ++s;
  }
  while ((*s++ = *t++) != '\0')
  {
  }
}

// Exercise 5-4. page 107
int strend(const char *s, const char *t)
{
  const char *tstart = t;
  while (*s)
  {
    ++s;
  }
  while (*t)
  {
    ++t;
  }
  while (*--s == *--t && t != tstart)
  {
  }
  return t == tstart;
}

// Exercise 5-5. page 107
char *my_strncpy(char *s, const char *t, size_t n)
{
  char *sstart = s;
  for (; n > 0 && *t; --n, ++s, ++t)
  {
    *s = *t;
  }
  for (; n; --n, ++s)
  {
    *s = '\0';
  }
  return sstart;
}

char *my_strncat(char *s, const char *t, size_t n)
{
  char *sstart = s;
  while (*s)
  {
    ++s;
  }
  for (; n > 0 && (*s++ = *t++) != '\0'; --n)
  {
  }
  if (n == 0)
  {
    *s = '\0';
  }
  return sstart;
}

int my_strncmp(const char *s, const char *t, size_t n)
{
  for (; n > 0 && *s && (*s == *t); --n, ++s, ++t)
  {
  }
  return n ? *s - *t : 0;
}
