#ifndef LISTTEST
#define LISTTEST
#include "List.hh"
#include "IRunnable.hh"
#include <string>
class ListTest: public List<string>, public IRunnable
{
private:
  string klucz;
public:
  bool load(std:: string TytulKsiazki, int LiczbaElementow);
  void display();
  void reset();
  int find(string item);

  virtual bool run()
  {
    if(find(klucz)>0)
      return true;
    else 
      return false;
  }

  virtual bool prepare(int size)
  {
    reset(); 
    if(load("test.doc", size)){
      klucz = get(rand()%size);
      return true;
    }
    else return  false;
  }
};

class ListTest_sort : public List<int>, public IRunnable {

private:
	int sizeOfTest;
	/*!
	 * \brief Metoda ustawia punkt startowy generatora
	 * pseudolosowego.
	 */
	void seedSrand (void) {
		srand(time(NULL));
	}
	
	/*!
	 * \brief Metoda generuje liczbę pseudolosową z zakresu 0..9
	 *
	 *\retval Liczba pseudolosowa z zakresu 0..9
	 */
	int generateRandomDgt (void) {
		return rand()%9999;
	}
public:	

	/*!
	 *\brief Konstruktor klasy testującej
	 *
	 */
	ListTest_sort () {
		seedSrand();
	}
	
	virtual bool prepare(int size) {
		sizeOfTest = size;
		for (int i = 0; i<size; i++) {
			add(generateRandomDgt(),i);
		}
		return true;
	}
	
	virtual bool run() {
		qs();
		return true;
	}
};


#endif
