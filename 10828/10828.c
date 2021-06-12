#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_list
{
	int				data;
	struct s_list	*next;
}				t_list;

void	push(t_list **ptr, int data)
{
	t_list *lst;

	lst = (t_list *)malloc(sizeof(t_list));
	lst->data = data;
	lst->next = NULL;
	if (*ptr == NULL)
		*ptr = lst;
	else
	{
		lst->next = *ptr;
		*ptr = lst;
	}
}

int		pop(t_list **ptr)
{
	int ret;

	if (*ptr == NULL)
		return (-1);
	ret = (*ptr)->data;
	*ptr = (*ptr)->next;
	return (ret);
}

int		peek(t_list *lst)
{
	if (lst == NULL)
		return (-1);
	return (lst->data);
}

int		size(t_list *lst)
{
	int ret;

	ret = 0;
	while (lst)
	{
		++ret;
		lst = lst->next;
	}
	return (ret);
}

int		is_empty(t_list *lst)
{
	if (lst == NULL)
		return (1);
	return (0);
}

int		main(void)
{
	int		n;
	int		d;
	char	str[6];
	t_list	*top;

	top = NULL;
	scanf("%d", &n);
	for (int i=0; i<n; i++)
	{
		scanf("%s", str);
		if (strcmp(str, "push") == 0)
		{
			scanf("%d", &d);
			push(&top, d);
		}
		else if (strcmp(str, "pop") == 0)
			printf("%d\n", pop(&top));
		else if (strcmp(str, "top") == 0)
			printf("%d\n", peek(top));
		else if (strcmp(str, "size") == 0)
			printf("%d\n", size(top));
		else if (strcmp(str, "empty") == 0)
			printf("%d\n", is_empty(top));
	}

	return 0;
}
