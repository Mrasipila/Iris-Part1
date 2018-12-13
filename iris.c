#include "iris.h"

list * CreateDataList(FILE * p_file, flower p_fleur)
{
	if (!p_file)
		return	EXIT_FAILURE;

	fscanf_s(p_file, "%d, %d, %d, %d, %s\n", &p_fleur.m_sepalWidth, &p_fleur.m_sepalLength, &p_fleur.m_petalWidth, &p_fleur.m_petalLength, &p_fleur.m_specieNamed);

	return NULL;
}

float entropy(float nb_class1, float nb_class2, float nb_class3, float efftot)
{
	float val_entropy;
	float P1_succes, P2_succes, P3_succes;
	P1_succes = nb_class1 / efftot;
	P2_succes = nb_class2 / efftot;
	P3_succes = nb_class3 / efftot;
	val_entropy = -P1_succes*log2f(P1_succes) - P2_succes*log2f(P3_succes) - P3_succes*log2f(P3_succes);
	return val_entropy;
}

