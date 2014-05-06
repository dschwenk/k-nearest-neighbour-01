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

		// Summe Abstand, Summe kleinster Abstand
		float sum = 0;
		float smallestsum[K];
		for(int i=0;i<K;i++){
			smallestsum[i] = 10000000000;
		}		


		Vector* NearestVektors[K];
		// initialisiere Array mit NULL
		for(int i=0;i<K;i++){
			NearestVektors[i] = NULL;
		}
		for(int i=0;i<K;i++){
			NearestVektors[i] = new Vector(0,0,0,0);
		}
		
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

			// ist Abstand kleiner als bisher, NearestVektors neu sortieren + Daten einfuegen
			for(int i=0;i<K;i++){
				if(sum < smallestsum[i]){
					//
					// kleinste Summe
					if(i == 0){
						// -> von 3 in 4 uebertragen
						NearestVektors[4]->clear();
						for(int i = 0;i<ElementeJeVektor;i++){
							NearestVektors[4]->addPoint((NearestVektors[3]->getPoint(i)));
						}
						NearestVektors[4]->setClas(NearestVektors[3]->getClas());
						smallestsum[4] = smallestsum[3];
						
						// -> von 2 in 3 uebertragen
						NearestVektors[3]->clear();
						for(int i = 0;i<ElementeJeVektor;i++){
							NearestVektors[3]->addPoint((NearestVektors[2]->getPoint(i)));
						}
						NearestVektors[3]->setClas(NearestVektors[2]->getClas());
						smallestsum[3] = smallestsum[2];

						// -> von 1 in 2 uebertragen
						NearestVektors[2]->clear();
						for(int i = 0;i<ElementeJeVektor;i++){
							NearestVektors[2]->addPoint((NearestVektors[1]->getPoint(i)));
						}
						NearestVektors[2]->setClas(NearestVektors[1]->getClas());
						smallestsum[2] = smallestsum[1];

						// -> von 0 in 1 uebertragen
						NearestVektors[1]->clear();
						for(int i = 0;i<ElementeJeVektor;i++){
							NearestVektors[1]->addPoint((NearestVektors[0]->getPoint(i)));
						}
						NearestVektors[1]->setClas(NearestVektors[0]->getClas());
						smallestsum[1] = smallestsum[0];

						// Daten in 0 eintragen
						NearestVektors[0]->clear();
						for(int i = 0;i<ElementeJeVektor;i++){
							NearestVektors[0]->addPoint((FileVektor->getPoint(i)));
						}
						NearestVektors[0]->setClas(FileVektor->getClas());
						smallestsum[0] = sum;

						break;


					}
					//
					// 2. kleinste Summe
					if(i == 1){
						// -> von 3 in 4 uebertragen
						NearestVektors[4]->clear();
						for(int i = 0;i<ElementeJeVektor;i++){
							NearestVektors[4]->addPoint((NearestVektors[3]->getPoint(i)));
						}
						NearestVektors[4]->setClas(NearestVektors[3]->getClas());
						smallestsum[4] = smallestsum[3];
						
						// -> von 2 in 3 uebertragen
						NearestVektors[3]->clear();
						for(int i = 0;i<ElementeJeVektor;i++){
							NearestVektors[3]->addPoint((NearestVektors[2]->getPoint(i)));
						}
						NearestVektors[3]->setClas(NearestVektors[2]->getClas());
						smallestsum[3] = smallestsum[2];
						
						// -> von 1 in 2 uebertragen
						NearestVektors[2]->clear();
						for(int i = 0;i<ElementeJeVektor;i++){
							NearestVektors[2]->addPoint((NearestVektors[1]->getPoint(i)));
						}
						NearestVektors[2]->setClas(NearestVektors[1]->getClas());
						smallestsum[2] = smallestsum[1];

						// Daten in 1 eintragen
						NearestVektors[1]->clear();
						for(int i = 0;i<ElementeJeVektor;i++){
							NearestVektors[1]->addPoint((FileVektor->getPoint(i)));
						}
						NearestVektors[1]->setClas(FileVektor->getClas());
						smallestsum[1] = sum;
						
						break;
					}
					//
					// 3. kleinste Summe
					if(i == 2){
						// -> von 3 in 4 uebertragen
						NearestVektors[4]->clear();
						for(int i = 0;i<ElementeJeVektor;i++){
							NearestVektors[4]->addPoint((NearestVektors[3]->getPoint(i)));
						}
						NearestVektors[4]->setClas(NearestVektors[3]->getClas());
						smallestsum[4] = smallestsum[3];
						
						// -> von 2 in 3 uebertragen
						NearestVektors[3]->clear();
						for(int i = 0;i<ElementeJeVektor;i++){
							NearestVektors[3]->addPoint((NearestVektors[2]->getPoint(i)));
						}
						NearestVektors[3]->setClas(NearestVektors[2]->getClas());
						smallestsum[3] = smallestsum[2];

						// Daten in 2 eintragen
						NearestVektors[2]->clear();
						for(int i = 0;i<ElementeJeVektor;i++){
							NearestVektors[2]->addPoint((FileVektor->getPoint(i)));
						}
						NearestVektors[2]->setClas(FileVektor->getClas());
						smallestsum[2] = sum;

						break;
					}
					//
					// 4. kleinste Summe
					if(i == 3){
						// -> von 3 in 4 uebertragen
						NearestVektors[4]->clear();
						for(int i = 0;i<ElementeJeVektor;i++){
							NearestVektors[4]->addPoint((NearestVektors[3]->getPoint(i)));
						}
						NearestVektors[4]->setClas(NearestVektors[3]->getClas());
						smallestsum[4] = smallestsum[3];

						// Daten in 3 eintragen
						NearestVektors[3]->clear();
						for(int i = 0;i<ElementeJeVektor;i++){
							NearestVektors[3]->addPoint((FileVektor->getPoint(i)));
						}
						NearestVektors[3]->setClas(FileVektor->getClas());
						smallestsum[3] = sum;

						break;
					}
					//
					// 5. kleinste Summe
					if(i == 4){
						// in 4 eintragen
						NearestVektors[4]->clear();
						for(int i = 0;i<ElementeJeVektor;i++){
							NearestVektors[4]->addPoint((FileVektor->getPoint(i)));
						}
						NearestVektors[4]->setClas(FileVektor->getClas());
						smallestsum[4] = sum;

						break;
					}

				}
			}
			FileVektor->clear();
			sum = 0;
		}

		// Datei schlieﬂen, naehster Vektor ausgeben, Klasse zurueckgeben
		file.close();
		
		// Klasse der k-naechsten Vektoren berechnen
		int class1 = 0;
		int class2 = 0;
		int class3 = 0;
		int returnclass = 0;
		for(int i=0;i<K;i++){
			if(NearestVektors[i]->getClas() == 1){
				class1++;
			}
			if(NearestVektors[i]->getClas() == 2){
				class2++;
			}
			if(NearestVektors[i]->getClas() == 3){
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
		// cout << "\nDer naeheste Vektor ist: \n";
		// NearestVektors[i]->print();
		return returnclass;
	}
	else {
		cout << "Unable to open file";
		return -1;
	}
}