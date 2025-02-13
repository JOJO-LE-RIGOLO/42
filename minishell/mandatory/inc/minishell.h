/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:01:53 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/12 20:23:17 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define Hello "\033[31m[\033[34mminishell>\033[31m]\033[0m "
# define PATH_MAX 4096
# define CLEAR_LINE "\033[2K\r"
# define CURSOR_FORWARD "\033[C"
# define CURSOR_BACKWARD "\033[D"

# include "../../Utils/libft/libft.h"
# include "../../Utils/ft_printf/ft_printf.h"
# include "../../Utils/get_next_line/get_next_line_bonus.h"

# include <stdio.h>          // printf, perror
# include <stdlib.h>         // malloc, free, getenv, exit
# include <unistd.h>         // write, access, read, close, fork, getcwd, chdir, pipe, isatty, ttyslot
# include <readline/readline.h> // readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay
# include <readline/history.h>  // add_history
# include <fcntl.h>          // open
# include <sys/wait.h>       // wait, waitpid, wait3, wait4
# include <signal.h>         // signal, sigaction, sigemptyset, sigaddset, kill
# include <sys/stat.h>       // stat, lstat, fstat
# include <dirent.h>         // opendir, readdir, closedir
# include <string.h>         // strerror
# include <termios.h>        // tcsetattr, tcgetattr
# include <sys/ioctl.h>      // ioctl
# include <curses.h>         // tgetent, tgetflag, tgetnum, tgetstr
# include <term.h>           // tgoto, tputs

/* Structure qui va tout recuperer et pour executer */
typedef struct s_tree
{
    char            *path;
    char            **args;
    char            **env;
    char            *file1;
    char            redirections[2];
    int                     mod;
    struct s_tree *tleft;
    struct s_tree *tright;
    struct s_tree *parent;
}           t_tree;

typedef struct s_commands
{
    t_tree  *root;
    int     i;
    struct s_commands   *next;
}           t_commands;

/* Structure pour l'Historique et le terminal */
typedef struct s_historique
{
    char    *line;
    struct s_historique *next;
    struct s_historique *prev;
}           t_historique;

typedef struct 
{
    t_historique *head;
    t_historique *tail;
    t_historique *current;
}           t_history;

/* Fonctions pour les signaux */
void    setup_signals(void);
void    sigquit_handler(int signum);
void    handle_signals(int signum);

/* Fonctions pour l'Historique et le Terminal */
char    *ft_readline(t_history *history);
void    init_history(t_history *history);
void    ft_rl_clear_history(t_history *history);
void    ft_rl_on_new_line(void);
void    ft_rl_replace_line(const char *new_line);
void    ft_rl_redisplay(void);
void    print_line(const char *line);
void    ft_add_history(t_history *history, const char *line);
void    disableRawMode(void);
void    enableRawMode(void);

/* Fonctions de Parsing */
t_commands  *ft_ultimate_parse(char *line, char **envp);
t_commands	*ft_lstnew(char **args, char **envp);
t_commands	*ft_lstlast(t_commands *lst);
void        ft_lstadd_back(t_commands **lst, t_commands *new);
void        ft_lstclear(t_commands **lst);
void        ft_verif(t_commands **list, char *str);
char        *ft_find_cmd(char *cmd);

/* Fonctions pour Executer */

/* Utils */
void        msg_error(char *why);
void        ft_cleartab(char **args);

#endif