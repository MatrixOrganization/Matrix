#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

class Matrix
{
  public:
		
  void Begin();							// commence l’application
  void Menu();							// Affiche les fonctionnalités

  //Commandes:
  
  void NewMatrix(long, long);		                        	// creer une matrice aléatoire
  void Back();			                          	// permet de revenir à l’étape précédente
  bool Delete(string);		                    		// supprime une matrice de la BDD
  void DisplayDB();		                        	  // affiche les matrices de la BDD
  bool Open(string) ;	                        		// ouvre un fichier txt “s” pour créer la matrice
  void Help(string) ; 		                    		// donne des infos sur chaque opération ou cmd
  void Quit();			                            	// quitte et ferme tous les fichiers ouverts
  bool OpenFile();                                // retourne true si le fichier existe/s'est correctement ouvert
  bool CloseFile();                               // retourne true si

  void Quit();	                            	// quitte et ferme tous les fichiers ouverts

  //Les fonctions de manipulation sont des bool pour renvoyer false en cas d’erreur

  //Manipulation
  
  bool SoustractionM(string); 	              			// soustraction de matrices (M)-(M)
  bool SoustractionV(double);	                		// soustraction de la matrice par une valeur (M)-Val

  bool AdditionM(string) ;	                  		// addition de matrices (M)+(M)
  bool AdditionV(double);	                    		// addition de la matrice par une valeur (M)+Val

  bool MultiplicationM(string);  	            		// multiplication de matrices (M)*(M)
  bool MultiplicationV(double); 	            		// multiplication de la matrice par une valeur (M)*Val
  
  bool DivisionM(string); 	                  		// division de matrices (M)/(M)
  bool DivisionV(double);	                    		// division de la matrice par une valeur (M)/Val

  bool Pow(int);			                        // puissance (M)^v
  bool Modulo(int);		                        	// modulo (M)%v
  bool Compare(string);		                    		// comparaison de matrices (M)&(M)
  bool Range();			                          	// rang de la matrice (M)
  bool Transpose();		                        	// transposée de la matrice (M)
  bool Identity();			                      	/* créé la matrice identité avec les même dimension 
  								                              que la matrice ouverte */
  private:
  
    double **buffMatrix;		                    		    // sauvegarde de la matrice dans un fichier.txt
    String FileName;			                            	// le nom du fichier de la matrice sur laquelle on travaille
		
  protected:
  
    double **buffMatrix;		                    		// sauvegarde de la matrice dans un fichier.txt
    fstream M;			                            	// le fichier de la matrice sur laquelle on travaille

}

#endif // MATRIX_H

