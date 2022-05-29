/*
 * LagerDialog.cpp
 *
 *  Created on: 29.05.2022
 *      Author: freyermuth
 */

#include "LagerDialog.h"

LagerDialog::LagerDialog(){
	string name;
	cout << "Bitte Namen des Lagers eingeben: ";
	cin >> name;
	lager = Lager(name);
};

LagerDialog::~LagerDialog(){};


void LagerDialog::start(){
	int funktion = -1;
	do {
		try{
			gebeDialogAus();
			funktion = leseBenutzerEingabe();
			fuehreFunktionAus(funktion);

		}catch(char* error){
			cout << error << endl;
		}
	} while (funktion != BEENDE_PROGRAMM);
}

void LagerDialog::gebeDialogAus(){
	cout << LEGE_NEUEN_ARTIKEL_AN << ": Neuen Artikel anlegen und im Lager ablegen.\n"
			<< LEGE_NEUEN_ARTIKEL_OHNE_BESTAND_AN << ": Neuen Artikel ohne Bestand anlegen und im Lager ablegen.\n"
			<< ENTFERNE_ARTIKEL << ": Artikel aus dem Lager entfernen.\n"
			<< BUCHE_ARTIKEL_ZUGANG << ": Einen Artikelzugang buchen.\n"
			<< BUCHE_ARTIKEL_ABGANG << ": Einen Artikelabgang buchen.\n"
			<< AENDERE_PREIS << ": Den Preis fuer einen Artikel aendern.\n"
			<< BERECHNE_GESAMT_WERT << ": Gesamtwert aller im Lager enthaltener Artikel berechnen.\n"
			<< BEENDE_PROGRAMM << ": Programm beenden. Lager samt allen Artikeln wird geloescht.\n"
			<< "Ihre Eingabe >> ";
}

int LagerDialog::leseBenutzerEingabe(){
	int eingabe = -1;
	cin >> eingabe;
	return eingabe;
}

void LagerDialog::fuehreFunktionAus(int funktion){
	switch(funktion){
	case LEGE_NEUEN_ARTIKEL_AN:
		legeNeuenArtikelAn();
		break;
	case LEGE_NEUEN_ARTIKEL_OHNE_BESTAND_AN:
		legeNeuenArtikelOhneBestandAn();
		break;
	case ENTFERNE_ARTIKEL:
		entferneArtikel();
		break;
	case BUCHE_ARTIKEL_ZUGANG:
		bucheArtikelZugang();
		break;
	case BUCHE_ARTIKEL_ABGANG:
		bucheArtikelAbgang();
		break;
	case AENDERE_PREIS:
		aenderePreis();
		break;
	case BERECHNE_GESAMT_WERT:
		berechneGesamtWert();
		break;
	case BEENDE_PROGRAMM:
		cout << "Programm wird beendet..." << endl;
		break;
	default:
		cout << "Ungueltige Eingabe" << endl;
	}
}

void LagerDialog::legeNeuenArtikelAn(){
	int artikelnummer = 0;
	int bestand;
	double preis;
	string beschreibung;

	cout << "Artikelnummer: ";
	cin >> artikelnummer;
	cout << "Beschreibung: ";
	getline(cin >> ws, beschreibung);
	cout << "Bestand: ";
	cin >> bestand;
	cout << "Preis: ";
	cin >> preis;

	lager->legeNeuenArtikelAn(new Artikel(artikelnummer, beschreibung, bestand, preis));
}

void LagerDialog::legeNeuenArtikelOhneBestandAn(){
	int artikelnummer = 0;
	double preis = 0.0;
	string beschreibung;

	cout << "Artikelnummer: ";
	cin >> artikelnummer;
	cout << "Beschreibung: ";
	getline(cin >> ws, beschreibung);
	cout << "Preis: ";
	cin >> preis;

	lager->legeNeuenArtikelAn(new Artikel(artikelnummer, beschreibung, preis));
}

void LagerDialog::entferneArtikel(){
	int artikelnummer = 0;

	cout << "Artikelnummer: ";
	cin >> artikelnummer;

	lager->entferneArtikel(artikelnummer);
}

void LagerDialog::bucheArtikelZugang(){
	int zugang = 0;
	int nummer = 0;

	cout << "Artikelnummer: ";
	cin >> nummer;
	cout << "Zugangsbetrag: ";
	cin >> zugang;

	lager->bucheArtikelZugang(nummer, zugang);
}

void LagerDialog::bucheArtikelAbgang(){
	int abgang = 0;
	int nummer = 0;

	cout << "Artikelnummer: ";
	cin >> nummer;
	cout << "Abgangsbetrag: ";
	cin >> abgang;

	lager->bucheArtikelAbgang(nummer, abgang);
}

void LagerDialog::aenderePreis(){
	int artikelnummer = 0;
	double prozent = 0.0;

	cout << "Artikelnummer: ";
	cin >> artikelnummer;
	cout << "prozentuale Aenderung: ";
	cin >> prozent;

	lager->aenderePreis(artikelnummer, prozent);
}

void LagerDialog::berechneGesamtWert(){
	cout << "Gesamtwert: " << lager->berechneGesamtWert() << endl;
}










