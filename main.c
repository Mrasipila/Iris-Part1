#include "iris.h"

int main(int argc, char **argv)
{
	flower * fleur = (flower*)calloc(1, sizeof(flower));
	FILE* file;
	errno_t err = fopen_s(&file, "data.txt", "r+");


	// Set pointer to beginning of file:
	fseek(file, 0L, SEEK_SET);

	fscanf_s(file, "%f,%f,%f,%f,", &fleur->m_sepalWidth, &fleur->m_sepalLength, &fleur->m_petalWidth, &fleur->m_petalLength);
	fscanf_s(file, "%s", fleur->m_specieNamed, _countof(fleur->m_specieNamed));
	printf("%f, %f, %f, %f, %s", fleur->m_sepalWidth, fleur->m_sepalLength, fleur->m_petalWidth, fleur->m_petalLength, fleur->m_specieNamed);
	system("pause");
	return 0;
}