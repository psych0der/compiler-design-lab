/*


(c) psych0der 
Class for deterministic finite automata
#simulates raw DFA

*/

#include <string>
#include <vector>
#include <map>
#include "states.h"
	
class DeterministicFiniteAutomata
{
private:
	vector<State> states;
	int currentState;
	int startState;
	int totalStates;
	int finalState;
	vector<char>alphabet;
	
public:
	DeterministicFiniteAutomata();
	void insertStates(int);
	void setAlphabet(string);
	bool validateInput(string);
	void setStartState(int);
	void addTransition(int , char, int);
	void makeFinal(int);
	int getFinalState(void);
	bool execute(string);
	
};