# Mini Grep (C Implementation)

A lightweight implementation of the Linux `grep` command, written in C.
## What it does
It takes two files as input:
1. A **pattern file** (containing words/lines to search for).
2. A **source file** (the text to search in).
## Key Features
- **Memory Efficient:** Uses constant memory O(1). It reads files line-by-line using a fixed buffer, so it works even with huge files without using up RAM.
- **Pure C:** No use of the `system()` call. Everything is handled via standard I/O libraries.
- **Clean:** Proper memory allocation and deallocation (no memory leaks).

## How to Compile
You need `gcc` installed. Run this command in the terminal:

```bash
gcc -Wall -Wextra -o mygrep mygrep.c

How to Run
Syntax: ./grep <pattern_file> <search_file>
Example
1. Create some test files

echo "apple" > patterns.txt
echo "I like apple pie." > text.txt
echo "I like bananas." >> text.txt

2. Run the program
./grep pattern.txt text.txt

3.Output
I like apple pie.
