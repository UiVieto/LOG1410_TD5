///////////////////////////////////////////////////////////
//  FormatStrategy.cpp
//  Implementation of the Class FormatStrategy
//  Created on:      02-avr.-2022 14:16:26
//  Original author: francois
///////////////////////////////////////////////////////////

#include "FormatStrategy.h"
#include "TimeFormater.h"

FormatStrategy::FormatStrategy(std::string id)
{
	registerFormatStrategy(id, this);
}

FormatStrategy::time_decomposition FormatStrategy::decomposeTime(int time) const
{
	// � compl�ter: d�composer la dur�e en nombre de jours, heures, minutes et secondes
	//              retourner le r�sultat de la d�composition dans un objet time_decomposition

	return time_decomposition();
}

void FormatStrategy::registerFormatStrategy(std::string id, const FormatStrategy* strategy)
{
	// � compl�ter: ins�rer la strat�gie dans le registre des strat�gies de la classe TimeFormater
}
