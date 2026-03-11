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
/* Function to print error and usage message */
void print_error_message(int argc, char *argv[])
{
    printf("-------------------------------------------------------\n");
    printf("ERROR: %s : INVALID ARGUMENTS\n", argv[0]);
    printf("USAGE :\n");
    printf("To view please pass like: ./a.out -v mp3filename\n");
    printf("To edit please pass like: ./a.out -e -t/-a/-A/-y/-C/-c new_content mp3filename\n");
    printf("-------------------------------------------------------\n");
}
/* Function to print help message */
void print_help(void)
{
    printf("Usage : mp3tag -[taAyCc] 'value' file_name\n");
    printf("        mp3tag -v\n");
    printf("-t Modifies a Title tag\n");
    printf("-a Modifies a Artist tag\n");
    printf("-A Modifies a Album tag\n");
    printf("-y Modifies a Year tag\n");
    printf("-C Modifies a Genre tag\n");
    printf("-c Modifies a Comment tag\n");
}
/* Main function */
int main(int argc, char *argv[])
{
    /* Check number of arguments */
    if (argc < 2)
    {
        print_error_message(argc, argv);
        return 0;
    }
    /* If user gives help option */
    if (strcmp(argv[1], "--help") == 0)
    {
        print_help();
    }
    /* If user gives view option */
    else if (strcmp(argv[1], "-v") == 0)
    {
        if (argc != 3)
            print_error_message(argc, argv);
        else
            mp3_view(argv[2]);
    }
    /* If user gives edit option */
    else if (strcmp(argv[1], "-e") == 0)
    {
        if (argc != 5)
            print_error_message(argc, argv);
        else
            mp3_edit(argv[2], argv[3], argv[4]);
    }
    /* For invalid arguments */
    else
    {
        print_error_message(argc, argv);
    }
    return 0;
}
