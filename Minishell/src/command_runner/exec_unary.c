/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:11:16 by mmeuric           #+#    #+#             */
/*   Updated: 2025/04/01 00:28:12 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <command_runner.h>

void	exit_if_forked(bool forked)
{
	if (forked)
		exit(get_exit_status());
	return ;
}

static	void	wait_and_exit_status(int pid)
{
	int	exit_status;

	waitpid(pid, &exit_status, 0);
	set_exit_status(WEXITSTATUS(exit_status));
	if (WIFSIGNALED(exit_status) == 1)
	{
		if (WTERMSIG(exit_status) == 3)
			ft_putendl_fd("Quit : 3", 2);
		set_exit_status(128 + exit_status);
	}
}

void	exec_redir(t_ast_redir *tree, bool forked)
{
	int		fd_to_dup;
	int		fd_backup;
	char	*file_name;

	file_name = check_file_tok(tree->file_tok);
	if (!file_name)
		return (exit_if_forked(forked));
	fd_to_dup = open(file_name, tree->mode, 0644);
	if (fd_to_dup < 0)
		return (print_err(file_name, 0), set_exit_status(1),
			exit_if_forked(forked));
	else
	{
		fd_backup = dup(tree->fd);
		if (fd_to_dup != tree->fd)
		{
			dup2(fd_to_dup, tree->fd);
			close(fd_to_dup);
		}
		set_exit_status(0);
	}
	(free(file_name), executor(tree->cmd, forked));
	if (fd_backup != tree->fd)
		(dup2(fd_backup, tree->fd), close(fd_backup));
}

void	exec_exe(t_ast_exec *exe, bool forked)
{
	char	**argv;
	pid_t	pid;
	t_env	*envp;

	argv = expand_args(exe->argv_tok);
	log_last_command(argv[split_len(argv) - 1]);
	envp = get_envp(NULL);
	if (check_builtins(split_len(argv) - 1, argv[0], argv + 1))
	{
		exit_if_forked(forked);
		return (free_list(argv));
	}
	if (!forked)
		pid = ft_fork();
	if (forked || !pid)
	{
		reset_default_sig_handlers();
		print_err(argv[0], execute_cmd(argv, envp));
		exit(get_exit_status());
	}
	wait_and_exit_status(pid);
	free_list(argv);
	exit_if_forked(forked);
}

void	exec_subsh(t_ast_subsh *tree, bool forked)
{
	pid_t	pid;
	int		exit_status;

	pid = ft_fork();
	if (!pid)
		executor(tree->cmd, true);
	waitpid(pid, &exit_status, 0);
	set_exit_status(WEXITSTATUS(exit_status));
	if (forked)
		exit(get_exit_status());
}
