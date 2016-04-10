#ifndef LIST
#define LIST
/*!
  \file 
  \brief Definicja klasy List

  Plik zawiera definicje szablonu klasy IList, 
  który jest interfejsem listy
*/
#include "IList.hh"
/*!
  \brief Szablon listy

  Na liste mozemy wpisywac na każde miejsce 
  i usuwać z każdego miejsca
*/
template <typename Typ>
class List: public IList<Typ>
{
protected:
  tablica1D <Typ> Tablica;
public:
  /*!
    \brief Zapisywanie na liste
    
    Wkłada element na dowolne miejsce na liście, jeżeli int index jest większy minimum o 2 od 
    indexu ostatniego elementu to przestrzeń między elementami zostaje uzupełniona przez wartości 0.
    Jeżeli int index wskazuje na miejsce, gdzie znajduje się element to zostaje on przepisany na kolejną
    pozycje, a na jego miejsce zostaje wpisany item

    \param[in] item - element, który chcemy umieścić na liście
    \param[in] index - miejsce, gdzie chcemy zapisać element (liczony od 0)
  */
  virtual void add (Typ item, int index){
    Tablica.DodajElement(item, index);
  }

  /*!
    \brief Ściąganie z listy
    
    Usuwa element z listy 
    \exception EmptyListException wyjątek pustej listy, wyrzucany gdy chcemy usunąć element o indexie
    którego nie ma na liście
    \return Zwraca usunięty element
  */
  virtual Typ remove(int index)
    throw (EmptyListException)
  {
    if(index > Tablica.Index())
      throw EmptyListException();
    else
      return Tablica.UsunElement(index);
  }
  /*!
    \brief Rozmiar listy
    
    Rozmiar listy jest liczbą całkowitą liczoną od 0, gdy lista pusty,

    \return Zwraca liczbę elementów zapisanych na liście
  */
  virtual int size(){return Tablica.Index()+1;}
  /*!
    \brief Czy pusty?
    
    Sprawdza czy na liście znajdują się elementy

    \retval true - lista pusty
    \retval false - na liście są elementy
  */
  virtual bool isEmpty()
  {
    if(Tablica.Index() >= 0) return false;
    else return true;		   
  }
  /*!
    \brief Element listy
    
    Dostęp do dowolnego elementu listy
    \exception EmptyListException wyjątek pustej listy, wyrzucany gdy chcemy odczytać element o indexie
    którego nie ma na liście
    \param[in] index - Numer elementu, który chcemy odczytać, gdzie index 0 to pierwszy element
    \return Zwraca element, bez jego usuwania
  */
  virtual Typ get(int index) 
  {
    if (index > Tablica.Index())
      throw EmptyListException();
    else
      return Tablica[index];
  }
  
private:
	void quicksort(int indexFront, int indexBack) {
		if (indexBack == 0) {throw EmptyListException();}
  		else 
  			Tablica.qs(indexFront,indexBack);
  		}
  	void quicksort_random(int indexFront, int indexBack) {
  		if (indexBack == 0) {throw EmptyListException();}
  		else 
  			Tablica.qs_random(indexFront,indexBack);
  	}
  	void quicksort_mo3(int indexFront, int indexBack) {
  		if (indexBack == 0) {throw EmptyListException();}
  		else 
  			Tablica.qs_mo3(indexFront,indexBack);
  	}
  	
public:
  /*!
   *\brief Sortowanie szybkie
   *
   * Sortuje elementy algorytmem quicksort - piwotem środkowy element
   * \param[in] indexFront indeks elementu pierwszego do sortowania
   * \param[in] indexBack indeks elementu ostatniego do sortowania
   * \warning wymaga typu danych zawierającego przeciążenie operatora porównania
   * \exception EmptyListException gdy lista jest pusta
   */
   virtual void qs(void) {
   		try {
	   		quicksort(0,Tablica.Index());
	   		//Tablica.showDebugInfo();
	   	}
	   	catch (...) {
	   		throw;
	   	}
   }
   
   virtual void qs_random(void) {
   		try {
	   		quicksort_random(0,Tablica.Index());
	   		//Tablica.showDebugInfo();
	   	}
	   	catch (...) {
	   		throw;
	   	}
   }
   
   virtual void qs_mo3(void) {
   		try {
	   		quicksort_mo3(0,Tablica.Index());
	   		//Tablica.showDebugInfo();
	   	}
	   	catch (...) {
	   		throw;
	   	}
   }
};

#endif
