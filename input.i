
#include <stdio.h>
#ifndef PREPROCESSOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#endif

void removeComments(FILE *fp, FILE *fd);
void fileInclusion(FILE *fp, FILE *fd);
void macroHandler(FILE *fp, FILE *fd);





int main()
{
        float a = 3.14;
        int b = 100;

        
        printf("PI = %f\n", a);
        printf("NUM = %d\n", b);

        return 0;
}

