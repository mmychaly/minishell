/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmychaly <mmychaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:47:25 by artemii           #+#    #+#             */
/*   Updated: 2024/11/22 03:56:13 by mmychaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void ft_redirection_in(t_data *data)
{
    int fd_in;
    printf("ft_redirection_in \n");
    if(data->prev_pipe != -1)
    {
        free_pipe(data->prev_pipe);
		close(data->prev_pipe);
    }
    if(data->cmd[data->i]->here_doc_pfd != 0)
    {
        free_pipe(data->cmd[data->i]->here_doc_pfd);
		close(data->cmd[data->i]->here_doc_pfd);
        data->cmd[data->i]->here_doc_pfd = 0;
    }
    if (data->i != data->nb_pipe)
        close(data->pipefd[0]);
    fd_in = open(data->cmd[data->i]->input_file, O_RDONLY, 0644);
    if (fd_in == -1)
    {
        perror("Error opening input file");
        if (data->i != data->nb_pipe)
            close(data->pipefd[1]);
        if (data->nb_pipe == 0 && data->builtin_cmd == 1)
	    {
            printf("ft_redirection_in in if return\n");
    		data->back_in_main = 1;
    		data->exit_status = 1;
    		return ;
    	}
    	else
    	{
    		free_all_data(data);
    		rl_clear_history();
    		exit (EXIT_FAILURE) ;
	    }
    }
    if (data->nb_pipe == 0 && data->builtin_cmd == 1)
        close(fd_in);
    else
    {
        printf("befor (dup2(fd_in, STDIN_FILENO))\n");
        if (dup2(fd_in, STDIN_FILENO) == -1)
        {
        perror("Error duplicating file descriptor for input");
        if (data->i != data->nb_pipe)
            close(data->pipefd[1]);
        close(fd_in);
        free_all_data(data);
        rl_clear_history();
        exit(EXIT_FAILURE);
        }
        close(fd_in); // Закрываем дескриптор файла после перенаправления
        data->flag_pipe = 0;
    }
}

void	ft_redirection_here_doc(t_data *data)
{
    int fd_in;
    
    printf("in ft_redirection_here_doc\n");
    if(data->prev_pipe != -1)
    {
        free_pipe(data->prev_pipe);
		close(data->prev_pipe);
    }
    if (data->i != data->nb_pipe)
    {
        close(data->pipefd[0]);
    }
    if (data->cmd[data->i]->input_file != NULL)
    {
        fd_in = open(data->cmd[data->i]->input_file, O_RDONLY, 0644);
        if (fd_in == -1)
        {
            perror("Error opening input file");
            free_pipe(data->cmd[data->i]->here_doc_pfd);
		    close(data->cmd[data->i]->here_doc_pfd);
            data->cmd[data->i]->here_doc_pfd = 0;
            if (data->i != data->nb_pipe)
                close(data->pipefd[1]);
            if (data->nb_pipe == 0 && data->builtin_cmd == 1)
	        {
                printf("ft_redirection_here_doc in if return\n");
    		    data->back_in_main = 1;
    		    data->exit_status = 1;
    		    return ;
    	    }
    	    else
    	    {
           		free_all_data(data);
        		rl_clear_history();
                exit (EXIT_FAILURE) ;
	        }
        }
        close(fd_in);
    }
    if (data->nb_pipe == 0 && data->builtin_cmd == 1)
    {
        free_pipe(data->cmd[data->i]->here_doc_pfd);
    	close(data->cmd[data->i]->here_doc_pfd);
        data->cmd[data->i]->here_doc_pfd = 0;
    }
    else
    {
        printf("befor dup2(data->cmd[data->i]->here_doc_pfd, STDIN_FILENO) // data->builtin_cmd == %i\n", data->builtin_cmd);
	    if (dup2(data->cmd[data->i]->here_doc_pfd, STDIN_FILENO) == -1)
	    {
    		perror("Error: dup2 prev_pipe");
    		free_pipe(data->cmd[data->i]->here_doc_pfd);
    		close(data->cmd[data->i]->here_doc_pfd);
            data->cmd[data->i]->here_doc_pfd = 0;
            if (data->i != data->nb_pipe)
                close(data->pipefd[1]);
            free_all_data(data);
            rl_clear_history();
    		exit (EXIT_FAILURE);
	    }
        close(data->cmd[data->i]->here_doc_pfd);
        data->cmd[data->i]->here_doc_pfd = 0;
        data->flag_pipe = 1;
    }
}

void	ft_redirection_pipe(t_data *data)
{
    printf("in ft_redirection_pipe\n");
    if (data->i != data->nb_pipe)
        close(data->pipefd[0]);
    if (dup2(data->prev_pipe, STDIN_FILENO) == -1)
	{
		perror("Error: dup2 prev_pipe");
		free_pipe(data->prev_pipe);
		close(data->prev_pipe);
        if (data->i != data->nb_pipe)
            close(data->pipefd[1]);
        free_all_data(data);
        rl_clear_history();
		exit (EXIT_FAILURE);
	}
	close(data->prev_pipe);
    data->flag_pipe = 1;
}

void	ft_redirection_out_cmd(t_data *data)
{
    printf("ft_redirection_out_cmd\n");
	int	fd_out;
    if (data->nb_pipe == 0 && data->builtin_cmd == 1 && data->display_builtin_cmd == 1)//Сохраняем стандартный канал вывода
        data->std_out = dup(1);
    if (data->i != data->nb_pipe)
    {
        close(data->pipefd[1]);
    }
	if (data->cmd[data->i]->pos_append > data->cmd[data->i]->pos_output)
    {
        if (data->cmd[data->i]->output_file != NULL)
        {
            fd_out = open(data->cmd[data->i]->output_file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
            if (fd_out == -1)
            {
                perror("Error opening output file");
                if (data->flag_pipe > 0)
                    free_pipe(0);
                if (data->std_out != 0)
                    close(data->std_out);
                if (data->nb_pipe == 0 && data->builtin_cmd == 1)
	            {
    		        data->back_in_main = 1;
    		        data->exit_status = 1;
    	            return ;
                }
	            else    	            
                {
           		    free_all_data(data);
        		    rl_clear_history();
                    exit (EXIT_FAILURE);
	            }
            }
            close(fd_out);
        }
		fd_out = open(data->cmd[data->i]->append_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
    }
	else
    {
        if (data->cmd[data->i]->append_file != NULL)
        {
            fd_out = open(data->cmd[data->i]->append_file, O_WRONLY | O_CREAT | O_APPEND, 0644);;
            if (fd_out == -1)
            {
                perror("Error opening output file");
                if (data->flag_pipe > 0)
                    free_pipe(0);
                if (data->std_out != 0)
                    close(data->std_out);
                if (data->nb_pipe == 0 && data->builtin_cmd == 1)
	            {
    		        data->back_in_main = 1;
    		        data->exit_status = 1;
    	            return ;
                }
	            else    	            
                {
           		    free_all_data(data);
        		    rl_clear_history();
                    exit (EXIT_FAILURE);
	            }
            }
            close(fd_out);
        }
		fd_out = open(data->cmd[data->i]->output_file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
    }
	if (fd_out == -1)
    {
        perror("Error opening output file");
        if (data->flag_pipe > 0)
             free_pipe(0);
        if (data->std_out != 0)
            close(data->std_out);
        if (data->nb_pipe == 0 && data->builtin_cmd == 1)
	    {
    		data->back_in_main = 1;
    		data->exit_status = 1;
    	    return ;
        }
	    else    	            
        {
           	free_all_data(data);
        	rl_clear_history();
            exit (EXIT_FAILURE);
	    }
    }
    if (data->nb_pipe == 0 && data->builtin_cmd == 1 && data->display_builtin_cmd != 1)
        close(fd_out);
    else
    {
         printf("befor dup2(fd_out, STDOUT_FILENO)\n");
	    if (dup2(fd_out, STDOUT_FILENO) == -1)
	    {
		    perror("dup2 fd_out");
            if (data->flag_pipe > 0)
		      free_pipe(0);
		    close(fd_out);
            if (data->std_out != 0)
                close(data->std_out);
            if (data->nb_pipe == 0 && data->builtin_cmd == 1 && data->display_builtin_cmd == 1)
            {
                data->back_in_main = 1;
    		    data->exit_status = 1;
    	        return ;
            }
            free_all_data(data);
            rl_clear_history();
		    exit (EXIT_FAILURE);
	    }
        close(fd_out);
    }
}

void    ft_redirection_out_pipe(t_data *data)
{
    printf("in ft_redirection_out_pipe\n");
    if (dup2(data->pipefd[1], STDOUT_FILENO) == -1)
	{
		perror("Error: dup2 pipefd[1]");
        if (data->flag_pipe > 0)
		    free_pipe(0);
		close(data->pipefd[1]);
        free_all_data(data);
        rl_clear_history();
		exit (EXIT_FAILURE);
	}
    close(data->pipefd[1]);
}
