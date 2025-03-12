#ifndef MY_STRINGS_H_
#define MY_STRINGS_H_

int split(const char *txt, char delim, char ***tokens);
void reverseStr(char *str);
int isPalindrome(const char *target);
char *replace(const char *s, const char *oldW, const char *newW);

#ifdef MY_STRINGS_IMPLEMENTATION
#include <malloc.h>
#include <string.h>

int split(const char *txt, char delim, char ***tokens) {
  int *tklen, *t, count = 1;
  char **arr, *p = (char *)txt;

  while (*p != '\0')
    if (*p++ == delim)
      count += 1;

  t = tklen = (int *)calloc(count, sizeof(int));

  for (p = (char *)txt; *p != '\0'; p++)
    *p == delim ? *t++ : (*t)++;

  *tokens = arr = (char **)malloc(count * sizeof(char *));
  t = tklen;
  p = *arr++ = (char *)calloc(*(t++) + 1, sizeof(char *));

  while (*txt != '\0') {
    if (*txt == delim) {
      p = *arr++ = (char *)calloc(*(t++) + 1, sizeof(char *));
      txt++;
    } else
      *p++ = *txt++;
  }

  free(tklen);
  return count;
}

void reverseStr(char *str) {
  int len = strlen(str);

  for (int i = 0; i < len / 2; i++) {
    char temp = str[i];
    str[i] = str[len - 1 - i];
    str[len - 1 - i] = temp;
  }
}

int isPalindrome(const char *target) {
  size_t len = strlen(target);

  char reverseBuf[len + 1];
  strcpy(reverseBuf, target);
  reverseStr(reverseBuf);

  return strcmp(target, reverseBuf) == 0;
}

char *replace(const char *s, const char *oldW, const char *newW) {
  char *result;
  int i, cnt = 0;
  int newWlen = strlen(newW);
  int oldWlen = strlen(oldW);

  // Counting the number of times old word
  // occur in the string
  for (i = 0; s[i] != '\0'; i++) {
    if (strstr(&s[i], oldW) == &s[i]) {
      cnt++;

      // Jumping to index after the old word.
      i += oldWlen - 1;
    }
  }

  // Making new string of enough length
  result = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1);

  i = 0;
  while (*s) {
    // compare the substring with the result
    if (strstr(s, oldW) == s) {
      strcpy(&result[i], newW);
      i += newWlen;
      s += oldWlen;
    } else
      result[i++] = *s++;
  }

  result[i] = '\0';
  return result;
}
#endif // MY_STRINGS_IMPLEMENTATION

#endif // MY_STRINGS_H_
