///////////////////////////////////////////////////////////
//  CompositeStep.cpp
//  Implementation of the Class CompositeStep
//  Created on:      19-mars-2022 11:23:22
//  Original author: Fran�ois
///////////////////////////////////////////////////////////

#include "CompositeStep.h"
#include "AbsRecipeVisitor.h"

CompositeStep::CompositeStep(std::string title)
	: AbsStep(title, 0)
{
}

CompositeStep::CompositeStep(const CompositeStep& mdd)
	: AbsStep(mdd)
{
	// � compl�ter pour copier toutes les sous-�tapes contenues dans l'�tape
	for (auto&& step : mdd.m_stepsContainer) {
		addRecipeComponent(*step);
	}
}

CompositeStep* CompositeStep::clone() const
{
	// � compl�ter pour construire un nouvel objet CompositeStep en appelant le constructeur de copie
	return new CompositeStep(*this);
}

RecipeComponentIterator CompositeStep::begin() {

	return m_stepsContainer.begin();
}


RecipeComponentIterator_const CompositeStep::cbegin() const {

	return m_stepsContainer.cbegin();
}


RecipeComponentIterator_const CompositeStep::cend() const
{
	return m_stepsContainer.cend();
}

RecipeComponentIterator CompositeStep::end()
{
	return  m_stepsContainer.end();
}

AbsRecipeComponent& CompositeStep::addRecipeComponent(const AbsRecipeComponent& member)
{
	const AbsStep& step = dynamic_cast<const AbsStep&>(member);
	return addRecipeComponent(step);
}

AbsRecipeComponent& CompositeStep::addRecipeComponent(const AbsStep& member)
{
	// � compl�ter pour construire par clonage une copie de l'objet re�u en param�tre
	// et l'ins�rer dans le conteneur des �tapes. On retourne une r�f�rence � l'objet
	// qui vient d'�tre ins�r� dans le conteneur.
	m_stepsContainer.push_back(RecipeComponentPtr(member.clone()));

	return *m_stepsContainer.back();
}

void CompositeStep::deleteRecipeComponent(RecipeComponentIterator_const child)
{
	// � compl�ter pour �liminer des �tapes l'�l�ment auquel r�f�re l'it�rateur
	m_stepsContainer.erase(child);
}

void CompositeStep::deleteAllComponents(void)
{
	// � compl�ter pour �liminer tous les �l�ments de l'�tape
	m_stepsContainer.clear();
}

int CompositeStep::getDuration() const
{
	// � compl�ter pour calculer le temps total en sommant la dur�e de toutes les sous-�tapes
	int duration = 0;
	for (auto&& step : m_stepsContainer) {
		duration += step->getDuration();
	}
	return duration;
}

std::ostream& CompositeStep::printToStream(std::ostream& o) const
{
	// � compl�ter pour imprimer sur un stream une �tape et ses sous-�tapes
	o << this->getDescription() << std::endl;
	++m_indent;
	int counter = 0;
	for (auto&& step : m_stepsContainer) {
		counter++;
		indent(o);
		o << counter << " " << *step;
	}
	--m_indent;

	return o;
}

void CompositeStep::accept(class AbsRecipeVisitor& visitor) {
	visitor.processCompositeStep(*this);
}
