#include <stdlib.h>
#define MY_STRINGS_IMPLEMENTATION
#include "my_strings.h"

#include <malloc.h>
#include <stdio.h>

int cmpStr(const void *a, const void *b) {
  return strcmp(*(const char **)a, *(const char **)b);
}

int getNameValue(const char *name) {
  int sum = 0;

  for (size_t i = 0; i < strlen(name); ++i)
    sum += name[i] - 'A' + 1;

  return sum;
}

int main(int argc, char **argv) {
  printf("[INFO]: Problem: https://projecteuler.net/problem=22\n");
  printf("[INFO]: Description: What is the total of all the name scores(sum of "
         "each letter index in alphabet) in the file(provided by first program "
         "argument)?\n");

  if (argc < 2) {
    fprintf(stderr, "[ERROR]: missing argument: filename\n");
    return 0;
  }

  char *filename = argv[1];
  FILE *file = fopen(filename, "r");
  if (!file) {
    perror("[ERROR]: failed to open file: ");
    return 1;
  }

  long long sum = 0;

  while (1) {
    char *line;
    size_t len;
    if (getline(&line, &len, file) == -1)
      break;

    char *sanitizedLine = replace(line, "\"", "");

    char **names;
    int namesCount = split(sanitizedLine, ',', &names);

    qsort(names, namesCount, sizeof(char *), cmpStr);

    for (int i = 0; i < namesCount; ++i) {
      sum += (i + 1) * getNameValue(names[i]);
    }

    for (int i = 0; i < namesCount; ++i)
      free(names[i]);
    free(names);
    free(sanitizedLine);
    free(line);
  }

  printf("[INFO]: Solution: %lld\n", sum);
  fclose(file);
  return 0;
}
