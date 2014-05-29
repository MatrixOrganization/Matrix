#include "Matrix.h"
#include <stdlib.h>

void Matrix::Begin()
{
    cout<< "Bienvenue" << endl;
    system("chmod a+x ls.sh");
    system("mkdir Matrix");
    Menu();

}

void Matrix::FlushCin()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Matrix::Menu()
{
    int command=0;
    string s;
    system("clear");

    while(command!=6)
    {

        if(cin.fail())
        {
            system("clear");
            cout << "Erreur, veuillez entrer une commande valide: " << endl << endl;
            FlushCin();
        }

        cout<< "Que voulez vous faire ?" << endl
        << "1-Creer un matrice" << endl
        << "2-Afficher les matrices de la base de donnée" << endl
        << "3-Manipulation"<<endl
        << "4-Suppression matrice"<<endl
        << "5-Help" << endl
        << "6-Quitter" << endl;
        
        
        cin>>command;

        if(command==1)
        {
            system("clear");
            StartTimer();
            NewMatrix();
            DisplayTimer();
        }
        if(command==2)//Afficher les matrices déjà créé
        {
            system("clear");
            DisplayDB();
        }
        if(command==3)
        {
            system("clear");
            ChooseOp();
        }
        if(command==4)
        {
            system("clear");
            Delete();
        }
        if(command==5)
        {
            system("clear");
            cin>>s;
            Help(s);
        }
        
    }

}

void Matrix::ChooseOp()
{
    int command;
    bool b;

    system("clear");

    do
    {
        if(cin.fail())
        {
            system("clear");
            cout << "Erreur, veuillez entrer une commande valide: " << endl << endl;
            FlushCin();
        }

        cout<< "Que voulez vous faire ?" << endl
        << "1-Addition" << endl
        << "2-Soustraction" << endl
        << "3-Multiplication"<<endl
        << "4-Determiner si une matrice est creuse" << endl
        << "5-Identité" << endl
        << "6-Matrice puissance N" << endl
        << "7-Annuler" << endl;

        DisplayDB();

        cout << "Commande (entre 1 et 7): ";
        cin >> command;

        if(command==1)
        {
            cout << "Voulez-vous additioner deux matrices ou une matrice par un nombre?" << endl
            << "1- Avec nombre" << endl
            << "2- Avec matrice" << endl;
            cin >> command;

            if(command==1)
            {
                StartTimer();
                AdditionV();
                DisplayTimer();
            }
            else
            {
                StartTimer();
                AdditionM();
                DisplayTimer();
            }
        }
        else if(command==2)
        {
            cout << "Voulez-vous soustraire deux matrices ou une matrice par un nombre?" << endl
            << "1- Avec nombre" << endl
            << "2- Avec matrice" << endl;
            cin >> command;

            if(command==1)
            {
                StartTimer();
                SoustractionV();
                DisplayTimer();
            }
            else
            {
                StartTimer();
                SoustractionM();
                DisplayTimer();
            }
        }
        else if(command==3)
        {
            cout << "Voulez-vous multipier deux matrices ou une matrice par un nombre?" << endl
            << "1- Avec nombre" << endl
            << "2- Avec matrice" << endl;
            cin >> command;

            if(command==1)
            {
                StartTimer();
                MultiplicationV();
                DisplayTimer();
            }
            else
            {
                StartTimer();
                MultiplicationM();
                DisplayTimer();
            }
            
        }
        else if(command==4)
        {
            

            if(Sparse())
            {
                system("clear");
                cout << "La matrice est creuse" << endl << endl;
            }
            else
            {
                system("clear");
                cout << "La matrice n'est pas creuse" << endl; 
            }
        }
        else if(command==5)
        {
            StartTimer();
            Identity();
            DisplayTimer();
        }
        else if(command==6)
        {
            StartTimer();
            Pow();
            DisplayTimer();
        }

    }while(command!=7);

     system("clear");
}

bool Matrix::CheckOpen(string S)
{
    fstream Check;

    Check.open(S.c_str(), ios::in | ios::out);

    if(Check)
    {
        Check.close();
        return true;
    }

    return false;
}

bool Matrix::Open(int m)
{   

    string path="Matrix/";
    string c;

    cin>>c;
    path+=c;
    path+=".txt";

    if(CheckOpen(path))
    {
        if(m==1)        M1.open(path.c_str(), ios::in| ios::out );
        else if(m==2)    M2.open(path.c_str(), ios::in| ios::out );
        else if(m==3)   M3.open(path.c_str(), ios::out|ios::in | ios::trunc);

        return true;
    }
    return false;
}

void Matrix::CloseFile(int m)
{
    if(m==1)M1.close();
    else if(m==2)M2.close();
    else if(m==3)M3.close();
}
void Matrix::Read_Size(int matrice,int & l,int &c)
{
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
    cout << endl << "Liste des fichiers" << endl;
    system("./ls.sh");
    cout << endl;
 }

 void Matrix::Delete()
 {
    string command="rm Matrix/";
    string file;
    cout << "Choisissez le fichier à supprimer:" << endl;
    DisplayDB();

    cin >> file;
    file+=".txt";
    command+=file;
    system(command.c_str());

 }

 bool Matrix::Sparse()
{
    int l,c;
    double v;
    double nb_value_zero = 0, nb_value = 0, percent_sparse = 90; // matrice creuse si 90% des valeurs sont = 0
    string value;

    cout<< "Matrice à vérifier: " <<endl;
    
    while(!Open(1))
    {
        system("clear");
        cout << "Entrez une matrice valide:" << endl;
        DisplayDB();
        cout << "Matrice: ";
    }
    
    Read_Size(1,l,c);

    while(!M1.eof())
    {
        nb_value++;
        Read_Value(1,l,c,v);
        if(v == 0)
            nb_value_zero++;
    }

    
    nb_value_zero = (nb_value_zero/nb_value)*100;

    if(nb_value_zero >= 90)
        return true;

    return false;
}

void Matrix::NewMatrix()
{

    int height, weight, sizeChoice;
    double percent;

    cout << "Pour créer une matrice, veuillez tapez:" << endl;
    cout<<"La longueur: "<<endl;
    cin >> height;

    while(cin.fail() || height < 0)
    {
        FlushCin();
        cout << "Entrez une longueur valide !" << endl;
        cout << "Longueur: ";
        cin >> height;
    }

    cout<<"La largeur: "<<endl;
    cin >> weight;

    while(cin.fail() || weight < 0)
    {
        FlushCin();
        cout << "Entrez une largeur valide !" << endl;
        cout << "Largeur: ";
        cin >> weight;
    }

    cout << "Choix de la taille des valeurs" << endl;
    cout <<"-Si 0-9: tapez 10 "<<
    endl <<"-Si 0-99: tapez 100"<<
    endl <<"-Si 0-999: tapez 1000"<<
    endl <<"-Si 0-9999: tapez 10000" << endl;

    cin >> sizeChoice;

    while(cin.fail() || weight < 0)
    {
        FlushCin();
        cout << "Entrez une taille de valeurs valide !" << endl;
        cout << "Choix de la taille des valeurs" << endl;
        cout <<"-Si 0-9: tapez 10 "<<
        endl <<"-Si 0-99: tapez 100"<<
        endl <<"-Si 0-999: tapez 1000"<<
        endl <<"-Si 0-9999: tapez 10000" << endl;
        cin >> sizeChoice;
    }

    string z = "Matrix/";
    string nameFile;
    cout << "Nom du fichier de la matrice:" << endl << " -> ";
    cin >> nameFile;
    z+=nameFile;
    z+=".txt";

    ofstream newMat(z.c_str(), ios::out | ios::trunc);
        if(!newMat.is_open())
            cout << "Impossible d'ouvrir le fichier en écriture !" << endl;

        else
        {
            newMat << height << " " << weight << endl;
            for(int i=0; i<height; i++)
            {
                system("clear");
                percent = (double) i/(double)weight;
                cout<<"Progression:"<< percent*100 << "%" <<endl;

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

void Matrix::StartTimer()
{
    begin = clock();
}

void Matrix::DisplayTimer()
{
    int tmp;
    end = clock();
    double timer = (double ) (end - begin)/CLOCKS_PER_SEC;
    if(timer>60)
    {
        int tmp = timer/60;
        int sec = (int) timer;
        sec = sec%60;
        cout << "Temps d'execution: " << tmp << " minutes " << sec << " secondes." << endl;
    }
    else
       cout << "Temps d'execution: " << timer << " secondes." << endl;
} 

bool Matrix::MultiplicationM()
{
    double vM1,vM2,vM3,percent;
    int lM1,cM1,lM3,cM3;
    string line;
    cout<< "Premiere opérande: " <<endl;
    
    while(!Open(1))
    {
        system("clear");
        cout << "Entrez une matrice valide:" << endl;
        DisplayDB();
        cout << "Matrice: ";
    }

    cout<< "Deuxieme opérande: " <<endl;
    
    while(!Open(2))
    {
        system("clear");
        cout << "Entrez une matrice valide:" << endl;
        DisplayDB();
        cout << "Matrice: ";
    }

    if(!Check_Size('m',lM3,cM3))return false;
    cout<< "Créer le fichier du résultat: " <<endl;
    Open(3);

    M3<< lM3 << " " << cM3 << endl;
    M1.seekg(0, M1.beg);
    Read_Size(1,lM1,cM1);

    for(int i=0; i < lM3; i++)
    {

            system("clear");
            percent = (double) i/(double)lM3;
            cout<<"Progression:"<< percent*100 << "%" <<endl;
        

        for(int j=0; j < cM3; j++)
        {
            vM3=0;
            M1.seekg(0, M1.beg);
            getline(M1,line);
            M2.seekg(0, M2.beg);
            getline(M2,line);

            for(int k=0; k < cM1; k++)
            {
                vM1=Place_to_Coord(1,i,k);
                vM2=Place_to_Coord(2,k,j);

                if(vM1!=0 && vM2!=0)
                    vM3+=vM1*vM2;
                else if(vM1==1)
                    vM3+=vM2;
                else if(vM2==1)
                    vM3+=vM1;
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
    
    while(!Open(1))
    {
        system("clear");
        cout << "Entrez une matrice valide:" << endl;
        DisplayDB();
        cout << "Matrice: ";
    }

    cout<<"Deuxieme opérande: "<<endl;
    
    while(!Open(2))
    {
        system("clear");
        cout << "Entrez une matrice valide:" << endl;
        DisplayDB();
        cout << "Matrice: ";
    }

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
        if(v1!=0 && v2!=0)
            M3<< l << " " << c << " " << v1+v2 << endl;
        else if (v1==0)
            M3<< l << " " << c << " " << v2 << endl;
        else if (v2==0)
            M3<< l << " " << c << " " << v1 << endl;
        else
            M3<< l << " " << c << " " << 0 << endl;
    }
    CloseFile(1);
    CloseFile(2);
    CloseFile(3);
    return true;
}
bool Matrix::SoustractionM()
{
     cout<<"Premier opérande:"<<endl;

    while(!Open(1))
    {
        system("clear");
        cout << "Entrez une matrice valide:" << endl;
        DisplayDB();
        cout << "Matrice: ";
    }

    cout<<"Deuxieme opérande: "<<endl;

    while(!Open(2))
    {
        system("clear");
        cout << "Entrez une matrice valide:" << endl;
        DisplayDB();
        cout << "Matrice: ";
    }

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
    
    while(!Open(1))
    {
        system("clear");
        cout << "Entrez une matrice valide:" << endl;
        DisplayDB();
        cout << "Matrice: ";
    }

    cout << endl << "Entrez le coefficent "<<endl;
    cin>>val;

    while(cin.fail())
    {
        FlushCin();
        cout << "Entrez un coefficient valide !" << endl;
        cout << "coefficient: ";
        cin >> val;
    }

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
    
    while(!Open(1))
    {
        system("clear");
        cout << "Entrez une matrice valide:" << endl;
        DisplayDB();
        cout << "Matrice: ";
    }

    cout<<"Entrez le coefficent "<<endl;
    cin>>val;

    while(cin.fail())
    {
        FlushCin();
        cout << "Entrez un coefficient valide !" << endl;
        cout << "coefficient: ";
        cin >> val;
    }

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
    
    while(!Open(1))
    {
        system("clear");
        cout << "Entrez une matrice valide:" << endl;
        DisplayDB();
        cout << "Matrice: ";
    }

    cout<<"Entrez le coefficent "<<endl;
    cin>>val;

    while(cin.fail())
    {
        FlushCin();
        cout << "Entrez un coefficient valide !" << endl;
        cout << "coefficient: ";
        cin >> val;
    }

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
   
    while(!Open(1))
    {
        system("clear");
        cout << "Entrez une matrice valide:" << endl;
        DisplayDB();
        cout << "Matrice: ";
    }

    cout<<"Entrez le coefficent "<<endl;
    cin>>val;

    while(cin.fail())
    {
        FlushCin();
        cout << "Entrez un coefficient valide !" << endl;
        cout << "coefficient: ";
        cin >> val;
    }

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

bool Matrix::Compare()
{
    double vM1,vM2;
    int lM2,cM2,lM1,cM1;
    cout<< "Premiere opérande: " <<endl;
    
    while(!Open(1))
    {
        system("clear");
        cout << "Entrez une matrice valide:" << endl;
        DisplayDB();
        cout << "Matrice: ";
    }

    cout<< "Deuxieme opérande: " <<endl;
    
    while(!Open(2))
    {
        system("clear");
        cout << "Entrez une matrice valide:" << endl;
        DisplayDB();
        cout << "Matrice: ";
    }
    
    Read_Size(1,lM1,cM1);
    Read_Size(2,lM2,cM2);
    if(lM1!=lM2 || cM1!=cM2)
        return false;
   

    while(!M1.eof())
    {
       Read_Value(1,lM1,cM1,vM1);
       Read_Value(2,lM1,cM1,vM2);
       if(vM1!=vM2)return false;
    }

    CloseFile(1);
    CloseFile(2);
    
    return true;
}

bool Matrix::Identity()
{
    int lM1,cM1;
    cout<< "Calculer la matrice Identité pour: " <<endl;
    
    while(!Open(1))
    {
        system("clear");
        cout << "Entrez une matrice valide:" << endl;
        DisplayDB();
        cout << "Matrice: ";
    }
    
    cout<<"Nom du fichier résultat: "<<endl;
    Open(3);

    Read_Size(1,lM1,cM1);
    M3<<lM1<<" "<<cM1<<endl;

    if(lM1==cM1)
    {
        for (int i = 0; i < lM1; i++)
        {
            for (int j = 0; j < cM1; j++)
            {
                if (i==j)
                    M3 << i <<" " << j << " " << 1 << endl;
                else
                    M3 << i <<" " << j << " " << 0 << endl;

            }
        }
    }
    else
    {
        cout << "Erreur lors de l'ouverture de la matrice" << endl;
        return false;
    }

    CloseFile(1);
    CloseFile(3);
    return true;

}

bool Matrix::Pow()
{
    double val,v,vTemp;
    int l,c;

    cout<<"Entrez la matrice à manipuler "<<endl;
    
    while(!Open(1))
    {
        system("clear");
        cout << "Entrez une matrice valide:" << endl;
        DisplayDB();
        cout << "Matrice: ";
    }

    cout<<"Entrez le coefficent "<<endl;
    cin>>val;

    while(cin.fail())
    {
        FlushCin();
        cout << "Entrez un coefficient valide !" << endl;
        cout << "coefficient: ";
        cin >> val;
    }

    cout<<"Nom du fichier résultat: "<<endl;
    Open(3);

    Read_Size(1,l,c);
    M3<<l<<" "<<c<<endl;

    while(!M1.eof())
    {
        if(val>=0)
        {

            Read_Value(1,l,c,v);

            vTemp = v;

            for(int i=1; i<val; i++) 
                v*=vTemp; 
            
            M3<<l<<" "<<c<<" "<<v<<endl;

        }
        
        else
        {
            Read_Value(1,l,c,v);

            vTemp = v;

            for(int i=1; i<-val; i++) 
                v*=vTemp; 

            M3<<l<<" "<<c<<" "<<1/v<<endl;
        }
        

        
    }

    CloseFile(1);
    CloseFile(3);

    return true;
}


