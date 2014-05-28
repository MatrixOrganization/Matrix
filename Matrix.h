
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

class Matrix
{
  public:

  void Begin();                            // commence l’application
  void Menu();                            // Affiche les fonctionnalités
  void ChooseOp();

  //Commandes:

  void NewMatrix();                                    // creer une matrice aléatoire
  void Back();                                          // permet de revenir à l’étape précédente
  void Delete();                                    // supprime une matrice de la BDD
  void DisplayDB();                                      // affiche les matrices de la BDD
                                    // ouvre un fichier txt “s” pour créer la matrice

  void Open(int );
  void Help(string);                                     // donne des infos sur chaque opération ou cmd
  void Quit();                                            // quitte et ferme tous les fichiers ouverts
                                 // retourne true si le fichier existe/s'est correctement ouvert
  void CloseFile(int );                               // retourne true si

                                   // quitte et ferme tous les fichiers ouverts

  //Les fonctions de manipulation sont des bool pour renvoyer false en cas d’erreur

  //Manipulation

  bool SoustractionM();                               // soustraction de matrices (M)-(M)
  bool SoustractionV();                            // soustraction de la matrice par une valeur (M)-Val

  bool AdditionM() ;                              // addition de matrices (M)+(M)
  bool AdditionV();                                // addition de la matrice par une valeur (M)+Val

  bool MultiplicationM();                          // multiplication de matrices (M)*(M)
  bool MultiplicationV();                         // multiplication de la matrice par une valeur (M)*Val
                              // division de matrices (M)/(M)
  bool DivisionV();                                // division de la matrice par une valeur (M)/Val

  bool Pow();                                    // puissance (M)^v                              // modulo (M)%v
  bool Compare();                                 // comparaison de matrices (M)&(M)                                         // rang de la matrice (M)                                   // transposée de la matrice (M)
  bool Identity();                        // créé la matrice identité avec les même dimension que la matrice ouverte

    // Fonctions sur les matrices

  void Read_Value(int ,int&, int&, double&);                                    // lit et retourne une valeur de la matrice
  void Read_Size(int,int &,int&);
  bool Sparse();                     // matrice creuse ?
  double Place_to_Coord(int matrix,int line,int col);
  bool Check_Size(char m,int & l,int & c);

  void StartTimer();
  void DisplayTimer();



  private:

    clock_t begin, end;
    double **buffMatrix;                                        // sauvegarde de la matrice dans un fichier.txt
    string FileName;
    fstream M1;
    fstream M2;                                          // le nom du fichier de la matrice sur laquelle on travaille
    fstream M3;
};





