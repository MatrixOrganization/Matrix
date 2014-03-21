#include “Matrix.h”

void Matrix::Begin()
{
	cout<< "Bienvenue" << endl;
	Menu();
	
}
void Matrix::Menu()
{
	int command;
	string s;
	cout<< "Que voulez vous faire ?" << endl 
	<< "1-Ouvrir une matrice" << endl 
	<< "2-Afficher les matrices de la base de donnée" << endl
	<< "3-Help" << endl
	<< "4-Quitter" << endl;
	cin>>command;
	if(command==1)//OPEN
	{
		Open();
	}
	if(command==2)//Afficher les matrices déjà créé
	{
		DisplayDB();
	}
	if(command==3)//Help
	{
		cin>>s;
		Help(s);
	}
	if(command==4)//quiter
	{
		Quit();
	}
}

 void Matrix::DisplayDB()
 {
	//sous entend que les matrices se trouvent dans le dossier DB 
	system("for i in DB/* do echo i \" \";done");	
 }
 
 bool Sparse() // matrice creuse ?
{
    int nb_value_zero = 0, nb_value = 0, percent_sparse = 70; // matrice creuse si 70% des valeurs sont = 0
    string value;

    while(getline(M, value))
    {
        nb_value++;
        if(value == 0)
            nb_value_zero++;
    }

    nb_value_zero = (nb_value_zero*100)/nb_value;

    if(nb_value_zero >= percent_sparse)
        return true; // creuse
    return false; // pas creuse
}

void Matrix::NewMatrix(long height, long weight)
{
	int sizeChoice;
	cout << "Choix de la taille des valeurs" << endl;
	cout << "Si 0-9: tapez 10; si 0-99: tapez 100; si 0-999: tapez 1000; si 0-9999: tapez 10000" << endl;
	cin >> sizeChoice;

	string nameFile;
	cout << "Nom du fichier de la matrice:" << endl << " -> ";
	cin >> nameFile;

	ofstream newMat(nameFile.c_str(), ios::out | ios::trunc);
		if(!newMat.is_open())
    		cout << "Impossible d'ouvrir le fichier en écriture !" << endl;

		else
		{
			newMat << "L C V" << endl;
			for(int i=1; i<height; i++)
			{
				for(int j=1; j<weight; j++)
				{
					newMat << i << " " << j << " " << rand()%sizeChoice << endl;
				}
			}
			newMat << " " << endl;
		}
		newMat.close();

	return 0;
}

void Matrix::Help(string)
{
	if(string=="open")
		cout << "Permet l'ouverture d'un fichier contenant une matrice (nom du fichier en argument)" << endl;
	if(string=="displaybdd")
		cout << "Permet d'afficher les matrices dans la base de données" << endl;
}
