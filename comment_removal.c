
#include "preprocessor.h"

void removeComments(FILE *fp, FILE *fd)
{
        int ch, next;

        while((ch = fgetc(fp)) != EOF)
        {
                if(ch == '/')
                {
                        next = fgetc(fp);

                        if(next == '/')
                        {
                                while((ch = fgetc(fp)) != EOF && ch != '\n');

                                if(ch == '\n')
                                        fputc('\n', fd);
                        }
                        else if(next == '*')
                        {
                                while((ch = fgetc(fp)) != EOF)
                                {
                                        if(ch == '*')
                                        {
                                                next = fgetc(fp);

                                                if(next == '/')
                                                        break;

                                                if(next != EOF)
                                                        ungetc(next, fp);
                                        }
                                }
                        }
                        else
                        {
                                fputc(ch, fd);

                                if(next != EOF)
                                        ungetc(next, fp);
                        }
                }
                else
                {
                        fputc(ch, fd);
                }
        }
}

