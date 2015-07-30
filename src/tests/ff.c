#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	const char *ff = "ff.in";
	char *joe = "joe frank\n";
	char ch;
	int frank = 25;
	FILE* fout = fopen(ff, "w");
	FILE* finn = NULL;

	/* write shit */
	fputs(joe, fout);
	fwrite(&frank, sizeof(int), 1, fout);
	fclose(fout);

	/* read shit */
	finn = fopen(ff, "r");
	ch = fgetc(finn);
	while (ch != '\n')
	{
		printf("%c", ch);
		ch = fgetc(finn);
	}
	fread(&frank, sizeof(char), 1, finn);
	frank--;
	printf("\n%d\n", frank);

	fclose(finn);

	return 0;
}