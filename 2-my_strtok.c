#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN 1 /* à l'interieur d'un mot*/
#define OUT 0 /* à l'exterieur d'un mot*/
/**
 *
 *
 **/
void main(void)
{
	int etat, c, nl, nm, nc;

	etat = OUT;
	nl = nc = nm = 0;

	while ((c = getchar()) != EOF)
		{
			++nc;
			if (c == '\n')
				++nl;
			if (c == ' ' || c == '\n' || c == '\t')
				etat = OUT;
			else if (etat == OUT)
				{
					etat == IN;
					++nm;
				}

		}
	printf("%d %d %d\n", nl, nm, nc);
}
