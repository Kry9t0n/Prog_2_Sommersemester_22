/*
 * ArtikelDialog.cpp
 *
 *  Created on: 16.05.2022
 *      Author: freyermuth
 */
#include "ArtikelDialog.h"

ArtikelDialog::ArtikelDialog(){};

ArtikelDialog::~ArtikelDialog(){
	delete artikel; //reservierten Speicher freigeben
};

void ArtikelDialog::starte(){
	int funktion = -1;

	do {
		gebeDialogAus();
		try{
			funktion = benutzerEingabe();
			fuehreFunktionAus(funktion);
		}catch(const char* error){
			cout << error << endl;
		}
		cout << "\n";
	} while (funktion != BEENDE_PROGRAMM);
}

void ArtikelDialog::gebeDialogAus(){
	cout << "###Benutzerdialog: ###\n"
		 << BEENDE_PROGRAMM << ": Beende Programm\n"
		 << LEGE_NEUES_ARTIKEL_OBJEKT_AN << ": Lege neues Artikel-Objekt an\n"
		 << ERHOEHE_BESTAND << ": Erhoehe den Bestand\n"
		 << VERRINGERE_BESTAND << ": Verringere den Bestand\n"
		 << GEBE_ARTIKEL_AUS << ": Gebe die Artikeldaten aus\n"
		 << PREIS_AENDERN << ": Aendere den Preis\n"
		 << NEUER_BESTAND << ": Setze neuen Bestand\n"
		 << NEUE_BESCHREIBUNG << ": Setze neue Beschreibung\n"
		 << LEGE_NEUEs_ARTIKEL_OBJEKT_OHNE_BESTAND_AN << ": Lege neuen Artikel ohne Bestandsangabe an\n"
		 << "Ihre Eingabe: ";
}

int ArtikelDialog::benutzerEingabe(){
	int eingabe = 0;
	cin >> eingabe;
	return eingabe;
}

void ArtikelDialog::fuehreFunktionAus(int funktion){
	switch(funktion){
	case BEENDE_PROGRAMM:
		cout << "Beende Programm" << endl;
		break;
	case LEGE_NEUES_ARTIKEL_OBJEKT_AN:
		neuenArtikelAnlegen();
		break;
	case ERHOEHE_BESTAND:
		erhoeheBestand();
		break;
	case VERRINGERE_BESTAND:
		verringereBestand();
		break;
	case GEBE_ARTIKEL_AUS:
		gebeArtikelAus();
		break;
	case PREIS_AENDERN:
		aenderePreis();
		break;
	case NEUER_BESTAND:
		neuerBestand();
		break;
	case NEUE_BESCHREIBUNG:
		neueBeschreibung();
		break;
	case LEGE_NEUEs_ARTIKEL_OBJEKT_OHNE_BESTAND_AN:
		neuenArtikelOhneBestandAnlegen();
		break;
	default:
		cout << "Ungeueltige Eingabe!";
	}
}

void ArtikelDialog::neuenArtikelAnlegen(){
	int nummer = 0;
	string beschreibung = "";
	int bestand = 0;
	int preis = 0;

	if(artikel != NULL){
		cout << "Artikel existiert schon!" << endl;
	}else{
		cout << "Welche Nummer bekommt der Artikel?:";
		cin >> nummer;
		cout << "Welche Beschreinung bekommt der Artikel?:";
		cin >> beschreibung;
		cout << "Wie gross soll der Bestand dieses Artikels sein?:";
		cin >> bestand;
		cout << "Welchen Preis soll der Artikel haben?:";
		cin >> preis;

		artikel = new Artikel(nummer, beschreibung, bestand, preis);
	}
}

void ArtikelDialog::neuenArtikelOhneBestandAnlegen(){
	int nummer = 0;
	string beschreibung = "";
	double preis = 0.0;

	if(artikel != NULL){
		cout << "Funktion nicht verfuegbar. Es wurde schon ein Artikel angelegt!" << endl;
	}else{
		cout << "Welche Nummer bekommt der Artikel?";
		cin >> nummer;
		cout << "Welche Beschreibung bekommt der Artikel?";
		cin >> beschreibung;
		cout << "Welchen Preis soll der Artikel haben?";
		cin >> preis;

		artikel = new Artikel(nummer, beschreibung, preis);
	}
}

void ArtikelDialog::erhoeheBestand(){
	int bestandsErhoehung = 0;

	if(artikel == NULL){
		cout << "Es muss erst ein Artikel angelegt werden bevor diese Operation moeglich ist!" << endl;
	}else{
		cout << "Um wie viel soll der Bestand erhoeht werden?:";
		cin >> bestandsErhoehung;
		artikel->erhoeheBestand(bestandsErhoehung);
	}
}

void ArtikelDialog::verringereBestand(){
	int bestandsVerringerung = 0;

	if(artikel == NULL){
		cout << "Es muss erst ein Artikel angelegt werden bevor diese Operation moeglich ist!" << endl;
	}else{
		cout << "Um wie viel soll der Bestand verringert werden?:";
		cin >> bestandsVerringerung;
		artikel->verringereBestand(bestandsVerringerung);
	}
}

void ArtikelDialog::gebeArtikelAus(){
	if(artikel == NULL){
		cout << "Es wurde noch kein Artikel angelegt!" << endl;
	}else{
		cout << artikel->toString();
	}
}

void ArtikelDialog::aenderePreis(){
	double preisAenderung = 0.0;

	if(artikel == NULL){
		cout << "Kein Artikel vorhanden um den Preis zu aendern!";
	}else{
		cout << "Um wie viel Prozent soll der Preis veraendert werden?:";
		cin >> preisAenderung;
		artikel->preisAendern(preisAenderung);
	}
}

void ArtikelDialog::neuerBestand(){
	int neuerBestand = 0;

	if(artikel == NULL){
		cout << "Es wurde noch kein Artikel angelegt!";
	}else{
		cout << "Bitte neuen Bestand eingeben:";
		cin >> neuerBestand;

		artikel->setBestand(neuerBestand);
	}
}

void ArtikelDialog::neueBeschreibung(){
	string neueBeschreibung = "";

	if(artikel == NULL){
		cout << "Es muss erst ein Artikel angelegt werden bevor diese Operation durchgefuerht werden kann!";
	}else{
		cout << "Neue Beschreibung eingeben:";
		cin >> neueBeschreibung;

		artikel->setBeschreibung(neueBeschreibung);
	}
}
