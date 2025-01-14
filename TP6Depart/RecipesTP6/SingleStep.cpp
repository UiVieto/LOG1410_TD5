///////////////////////////////////////////////////////////
//  SingleStep.cpp
//  Implementation of the Class SingleStep
//  Created on:      19-mars-2022 11:14:24
//  Original author: francois
///////////////////////////////////////////////////////////

#include "SingleStep.h"
#include "AbsRecipeVisitor.h"

SingleStep::SingleStep(std::string description, int duration)
	: AbsStep(description, duration)
{
}

SingleStep* SingleStep::clone() const
{
	// � compl�ter pour construire une nouvelle �tape simple en appelant le constructeur de copie
	return new SingleStep(*this);
}

std::ostream& SingleStep::printToStream(std::ostream& o) const
{
	// � compl�ter pour imprimer sur un stream une �tape
	o << this->getDescription() << std::endl;
	return o;
}

void SingleStep::accept(class AbsRecipeVisitor& visitor) {
	visitor.processSingleStep(*this);
}