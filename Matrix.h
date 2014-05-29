
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

class Matrix
{
  public:

  void Begin();
  void Menu();
  void ChooseOp();

  //Commandes:

  void NewMatrix();
  void Back();
  void Delete();
  void DisplayDB();

  bool CheckOpen(string);
  bool Open(int);
  void Help(string);
  void Quit();

  void CloseFile(int );

  //Les fonctions de manipulation sont des bool pour renvoyer false en cas d’erreur

  //Manipulation

  bool SoustractionM();
  bool SoustractionV();

  bool AdditionM();
  bool AdditionV();

  bool MultiplicationM();
  bool MultiplicationV();

  bool DivisionV();

  bool Pow();
  bool Compare();
  bool Identity();

    // Fonctions sur les matrices

  void Read_Value(int ,int&, int&, double&);
  void Read_Size(int,int &,int&);
  bool Sparse();

  double Place_to_Coord(int matrix,int line,int col);
  bool Check_Size(char m,int & l,int & c);

  void StartTimer();
  void DisplayTimer();
  void FlushCin();


  private:

    clock_t begin, end;
    double **buffMatrix;
    string FileName;
    fstream M1;
    fstream M2;
    fstream M3;
};
