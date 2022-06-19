CC = g++
OUTPUT = lagerProgramm
OBJ = Artikel.o LagerDialog.o artikelMain.o Lager.o
CXXFLAGS = -std=c11-std -Wall -pedantic

artikelPrgramm: ${OBJ}
	${CC} ${OBJ} -o ${OUTPUT}
Artikel.o:
	${CC} -c Artikel.cpp
LagerDialog.o:
	${CC} -c LagerDialog.cpp
artikelMain.o:
	${CC} -c artikelMain.cpp
Lager.o:
	${CC} -c Lager.cpp
clean:
	rm ${OBJ} ${OUTPUT}
