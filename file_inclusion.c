
#include "preprocessor.h"

void fileInclusion(FILE *fp, FILE *fd)
{
        FILE *hf;
        char line[1024];
        char filename[100];
        int ch, r;

        while(fgets(line, sizeof(line), fp))
        {
                r = sscanf(line, " #include \"%99[^\"]\"", filename);

                if(r != 1)
                        r = sscanf(line, " #include <%99[^>]>", filename);

                if(r == 1)
                {
                        hf = fopen(filename, "r");

                        if(hf == 0)
                        {
                                fputs(line, fd);
                                continue;
                        }

                        while((ch = fgetc(hf)) != EOF)
                        {
                                fputc(ch, fd);
                        }

                        fclose(hf);
                }
                else
                {
                        fputs(line, fd);
                }
        }
}

