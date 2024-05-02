all: cadenas_main

cadenas_main: cadenas_main.o cadenas_func.o simbolo.o lenguajes.o
	g++ -o cadenas_main cadenas_main.o cadenas_func.o simbolo.o lenguajes.o -std=c++2a

cadenas_func.o: cadenas_func.cc
	g++ -c -o cadenas_func.o cadenas_func.cc -std=c++2a

cadenas_main.o: cadenas_main.cc
	g++ -c -o cadenas_main.o cadenas_main.cc -std=c++2a

simbolo.o: simbolo.cc
	g++ -c -o simbolo.o simbolo.cc -std=c++2a

lenguajes.o: lenguajes.cc
	g++ -c -o lenguajes.o lenguajes.cc -std=c++2a

clean:
	-rm cadenas_main.o cadenas_func.o simbolo.o lenguajes.o cadenas_main