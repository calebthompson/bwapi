#include "Unit.h"
#include "BW_Unit.h"
#include "UnitPrototypeDefinitions.h"
#include "Player.h"
#include "Globals.h"
//----------------------------- CONSTRUCTOR -----------------------------------
Unit::Unit(BW_Unit *rawData)
{
  this->rawData = rawData;
}
//----------------------------- DESTRUCTOR -----------------------------------
Unit::~Unit()
{
}
//-------------------------- GET HEALTH POINTS --------------------------------
u16 Unit::getHealthPoints() const
{
  return rawData->healthPoints;
}
//----------------------- GET HEALT POINTS FACTION ----------------------------
u8 Unit::getHealthPointsFraction() const
{
  return rawData->healthPointsFraction;
}
//-------------------------- GET HEALTH POINTS --------------------------------
u16 Unit::getShieldPoints() const
{
  return rawData->shieldPoints;
}
//----------------------- GET HEALT POINTS FACTION ----------------------------
u8 Unit::getShieldPointsFraction() const
{
  return rawData->shieldPointsFraction;
}
//--------------------------  GET UNIT PROTOTYPE -----------------------------
const UnitPrototype* const Unit::getPrototype() const
{
  switch (this->rawData->unitID)
  {
    case BW_UnitType::Protoss_Probe  : return Prototypes::Probe;
    case BW_UnitType::Protoss_Zealot : return Prototypes::Zealot;
    case BW_UnitType::Terran_SCV     : return Prototypes::SCV;
    case BW_UnitType::Zerg_Queen     : return Prototypes::Queen;
    default : return NULL;
  }
}
//------------------------------ CAN ORDER -----------------------------------
bool Unit::canOrder(const AbilityPrototype* const ability, Unit* target) const
{
 if (!this->getPrototype()->canOrder(ability, target))
    return false;

  if (this == target &&
      !(ability->getTargetFlags() & TargetType::TARGET_SELF))
    return false;

  if (this->getOwner() == target->getOwner() &&
      !(ability->getTargetFlags() & TargetType::TARGET_MY_UNITS))
    return false;

  if (this->getOwner() == target->getOwner() &&
      !(ability->getTargetFlags() & TargetType::TARGET_OPPONENTS_UNITS))
    return false;

  return true;
}
//------------------------------ CAN ORDER -----------------------------------
bool Unit::canOrder(const AbilityPrototype* const ability, BW_Position target) const
{
  if (!this->getPrototype()->canOrder(ability, target))
    return false;
  return true;
}
//-------------------------------- ORDER -------------------------------------
void Unit::order(const AbilityPrototype* const ability, Unit* target)
{
}
//--------------------------------- ORDER ------------------------------------
void Unit::order(const AbilityPrototype* const ability, BW_Position target)
{
}
//------------------------------- GET OWNER ----------------------------------
Player* Unit::getOwner() const
{
  return Broodwar.players[this->rawData->playerID];
}
//-------------------------------- IS VALID ----------------------------------
bool Unit::isValid() const
{
  return this->getHealthPoints() > 0 || 
         this->getHealthPointsFraction() > 0;
}
//----------------------------------------------------------------------------
