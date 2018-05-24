#include "lemin.h"

void	parse_room(t_lem *lem)
{
	t_rooms *temp;
	t_rooms *temp1;

	if(!(temp = (t_rooms *)malloc(sizeof(t_rooms))))
		return ;
	temp->next = lem->head;
	temp->name = ft_strdup(lem->tab[0]);
	//ft_putstr(temp->name);
	lem->sr_name = !lem->sr_name && lem->start == 1 ? temp->name : lem->sr_name;
	lem->er_name = !lem->er_name && lem->end == 1 ? temp->name : lem->er_name;
	ft_linedigit(lem->tab[1]) ? temp->x = ft_atoi(lem->tab[1]) : lem_error("invalid rooms");
	ft_linedigit(lem->tab[2]) ? temp->y = ft_atoi(lem->tab[2]) : lem_error("invalid rooms");
	ft_memdel((void**)&lem->tab[0]);
	ft_memdel((void**)&lem->tab[1]);
	ft_memdel((void**)&lem->tab[2]);
	free(lem->tab);
	temp1 = lem->head;
	while(temp1)
	{
		if(!ft_strcmp(temp1->name, temp->name))
			lem_error("duplicate room name");//duplicate name error
		if((temp1->x == temp->x) && (temp1->y == temp->y))
			lem_error("same room coordinate");//same coordinate error
		//ft_putstr("I'm here \n");
		temp1 = temp1->next;
	}
	lem->head = temp;
	lem->num_room++;
}