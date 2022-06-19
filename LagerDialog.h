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
	 * Konstruktor
	 * @param lager Lagerobjekt das von dem Dialog verwaltet werden soll.
	 */
	LagerDialog(Lager* lager);
	/**
	 * Standard-Destruktor
	 */
	~LagerDialog();
	/**
	 * Startet den Dialog und laeuft bis zum Ende.
	 */
	void start();
	/**
	 * Getter-Methode fuer das lager Attribut.
	 */
	Lager* getLager(){
		return this->lager;
	}
	/**
	 * setter-Methode fuer das lager Attribut.
	 */
	void setLager(Lager* lager){
		this->lager = lager;
	}

private:
	/**
	 * Konstante um die Methode zu waehlen, die einen neuen Artikel anlegt und ihn im Lager speichert.
	 */
	static const int LEGE_NEUEN_ARTIKEL_AN = 0;
	/**
	 * Konstante um die Methode zu waehlen, die einen neuen Artikel ohne Bestand anlegt und diesen im Lager speichert.
	 */
	static const int LEGE_NEUEN_ARTIKEL_OHNE_BESTAND_AN = 1;
	/**
	 * Konstante um die Methode zu waehlen, die einen Artikel aus dem Lager entfernt.
	 */
	static const int ENTFERNE_ARTIKEL = 2;
	/**
	 * Konstante um die Methode zu waehlen, die einen Zugang fuer einen Artikel bucht.
	 */
	static const int BUCHE_ARTIKEL_ZUGANG = 3;
	/**
	 * Konstante um die Methode zu waehlen, die einen Abgang fuer einen Artikel bucht.
	 */
	static const int BUCHE_ARTIKEL_ABGANG = 4;
	/**
	 * Konstante um die Methode zu waehlen, die die Preise aller Artikel aendert.
	 */
	static const int AENDERE_PREIS = 5;
	/**
	 * Konstante um die Methode zu waehlen, die den Gesamtwert aller im Lager enthaltenen Artikel berechnet.
	 */
	static const int BERECHNE_GESAMT_WERT = 6;
	/**
	 * Konstante um die Methode zu waehlen, die alle Lagerdaten ausgibt.
	 */
	static const int GEBE_LAGER_AUS = 7;
	/**
	 * Konstante um die Methode zu waehlen, mit der man das Lager kopieren kann.
	 */
	static const int LAGER_KOPIEREN = 8;
	/**
	 * Konstante um die Methode zu waehlen, mit der man ein neues Lager erstellt und danach uebernimmt.
	 */
	static const int NEUES_LAGER = 9;
	/**
	 * Konstante um die Methode zu wahlen, die das Programm beendet.
	 */
	static const int BEENDE_PROGRAMM = 10;

	/**
	 * Stringkonstante fuer Fehlerbehandlung bei Wiederverwendung einer bereits genutzen Artikelnummer
	 */
	const string ARTIKELNUMMER_SCHON_VERWENDET = "Artikelnummer ist schon in Verwendung!";
	/**
	 * Stringkonstante fuer Fehlerbehandlung falls gesuchter Artikel nicht gefunden werden konnte.
	 */
	const string ARTIKEL_NICHT_GEFUNDEN = "Artikel nicht gefunden!";
	/**
	 * Pointer auf das dynamisch erzeugte Lagerobjekt.
	 */
	Lager* lager;

	/**
	 * Gibt den Hauptdialog aus.
	 */
	void gebeDialogAus();
	/**
	 * Gibt alle Lagerdaten aus.
	 */
	void gebeLagerAus();
	/**
	 * Liesst Benutzereingaben von der Konsole.
	 */
	int leseBenutzerEingabe();
	/**
	 * Fuehrt eine Funktion anhand einer Benutzereingabe aus.
	 */
	void fuehreFunktionAus(int funktion);
	/**
	 * Erfragt alle noetigen Daten um einen neuen Artikel anzulegen und speichert diesen im Lager.
	 */
	void legeNeuenArtikelAn();
	/**
	 * Erfragt alle noetigen Daten, um einen neuen Artikel ohne Bestand anzulegen und speichert diesen im Lager.
	 */
	void legeNeuenArtikelOhneBestandAn();
	/**
	 * Erfragt die Artikelnummer des zu entfernenden Artikels und loescht ihn falls er vorhanden ist.
	 */
	void entferneArtikel();
	/**
	 * Erfragt Artikelnummer und Zugangsbetrag und bucht diesen Zugang zu dem jeweiligen Artikel hinzu.
	 */
	void bucheArtikelZugang();
	/**
	 * Erfragt Artikelnummer und Abgangsbetrag und bucht diesen Abgang von dem jeweiligen Artikel ab.
	 */
	void bucheArtikelAbgang();
	/**
	 * Erfragt die prozentuelle Preisaenderung und aendert die Preise fuer alle Artikel um diesen Prozentsatz.
	 */
	void aenderePreis();
	/**
	 * Berechnet den Wert aller im Lager enthaltenen Artikel.
	 */
	void berechneGesamtWert();
	/**
	 * Erstellt eine Kopie des Lagers. Diese kann mit einem gesonderten Dialog verwaltet werden. Wird dieser
	 * Dialog beendet, so wird die Kopie geloescht und man kehrt zu dem urspruenglichen Lager zurueck.
	 */
	void kopiereLager();
	/**
	 * Erstellt ein neues Lager und uebernimmt dieses als das zu verwaltende Lager. Bevor
	 * es zu der Uebernahme kommt, koennen Artikel hinzugefuegt werden.
	 */
	void neuesLager();
};
