/*
 * artikelMain.cpp
 *
 *  Created on: 08.05.2022
 *      Author: freyermuth
 */

#include "artikel.h"
#include <iostream>

using namespace std;

void starte();

int main(int argc, char **argv) {
	starte();
	return 0;
}

void starte(){
	int artikelnummer = 0;
	string beschreibung;
	int artikelbestand = 0;
	int erhoehe = 0;
	int verringern = 0;

	cout << "### Benutzerdialog ###" << endl;

	cout << "Artikelnummer eingeben: ";
	cin >> artikelnummer;

	cout << "Artikelbeschreibung eingeben: ";
	/*
	 * mit getline kann eine ganze Zeile eingelesen werden
	 */
	getline(cin >> ws, beschreibung); //der ws Manipulator bewirkt, dass getline whitespaces in dem Inputstream ignoriert.

	cout << "Artikelbestand eingeben: ";
	cin >> artikelbestand;
	//cout << endl;

	Artikel artikel_1(artikelnummer, beschreibung, artikelbestand);

	cout << "Ausgabe ihres neuen Artikels: \n" << artikel_1.toString();

	cout << "Um wie viel wollen Sie den Artikelbestand erhoehen?: ";
	cin >> erhoehe;
	cout << endl;
	artikel_1.erhoeheArtikelBestand(erhoehe);
	cout << artikel_1.toString();

	cout << "Um wie viel wollen Sie den Artikelbestand verringern?: ";
	cin >> verringern;
	cout << endl;
	artikel_1.verringereArtikelBestand(verringern);
	cout << artikel_1.toString();
}


