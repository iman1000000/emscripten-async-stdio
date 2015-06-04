#include <stdio.h>

#ifdef __EMSCRIPTEN__
int getc_async(FILE *stream);
int getchar_async(void);
int fgetc_async(FILE *stream);
char *fgets_async(char *s, int size, FILE *stream);

#define getc getc_async
#define getchar getchar_async
#define fgetc fgetc_async
#define fgets fgets_async

#endif
