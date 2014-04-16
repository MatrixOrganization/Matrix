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
void Matrix::Read_Size(int matrice,int & l,int &c)
{
    string s;
    if(matrice==1) M1 >> l >> c;
    else if(matrice==2) M2 >> l >> c;
}
void Matrix::Read_Value(int matrice,int &l, int &c, double &v) // lit et retourne une valeur de la matrice
 {

    if(matrice==1)M1 >> l >> c >> v;
    else if(matrice==2)M2 >> l >> c >> v;
    else cout << "La matrice n'existe pas"<<endl;

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
    nameFile+=".txt";
    ofstream newMat(nameFile.c_str(), ios::out | ios::trunc);
        if(!newMat.is_open())
            cout << "Impossible d'ouvrir le fichier en écriture !" << endl;

        else
        {
            newMat << height << " " << weight << endl;
            for(int i=0; i<height; i++)
            {
                for(int j=0; j<weight; j++)
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
bool Matrix::Check_Size(char param,int & l,int & c)
{
    int l1,c1,l2,c2;
    Read_Size(1,l1,c1);
    Read_Size(2,l2,c2);
    if(param=='m' && l2==c1)
    {
        l=l1;
        c=c2;
        return true;
    }
    if((param=='a' || param=='s') && (l1==l2 && c1==c2))
    {
        l=l1;
        c=c1;
       return true;
    }
     return false;
}
double Matrix::Place_to_Coord(int matrix,int line,int col)
{
    string chaine;
    int l,c;
    double v;

    if(matrix==1)
    {
        while(!M1.eof())
        {
            Read_Value(1,l,c,v);
            if(l==line && c==col)return v;
        }
    }
    else
    {
        while(!M2.eof())
        {
            Read_Value(2,l,c,v);
            if(l==line && c==col)return v;
        }
    }

    return 0.0;
}
bool Matrix::MultiplicationM()
{
    double vM1,vM2,vM3;
    int lM1,cM1,lM3,cM3;
    string line;

    cout<< "Premiere opérande: " <<endl;
    Open(1);
    cout<< "Deuxieme opérande: " <<endl;
    Open(2);
    if(!Check_Size('m',lM3,cM3))return false;
    cout<< "Créer le fichier du résultat: " <<endl;
    Open(3);

    M3<< lM3 << " " << cM3 << endl;

    Read_Size(1,lM1,cM1);

    for(int i=0; i < lM3; i++)
    {
        for(int j=0; j < cM3; j++)
        {
            vM3=0;

            for(int k=0; k < cM1; k++)
            {
                vM1=Place_to_Coord(1,i,k);
                vM2=Place_to_Coord(2,k,j);
                vM3+=vM1*vM2;
            }

            M3 << i << " "<< j << " " << vM3 << endl;
        }
    }


    CloseFile(1);
    CloseFile(2);
    CloseFile(3);
    return true;
}


bool Matrix::AdditionM()
{
    cout<<"Premier opérande:"<<endl;
    Open(1);
    cout<<"Deuxieme opérande: "<<endl;
    Open(2);
    int lm3,cm3;
    if(!Check_Size('a',lm3,cm3))
    {
        cout<<"Matrices incompatible"<<endl;
        return false;
    }
    cout<<"nom du fichier résultat:"<<endl;
    Open(3);
    M3<<lm3<<" "<<cm3<<endl;
    int l,c;
    double v2,v1;
    while(!M1.eof())
    {
        Read_Value(1,l,c,v1);
        Read_Value(2,l,c,v2);
        M3<< l << " " << c << " " << v1+v2 << endl;
    }
    CloseFile(1);
    CloseFile(2);
    CloseFile(3);
    return true;
}
bool Matrix::SoustractionM()
{
     cout<<"Premier opérande:"<<endl;
    Open(1);
    cout<<"Deuxieme opérande: "<<endl;
    Open(2);
    int lm3,cm3;
    if(!Check_Size('s',lm3,cm3))
    {
        cout<<"Matrices incompatible"<<endl;
        return false;
    }
    cout<<"nom du fichier résultat:"<<endl;
    Open(3);
    M3<<lm3<<" "<<cm3<<endl;
    int l,c;
    double v2,v1;
    while(!M1.eof())
    {
        Read_Value(1,l,c,v1);
        Read_Value(2,l,c,v2);
        M3<< l << " " << c << " " << v1-v2 << endl;
    }
    CloseFile(1);
    CloseFile(2);
    CloseFile(3);
    return true;
}

bool Matrix::AdditionV()
{
    double val,v;
    int l,c;
    cout<<"Entrez la matrice à manipuler "<<endl;
    Open(1);
    cout<<"Entrez le coefficent "<<endl;
    cin>>val;
    if(val==0) return false;
    cout<<"Nom du fichier résultat: "<<endl;
    Open(3);
    Read_Size(1,l,c);
    M3<<l<<" "<<c<<endl;
    while(!M1.eof())
    {
        Read_Value(1,l,c,v);
        M3<<l<<" "<<c<<" "<<v+val<<endl;
    }

    CloseFile(1);
    CloseFile(3);
    return true;
}
bool Matrix::SoustractionV()
{
    double val,v;
    int l,c;
    cout<<"Entrez la matrice à manipuler "<<endl;
    Open(1);
    cout<<"Entrez le coefficent "<<endl;
    cin>>val;
    if(val==0) return false;
    cout<<"Nom du fichier résultat: "<<endl;
    Open(3);
    Read_Size(1,l,c);
    M3<<l<<" "<<c<<endl;
    while(!M1.eof())
    {
        Read_Value(1,l,c,v);
        M3<<l<<" "<<c<<" "<<v-val<<endl;
    }

    CloseFile(1);
    CloseFile(3);
    return true;
}
bool Matrix::MultiplicationV()
{
    double val,v;
    int l,c;
    cout<<"Entrez la matrice à manipuler: "<<endl;
    Open(1);
    cout<<"Entrez le coefficent "<<endl;
    cin>>val;
    if(val==1) return false;
    cout<<"Nom du fichier résultat: "<<endl;
    Open(3);
    Read_Size(1,l,c);
    M3<<l<<" "<<c<<endl;
    while(!M1.eof())
    {
        Read_Value(1,l,c,v);
        M3<<l<<" "<<c<<" "<<v*val<<endl;
    }

    CloseFile(1);
    CloseFile(3);
    return true;
}
bool Matrix::DivisionV()
{
        double val,v;
    int l,c;
    cout<<"Entrez la matrice à manipuler: "<<endl;
    Open(1);
    cout<<"Entrez le coefficent "<<endl;
    cin>>val;
    if(val==0 || val==1) return false;
    cout<<"Nom du fichier résultat: "<<endl;
    Open(3);
    Read_Size(1,l,c);
    M3<<l<<" "<<c<<endl;
    while(!M1.eof())
    {
        Read_Value(1,l,c,v);
        M3<<l<<" "<<c<<" "<<v/val<<endl;
    }

    CloseFile(1);
    CloseFile(3);
    return true;
}



