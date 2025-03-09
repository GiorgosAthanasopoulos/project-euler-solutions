#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **str_split(char *a_str, const char a_delim) {
  char **result = 0;
  size_t count = 0;
  char *tmp = a_str;
  char *last_comma = 0;
  char delim[2];
  delim[0] = a_delim;
  delim[1] = 0;

  /* Count how many elements will be extracted. */
  while (*tmp) {
    if (a_delim == *tmp) {
      count++;
      last_comma = tmp;
    }
    tmp++;
  }

  /* Add space for trailing token. */
  count += last_comma < (a_str + strlen(a_str) - 1);

  /* Add space for terminating null string so caller
     knows where the list of returned strings ends. */
  count++;

  result = malloc(sizeof(char *) * count);

  if (result) {
    size_t idx = 0;
    char *token = strtok(a_str, delim);

    while (token) {
      assert(idx < count);
      *(result + idx++) = strdup(token);
      token = strtok(0, delim);
    }
    assert(idx == count - 1);
    *(result + idx) = 0;
  }

  return result;
}

int main(int argc, char **argv) {
  printf("[INFO]: Problem: https://projecteuler.net/problem=11\n");
  printf("[INFO]: Description: What is the greatest product of x adjacent "
         "numbers in the same direction in the y by z grid (where x is the "
         "amount of adjacent numbers to count, and y, z are the dimensions of "
         "the grid provided by file f, all parameters provided as program "
         "arguments)?\n");
  printf("[INFO]: Reference: "
         "https://stackoverflow.com/questions/9210528/"
         "split-string-with-delimiters-in-c\n");
  printf(
      "[INFO]: Reference: "
      "https://stackoverflow.com/questions/3501338/c-read-file-line-by-line\n");

  if (argc < 5) {
    fprintf(stderr, "[ERROR]: missing arguments: required: x y z f (x=adjacent "
                    "number count, y=rows in grid, z=cols in grid, f=filename "
                    "containing grid)");
    return 1;
  }

  int adjacentCount = atoi(argv[1]);
  int rows = atoi(argv[2]);
  int cols = atoi(argv[3]);
  char *filename = argv[4];
  printf("[INFO]: Using parameters: adjacentCount=%d, rows=%d, cols=%d, "
         "filename=%s\n",
         adjacentCount, rows, cols, filename);

  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("[ERROR]: failed to open file: ");
    return 1;
  }

  int grid[rows][cols];
  int lineNo = 0;
  while (1) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read = getline(&line, &len, file);
    if (read == -1) {
      break;
    }

    char **nums = str_split(line, ' ');
    for (int i = 0; i < cols; ++i) {
      grid[lineNo][i] = atoi(nums[i]);
    }

    if (line) {
      free(line);
    }
    if (nums) {
      free(nums);
    }
    lineNo++;
  }

  int product = 1;

  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {

      int canSearchUp = row >= adjacentCount - 1;
      if (canSearchUp) {
        int upProduct = 1;
        for (int targetY = row - adjacentCount + 1; targetY <= row; ++targetY) {
          upProduct *= grid[targetY][col];
        }
        if (upProduct > product) {
          product = upProduct;
        }
      }

      int canSearchDown = row <= rows - adjacentCount;
      if (canSearchDown) {
        int downProduct = 1;
        for (int targetY = row + adjacentCount - 1; targetY >= row; --targetY) {
          downProduct *= grid[targetY][col];
        }
        if (downProduct > product) {
          product = downProduct;
        }
      }

      // search left
      int canSearchLeft = col >= adjacentCount - 1;
      if (canSearchLeft) {
        int leftProduct = 1;
        for (int targetX = col - adjacentCount + 1; targetX <= col; ++targetX) {
          leftProduct *= grid[row][targetX];
        }
        if (leftProduct > product) {
          product = leftProduct;
        }
      }

      // search right
      int canSearchRight = col <= cols - adjacentCount;
      if (canSearchRight) {
        int rightProduct = 1;
        for (int targetX = col + adjacentCount - 1; targetX >= col; --targetX) {
          rightProduct *= grid[row][targetX];
        }
        if (rightProduct > product) {
          product = rightProduct;
        }
      }

      // search diagonally top left
      if (canSearchUp && canSearchLeft) {
        int topLeftProduct = 1;
        int stop = adjacentCount;
        int x = col;
        int y = row;
        while (stop != 0) {
          topLeftProduct *= grid[y][x];
          x--;
          y--;
          stop--;
        }
        if (topLeftProduct > product) {
          product = topLeftProduct;
        }
      }

      // search diagonally top right
      if (canSearchUp && canSearchRight) {
        int topRightProduct = 1;
        int stop = adjacentCount;
        int x = col;
        int y = row;
        while (stop != 0) {
          topRightProduct *= grid[y][x];
          x++;
          y--;
          stop--;
        }
        if (topRightProduct > product) {
          product = topRightProduct;
        }
      }

      // search diagonally bottom left
      if (canSearchDown && canSearchLeft) {
        int bottomLeftProduct = 1;
        int stop = adjacentCount;
        int x = col;
        int y = row;
        while (stop != 0) {
          bottomLeftProduct *= grid[y][x];
          x--;
          y++;
          stop--;
        }
        if (bottomLeftProduct > product) {
          product = bottomLeftProduct;
        }
      }

      // search diagonally bottom right
      if (canSearchDown && canSearchRight) {
        int bottomRightProduct = 1;
        int stop = adjacentCount;
        int x = col;
        int y = row;
        while (stop != 0) {
          bottomRightProduct *= grid[y][x];
          x++;
          y++;
          stop--;
        }
        if (bottomRightProduct > product) {
          product = bottomRightProduct;
        }
      }
    }
  }

  printf("[INFO]: Solution: %d\n", product);
  fclose(file);
  return 0;
}
