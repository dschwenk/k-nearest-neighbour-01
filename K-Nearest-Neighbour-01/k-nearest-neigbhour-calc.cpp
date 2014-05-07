#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>

#include "vector.h"
#include "k-nearest-neigbhour-calc.h"

using namespace std;



int calcKNearstNeighbour(Vector* refVektor){	
	
	// stream zur Datei + Datei oeffnen
	ifstream file("points.txt",ios::in);
	if (file.is_open()){

		// Summe Abstand, Summe
		float sum = 0;
		// verwaltet die K kleinsten Abstaende
		float smallestsum[K];
		for(int i=0;i<K;i++){
			smallestsum[i] = 10000000000;
		}		

		// verwaltet die Vektoren mit den k kleinsten Abstaende
		Vector* NearestVektors[K];
		// initialisiere Array mit NULL
		for(int i=0;i<K;i++){
			NearestVektors[i] = NULL;
		}
		for(int i=0;i<K;i++){
			NearestVektors[i] = new Vector(0,0,0,0);
		}
		
		// Daten aus Datei werden in diesen Vektor kopiert
		Vector* FileVektor = new Vector(false);
		
		// es wird zeilenweise aus Datei gelesen und jeweils in line gespeichert
		string line;

		// Datei zeilenweise auslesen
		while(getline(file,line)){
			
			// http://stackoverflow.com/questions/1894886/parsing-a-comma-delimited-stdstring
			// parse String - Elemente zum Vektor hinzufuegen
			stringstream ss(line);
			float punkt = 0;
			int i = 0;
			while(i < ElementeJeVektor){
				ss >> punkt;
				FileVektor->addPoint(punkt);
				if(ss.peek() == ','){
					ss.ignore();
				}
				i++;
			}
			// Klasse parsen und in FileVektor speichern
			int fileclas = -1;
			ss >> fileclas;
			FileVektor->setClas(fileclas);

			// berechene Abstand
			for(int i=0;i<ElementeJeVektor;i++){
				sum += (refVektor->getPoint(i) - FileVektor->getPoint(i)) * (refVektor->getPoint(i) - FileVektor->getPoint(i));
			}

			// ist Abstand kleiner als bisher, NearestVektorArray neu sortieren
			for(int i=0;i<K;i++){
				if(sum < smallestsum[i]){
					//
					// kleinste Summe
					if(i == 0){
						// -> von 3 in 4 uebertragen
						transferVektor(NearestVektors[3], NearestVektors[4]);
						smallestsum[4] = smallestsum[3];
						// -> von 2 in 3 uebertragen
						transferVektor(NearestVektors[2], NearestVektors[3]);
						smallestsum[3] = smallestsum[2];
						// -> von 1 in 2 uebertragen
						transferVektor(NearestVektors[1], NearestVektors[2]);
						smallestsum[2] = smallestsum[1];
						// -> von 0 in 1 uebertragen
						transferVektor(NearestVektors[0], NearestVektors[1]);
						smallestsum[1] = smallestsum[0];
						// Daten in 0 eintragen
						transferVektor(FileVektor, NearestVektors[0]);
						smallestsum[0] = sum;
						break;
					}
					//
					// 2. kleinste Summe
					if(i == 1){
						// -> von 3 in 4 uebertragen
						transferVektor(NearestVektors[3], NearestVektors[4]);
						smallestsum[4] = smallestsum[3];
						// -> von 2 in 3 uebertragen
						transferVektor(NearestVektors[2], NearestVektors[3]);
						smallestsum[3] = smallestsum[2];
						// -> von 1 in 2 uebertragen
						transferVektor(NearestVektors[1], NearestVektors[2]);
						smallestsum[2] = smallestsum[1];
						// Daten in 1 eintragen
						transferVektor(FileVektor, NearestVektors[1]);
						smallestsum[1] = sum;
						break;
					}
					//
					// 3. kleinste Summe
					if(i == 2){
						// -> von 3 in 4 uebertragen
						transferVektor(NearestVektors[3], NearestVektors[4]);
						smallestsum[4] = smallestsum[3];
						// -> von 2 in 3 uebertragen
						transferVektor(NearestVektors[2], NearestVektors[3]);
						smallestsum[3] = smallestsum[2];
						// Daten in 2 eintragen
						transferVektor(FileVektor, NearestVektors[2]);						
						smallestsum[2] = sum;
						break;
					}
					//
					// 4. kleinste Summe
					if(i == 3){
						// -> von 3 in 4 uebertragen
						transferVektor(NearestVektors[3], NearestVektors[4]);
						smallestsum[4] = smallestsum[3];
						// Daten in 3 eintragen
						transferVektor(FileVektor, NearestVektors[3]);
						smallestsum[3] = sum;
						break;
					}
					//
					// 5. kleinste Summe
					if(i == 4){
						// in 4 eintragen
						transferVektor(FileVektor, NearestVektors[4]);
						smallestsum[4] = sum;
						break;
					}
				}
			}
			FileVektor->clear();
			sum = 0;
		}

		// Datei schlieﬂen, naehste Vektoren ausgeben, Klasse zurueckgeben
		file.close();
		
		// Klasse der k-naechsten Vektoren berechnen
		/*
			anderes System zum bestimmen der Klassen erforderlich ... 
		*/
		int getClas = 0;
		int class1 = 0;
		int class2 = 0;
		int class3 = 0;
		int returnclass = 0;
		for(int i=0;i<K;i++){
			getClas = NearestVektors[i]->getClas();
			if(getClas == 1){
				class1++;
			}
			if(getClas == 2){
				class2++;
			}
			if(getClas == 3){
				class3++;
			}
		}
		if((class1 > class2) && (class1 > class3)){
			returnclass = 1;
		}
		if((class2 > class1) && (class2 > class3)){
			returnclass = 2;
		}
		if((class3 > class1) && (class3 > class2)){
			returnclass = 3;
		}

		// k naehste Vektoren ausgeben
		cout << "\nDie " << K << " naehesten Vektor sind: \n";
		for(int i=0;i<K;i++){
			NearestVektors[i]->print();
		}

		return returnclass;
	}
	else {
		cout << "Unable to open file";
		return -1;
	}
}



// uebertrage Punkte und Klasse von SrcVektor in DestVektor
void transferVektor(Vector* SrcVektor, Vector* DestVektor){
	DestVektor->clear();
	for(int i = 0;i<ElementeJeVektor;i++){
		DestVektor->addPoint(SrcVektor->getPoint(i));
	}
	DestVektor->setClas(SrcVektor->getClas());
}