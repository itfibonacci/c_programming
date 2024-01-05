#include <stdio.h>
//#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int argc, char** argv) {
  // Check that a filename was passed as a command line argument
  if (argc != 2) {
    fprintf(stderr, "Error: expecting exactly one argument (filepath)\n");
    return 1;
  }

  // Open the file for reading
  FILE* file = fopen(argv[1], "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  // Set up the buffer
  char buffer[BUFFER_SIZE];

  // Read data from the file into the buffer
  while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
    // Write the contents of the buffer to stdout
    fputs(buffer, stdout);
  }

  // Close the file
  fclose(file);

  return 0;
}
