#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * grep(const char *pattern, const char *input) {
  char *output = NULL;
  size_t output_size = 0;
  FILE *fp = open_memstream(&output, &output_size);
  if (fp == NULL) {
    perror("open_memstream");
    return NULL;
  }

  char *line = NULL;
  size_t line_size = 0;
  while (getline(&line, &line_size, stdin) != -1) {
    if (strstr(line, pattern) != NULL) {
      fputs(line, fp);
    }
  }

  free(line);
  fclose(fp);
  return output;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s PATTERN INPUT\n", argv[0]);
    return 1;
  }

  char *output = grep(argv[1], argv[2]);
  if (output == NULL) {
    return 1;
  }

  printf("%s", output);
  free(output);
  return 0;
}
