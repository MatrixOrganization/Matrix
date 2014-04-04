
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

  //Commandes:

  void NewMatrix();                                    // creer une matrice aléatoire
  void Back();                                          // permet de revenir à l’étape précédente
  bool Delete(string);                                    // supprime une matrice de la BDD
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

  void SoustractionM();                               // soustraction de matrices (M)-(M)
  void SoustractionV(double);                            // soustraction de la matrice par une valeur (M)-Val

  void AdditionM() ;                              // addition de matrices (M)+(M)
  void AdditionV(double);                                // addition de la matrice par une valeur (M)+Val

  bool MultiplicationM();                          // multiplication de matrices (M)*(M)
  void MultiplicationV(double);                         // multiplication de la matrice par une valeur (M)*Val

  void DivisionM();                               // division de matrices (M)/(M)
  void DivisionV(double);                                // division de la matrice par une valeur (M)/Val

  bool Pow(int);                                    // puissance (M)^v
  bool Modulo(int);                                    // modulo (M)%v
  bool Compare(string);                                    // comparaison de matrices (M)&(M)
  bool Range();                                          // rang de la matrice (M)
  bool Transpose();                                    // transposée de la matrice (M)
  bool Identity();                        // créé la matrice identité avec les même dimension que la matrice ouverte

    // Fonctions sur les matrices

  void Read_Value(int ,int&, int&, double&);                                    // lit et retourne une valeur de la matrice
  bool Sparse();                     // matrice creuse ?
  double Place_to_Coord(int line,int col);
  bool Check_Size(int & l,int & c);


  private:

    double **buffMatrix;                                        // sauvegarde de la matrice dans un fichier.txt
    string FileName;
    fstream M1;
    fstream M2;                                          // le nom du fichier de la matrice sur laquelle on travaille
    fstream M3;
};




