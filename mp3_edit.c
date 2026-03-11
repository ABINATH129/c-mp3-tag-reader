/* NAME : ABINATH S 
   DATE : 28/10/2025
   DESCRIPTION : To read and edit tags for an mp3 file
   		 1.read the arguments using command line arguments
		 2.check the arguments is valid or not
		 3.print thr help menu and error message
		 4.check the file is mp3 or not 
		 5.check for id3
		 6.read tags and print in the stdout for view
		 7.edit the particular tag and save in the new file and rename to same file name
*/
#include "mp3_header.h"
/* Function to edit mp3 tag */
void mp3_edit(char *tag_option, char *new_value, char *filename)
{
    printf("-----------------------------Select Edit option-----------------------------\n");
    FILE *src = fopen(filename, "rb"); // open original file
    if (src == NULL)
    {
        printf("Error: Cannot open file %s\n", filename);
        return;
    }
    FILE *temp = fopen("temp.mp3", "wb"); // create temp file
    if (temp == NULL)
    {
        printf("Error: Cannot create temp file.\n");
        fclose(src);
        return;
    }
    /* Match the option with tag name */
    char tag_to_edit[5];
    if (strcmp(tag_option, "-t") == 0)
        strcpy(tag_to_edit, "TIT2");
    else if (strcmp(tag_option, "-a") == 0)
        strcpy(tag_to_edit, "TPE1");
    else if (strcmp(tag_option, "-A") == 0)
        strcpy(tag_to_edit, "TALB");
    else if (strcmp(tag_option, "-y") == 0)
        strcpy(tag_to_edit, "TYER");
    else if (strcmp(tag_option, "-C") == 0)
        strcpy(tag_to_edit, "TCON");
    else if (strcmp(tag_option, "-c") == 0)
        strcpy(tag_to_edit, "COMM");
    else
    {
        printf("Invalid edit option.\n");
        fclose(src);
        fclose(temp);
        remove("temp.mp3");
        return;
    }
    unsigned char buffer[10];
    fread(buffer, 1, 10, src);  // read 10 bytes of header
    fwrite(buffer, 1, 10, temp); // write 10 bytes to new file
    /* Read each tag and copy to temp file */
    while (!feof(src))
    {
        char tag[5] = {0};
        if (fread(tag, 1, 4, src) != 4)
            break;
        unsigned char size_bytes[4], flag[2];
        fread(size_bytes, 1, 4, src);
        fread(flag, 1, 2, src);
        int size = bytes_to_int(size_bytes);
        char *data = malloc(size);
        fread(data, 1, size, src);
        /* If tag is the one to be edited */
        if (strcmp(tag, tag_to_edit) == 0)
        {
            int new_size = strlen(new_value) + 1; // new size
            unsigned char new_size_bytes[4] = {0, 0, 0, new_size};
            fwrite(tag, 1, 4, temp);                // write tag
            fwrite(new_size_bytes, 1, 4, temp);     // write new size
            fwrite(flag, 1, 2, temp);               // write flag
            fputc(0x00, temp);                      // encoding byte
            fwrite(new_value, 1, strlen(new_value), temp); // write new data

            printf("Tag '%s' updated to: %s\n", tag, new_value);
        }
        else
        {
            /* Copy original tag if not edited */
            fwrite(tag, 1, 4, temp);
            fwrite(size_bytes, 1, 4, temp);
            fwrite(flag, 1, 2, temp);
            fwrite(data, 1, size, temp);
        }
        free(data);
    }
    fclose(src);
    fclose(temp);
    /* Replace old file with new file */
    remove(filename);
    rename("temp.mp3", filename);
}
