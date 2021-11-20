objects = main.o enigma.o plugboard.o reflector.o rotor.o helper.o 

enigma : $(objects)
	g++ -g -Wall $(objects) -o enigma

main.o : main.cpp enigma.h
	g++ -g -Wall -c main.cpp

enigma.o : enigma.cpp enigma.h
	g++ -g -Wall -c enigma.cpp

plugboard.o : plugboard.cpp plugboard.h
	g++ -g -Wall -c plugboard.cpp

reflector.o : reflector.cpp reflector.h
	g++ -g -Wall -c reflector.cpp

helper.o : helper.cpp helper.h
	g++ -g -Wall -c helper.cpp

rotor.o : rotor.cpp rotor.h
	g++ -g -Wall -c rotor.cpp

clean:
	rm enigma.o plugboard.o reflector.o main.o helper.o rotor.o
