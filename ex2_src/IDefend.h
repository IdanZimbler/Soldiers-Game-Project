#pragma once
class AWeapon;

// interface that represents a defendable object
class IDefend {
protected:
	// _________ Methods ___________
	virtual void defend(AWeapon* weapon) = 0;
};