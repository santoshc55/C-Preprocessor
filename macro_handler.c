
#include "preprocessor.h"

void macroHandler(FILE *fp, FILE *fd)
{
        char line[1024];
        char name[50], value[100];
        char word[50];
        char macro_name[50][50];
        char macro_value[50][100];
        int count = 0;
        int i, j, k, r;

        while(fgets(line, sizeof(line), fp))
        {
                r = sscanf(line, " #define %49s %99[^\n]", name, value);

                if(strncmp(line, "#define", 7) == 0)
                {
                        if(r == 2 && count < 50)
                        {
                                strcpy(macro_name[count], name);
                                strcpy(macro_value[count], value);
                                count++;
                        }

                        continue;
                }

                i = 0;

                while(line[i] != '\0')
                {
                        if(line[i] == '"' || line[i] == '\'')
                        {
                                char quote = line[i];

                                fputc(line[i], fd);
                                i++;

                                while(line[i] != '\0')
                                {
                                        fputc(line[i], fd);

                                        if(line[i] == '\\' && line[i+1] != '\0')
                                        {
                                                i++;
                                                fputc(line[i], fd);
                                        }
                                        else if(line[i] == quote)
                                        {
                                                i++;
                                                break;
                                        }

                                        i++;
                                }
                        }
                        else if(isalpha((unsigned char)line[i]) || line[i] == '_')
                        {
                                j = 0;

                                while(isalnum((unsigned char)line[i]) || line[i] == '_')
                                {
                                        if(j < 49)
                                                word[j++] = line[i];

                                        i++;
                                }

                                word[j] = '\0';

                                for(k = 0; k < count; k++)
                                {
                                        if(strcmp(word, macro_name[k]) == 0)
                                                break;
                                }

                                if(k < count)
                                        fputs(macro_value[k], fd);
                                else
                                        fputs(word, fd);
                        }
                        else
                        {
                                fputc(line[i], fd);
                                i++;
                        }
                }
        }
}

