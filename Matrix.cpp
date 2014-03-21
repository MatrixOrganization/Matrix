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
 
 double Matrix::Read_Value(fstream &M, int &l, int &c, int &v) // lit et retourne une valeur de la matrice
 {
    M >> l >> c >> v;
 }

 bool Matrix::Sparse() // matrice creuse ?
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

