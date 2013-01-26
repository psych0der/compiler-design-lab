/*


(c) psych0der 
Class for deterministic finite automata - states
#simulates individual state

*/
#include <cstdlib>
#include <iostream>
#include <stdexcept>


#include "states.h"

using namespace std;

State::State(int n)
{
	this->_id = n;
	this->_isFinal = false;
	cout<<"state q"<<this->_id<<" created\n";
	
}

void State::insertTransition(char c , int s)
{
	this->transitionLookup[c] = s ;
	
}

int State::getId()
{
	return this->_id;
}

void State::setFinal()
{
	this->_isFinal = true;
}

int State::getNextState(char c)
{
	 
	// method [at] throws  out_of_range exeption if key is not found.Prefferd over [] method for error checking
	int nextState;
	try {
	    nextState = this->transitionLookup.at(c);      // vector::at throws an out-of-range
		return nextState;
	  }
	  catch (out_of_range){
		 cout<<"exception id:"<<this->_id<<" -- "<<c;  
	    return -1;
	}
}

bool State::isFinal()
{
	return this->_isFinal;
}


