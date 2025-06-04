# 📄 get_next_line – Read a Line from a File Descriptor

**get_next_line** is a function designed to read a single line from a file descriptor, handling input efficiently and safely. This project will strengthen your understanding of buffer management, file I/O, and static variables in C.

---

## 🧠 Project Goals

- Master the use of **static variables**
- Work with file descriptors and `read()`
- Efficiently return lines of input one by one
- Handle edge cases like newlines, EOF, and varying buffer sizes

---

## 🔧 Function Prototype

```c
char *get_next_line(int fd);
```

- **Returns** the next line (including `\n` if present)
- Returns `NULL` on EOF or error
- Can be called repeatedly to read a file line-by-line

---

## 🛠️ Implementation Details

- Must use `read()`, `malloc()`, `free()`
- You **cannot** use your `libft` or `lseek()`
- No global variables allowed
- Must compile with: `-Wall -Wextra -Werror -D BUFFER_SIZE=n`

---

## 🧬 Example Integration

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void) {
    int fd = open("sample.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```
