
# Simple Shell Project

## Project Description
This project is a collaborative assignment to build a basic UNIX command interpreter in C. The goal is to create a functional shell similar to sh (/bin/sh), focusing on system calls and core programming concepts.

## Team Members
- Ezekiel Gwamna
- Ugo Ogadi

## Repository
Clone this repository: `https://github.com/izzymarc/simple_shell.git`

## Installation
To use this shell:

1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/izzymarc/simple_shell.git
   ```
2. Navigate to the project directory:
   ```bash
   cd simple_shell
   ```
3. Compile the program using GCC:
   ```bash
   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
   ```
4. Run the shell:
   ```bash
   ./hsh
   ```

## Usage
Run the shell in interactive mode by typing `./hsh`. Type commands as in any standard shell. The shell can also be used in non-interactive mode by piping commands into it.

## Features
- Basic command line interpretation and execution.
- Handling built-in commands.
- Parsing user input.
- Error handling and reporting.

## Project Structure
- `main.c`: Main entry point.
- Other source files for specific functionalities.
- Header file with function prototypes and libraries.
- `README.md`: Project documentation.
- `AUTHORS`: Contributors to the project.

## Contributing
This project is part of the ALX Software Engineering program and is intended for educational purposes.

## Acknowledgments
- Julien Barbier and the ALX SE team for project guidelines.
- Collaborative efforts of team members.

## License
This project is for educational use only.

Here is a list of files for the "0x16. C - Simple Shell" project:

1. `AUTHORS` - The file listing all individuals who have contributed to the project.
2. `shell.h` - The header file for the Simple Shell.
3. `main.c` - The main C file containing the code for the Simple Shell.
4. `coulson_logs.c` - A C file related to logging in the shell.
5. `friday_info.c` - A C file containing information related to the shell.
6. `hammer_env_lookup.c` - A C file for environment variable lookup.
7. `happy_builtins.c` - A C file for handling built-in commands.
8. `hogan_path.c` - A C file for handling the PATH environment variable.
9. `jarvis_execute.c` - A C file for executing commands.
10. `jarvis_shutdown.c` - A C file for shutting down the shell.
11. `mj_initialize.c` - A C file for shell initialization.
12. `morgan_memory_adjust.c` - A C file for memory adjustments.
13. `obadiah_structs.c` - A C file containing data structures.
14. `pepper_commands.c` - A C file for handling shell commands.
15. `pepper_env.c` - A C file for environment-related functions.
16. `potts_variables.c` - A C file for managing variables.
17. `rhodey_lists.c` - A C file for linked lists.
18. `rhodey_parse.c` - A C file for parsing.
19. `stane_faults.c` - A C file for handling faults.
20. `stark_input_line.c` - A C file for input handling.
21. `stark_parse_int.c` - A C file for parsing integers.
22. `stark_prompt.c` - A C file for the shell prompt.
23. `yinsen_errors.c` - A C file for handling errors.
24. `.simple_shell_history` - The history file for the shell's command history.
25. `man_1_simple_shell` - The manual page for the Simple Shell.
26. `README.md` - The README file containing information about the project.

These files collectively make up the Simple Shell project, containing various components and functionalities of the shell.
