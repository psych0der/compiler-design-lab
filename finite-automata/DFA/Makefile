dfa : DFA.o states.o dfa-tester.cpp states.o 
	g++ -g -o dfa dfa-tester.cpp DFA.o states.o
	
DFA.o : DFA.cpp DFA.h states.h states.cpp
	g++ -c DFA.cpp
	
states.o : states.cpp states.h
	g++ -c states.cpp