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
	lager = new Lager(name);
};

LagerDialog::LagerDialog(Lager* lager){
	this->lager = lager;
}

LagerDialog::~LagerDialog(){
	lager->loescheLager();
};


void LagerDialog::start(){
	int funktion = -1;
	do {
		try{
			gebeDialogAus();
			funktion = leseBenutzerEingabe();
			fuehreFunktionAus(funktion);

		}catch(const string& error){
			cout << error << endl;
		}catch(...){
			cout << "Fehler!" << endl;
		}
	} while (funktion != BEENDE_PROGRAMM);
}

void LagerDialog::gebeDialogAus(){
	cout << LEGE_NEUEN_ARTIKEL_AN << ": Neuen Artikel anlegen und im Lager ablegen.\n"
			<< LEGE_NEUEN_ARTIKEL_OHNE_BESTAND_AN << ": Neuen Artikel ohne Bestand anlegen und im Lager ablegen.\n"
			<< ENTFERNE_ARTIKEL << ": Artikel aus dem Lager entfernen.\n"
			<< BUCHE_ARTIKEL_ZUGANG << ": Einen Artikelzugang buchen.\n"
			<< BUCHE_ARTIKEL_ABGANG << ": Einen Artikelabgang buchen.\n"
			<< AENDERE_PREIS << ": Den Preis fuer alle Artikel aendern.\n"
			<< BERECHNE_GESAMT_WERT << ": Gesamtwert aller im Lager enthaltener Artikel berechnen.\n"
			<< GEBE_LAGER_AUS << ": Alle Lagerdaten ausgeben.\n"
			<< LAGER_KOPIEREN << ": Lager kopieren.\n"
			<< NEUES_LAGER << ": Neues Lager erstellen.\n"
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
	case GEBE_LAGER_AUS:
		gebeLagerAus();
		break;
	case LAGER_KOPIEREN:
		kopiereLager();
		break;
	case NEUES_LAGER:
		neuesLager();
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

	if(!lager->istArtikelnummerBelegt(artikelnummer)){
		lager->legeNeuenArtikelAn(new Artikel(artikelnummer, beschreibung, bestand, preis));
	}else{
		throw ARTIKELNUMMER_SCHON_VERWENDET;
	}

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

	if(!lager->istArtikelnummerBelegt(artikelnummer)){
		lager->legeNeuenArtikelAn(new Artikel(artikelnummer, beschreibung, preis));
	}else{
		throw ARTIKELNUMMER_SCHON_VERWENDET;
	}
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
	double prozent = 0.0;

	cout << "prozentuale Aenderung: ";
	cin >> prozent;

	lager->aenderePreis(prozent);
}

void LagerDialog::berechneGesamtWert(){
	cout << "Gesamtwert: " << lager->berechneGesamtWert() << endl;
}

void LagerDialog::gebeLagerAus(){
	cout << lager->toString() << endl;
}

void LagerDialog::kopiereLager(){
	char kopieUebernehmen;
	Lager neuesLager(*lager);
	cout << "### Dialogverwaltung Lagerkopie ###\n";
	LagerDialog neuerDialog(&neuesLager);
	neuerDialog.start();
}

void LagerDialog::neuesLager(){
	string lagerName;
	int artikelNummer = 0;
	string artikelBeschreibung;
	int artikelBestand = 0;
	double artikelPreis = 0.0;
	char benutzerEingabe;
	bool weiterEinlesen = true;

	cout << "Name des Lagers: ";
	cin >> lagerName;
	Lager neuesLager(lagerName); //lokales Objekt

	while(weiterEinlesen){
		cout << "Artikel hinzuguegen? (j/n): ";
		cin >> benutzerEingabe;
		if(benutzerEingabe == 'j' || benutzerEingabe == 'J'){
			cout << "Artikelnummer: ";
			cin >> artikelNummer;
			cout << "Beschreibung: ";
			cin >> artikelBeschreibung;
			cout << "Bestand:";
			cin >> artikelBestand;
			cout << "Preis: ";
			cin >> artikelPreis;
			if(!neuesLager.istArtikelnummerBelegt(artikelNummer)){
				neuesLager.legeNeuenArtikelAn(new Artikel(artikelNummer, artikelBeschreibung, artikelBestand, artikelPreis));
			}else{
				cout << ARTIKELNUMMER_SCHON_VERWENDET << endl;
			}

		}else if(benutzerEingabe == 'n' || benutzerEingabe == 'N'){
			cout << "Lager wird gespeichert...\n";
			weiterEinlesen = false;
		}else{
			cout << "Ungueltige Eingabe bitte wiederholen!\n";
		}
	}

	*lager = neuesLager;
}





