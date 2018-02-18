#include "RealPlayer.h"

// _________ Ctors & Dtors ___________
RealPlayer::RealPlayer(int playerID) :APlayer(playerID) {}
RealPlayer::RealPlayer(const RealPlayer & other){}
RealPlayer::~RealPlayer(){}
RealPlayer * RealPlayer::clone() const{return new RealPlayer(*this);}

// _________ Methods ___________
string RealPlayer::toString(){return "Player" + to_string(playerID) + "" ;}
