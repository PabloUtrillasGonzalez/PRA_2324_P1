#include <ostream>
#include <vector>
#include "List.h"

using namespace std;

template <typename T> 
class ListArray : public List<T> {

    private:
        // miembros privados
	T* arr;
	int max;
	int n;
	static const int MINSIZE = 2;
    
    public:
        // miembros públicos, incluidos los heredados de List<T>
	// Constructor y Destructor
    	ListArray(){arr = new T[MINSIZE];};
	~ListArray(){delete[] arr;};

	T operator[](int pos){
		if(pos < 0 || pos >=max){
			throw out_of_range("Posicion invalida");
		}else{
			return arr[pos];
		}
	}

	friend ostream&operator<<(ostream &out, const ListArray<T> &list){
		for(int i = 0; i < list.n ; i++){
			out << list[i] << " ";
		}
		return out;
	}

	void resize(int new_size){
		T* arrDin = new T[new_size]; // Array dinamico
		for(int i = 0; i<new_size;i++){
			arrDin[i] = arr[i];
		}

		delete[] arr;	// Borramos arr
		arr = arrDin;	// Indicamos a arr que apunte a arrDin 
		max = new_size;	// Actualizamos el nuevo tamaño de arr
	}

	// METODOS DE LA CLASE LIST A IMPLEMENTAR
		void insert(int pos, T e) override{
			if(pos < 0 || pos >=max){
				throw out_of_range("Posicion invalida");
			}

			if((e.size() + n) < max){
				resize(n + 1 + e.size());
			}

			
			//Creamos hueco para el array haciendo que el array principal se mueva a la derech
			//la cantidad de elementos que el que insertamos tenga, a excepción de si se va a insertar al final
			
			if(pos >= n){
				for(int i = n,x = 0; i < e.size() ; i++,x++){
					arr[i] = e.get[x];
				}
			}else{
				for(int i = 0,x = pos; x <= n ;i++,x++){
					arr[x] = arr[n+i];
					arr[x] = e[i];
					n++;
				}
			}
		
		}

                void append(T e) override{
			insert(n,e);
		}

                void prepend(T e) override{
			insert(0,e);
		}

                T remove(int pos) override{
			if(pos < 0 || pos >=max){
                                throw out_of_range("Posicion invalida");
                        }
			
			T elemElim = arr[pos];
                        //Movemos el array desde la posc hacia la izq
                        for(int i = pos; i < n-2 ;i++){
                        	arr[i] = arr[i+1];
			}
			n--;

			return elemElim;
		}

                T get(int pos) override{
			if(pos < 0 || pos >=max){
                                throw out_of_range("Posicion invalida");
                        }
			return arr[pos];
		}

                int search(T e) override{
			for(int i = 0; i < n-1 ;i++){
				if(arr[i] == e){
					return i;	
				}
               		}
			return -1;
		}

                bool empty() override{
			return n == 0;
		}

                int size() override{return n;}
};
