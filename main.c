#include "iris.h"

int main(int argc, char **argv)
{
	flower * fleur = (flower*)calloc(1, sizeof(flower));
	int nbLignes, c;
	FILE* file;
	errno_t err = fopen_s(&file, "data.txt", "r+");

	if (!err)
	{
		printf("fichier non valide");
		return EXIT_FAILURE;
	}

	system("pause");
	fseek(file, 0L, SEEK_SET);

	nbLignes = CountNbLignes(file);
	printf("nombre de lignes : %d\n", nbLignes);

	// Set pointer to beginning of file:
	fseek(file, 0L, SEEK_SET);
	system("pause");

	for (int i = 0; i < 10; i++)
	{
		flower tmp;
		fscanf_s(file, "%f,%f,%f,%f,", &tmp.m_sepalWidth, &tmp.m_sepalLength, &tmp.m_petalWidth, &tmp.m_petalLength);
		fscanf_s(file, "%s", tmp.m_specieNamed, _countof(tmp.m_specieNamed));
		printf("%f, %f, %f, %f, %s\n", tmp.m_sepalWidth, tmp.m_sepalLength, tmp.m_petalWidth, tmp.m_petalLength, tmp.m_specieNamed);

		c = fgetc(file);
	}

	system("pause");
	return 0;
}