/*
 * artikelMain.cpp
 *
 *  Created on: 08.05.2022
 *      Author: freyermuth
 */

//#include "ArtikelDialog.h"
#include "LagerDialog.h"

void starte();

int main(int argc, char **argv) {
	starte();
	return 0;
}

void starte(){
	/*
	ArtikelDialog dialog;
	dialog.starte();*/

	LagerDialog dialog;
	dialog.start();
}


