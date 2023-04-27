#include "minitalk.h"

// int main()
// {
// 	struct s_c_list lista14 = {NULL, 0};
// 	struct s_c_list lista13 = {&lista14, 'o'};
// 	struct s_c_list lista12 = {&lista13, 'z'};
// 	struct s_c_list lista11 = {&lista12, 'z'};
// 	struct s_c_list lista10 = {&lista11, 'a'};
// 	struct s_c_list lista9 = {&lista10, 'C'};
// 	struct s_c_list lista8 = {&lista9, 'l'};
// 	struct s_c_list lista7 = {&lista8, 'o'};
// 	struct s_c_list lista6 = {&lista7, 'C'};
// 	struct s_c_list lista5 = {&lista6, 'o'};
// 	struct s_c_list lista4 = {&lista5, 'l'};
// 	struct s_c_list lista3 = {&lista4, 'l'};
// 	struct s_c_list lista2 = {&lista3, 'o'};
// 	struct s_c_list lista = {&lista2, 'P'};

// 	print_list(&lista);	
// }

int	main(int argc, char **argv)
{
	struct s_c_list	*list = NULL;
	struct s_c_list	*temp = NULL;
	int				i = 0;

	if (argc < 2)
		return (1);
	while (argv[1][i])
	{
		temp = node_init();
		if (!temp)
		{
			free_list(list);
			return (1);
		}
		temp->c = argv[1][i];
		list = add_node(list, temp);
		i++;
	}
	temp = node_init();
	temp->c = argv[1][i];
	list = add_node(list, temp);
	print_list(list);
	free_list(list);
}
