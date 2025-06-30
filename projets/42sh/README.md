# 42sh

> "This isn’t just running commands. This is taming the terminal—with flair!"  

On this projet with the base of our `Minishell 2`, the goal is to recreat our shell base on the `TCSH`. By running multiple bult-in, that we are create.

---

## Features

- 🔧 Built-in and external commands 
  - Run standard shell commands or your own built-ins:
  - Exemple: `ls`, `cat`, `cd`, `exit`, `setenv`, `unsetenv`
- 🔗 Command chaining
Combine commands with:
  - `;` - sequential execution
  Example: `cd src; ls`
  - `|` – piping output between commands
  Examples: `cat file.txt | grep error`
  - `||` & `&&` – conditional execution
  Examples: `make && ./42sh`, `gcc file.c || echo "Compile failed"`
- Use file redirections:
  - `>` - overwrite a file
  Example: `echo "Hello" > file.txt`
  - `>>` - append to a file
  Example: `echo "More" >> file.txt`
  - `<` – read from a file
  Example: `sort < numbers.txt`
- 📜 Quoting and grouping
  - `'...'` – literal strings
  - `"..."` – interpolate variables
  - `(...)` – group commands
  Example: (cd src && make)
- Error handling
Proper handling of invalid commands, syntax errors, and return codes.

---

## Installation

1. Clone the repository:
   ```bash
   git clone git@github.com:EpitechPGEPromo2029/B-PSU-200-LIL-2-1-42sh-thomas.villot.git
   cd B-PSU-200-LIL-2-1-42sh-thomas.villot
   ```
2. Compile the project:
    ```bash
    make
    ```
3. Run the shell:
    ```bash
    ./42sh
    ```

## Example Usage

```bash
$> ls -l ; echo "Build complete"
$> cat main.c | grep "int"
$> echo "Hello World" > hello.txt
$> ./42sh && echo "Shell started"
$> false || echo "Previous command failed"
```

## Why?
This project was created as part of the Epitech curriculum to understand how a shell works internally — from parsing input to handling system calls and process management.


## Author
- Made with ❤️ by [@llosts](https://github.com/llosts)
- Made with ❤️ by [@ThomasVillot](https://github.com/ThomasVillot)
- Made with ❤️ by [@FloWindels](https://github.com/FloWindels)
- Made with ❤️ by [@yohandprt](https://github.com/yohandprt)
- Made with ❤️ by [@BaptisteVanBunderen](https://github.com/BaptisteVanBunderen)