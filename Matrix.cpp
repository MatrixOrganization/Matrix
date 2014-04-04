
#include "Matrix.h"
#include <stdlib.h>
void Matrix::Begin()
{
    cout<< "Bienvenue" << endl;
    Menu();

}
void Matrix::Menu()
{
     int command;
     string s;
    do
    {
        cout<< "Que voulez vous faire ?" << endl
        << "1-Creer un matrice" << endl
        << "2-Afficher les matrices de la base de donnée" << endl
        << "3-Manipulation"<<endl
        << "4-Help" << endl
        << "5-Quitter" << endl;
        cin>>command;
        if(command==1) NewMatrix();
       /* if(command==2)//Afficher les matrices déjà créé
        {
            DisplayDB();
        }*/
        if(command==3)
        {
            MultiplicationM();
        }
        if(command==4)//Help
        {
            cin>>s;
            Help(s);
        }
    }while(command!=5);

}


void Matrix::Open(int m)
{
    string c;
    cin>>c;
    c+=".txt";
    if(m==1)        M1.open(c.c_str(), ios::in| ios::out );
    else if(m==2)    M2.open(c.c_str(), ios::in| ios::out );
    else if(m==3)   M3.open(c.c_str(), ios::out|ios::in | ios::trunc);
}

void Matrix::CloseFile(int m)
{
    if(m==1)M1.close();
    else if(m==2)M2.close();
    else if(m==3)M3.close();
}

void Matrix::Read_Value(int matrice,int &l, int &c, double &v) // lit et retourne une valeur de la matrice
 {

    if(matrice==1)M1 >> l >> c >> v;
    else if(matrice==2)M2 >> l >> c >> v;
    else cout << "La matrice n'existe pas"<<endl;
     cout<<"ici"<<endl;
    cout<<v<<endl;
 }

 void Matrix::DisplayDB()
 {
    //sous entend que les matrices se trouvent dans le dossier DB
 }

 bool Matrix::Sparse() // matrice creuse ?
{
    int l,c;
    double v;
    int nb_value_zero = 0, nb_value = 0, percent_sparse = 90; // matrice creuse si 90% des valeurs sont = 0
    string value;

    while(getline(M1, value))
    {
        nb_value++;
        Read_Value(1,l,c,v);
        if(v == 0.0)
            nb_value_zero++;
    }

    nb_value_zero = (nb_value_zero*100)/nb_value;

    if(nb_value_zero >= percent_sparse)
        return true; // creuse
    return false; // pas creuse
}

void Matrix::NewMatrix()
{

    int height;
     int  weight;
    cout<<"Longueur: "<<endl;
    cin >> height;
    cout<<"Largeur: "<<endl;
    cin >> weight;

    int sizeChoice;
    cout << "Choix de la taille des valeurs" << endl;
    cout << "Si 0-9: tapez 10 "<<
    endl<<"si 0-99: tapez 100"<<
    endl<<" si 0-999: tapez 1000"<<
    endl<<" si 0-9999: tapez 10000" << endl;

    cin >> sizeChoice;

    string nameFile;
    cout << "Nom du fichier de la matrice:" << endl << " -> ";
    cin >> nameFile;

    ofstream newMat(nameFile.c_str(), ios::out | ios::trunc);
        if(!newMat.is_open())
            cout << "Impossible d'ouvrir le fichier en écriture !" << endl;

        else
        {
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
}


void Matrix::Help(string chaine)
{
    if(chaine=="open")
        cout << "Permet l'ouverture d'un fichier contenant une matrice (nom du fichier en argument)" << endl;
    if(chaine=="displaybdd")
        cout << "Permet d'afficher les matrices dans la base de données" << endl;
    if(chaine=="back")
        cout << "Permet de revenir à l'étape précédente" << endl;
    if(chaine=="quit")
        cout << "Permet de fermer les fichiers en cours et fermer le programme" << endl;
    if(chaine=="delete")
        cout << "Permet de supprimer un fichier de matrice de la base de données (nom du fichier en argument)" << endl;
    if(chaine=="soustractionM")
        cout << "Permet de faire une soustraction entre deux matrices (nom du fichier en argument)" << endl;
    if(chaine=="soustractionV")
        cout << "Permet de faire une soustraction entre une matrice et une valeur (valeur en argument)" << endl;
    if(chaine=="additionM")
        cout << "Permet de faire une addition entre deux matrices (nom du fichier en argument)" << endl;
    if(chaine=="additionV")
        cout << "Permet de faire une addition entre une matrice et une valeur (valeur en argument)" << endl;
    if(chaine=="multiplicationM")
        cout << "Permet de faire une multiplication entre deux matrices (nom du fichier en argument)" << endl;
    if(chaine=="multiplicationV")
        cout << "Permet de faire une multiplication entre une matrice et une valeur (valeur en argument)" << endl;
    if(chaine=="divisionM")
        cout << "Permet de faire une division entre deux matrices (nom du fichier en argument)" << endl;
    if(chaine=="divisionV")
        cout << "Permet de faire une division entre une matrice et une valeur (valeur en argument)" << endl;
}
bool Matrix::Check_Size(int & l,int & c)
{
    M1.seekg(0,ios::end);
    M2.seekg(10,ios::end);
    return true;
}
double Matrix::Place_to_Coord(int line,int col)
{
    string chaine;
    int l,c;
    double v;
    while(getline(M2,chaine))
    {
        Read_Value(2,l,c,v);
        if(l==line && c==col)return v;
    }
    return 0.0;
}
bool Matrix::MultiplicationM()
{
    double a;
    cout<< "Premiere opérande: " <<endl;
    Open(1);
    cout<< "Deuxieme opérande: " <<endl;
    Open(2);
    int lM3,cM3;
    if(!Check_Size(lM3,cM3))return false;
    cout<< "Créer le fichier du résultat: " <<endl;
    Open(3);
    string line;

    int l,c;
    double v;

    while(getline(M1,line))
    {
    cout<<"ici1"<<endl;
       Read_Value(1,l,c,v);
        for(int i=0;i<lM3;i++)
        {
            for(int j=0;j<cM3;j++)
            {
                M3<<i<<" ";
                M3<<j<<" ";
                if(v!=0.0)
                {
                    a=Place_to_Coord(c,l);
                    if(a!=0.0)M3<<a*v;
                    else M3<<0.0;
                }
                else M3<<0.0;
            }
            M3<<"\n";
        }
    }

    CloseFile(1);
    CloseFile(2);
    CloseFile(3);
    return true;
}

