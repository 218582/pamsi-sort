#include <iostream>
#include "../inc/tablica1d.hh"
#include <cstdlib>
#define MAXRAND 100
using namespace std;
#define ROZMIAR_TABLICY 100000

double obliczSekundy( clock_t czas )
{
    return static_cast < double >( czas ) / CLOCKS_PER_SEC;
}


int main()
{
  tablica1D Ex;
  for(int i=0; i<ROZMIAR_TABLICY; ++i){
      Ex.DodajElement(rand() %MAXRAND);
      cout<< i <<endl;
  }
  
  cout << "Liczba sekund to:"<<obliczSekundy(clock())<< endl;
    
}

