#ifdef __EMSCRIPTEN__
#include <stdio.h>
#include <emscripten.h>

#define POLL_RATE 100

int has_line(void) {
    return EM_ASM_INT_V(
        if (fifo.line) {
            // TODO: move this somewhere more appropriate
            fifo.line = false;
            return 1;
        } else
            return 0;
    );
}

int has_char(void) {
    return EM_ASM_INT_V(
        if (fifo.data.length > 0) {
            return 1;
        } else
            return 0;
    );
}

void wait_for_line(void) {
    while (1) {
        if (has_line()) {
            break;
        }
        emscripten_sleep(POLL_RATE);
    }
}

void wait_for_char(void) {
    while (1) {
        if (has_char()) {
            break;
        }
        emscripten_sleep(POLL_RATE);
    }
}

char *fgets_async(char *s, int size, FILE *stream) {
    if (stream == stdin) {
        wait_for_line();
    }
    return fgets(s, size, stream);
}

int fgetc_async(FILE *stream) {
    if (stream == stdin) {
        wait_for_char();
    }
    return fgetc(stream);
}

int getc_async(FILE *stream) { return fgetc_async(stream); }
int getchar_async(void) { return fgetc_async(stdin); }
#endif
