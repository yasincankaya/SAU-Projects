all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/SayilarListesi.cpp -o ./lib/SayilarListesi.o
bagla:
	g++ ./lib/SayilarListesi.o ./lib/Dugum.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program