#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#endif

void removeComments(FILE *fp, FILE *fd);
void fileInclusion(FILE *fp, FILE *fd);
void macroHandler(FILE *fp, FILE *fd);
