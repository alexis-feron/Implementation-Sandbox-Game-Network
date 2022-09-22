exe   : objet.o 	reseau.o 	objetMat.o reseauMat.o main.o
	g++ objet.o reseau.o 	objetMat.o reseauMat.o main.o -o exe

objet.o : objet.cpp objet.hpp 
	g++ -c objet.cpp

reseau.o : reseau.cpp reseau.hpp 
	g++ -c reseau.cpp

objetMat.o : objetMat.cpp objetMat.hpp 
	g++ -c objetMat.cpp

reseauMat.o : reseauMat.cpp reseauMat.hpp 
	g++ -c reseauMat.cpp

main.o : main.cpp objet.hpp reseau.hpp objetMat.hpp reseauMat.hpp
	g++ -c main.cpp

clean :
	rm *.o exe