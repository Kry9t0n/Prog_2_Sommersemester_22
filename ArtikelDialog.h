/*
 * ArtikelDialog.h
 *
 *  Created on: 16.05.2022
 *      Author: freyermuth
 */

#ifndef ARTIKELDIALOG_H_
#define ARTIKELDIALOG_H_

#include <iostream>
#include "Artikel.h"

using namespace std;

/**
 * Die Klasse beschreibt einen Benutzerdialog.
 */
class ArtikelDialog {
private:
	/**
	 * Konstante um die Methode zu waehlen die das Programm beendet.
	 */
	static const int BEENDE_PROGRAMM  = 0;
	/**
	 * Konstante um die Methode zu waehlen die einen neuen Artikel anlegt.
	 */
	static const int LEGE_NEUES_ARTIKEL_OBJEKT_AN = 1;
	/**
	 * Konstante um die Methode zu waehlen die den Bestand eines Artikels erhoeht.
	 */
	static const int ERHOEHE_BESTAND = 2;
	/**
	 * Konstante um die Methode zu waehlen die den Bestand verringert.
	 */
	static const int VERRINGERE_BESTAND = 3;
	/**
	 * Konstante um die Methode zu waehlen die die Daten des Artikels auf der Konsole ausgibt.
	 */
	static const int GEBE_ARTIKEL_AUS = 4;
	/**
	 * Konstante um die Methode zu waehlen die den Preis eines Artikels aendert.
	 */
	static const int PREIS_AENDERN = 5;
	/**
	 * Konstante um die Methode zu waehlen die einen neuen Bestand eines Artikels setzt.
	 */
	static const int NEUER_BESTAND  = 6;
	/**
	 * Konstante um die Methode zu waehlen die eine neue Beschreibung eines Artikels setzt.
	 */
	static const int NEUE_BESCHREIBUNG = 7;
	/**
	 * Konstane um die Methode zu waehlen die ein neues Artikelobjekt ohne Bestandsangabe anlegt.
	 */
	static const int LEGE_NEUEs_ARTIKEL_OBJEKT_OHNE_BESTAND_AN = 8;

	/**
	 * Ein Pointer auf das dynamisch erzeugte Artikelobjekt.
	 */
	Artikel* artikel = NULL;

	/**
	 * Methode zur Ausgabe des Dialogs auf der Konsole.
	 */
	void gebeDialogAus();

	/**
	 * Methode um die Benutzereingabe von der Konsole zu lesen.
	 */
	int benutzerEingabe();

	/**
	 * Fuehrt anhand der entsprechenden Benutzereingabe die gewollte Funktion aus.
	 * @param funktion Zahl die als entsprechende Funktion interpretiert wird
	 */
	void fuehreFunktionAus(int funktion);

	/**
	 * Legt einen neuen Artikel unter Beachtung aller Attribute an.
	 */
	void neuenArtikelAnlegen();

	/**
	 * Fragt nach der Hoehe der gewuenschten Bestandserhoehung und fuehrt diese durch.
	 */
	void erhoeheBestand();

	/**
	 * Fragt nach der gewuenschten Bestandsverringerung und fuehrt diese durch.
	 */
	void verringereBestand();

	/**
	 * Gibt alle Daten des Artikels auf der Konsole aus.
	 */
	void gebeArtikelAus();

	/**
	 * Fragt nach der prozentualen Preisaenderung und fuehrt diese durch.
	 */
	void aenderePreis();

	/**
	 * Erfragt den gewuenschten neuen Bestand und fuerht die Aenderung am Artikel durch.
	 */
	void neuerBestand();

	/**
	 * Erfragt eine neue Beschreibung und aendert die Beschreibung des Artikels.
	 */
	void neueBeschreibung();
	/**
	 * Legt einen neuen Artikel ohne Bestandsdaten an.
	 */
	void neuenArtikelOhneBestandAnlegen();
public:
	/**
	 * Standard-Konstruktor
	 */
	ArtikelDialog();

	/**
	 * Standard-Destruktor
	 */
	~ArtikelDialog();

	/**
	 * Startet das Programm und laeuft bis zu seinem Ende.
	 */
	void starte();
};




#endif /* ARTIKELDIALOG_H_ */
