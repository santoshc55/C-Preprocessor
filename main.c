
#include "preprocessor.h"

int main(int argc, char **argv)
{
        FILE *fp, *fd, *temp, *temp2;
        char output[100];
        char *p;
        int i;

        if(argc != 2)
        {
                printf("Usage: ./mypreprocessor filename\n");
                return 1;
        }

        fp = fopen(argv[1], "r");

        if(fp == 0)
        {
                printf("Source file not present\n");
                return 1;
        }

        p = strrchr(argv[1], '.');

        if(p != 0)
        {
                i = p - argv[1];

                if(i > 97)
                {
                        printf("Filename too long\n");
                        fclose(fp);
                        return 1;
                }

                strncpy(output, argv[1], i);
                output[i] = '\0';
                strcat(output, ".i");
        }
        else
        {
                if(strlen(argv[1]) > 97)
                {
                        printf("Filename too long\n");
                        fclose(fp);
                        return 1;
                }

                strcpy(output, argv[1]);
                strcat(output, ".i");
        }

        fd = fopen(output, "w");

        if(fd == 0)
        {
                printf("Output file not created\n");
                fclose(fp);
                return 1;
        }

        printf("Source file opened successfully\n");
        printf("Output file created: %s\n", output);

        temp = tmpfile();
        temp2 = tmpfile();

        if(temp == 0 || temp2 == 0)
        {
                printf("Temporary file not created\n");

                if(temp != 0)
                        fclose(temp);

                if(temp2 != 0)
                        fclose(temp2);

                fclose(fp);
                fclose(fd);
                return 1;
        }

        /* Step 1: File Inclusion */
        fileInclusion(fp, temp);

        rewind(temp);

        /* Step 2: Comment Removal */
        removeComments(temp, temp2);

        rewind(temp2);

        /* Step 3: Macro Substitution */
        macroHandler(temp2, fd);

        fclose(temp);
        fclose(temp2);
        fclose(fp);
        fclose(fd);

        printf("Preprocessing completed successfully\n");

        return 0;
}

