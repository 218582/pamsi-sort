#ifndef LISTTEST
#define LISTTEST
#include "List.hh"
#include "IRunnable.hh"
#include <string>
#include <ctime>
#include <chrono>
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

class ListTestQs: public List<int>, public IRunnable {
private:
	int typeOfTest;
	int sizeOfTest;
	double randomShift=0;
	/*!
	 * \brief Metoda ustawia punkt startowy generatora
	 * pseudolosowego.
	 */
	void seedSrand (void) {
		std::chrono::time_point<std::chrono::high_resolution_clock> one, two;
		one = std::chrono::high_resolution_clock::now();
		randomShift=randomShift+0.0001;
		two = std::chrono::high_resolution_clock::now();
		srand((double ((two-one).count())+randomShift));
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
	 ListTestQs () {
		seedSrand();
		typeOfTest = 0;
	}
	
	ListTestQs (int type) {
		seedSrand();
		typeOfTest = type;
	}
	
	virtual bool prepare (int size) {
		sizeOfTest = size;
		for (int i = 0; i<size; i++) {
			add(generateRandomDgt(),i);
		}
		return true;		
	}
	
	virtual bool run () {
		switch (typeOfTest) {
			case 0: qs(); break;
			case 1: qs_random(); break;
			case 2: qs_mo3(); break;
			default: break;
		}
		return true;		
	}

};

class ListTestPes: public List<int>, public IRunnable {
private:
	int sizeOfTest;
	
public:
	 ListTestPes () {}


	virtual bool prepare (int size) {
		sizeOfTest = size;
		for (int i = 0; i<size; i++) {
			add(i,i);
		}
		return true;		
	}
	
	virtual bool run () {
		qs_b();
		return true;		
	}
};
#endif
