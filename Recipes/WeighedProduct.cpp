#include <string>

#include "WeighedProduct.h"

WeighedProduct::WeighedProduct(std::string name, std::string origin, int weigth, float price)
	: AbsProduct(name, origin), m_weight(weigth), m_price(price)
{
}

AbsCatalogComponent* WeighedProduct::clone(void) const
{
	// └ complÚter pour construire un nouvel objet WeighedProduct en appelant le constructeur de copie
	return new WeighedProduct(*this);
}

float WeighedProduct::getPrice() const
{
	return m_price;
}

void WeighedProduct::setQuantityPrice(int weight, float price)
{
	m_weight = weight;
	m_price = price;
}

int WeighedProduct::getQuantity() const
{
	return m_weight;
}

std::ostream& WeighedProduct::printToStream(std::ostream& o) const
{
	// └ complÚter pour imprimer sur un stream un produit vendu au poids
	o << this->getName() << "(from " << this->getOrigin() << ") $" << this->getPrice() << " (" << this->getQuantity() << "g)" << std::endl;
	return o;
}
