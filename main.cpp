// =================================================================
//
// File: main.cpp
// Author: Alejandra cabrera A01704463
// Date: 6/9/2022
//
// =================================================================
#include <iostream>
#include <vector>
#include "header.h"
#include "search.h"
#include "bubble.h"
#include "selection.h"
#include "insertion.h"
#include "fstream"
using namespace std;

int main(int argc, char* argv[]) {

	//definir las variables
	int n, q, numero,contadorbubble,contadorselection,contadorinsertion;

	//abrir el archivo 
	ifstream inputFile;
	ofstream outputFile;
	outputFile.open(argv[2]);
	inputFile>>n;

	//Imprimir comparaciones de cada algoritmo
	vector<int>numeros;
	numeros.resize(n);

	for (int i=0; i<n; i++) {
		inputFile>>numero;
		numeros[i]=numero;
	}
	vector<int>x=numeros;
	contadorbubble=bubbleSort(x);
	x=numeros;
	contadorselection=selectionSort(x);
	x=numeros;
	contadorinsertion=insertionSort(x);
	outputFile<<contadorbubble<<" "<<contadorselection<<" "<<contadorinsertion<<endl;

	inputFile>>q;
	for (int i=0; i<q;i++){
		inputFile>>numero;
		int salida=sequentialSearch(x,numero);
		outputFile<<salida<<" ";
		int salida2=binarySearch(x,numero);
		outputFile<<salida2<<endl;
	
	}
	inputFile.close();
	outputFile.close();

	return 0;

}
