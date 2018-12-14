#include "iris.h"

int main(int argc, char **argv)
{
	list * flowerList = (list*)calloc(1, sizeof(list));
	int nbLignes, c;
	FILE* pfile;
	errno_t err = fopen_s(&pfile, "data.txt", "r+");

	if (pfile == NULL)
	{
		printf("fichier non valide");
		system("pause");
		return EXIT_FAILURE;
	}

	fseek(pfile, 0L, SEEK_SET);

	nbLignes = CountNbLignes(pfile);
	printf("nombre de lignes : %d\n", nbLignes);

	// Set pointer to beginning of file:
	fseek(pfile, 0L, SEEK_SET);

	flowerList = CreateDataList(pfile, flowerList, nbLignes);

	afficherList(flowerList);

	fclose(pfile);
	system("pause");
	return 0;
}