void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void	ft_print_line(int width, char begin_symbol, char middle_symbol, char end_symbol)
{
	int i;
	
	i = 0;
	while(i <= width)
	{
		if(i == 0)
			ft_putchar(begin_symbol);
		if(i <= (width - 2))
			ft_putchar(middle_symbol);
		if(i == (width - 1))
			ft_putchar(end_symbol);
		i++;
	}
}

void	rush(int x, int y)
{
	int i;

	i = 0;
	if (x <= 0 || y <= 0)
		return ;
	while(i <= y)
	{
		if (i == 0)
			ft_print_line(x, 'A', 'B', 'C');
		if(i <= (y - 2))
			ft_print_line(x, 'B', ' ', 'B');
		if(i == (y - 1))
			ft_print_line(x, 'C', 'B', 'A');
		ft_putchar('\n');
		i++;
	}
}