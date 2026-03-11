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
/* Function to view the mp3 tags */
void mp3_view(char *filename)
{
    FILE *fp = fopen(filename, "rb"); // open file in read mode
    if (fp == NULL)
    {
        printf("Error: Cannot open file %s\n", filename);
        return;
    }
    char header[3];
    fread(header, 1, 3, fp); // read first 3 bytes (should be "ID3")
    if (strncmp(header, "ID3", 3) != 0) // check header
    {
        printf("Not a valid MP3 file.\n");
        fclose(fp);
        return;
    }
    printf("------------------- MP3 TAG DETAILS -------------------\n");
    /* Define all tag IDs and names */
    char tags[6][5] = {"TIT2", "TPE1", "TALB", "TYER", "TCON", "COMM"};
    char names[6][10] = {"Title", "Artist", "Album", "Year", "Genre", "Comment"};
    /* Loop through all 6 tags */
    for (int i = 0; i < 6; i++)
    {
        fseek(fp, 10, SEEK_SET); // Skip 10-byte header
        unsigned char tag[5] = {0}, size_bytes[4], flag[2];
        int found = 0;
        /* Read every tag block one by one */
        while (fread(tag, 1, 4, fp))
        {
            fread(size_bytes, 1, 4, fp); // read tag size
            fread(flag, 1, 2, fp);       // read flag
            int size = bytes_to_int(size_bytes);
            /* If tag matches */
            if (strcmp((char *)tag, tags[i]) == 0)
            {
                char *data = malloc(size);
                fread(data, 1, size, fp);
                printf("%-8s: %s\n", names[i], data + 1); // skip first encoding byte
                free(data);
                found = 1;
                break;
            }
            else
            {
                fseek(fp, size, SEEK_CUR); // skip data if not matching
            }
        }
        /* If tag not found */
        if (!found)
            printf("%-8s: Not found\n", names[i]);
    }
    printf("-------------------------------------------------------\n");
    fclose(fp);
}
