/*


(c) psych0der 
Class for deterministic finite automata - states
#simulates individual state

*/

#include <string>
#include <map>

using namespace std;

class State
{

private:

	map<char,int> transitionLookup;
	bool _isFinal;
	int _id;
	

public:

	State(int);
	void insertTransition(char,int);
	int getId();
	void setFinal();
	int getNextState(char);
	bool isFinal();
	

};