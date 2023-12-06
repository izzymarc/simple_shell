
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

