#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

#include "vector.h"

using namespace std;


Vector::Vector() {
	// Punkte einlesen
	cout << "\nBitte Koordinaten & Klasse eingeben: \n";
	for(int i=0;i<ElementeJeVektor;i++){
		float input = 0;
		do {
			// clear zum zuruecksetzen nach Fehler, sync um Puffer zu leeren
			cin.clear();
			cin.sync();
			cout << "Koordinate: ";
		}
		while(!(cin >> input) && cin.fail());
		v.push_back(input);
		// v.push_back(i); // Fügt i ans Ende von v an.
	}
	do {
		// clear zum zuruecksetzen nach Fehler, sync um Puffer zu leeren
		cin.clear();
		cin.sync();
		cout << "Klasse: ";
	}
	while(!(cin >> this->clas) && cin.fail());
}


Vector::Vector(bool b){
	// nothing to do
};


Vector::Vector(float a, float b, float c, int clas){
	this->v.push_back(a);
	this->v.push_back(b);
	this->v.push_back(c);
	this->clas = clas;
};


void Vector::addPoint(float f){
	this->v.push_back(f);
}


void Vector::addPoints(){
	// v.clear(); Entfernt alle Elemente aus v; leert v.
	this->v.clear();
	// Punkte einlesen
	cout << "\nBitte Punkte eingeben: \n";
	for(int i=0;i<ElementeJeVektor;i++){
		float input = 0;
		do {
			// clear zum zuruecksetzen nach Fehler, sync um Puffer zu leeren
			cin.clear();
			cin.sync();
			cout << "Koordinate: ";
		}
		while(!(cin >> input) && cin.fail());
		this->v.push_back(input);
		// v.push_back(i); // Fügt i ans Ende von v an.
	}
}


void Vector::setClas(){
	// Klasse einlesen
	cout << "\nBitte Klassen eingeben: \n";
	do {
		// clear zum zuruecksetzen nach Fehler, sync um Puffer zu leeren
		cin.clear();
		cin.sync();
		cout << "Klasse: ";
	}
	while(!(cin >> this->clas) && cin.fail());
}


void Vector::setClas(int clas){
	this->clas = clas;
}


float Vector::getPoint(int i){
	return this->v[i];
}


int Vector::getSize(){
	// v.size(); Liefert die Anzahl aller Elemente in v.
	return this->v.size();
}

int Vector::getClas(){
	return this->clas;
}


void Vector::print(){
	// v[n]; Repräsentiert das n. Element in v (ohne zu prüfen, dass n existiert).
	int size = this->getSize();
	for(int i=0;i<size;i++){
		cout << left << setw(8) << v[i] << "  ";
	}
	cout << "|  " << this->clas << "\n";
}


void Vector::clear(){
	this->v.clear();
}


// NON Object functions

void newVector(){
	Vector* Vektor = new Vector();
	writeVectortoFile(Vektor);
}


int writeVectortoFile(Vector* Vektor){

	ofstream file("points.txt",ios::app);
	if (file.is_open()){
		file << "\n" ;
			for(int i=0;i<ElementeJeVektor;i++){
			// schreibe Punkte
			file << Vektor->getPoint(i) << ",";
		}
		// schreibe Klasse
		file << Vektor->getClas();

		// Datei schließen
		file.close();
		cout << "\nPunkt in Datei geschrieben\n\n";
		return 1;
	}
	else {
		cout << "\nKonnte Datei nicht oeffnen!\n\n";
		return 0;
	}

}


void printVectors(){
	string line;
	ifstream file("points.txt",ios::in);
	cout << "\n";
	if (file.is_open()){
		// auslesen
		while(getline(file,line)){
			cout << line << '\n';
		}
		// Datei schließen
		file.close();
		cout << "\n";
	}
	else {
		cout << "\nKonnte Datei nicht oeffnen!\n\n";
	}
}
