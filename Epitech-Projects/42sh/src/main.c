/*
** EPITECH PROJECT, 2025
** B-PSU-200-LIL-2-1-42sh-thomas.villot
** File description:
** Main entry point for the 42sh program
*/

#include <stdlib.h>
#include <string.h>

#include "error.h"
#include "shell.h"
#include "environement.h"
#include "bash.h"
#include "alias.h"


int main(int argc, char const **argv, char const **envp)
{
    shell_state_t shell;

    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        display_help();
        return SUCCESS;
    }
    if (argc != 1 || envp == NULL)
        return print_error("Error: Invalid arguments\n", FAILURE);
    shell.alias_list = create_alias_list();
    shell.bash_env = create_bash_env();
    shell.env_list = init_env_list(envp);
    shell.last_exit_status = 0;
    start_minishell(&shell);
    free_env_list(shell.env_list);
    free_alias(shell.alias_list);
    return shell.last_exit_status;
}
