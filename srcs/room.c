#include "lemin.h"

void	parse_room(t_lem *lem)
{
	t_rooms *temp;
	t_rooms *temp1;

	temp = (t_rooms *)malloc(sizeof(t_rooms));
	temp->next = lem->head;
	ft_strcpy(temp->name, lem->tab[0]);
	lem->sr_name = lem->start == 1 ? temp->name : lem->sr_name;
	lem->er_name = lem->end == 1 ? temp->name : lem->er_name;
	ft_linedigit(lem->tab[1]) ? temp->x = ft_atoi(tab[1]) : lem_error(2);
	ft_linedigit(lem->tab[2]) ? temp->y = ft_atoi(tab[2]) : lem_error(2);
	ft_memedel(&tab[0]);
	ft_memedel(&tab[1]);
	ft_memedel(&tab[2]);
	free(tab);
	temp1 = lem->head;
	while(temp1)
	{
		if(!ft_strcmp(temp1->name, temp->name))
			lem_error(2);
		if((temp1->x == temp->x) && (temp1->y == temp->y))
			lem_error(2);
		temp1 = temp1->next;
	}
	lem->head = temp;
	lem->num_rooms++;
}

void	check_room(t_lem *lem)
{
	int8_t	i;

	i = -1;
	space = 0;
	if(lem->line[0] < 33 || lem->line[0] == 'L')
		lem_error(2);
	while(ft_iswhitespace(line[++i])
		space++;
	space != 2 ? lem_error(2) : 0;
	lem->tab = ft_split_whitespaces(lem->line);
	free(lem->line);
	i = -1;
	while(lem->tab[++i])
		;
	if(i != 3)
		lem_error(2); // check for leaks before exit in tab array;
	parse_room(lem);
}
