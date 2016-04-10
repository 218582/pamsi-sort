#ifndef TABLICA1D
#define TABLICA1D
#include "Itablica1d.hh"
#include <ctime>
#include <chrono>

template <class Typ>
class tablica1D: public  Itablica1D<Typ>
{
protected:
  int Irozmiar=10;
  Typ* TablicaPtr;
  int index=-1;


  void Realokuj(){
    Typ* TablicaPomocnicza = new Typ [Irozmiar];
    for (int i = 0; i <= index; ++i ) TablicaPomocnicza[i] = TablicaPtr[i];
    delete [] TablicaPtr;
    TablicaPtr = TablicaPomocnicza;
  }
 
  void Realokuj(int Pozycja){
    Typ* TablicaPomocnicza = new Typ [Irozmiar];
    for (int i = 0; i < Pozycja; ++i ) TablicaPomocnicza[i] = TablicaPtr[i];
    for (int i = Pozycja + 1; i <=index; ++i) TablicaPomocnicza[i] = TablicaPtr[i-1];
    delete [] TablicaPtr;
    TablicaPtr = TablicaPomocnicza;
  }

  void ZwiekszRozmiar(){ Irozmiar*=2;}
public:
  tablica1D() {TablicaPtr = new Typ [Irozmiar];}
  virtual ~tablica1D() {delete [] TablicaPtr;}
  virtual int Index() {return index;}

  virtual void DodajElement (Typ Element){
    if ( index >= Irozmiar -1) {
      ZwiekszRozmiar();
      Realokuj();
    }
    TablicaPtr[++index] = Element;
  }
 

  virtual void DodajElement (Typ Element, int indexElementu){
    if(indexElementu > index){
      if ( indexElementu >= Irozmiar -1) {
	while (indexElementu >= Irozmiar -1) ZwiekszRozmiar();
	Realokuj(indexElementu);
      }
      index = indexElementu;
      TablicaPtr[index] = Element;
    }
    else{
      if(++index >= Irozmiar)
	ZwiekszRozmiar();
      Realokuj(indexElementu);
      TablicaPtr[indexElementu]=Element;
      
      
    } 
  }


  virtual Typ operator [] (int N)const  {   return TablicaPtr[N];}
  virtual Typ& operator [] (int N) { return TablicaPtr[N];}

  virtual Typ UsunElement() {
    Typ Element;
    if (index >= 0){
      Element = TablicaPtr[index];
      --index;
    }
    else return 0;
    return Element;
  }

  virtual Typ UsunElement(int indexElementu) {
    Typ Element;
    if (index >= 0 && index >= indexElementu){
      Element = TablicaPtr[indexElementu];
      --index;
      for (int i = indexElementu; i <= index; ++i){
	TablicaPtr [i] = TablicaPtr[i+1]; 
      }
    }
    else if(index >= 0 && indexElementu == 0){
      Element = TablicaPtr[0];
      delete TablicaPtr;
      ++TablicaPtr;
    }
    else return 0;
    return Element;
  }
  
  
  void swap(int indexOne, int indexTwo) {
		Typ elementOne;
		Typ elementTwo;
		elementOne = TablicaPtr[indexOne];
		elementTwo = TablicaPtr[indexTwo];
		TablicaPtr[indexOne] = elementTwo;
		TablicaPtr[indexTwo] = elementOne;
	}

  void showDebugInfo (void) {
  	for (int i=0;i<=index;i++) {
  		cout << TablicaPtr[i] << " ";
  	}
  	cout << endl;
  }
  double randomShift=0;
  void seedSrand (void) {
//		std::chrono::time_point<std::chrono::high_resolution_clock> one, two;
//		one = std::chrono::high_resolution_clock::now();
//		randomShift=randomShift+0.0001;
//		two = std::chrono::high_resolution_clock::now();
//		srand((double ((two-one).count())+randomShift));
		srand(time(NULL));
	}
  
  virtual void qs(int indexFront , int indexBack) {	
	int i = indexFront;
	int j = indexBack;
	Typ pivot = TablicaPtr[((i+j)/2)];
	do {
		while(TablicaPtr[i] < pivot) {
			i=i+1;
		}
		while (TablicaPtr[j] > pivot) {
			j=j-1;
		}
		if (i<=j) {
			swap(i,j);
			i=i+1;
			j=j-1;
		}
	} while (i<=j);
	if (indexFront < j) {
		qs(indexFront, j);
	}
	if (indexBack > i) {
		qs(i, indexBack);
	}
  }
  
    virtual void qs_random(int indexFront , int indexBack) {	
	int i = indexFront;
	int j = indexBack;
	seedSrand();
	
	Typ pivot = TablicaPtr[(rand()%(j-i))+i];
	do {
		while(TablicaPtr[i] < pivot) {
			i=i+1;
		}
		while (TablicaPtr[j] > pivot) {
			j=j-1;
		}
		if (i<=j) {
			swap(i,j);
			i=i+1;
			j=j-1;
		}
	} while (i<=j);
	if (indexFront < j) {
		qs_random(indexFront, j);
	}
	if (indexBack > i) {
		qs_random(i, indexBack);
	}
  }
  
  int middleOf3(int indexOne, int indexTwo, int indexThree) {
	if (TablicaPtr[indexOne] > TablicaPtr[indexTwo]) {
		if (TablicaPtr[indexTwo] > TablicaPtr[indexThree]) return indexTwo;
		else if (TablicaPtr[indexOne] > TablicaPtr[indexThree]) return indexThree;
		else return indexOne;
	}
	else {
		if (TablicaPtr[indexOne] > TablicaPtr[indexThree]) return indexOne;
		else if(TablicaPtr[indexTwo] > TablicaPtr[indexThree]) return indexThree;
		else return indexTwo;
	}
  }
  
  virtual void qs_mo3(int indexFront, int indexBack) {
  	int i = indexFront;
	int j = indexBack;
	seedSrand();
	
	Typ pivot = TablicaPtr[middleOf3(i, (rand()%(j-i))+i,j)];
	do {
		while(TablicaPtr[i] < pivot) {
			i=i+1;
		}
		while (TablicaPtr[j] > pivot) {
			j=j-1;
		}
		if (i<=j) {
			swap(i,j);
			i=i+1;
			j=j-1;
		}
	} while (i<=j);
	if (indexFront < j) {
		qs_random(indexFront, j);
	}
	if (indexBack > i) {
		qs_random(i, indexBack);
	}
  }


};

#endif
