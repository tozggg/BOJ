#include <stdio.h>
#include <stdlib.h>

typedef struct	s_stack
{
	int				data;
	struct s_stack	*prev;
}				t_stack;

void	push(t_stack **node, int data)
{
	t_stack *new = malloc(sizeof(t_stack));
	new->data = data;
	new->prev = *node;
	node = &new;
}

int		pop(t_stack *node)
{
	int res;
	
	if (node == NULL)
		return (-1);
	else
	{
		res = node->data;
		node = node->prev;
		return (res);
	}
}

int		size(t_stack *node)
{
	int		res;
	t_stack	*tmp;

	res = 0;
	tmp = node;
	while (tmp)
	{
		++res;
		tmp = node->prev;
	}
	return (res);
}

int		empty(t_stack *node)
{
	if (node == NULL)
		return (1);
	else
		return (0);
}

int		top(t_stack *node)
{
	if (empty(node))
		return (-1);
	else
		return (node->data);
}

int		equals(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (0);
		++s1;
		++s2;
	}
	if (*s1 == 0 && *s2 == 0)
		return (1);
	else
		return (0);
}

int		main()
{
	t_stack	*stack;
	int		cnt;
	char	str[30];
	int		tmp;

	scanf("%d", &cnt);
	for (int i=0; i<cnt; i++)
	{
		scanf("%s", str);
		if (equals(str, "push"))
		{
			scanf("%d", &tmp);
			printf("tmp-> %d\n", tmp);
			push(&stack, tmp);
			printf("%d", stack->data);
		}
		else if (equals(str, "top"))
			printf("%d\n", top(&stack));
		else if (equals(str, "size"))
			printf("%d\n", size(&stack));
		else if (equals(str, "pop"))
			printf("%d\n", pop(&stack));
		else if (equals(str, "empty"))
			printf("%d\n", empty(&stack));
		
	}
}
