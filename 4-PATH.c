#include "m.h"

list_t *buildlist(list_t **head, const char *str)
{
	list_t *newNode;
	char *newStr;

	newNode = malloc(sizeof(list_t));
	if (!newNode)
	{
		printf("Error in creation of newnode in buildlist");
		free(newNode);
		return (0);
	}

	newStr = strdup(str);
	if (!newStr)
	{
		free(newNode);
		printf("Error in creation of strdup in buildlist");
		return (0);
	}
	newNode->str = newStr;
	newNode->next = *head;
	*head = newNode;
	return (newNode);
}
void print_list(list_t *head)
{
	while (head)
	{
		printf("%s\n", head->str);
		head = head->next;
	}
}
int main(void)
{
	char *token, *path_copy = NULL;
	const char *temp = getenv("PATH");
	list_t *head;

	head = NULL;

	path_copy = malloc(strlen(temp) + 1);
	strcpy(path_copy, temp);

	token = strtok(path_copy, ":");
	while (token)
	{
		buildlist(&head, token);
		token = strtok(NULL, ":");
	}
	print_list(head);
	return (0);
}
