_This project has been created as part of the 42 curriculum by gpires-c_

# Libft

## Description
**Libft** is the foundational project of the 42 school curriculum. The goal of this project is to re-code a subset of standard C library (libc) functions, as well as additional utility functions that will be used throughout future projects in the 42 journey. 

By rebuilding these essential capabilities from scratch, this project provides a deep understanding of memory allocation, pointer manipulation, and data structure management in C. The resulting library is compiled into a `.a` static library file, ready to be linked with other C programs.

---

## Instructions

### Prerequisites
To compile and use this library, you need a C compiler (`gcc` or `clang`) and <a href="https://www.gnu.org/software/make/" target="_blank">GNU Make</a>. installed on your system.

### Compilation

* **Compile functions:**
    ```bash
    make
    ```
    This compiles the source files and creates the static library `libft.a`.

* **Clean object files (.o):**
    ```bash
    make clean
    ```

* **Full clean:**
    ```bash
    make fclean
    ```
    Removes all object files as well as the compiled `libft.a` library.

* **Recompile from scratch:**
    ```bash
    make re
    ```
    Executes `fclean` and `make` consecutively to fully rebuild the library.

* **Execution / Usage**
	To use `libft.a` in your own projects, include the header file `libft.h` in your source code files and link the library during compilation:

	```c
	#include "libft.h"
	```
Compile your program along with the library like this
```bash
gcc your_main_file.c -L. -lft -o my_program
```
## Resources

Here is a collection of standard documentation references, tutorials, and materials used during development:

    Linux Man Pages (man3/printf, man3/memset, etc.) — The definitive reference for standard C libraries and system behaviors.
- <a href="https://www.gnu.org/software/make/" target="_blank">GNU Make</a>
 - <a href="https://www.gnu.org/software/libc/" target="_blank">Libc</a>
  - <a href="https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_C_libraries.html" target="_blank">Creating and using libraries in a C program</a>


## IMPLEMENTED FUNCTIONS

### Libc Functions

These functions are re-implementations of standard C library functions, offering identical behavior and prototypes to their original counterparts.

    int ft_isalpha(int c); — Checks if the character is alphabetic.

    int ft_isdigit(int c); — Checks if the character is a digit (0-9).

    int ft_isalnum(int c); — Checks if the character is alphanumeric.

    int ft_isascii(int c); — Checks if the character fits in the ASCII character set.

    int ft_isprint(int c); — Checks for any printable character.

    size_t ft_strlen(const char *str); — Calculates the length of a string.

    void *ft_memset(void *buffer, int c, size_t size); — Fills a block of memory with a specified byte value.

    void ft_bzero(void *buffer, size_t size); — Erases the data in the memory block by writing zeroes (\0) to it.

    void *ft_memcpy(void *dest, const void *src, size_t n); — Copies n bytes from memory area src to memory area dest (non-overlapping areas).

    void *ft_memmove(void *dest, const void *src, size_t n); — Copies n bytes from memory area src to memory area dest (handles overlapping areas safely).

    size_t ft_strlcpy(char *dest, const char *src, size_t n); — Size-bounded string copying.

    size_t ft_strlcat(char *dest, const char *src, size_t size); — Size-bounded string concatenation.

    int ft_toupper(int c); — Converts a lower-case letter to uppercase.

    int ft_tolower(int c); — Converts an upper-case letter to lowercase.

    char *ft_strchr(const char *str, int c); — Locates the first occurrence of a character in a string.

    char *ft_strrchr(const char *str, int c); — Locates the last occurrence of a character in a string.

    int ft_strncmp(const char *str1, const char *str2, size_t n); — Compares two strings up to n bytes.

    void *ft_memchr(const void *s, int c, size_t n); — Scans a memory block for a specific byte.

    int ft_memcmp(const void *s1, const void *s2, size_t n); — Compares two memory blocks byte by byte.

    char *ft_strnstr(const char *big, const char *little, size_t n); — Locates a substring inside a larger string, bounded by length.

    int ft_atoi(const char *str); — Converts an ASCII string representing an integer into an actual int.

    void *ft_calloc(size_t nmemb, size_t size); — Allocates memory for an array and initializes all bytes to zero.

    char *ft_strdup(const char *str); — Duplicates a string by allocating dynamic memory for it.

### Additional Functions

These are utility functions that either complement standard libc behavior or provide specific string and output manipulations.

    char *ft_substr(char const *s, unsigned int start, size_t len); — Allocates and returns a substring from string s.

    char *ft_strjoin(char const *s1, char const *s2); — Allocates and returns a new string resulting from the concatenation of s1 and s2.

    char *ft_strtrim(char const *s1, char const *set); — Allocates and returns a copy of s1 with characters specified in set removed from the beginning and end.

    char ft_split(char const *s, char c); — Allocates and returns an array of strings obtained by splitting s using the character c as a delimiter.

    char *ft_itoa(int n); — Allocates and returns a string representing the integer passed as an argument.

    char *ft_strmapi(char const *s, char (*f)(unsigned int, char)); — Applies a function f to each character of string s to create a new string.

    void ft_striteri(char *s, void (*f)(unsigned int, char*)); — Applies a function f to each character of string s, passing its index and address to allow modification.

    void ft_putchar_fd(char c, int fd); — Outputs the character c to the given file descriptor.

    void ft_putstr_fd(char *s, int fd); — Outputs the string s to the given file descriptor.

    void ft_putendl_fd(char *s, int fd); — Outputs the string s followed by a newline to the given file descriptor.

    void ft_putnbr_fd(int n, int fd); — Outputs the integer n to the given file descriptor.

### Linked list

These functions allow the creation and manipulation of dynamic elements using a singly linked list structure defined as:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```
    t_list *ft_lstnew(void *content); — Allocates and returns a new node with the specified content.

    void ft_lstadd_front(t_list lst, t_list *new); — Adds the node new at the beginning of the list.

    int ft_lstsize(t_list *lst); — Counts the number of nodes in a list.

    t_list *ft_lstlast(t_list *lst); — Returns the last node of the list.

    void ft_lstadd_back(t_list lst, t_list *new); — Adds the node new at the end of the list.

    void ft_lstdelone(t_list *lst, void (*del)(void *)); — Frees the memory of a node's content using the del function, then frees the node itself.

    void ft_lstclear(t_list lst, void (*del)(void *)); — Deletes and frees a given node and every successor node using del and free.

    void ft_lstiter(t_list *lst, void (*f)(void *)); — Iterates over the list and applies the function f to the content of each node.

    t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)); — Iterates a list, applies f to the content of each node, and creates a new list from the results.


### AI Assistance Reference

    Gemini AI — This comprehensive documentation (README.md) was written and structured by Gemini.
