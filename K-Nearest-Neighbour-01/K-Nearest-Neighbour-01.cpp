// K-Nearest-Neighbour-01.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <time.h>

#include "vector.h"
#include "k-nearest-neigbhour-calc.h"


int main(){
	
	// Vektor, zu dem der naehste Vektor gesucht werden soll
	Vector* ReferenzVektor = new Vector(0,0,0,0);

	// Rueckgabe Klasse des naehste Vektors
	int clas = 0;

	// benoetigt fuer Menuauswahl
	char inputChoice = '\0';

	// Zeit messen
	// http://stefanhermann.com/?p=10
	//Definierung der Zeit-Variablen
	clock_t ClockStartSort;
	clock_t ClockEndSort;
	float neededTime = 0;

	while(true){
		cout << "Was wollen Sie tun?\n";
		cout <<	"v - Vektor anlegen und zur Datei hinzufuegen\n";
		cout << "l - Vektoren ausgeben\n";
		cout << "r - Referenzvektor anpassen\n";
		cout << "a - Referenzvektor ausgeben\n";
		cout << "n - Naehster Vektor berechnen\n";
		cout << "q - Programmende\n";
		cout << "Auswahl: ";

		cin >> inputChoice;

		switch(inputChoice){
			// neuer Vektor einlesen und in Datei schreiben
			case 'v':
				newVector();
				break;
			// Vektoren aus Datei auflisten
			case 'l':
				printVectors();
				break;
			// Referenzvektor anpassen
			case 'r':
				ReferenzVektor->addPoints();
				// ReferenzVektor->setClas();
				cout << "\nReferenzvektor angepasst.\n\n";
				break;
			// Referenzvektor ausgeben			
			case 'a':
				cout << "\nReferenzVektor: \n";				
				ReferenzVektor->print();
				cout << "\n";
				break;
			// berechne kleinsten Abstand Vektoren aus Datei - Referenzvektor, zurueckgegeben wird Klasse des naehsten Vektors
			case 'n':
				ClockStartSort = clock(); //CPU-Zeit zu Beginn des Programmes
				clas = calcKNearstNeighbour(ReferenzVektor);
				cout << "\nKlasse: " << clas << "\n\n";
				ClockEndSort=clock(); //CPU-Zeit am Ende des Programmes
				neededTime = (float)(ClockEndSort-ClockStartSort) / CLOCKS_PER_SEC; // Differenz Ende-Start -> Laufzeit
				cout << "Benoetigte Zeit: " << neededTime << "s\n\n";
				break;
			// Verlassen
			case 'q':
				// Objekte loeschen
				delete ReferenzVektor;
				return 0;
			default:
				cout << "\nUngueltige Eingabe!\n\n";
		}
	}	
	
	return 0;
}