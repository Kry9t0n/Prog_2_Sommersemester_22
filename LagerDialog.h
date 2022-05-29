/*
 * LagerDialog.h
 *
 *  Created on: 28.05.2022
 *      Author: freyermuth
 */
#include "Lager.h"
#include <iostream>

using namespace std;
/**
 * Beschreibt einen Benutzerdialog um das Lagerprogramm per Konsole zu bedienen.
 */
class LagerDialog{
public:
	/**
	 * Standardkonstruktor
	 */
	LagerDialog();
	/**
	 * Standard-Destruktor
	 */
	~LagerDialog();
	/**
	 * Startet den Dialog und laeuft bis zum Ende.
	 */
	void start();

private:
	static const int LEGE_NEUEN_ARTIKEL_AN = 0;
	static const int LEGE_NEUEN_ARTIKEL_OHNE_BESTAND_AN = 1;
	static const int ENTFERNE_ARTIKEL = 2;
	static const int BUCHE_ARTIKEL_ZUGANG = 3;
	static const int BUCHE_ARTIKEL_ABGANG = 4;
	static const int AENDERE_PREIS = 5;
	static const int BERECHNE_GESAMT_WERT = 6;
	static const int BEENDE_PROGRAMM = 7;


	Lager* lager;

	void gebeDialogAus();
	int leseBenutzerEingabe();
	void fuehreFunktionAus(int funktion);
	void legeNeuenArtikelAn();
	void legeNeuenArtikelOhneBestandAn();
	void entferneArtikel();
	void bucheArtikelZugang();
	void bucheArtikelAbgang();
	void aenderePreis();
	void berechneGesamtWert();
};
