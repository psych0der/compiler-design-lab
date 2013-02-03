/*


(c) psych0der 
Class for deterministic finite automata
#simulates raw DeterministicFiniteAutomata

*/

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include "DFA.h"
	

DeterministicFiniteAutomata::DeterministicFiniteAutomata()
{
	this->totalStates = 0;
	this->currentState = 0;
	this->startState = 0;
	this->finalState = 0;
	
}

void DeterministicFiniteAutomata::setStartState(int n)
{
	this->startState = n;
}
void DeterministicFiniteAutomata::setAlphabet(string s)
{
	if(s[0]=='[' && s[4] ==']')
	{
		for(char c = s[1] ;  c <=s[3];c++)
			alphabet.push_back(c);
		
		for(int i =5;i<s.length();i++)
			{
				alphabet.push_back(s[i]);
		
			}
		
	}
	else
	{
		for(int i =0;i<s.length();i++)
			{
				alphabet.push_back(s[i]);
		
			}
	}	
	
}

bool DeterministicFiniteAutomata::validateInput(string input)
{
	for(int i=0;i<input.length();i++)
		if(find(this->alphabet.begin(),this->alphabet.end(),input[i])== this->alphabet.end())
			return false;
	return true;
}

void DeterministicFiniteAutomata::insertStates(int num)
{
	
	for(int i=0;i<num;i++)
	{
		State s(this->totalStates++);
		this->states.push_back(s);
	}
}

void DeterministicFiniteAutomata::addTransition(int source , char c, int destination)
{
	
	this->states[source].insertTransition(c,destination);
	
}

void DeterministicFiniteAutomata::makeFinal(int n)
{
	this->states[n].setFinal();
}

int DeterministicFiniteAutomata::getFinalState(void)
{
		
	return this->finalState;
		
}

bool DeterministicFiniteAutomata::execute(string input)
{
	
	cout<<"\nstart state :q"<<this->startState<<"\n";
	char c;
	int next;
	bool valid = this->validateInput(input);
	if(!valid)
	{
		cout<<"input string consist of illegal characters\n";
		return false;
	}
	this->currentState  = this->startState;
	for(int i=0;i<input.length();i++)
	{
		c = input.at(i);
		next = states[this->currentState].getNextState(c);
		if(next == -1)
			return false;
		this->currentState = next;
		
	}
	this->finalState = this->currentState;
	if(this->states[this->currentState].isFinal())
		return true;
	else
		return false;
	
}


