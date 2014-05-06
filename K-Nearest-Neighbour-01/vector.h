#pragma once

#include <vector>
#include <string>

using namespace std;

// Anzahl an Elementen je Vektor
static const int ElementeJeVektor = 3;


class Vector {
	public:
		Vector();
		Vector(bool);
		Vector(float,float,float,int);
		void addPoint(float);
		void addPoints();
		void setClas();
		void setClas(int);
		float getPoint(int);
		int getSize();
		int getClas();
		void print();
		void clear();
	protected:
		int clas;
		std::vector<float> v;
		/* http://de.wikibooks.org/wiki/C++-Programmierung:_Vector
		vector<T> v(n, val); Deklariert v als vector, der bereits n Elemente vom Typ T mit dem Wert val enthält.
		*/
};


void newVector();
int writeVectortoFile(Vector* Vektor);
void printVectors();