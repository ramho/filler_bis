
#include "filler.h"

int		get_piece(t_filler *f, char *buf)
{
	int i;
	int x;

	x = 0;
	i = 0;
	while (i < ft_strlen(buf))
	{
		if (ft_isdigit(buf[i]) && x == 0)
		{
			x = 1;
			f->piece_x=get_digit(&i, buf);
		}
		if (ft_isdigit(buf[i]) && x == 1)
			f->piece_y=get_digit(&i, buf);
		i++;
	}
	f->piece_tot = f->piece_x * f->piece_y;
	copy_piece(f);
	return(0);
}

int copy_piece(t_filler *f)
{
	int i;
	char *line;
	FILE *ID = fopen("test.txt", "a");
	fprintf(ID,"in copy piece\n");
	fclose(ID);
	i = 0;
	if(!(f->piece_tab = malloc(sizeof(int*) * f->piece_x)))
		return(-1);
	while(get_next_line(0, &line) >= 0)
	{

		if (line)
		{
			if(!(f->piece_tab[i]=malloc(sizeof(int*) * f->piece_y)))
				return(-1);
			copy_piece_bis(f, &i, line);
			i++;
			if (i == (f->piece_x))
			{
				return(is_placable(f));
			}
		}
	}
	return(0);
}

void copy_piece_bis(t_filler *f, int *i, char *line)
{
	int j;

	j = 0;
	while(j < f->piece_y)
	{
		if(line[j] == '*')
			f->piece_tab[*i][j] = 1;
		else if (line[j] == '.')
			f->piece_tab[*i][j] = 0;
		j++;
	}
}
