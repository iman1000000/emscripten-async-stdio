# emscripten-async-stdio

Asynchronous replacement for stdio input functions for Emscripten and Terminal.js

Far from a complete solution, but functional.

## Usage

First, install Terminal.js:
```
npm install
```
Replace all includes of `<stdio.h>` with `"stdio_async.h"`.

Finally, compile your project with Emscripten to a.out.js, and open example.html.
NOTE: Must be compliled with EMTERPRETIFY and EMTERPRETIFY_ASYNC enabled.
See makefile for details.

## How it works

Using Emterpreter, execution of the C code can be paused without track of what
function is running. Whenever the C code blocks waiting for input, a polling
loop is set up to check if the input has arrived, and sleep for a short time if
is has not. This approach takes a fair bit of CPU depending on the polling
interval, but works better than blocking the whole Javascript execution thread.
The rest is simple plumbing and buffering for Terminal.js

## Known issues
  * Backspace and other special characters are not handled
  * Output only displays after a newline
  * Probably many more
