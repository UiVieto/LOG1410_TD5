///////////////////////////////////////////////////////////
//  NumericFormatStrategy.cpp
//  Implementation of the Class NumericFormatStrategy
//  Created on:      02-avr.-2022 14:16:27
//  Original author: francois
///////////////////////////////////////////////////////////

#include "NumericFormatStrategy.h"

NumericFormatStrategy NumericFormatStrategy::instance;

NumericFormatStrategy::NumericFormatStrategy()
	: FormatStrategy(NumericFormat)
{
}

std::string NumericFormatStrategy::format(int time) const 
{
	// À compléter: décomposer la durée et construire une chaine avec en format numérique
	time_decomposition time_dec = decomposeTime(time);

	std::string affichage = std::to_string(time_dec.days) + " : " + std::to_string(time_dec.hours) + " : " + std::to_string(time_dec.minutes) + " : " + std::to_string(time_dec.seconds);
	return affichage;
}