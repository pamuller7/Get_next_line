*this project has been created as part of the 42 curriculum by <pamuller>*

DESCRIPTION :
this project is an implementation of get_next_line, a function that return a line -ending with a newline or the end of file- read from a file descriptor (either from a file or from standard input)

INSTRUCTIONS :
no main included, but it be provided upon request.
the program must be compiled with the following flags :
sh : cc -Wall -Werror -Wextra

to change the BUFFER_SIZE, which defines the number of bytes read by the function, add :
sh : -D BUFFER_SIZE=wanted-size
after the compiler command.

EXPLENATION :
due to a risk of memory leak, the static is defined by BUFFER_SIZE as well, causing a timeout in some cases but no leaks if the file is not read until the end.

RESSOURCES :
open, read functions : https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/
man pages
No AI used