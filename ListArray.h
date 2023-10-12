#include <ostream>
#include <iostream>
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
    	ListArray(){
		max = MINSIZE;
		n = 0;
		arr = new T[MINSIZE];
	};
	~ListArray(){delete[] arr;};

	T operator[](int pos){
		if(pos < 0 || pos >=max){
			throw out_of_range("Posicion invalida");
		}else{
			return arr[pos];
		}
	}

	friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
		out << "List => [";
		if(list.n > 0){
			for(int i = 0; i < list.n ; i++){
				out << "\n\t" << list.arr[i];
			}

			out << "\n]";
		}else{
			out << "]";
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

			if((n + 1) > max){
				resize(n + 1);
			}

			
			//Creamos hueco para el array haciendo que el array principal se mueva a la derech
			//la cantidad de elementos que el que insertamos tenga, a excepción de si se va a insertar al final
			
			if(pos > n-1 || n == 0){
				arr[n] = e;
			}else{
				for(int i = 0,x = n,m = pos; m < n ;i++,m++){
					arr[x-i] = arr[(x-i)-1];
				}

				arr[pos] = e;
			}
			n+=1;
		
		}

                void append(T e) override{
			insert(n,e);
		}

                void prepend(T e) override{
			insert(0,e);
		}

                T remove(int pos) override{
			if(pos < 0 || pos >=max || n == 0 || pos >=n){
                                throw out_of_range("Posicion invalida");
                        }
			
			T elemElim = arr[pos];
                        //Movemos el array desde la posc hacia la izq
                        if(pos == n-1){
				arr[pos] = -1;
			}else{
				for(int i = pos; i < n-1 ;i++){
                        		arr[i] = arr[i+1];
				}
			}
			n--;

			return elemElim;
		}

                T get(int pos) override{
			if(pos < 0 || pos >=max || pos >= n){
                                throw out_of_range("Posicion invalida");
                        }
			return arr[pos];
		}

                int search(T e) override{
			for(int i = 0; i < n ;i++){
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
