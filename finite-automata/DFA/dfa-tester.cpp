/*


(c) psych0der 
DFA-simulation test

*/

#include <iostream>
#include "DFA.h"

using namespace std;	
int main()
{
	
	DeterministicFiniteAutomata dfa;
	dfa.setAlphabet("01");
	dfa.insertStates(3); // creation of states
	dfa.makeFinal(2);			// sets state 2 as final
	
	/* transition definition */

	dfa.addTransition(0, '1', 1);
	dfa.addTransition(1, '1', 2);
	dfa.addTransition(1, '0', 0);
	dfa.addTransition(2, '0', 1);
	dfa.addTransition(0, '0', 0);
	dfa.addTransition(2, '1', 2);
	
	/* executiong dfa */
	if(dfa.execute("01011"))
		cout<<"string accepted!!";
	else
		cout<<"string rejected";
	
	
	cout<<"\nfinal state : " <<dfa.getFinalState()<<"\n";
	
	
	
return 0;	
}

