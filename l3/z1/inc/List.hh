#ifndef LIST
#define LIST
/*!
  \file 
  \brief Definicja klasy List

  Plik zawiera definicje szablonu klasy IList, 
  który jest interfejsem listy
*/
#include "IList.hh"
#include <exception>
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
  void add (Typ item, int index){
    Tablica.DodajElement(item, index);
  }

  /*!
    \brief Ściąganie z listy
    
    Usuwa element z listy 
    \exception EmptyListException wyjątek pustej listy, wyrzucany gdy chcemy usunąć element o indexie
    którego nie ma na liście
    \return Zwraca usunięty element
  */
  Typ remove(int index)
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
  int size(){return Tablica.Index()+1;}
  /*!
    \brief Czy pusty?
    
    Sprawdza czy na liście znajdują się elementy

    \retval true - lista pusty
    \retval false - na liście są elementy
  */
  bool isEmpty()
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
  Typ get(int index) 
  {
    if (index > Tablica.Index())
      throw EmptyListException();
    else
      return Tablica[index];
  }
  
private:
	void swap(int indexOne, int indexTwo) {
		Typ elementOne;
		Typ elementTwo;
		try {
			elementOne = get(indexOne);
			elementTwo = get(indexTwo);
			remove(indexOne);
			add(elementTwo,indexOne);
			remove(indexTwo);
			add(elementOne,indexTwo);
		}
		catch (...) {
			throw;
		}
	}
 
  /*!
   *\brief Sortowanie szybkie
   *
   * Sortuje elementy na liście algorytmem quicksort
   * \param[in] indexFront indeks elementu pierwszego do sortowania
   * \param[in] indexBack indeks elementu ostatniego do sortowania
   * \note Tą metodę dodano na zajęciach w grupach, 2016-04-04 ~218582
   * \warning wymaga typu danych zawierającego przeciążenie operatora porównania
   * \exception EmptyListException gdy lista jest pusta
   */
  void quicksort(int indexFront, int indexBack) {
  	if (indexBack == 0) {throw EmptyListException();}
	int i = indexFront;
	int j = indexBack;
	Typ pivot = get((i+j)/2);
  	try{
  		do {
			while(get(i) < pivot) {
				i=i+1;
			}
			while (get(j) > pivot) {
				j=j-1;
			}
			swap(i,j);
			i=i+1;
			j=j-1;
		} while ((i<=j));
		if (indexFront < j) {
			quicksort (indexFront, j);
		}
		if (i<indexBack) {
			quicksort (i, indexBack);
		}
	}
  	catch(...) {
  		throw;
  	}
  }
  
public:
	/*!
	 *\brief Sortowanie szybkie całej listy
	 *
	 * Sortuje sortowaniem szybkim całą tablicę
	 */
	void qs(void) {
 		try {
 			for(int i=0;i<size()-1;i++) {
 				cout << get(i) << " ";
 			}
 			cout << endl << "------------------------------" << endl;
 			quicksort(0,size()-1);
 			for(int i=0;i<size()-1;i++) {
 				cout << get(i) << " ";
 			}
 		}	
 		catch (...) {
 			throw;
 		}
 	}
  
};

#endif
