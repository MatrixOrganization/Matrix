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