#ifndef MP3_HEADER_H
#define MP3_HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Function Declarations */
void mp3_view(char *filename);
void mp3_edit(char *tag_option, char *new_value, char *filename);
void print_error_message(int argc, char *argv[]);
void print_help(void);
/* Function to convert 4 bytes to integer (for tag size) */
static inline int bytes_to_int(unsigned char size[4])
{
    return (size[0] << 21) | (size[1] << 14) | (size[2] << 7) | (size[3]);
}
#endif
