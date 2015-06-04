example: example.c stdio_async.c stdio_async.h
	emcc -s EMTERPRETIFY=1 -s EMTERPRETIFY_ASYNC=1 example.c stdio_async.c
