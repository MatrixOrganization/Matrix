#include “Matrix.h”

void Matrix::Open(string FileName)
{
	cout << "Quelle matrice voulez-vous ouvrir? " << endl;
	
	do
	{
		if(!OpenFile())
			cout << "Ce fichier n'existe pas" << endl;

		cout << "Entrez le nom de la matrice:";x
		cin >> Filename;

	} while (!OpenFile());
}

void Matrix::NewMatrix(long height, long weight)
{
	int sizeChoice;
	cout << "Choix de la taille des valeurs" << endl;
	cout << "Si 0-9: tapez 10; si 0-99: tapez 100; si 0-999: tapez 1000; si 0-9999: tapez 10000" << endl;
	cin >> sizeChoice;

    randMatrix=new double*[height];
	for(int i=0; i<height; i++)
	{
		randMatrix[i]=new double[weight];
		for(int j=0; j<weight; j++)
		{
			randMatrix[i][j]=rand()%sizeChoice;
		}
	}

	/* test
	for(int i=0; i<height; i++)
	{
		for(int j=0; j<weight; j++)
		{
			cout << randMatrix[i][j] << endl;
		}
	}
	*/
	
}