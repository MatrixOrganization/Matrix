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
	<< "2-Afficher les matrices de la base de donnée"<<endl
	<< "3-help" <<endl
	<<"4-Quitter"<<endl;
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
