#include "ObjectClassifier.h"


// _________ Methods _________
bool ObjectClassifier::isSoldier(AOnBoard * pointer)
{
	Soldier* p = nullptr;
	try
	{
		p = dynamic_cast<Soldier*>(pointer);
	}
	catch (...) {}
	return p != nullptr;
}

bool ObjectClassifier::isParamedic(AOnBoard * pointer)
{
	ParamedicSoldier* p = nullptr;
	try
	{
		p = dynamic_cast<ParamedicSoldier*>(pointer);
	}
	catch (...) {}
	return p != nullptr;
}

bool ObjectClassifier::isAItem(AOnBoard * pointer)
{
	AItem* p = nullptr;
	try
	{
		p = dynamic_cast<AItem*>(pointer);
	}
	catch (...) {}
	return p != nullptr;
}

bool ObjectClassifier::isASolidItem(AOnBoard * pointer)
{
	ASolidItem* p = nullptr;
	try
	{
		p = dynamic_cast<ASolidItem*>(pointer);
	}
	catch (...) {}
	return p != nullptr;
}

bool ObjectClassifier::isAArmor(AOnBoard * pointer)
{
	AArmor* p = nullptr;
	try
	{
		p = dynamic_cast<AArmor*>(pointer);
	}
	catch (...) {}
	return p != nullptr;
}

bool ObjectClassifier::isAWeapon(AOnBoard * pointer)
{
	AWeapon* p = nullptr;
	try
	{
		p = dynamic_cast<AWeapon*>(pointer);
	}
	catch (...) {}
	return p != nullptr;
}

bool ObjectClassifier::isMissle(AOnBoard * pointer)
{
	Missle* p = nullptr;
	try
	{
		p = dynamic_cast<Missle*>(pointer);
	}
	catch (...) {}
	return p != nullptr;
}

bool ObjectClassifier::isM16(AOnBoard * pointer)
{
	M16* p = nullptr;
	try
	{
		p = dynamic_cast<M16*>(pointer);
	}
	catch (...) {}
	return p != nullptr;
}

bool ObjectClassifier::isUZI(AOnBoard * pointer)
{
	UZI* p = nullptr;
	try
	{
		p = dynamic_cast<UZI*>(pointer);
	}
	catch (...) {}
	return p != nullptr;
}

bool ObjectClassifier::isShieldArmor(AOnBoard * pointer)
{
	ShieldArmor* p = nullptr;
	try
	{
		p = dynamic_cast<ShieldArmor*>(pointer);
	}
	catch (...) {}
	return p != nullptr;
}

bool ObjectClassifier::isBodyArmor(AOnBoard * pointer)
{
	BodyArmor* p = nullptr;
	try
	{
		p = dynamic_cast<BodyArmor*>(pointer);
	}
	catch (...) {}
	return p != nullptr;
}

bool ObjectClassifier::isACollectAbleItem(AOnBoard * pointer)
{
	ACollectableItem* p = nullptr;
	try
	{
		p = dynamic_cast<ACollectableItem*>(pointer);
	}
	catch (...) {}
	return p != nullptr;
}
