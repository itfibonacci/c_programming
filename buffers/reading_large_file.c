#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024  // Define the size of the buffer

int main() {
  FILE* fp_in = fopen("input.txt", "r");  // Open the input file for reading
  FILE* fp_out = fopen("output.txt", "a");  // Open the output file for appending

  if (fp_in == NULL) {
    // Error handling for input file
  }

  if (fp_out == NULL) {
    // Create the output file if it does not exist
    fp_out = fopen("output.txt", "w");
  }

  char buffer[BUFFER_SIZE];  // Declare a buffer of 1024 characters
  size_t bytes_read;  // Declare a variable to store the number of bytes read

  // Read the input file in chunks using the buffer
  while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, fp_in)) > 0) {
    // Process the data in the buffer
    for (size_t i = 0; i < bytes_read; i++) {
      buffer[i] = toupper(buffer[i]);  // Convert each character to uppercase
    }
    fwrite(buffer, 1, bytes_read, fp_out);  // Write the transformed data to the output file
  }

  fclose(fp_in);  // Close the input file
  fclose(fp_out);  // Close the output file

  return 0;
}
