#include "../includes/filler.h"
int	get_number(char *l)
{
	int	i;

	i = 0;
	while (l[i] && !ft_isdigit(l[i]))
		i++;
	if (ft_isdigit(l[i]))
		return (i);
	return (-1);
}
int	ft_plat(char *l)
{
	int	x;

	if ((x = get_number(l)) == -1)
		exit(1);
	x = ft_atoi(&l[x]);
	return (x);
}

void	print_line(char *l)
{
	int	i;

	i = 0;
	while (l[i])
	{
		l[i] == 'O' ? printf("%s", RED): 0;
		l[i] == 'X' ? printf("%s", GREEN): 0;
		l[i] == 'o' || l[i] == 'x' ? printf("%s", YELLOW): 0;
		l[i] == '.' ? printf("%s", DEF): 0;
		l[i++] == '.' ? printf(".") : printf("#");
	}
	printf("%s\n", DEF);
}

void	print_lines(int x, char *l, int s)
{
	int	i;
	char	*line;

	i = 0;
	usleep(s);
	system("clear");
	print_line(&l[4]);
	while (i < x)
	{
		if (get_next_line(0, &line) <= 0)
			break ;
		print_line(&line[4]);
		free(line);
		i++;
	}
	printf("\n");
}

void	read_lines(int x, int s, int nop)
{
	char	*line;
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '0')
			print_lines(x, line, s);
		else if (line[0] == '=')
			line[3] == 'O' ?printf("%splayer 1 ==> [%s]%s\n", RED, &line[10], DEF): printf("%splayer 2 ==> [%s]%s\n", GREEN, &line[10], DEF);
		else if (nop && (line[0] == '.' || line[0] == '*'))
			printf("%s%s%s\n", YELLOW, line, DEF);
		free(line);	
	}
}

int	main(int  ac, char **av)
{
	char	*line;
	int	x;
	int	s;
	int	nop;

	nop = 1;
	s = 90000;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, PLAT))
		{
			x = ft_plat(line);
			free(line);
			break ;
		}
		free(line);
	}
	if (ac > 1 && ft_strcmp(av[1], NOP))
		s = atoi(av[1]);
	else if (ac == 3 && ft_strcmp(av[2], NOP))
		s = atoi(av[2]);
	if (ac > 1 && !ft_strcmp(av[1], NOP))
		nop = 0;
	else if (ac == 3 && !ft_strcmp(av[2], NOP))
		nop = 0;
	s <= 0 ? s = 90000 : 0;
	if (x > 0)
		read_lines(--x, s, nop);
	return (0);
}
