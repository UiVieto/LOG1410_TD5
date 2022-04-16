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
	// À compléter: décomposer la durée en nombre de jours, heures, minutes et secondes
	//              retourner le résultat de la décomposition dans un objet time_decomposition
	int secondsDay = 60 * 60 * 24;
	int secondsHour = 60 * 60;
	int secondsMinute = 60;
	int days = time / secondsDay;
	int hours = (time - (days * secondsDay)) / secondsHour;
	int minutes = (time - (days * secondsDay) - (hours * secondsHour)) / secondsMinute;
	int seconds = (time - (days * secondsDay) - (hours * secondsHour) - (minutes * secondsMinute));

	return time_decomposition(days, hours, minutes, seconds);
}

void FormatStrategy::registerFormatStrategy(std::string id, const FormatStrategy* strategy)
{
	// À compléter: insérer la stratégie dans le registre des stratégies de la classe TimeFormater
	TimeFormater& timeFormater = TimeFormater::getInstance();
	timeFormater.registerFormatStrategy(id, strategy);
}
