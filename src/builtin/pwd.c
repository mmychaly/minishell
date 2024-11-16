#include "../../include/minishell.h"

void	pwd(t_data *data)
{
	char *buffer;
	int	len;
	int	i;

	i = 0;
	if (data->nb_pipe != 0)//Закрываем в составной команде
		close_input(data);

	while (ft_strnstr(data->envp[i], "PWD", 3) == 0)
		i++;
	len = ft_strlen(data->envp[i]);
	len -= 3;
	buffer = malloc(sizeof(char) * len);
	if (buffer == NULL)
	{
		write(2, "Error malloc pwd\n", 17);
		if (data->nb_pipe == 0)
		{
			data->back_in_main = 1;
			data->exit_status = 1;
			return ;
		}
		else
		{
//			close(1); нужно или нет ?
			free_all_data(data);
			rl_clear_history();
			exit (1);
		}	
	}
	if (getcwd(buffer, len) != NULL) 
        printf("%s\n", buffer);
	else 
	{
        write(2, "Error getcwd\n", 13);
		free(buffer);
		if (data->nb_pipe == 0)
		{
			data->back_in_main = 1;
			data->exit_status = 1;
			return ;
		}
		else
		{
//			close(1);
			free_all_data(data);
			rl_clear_history();
			exit (1) ;
		}	
    }
	free(buffer);
	if (data->nb_pipe == 0)
	{
		data->back_in_main = 1;
		data->exit_status = 0;
		return ;
	}
	else
	{
//		close(1);
		free_all_data(data);
		rl_clear_history();
		exit (0) ;
	}
}