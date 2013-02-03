/*


(c) psych0der 
DFA-simulation test

*/

#include <iostream>
#include "DFA/DFA.h"

using namespace std;	
int main()
{
	
	DeterministicFiniteAutomata dfa;
	dfa.setAlphabet("01");
	
	dfa.insertStates(3);
	dfa.makeFinal(2);
	/* transitions IMPORTANT!! 2nd agument is character type */
	
	dfa.addTransition(0,'1',2);
	dfa.addTransition(0,'0',1);
	dfa.addTransition(1,'1',2);
	dfa.addTransition(1,'0',1);
	dfa.addTransition(2,'1',2);
	dfa.addTransition(2,'0',1);
	
	/* implementation pending */
	if(dfa.execute("101001"))
		cout<<"string accepted \n";
	else
		cout<<"string rejected \n";
	
	
return 0;	
}

