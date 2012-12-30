#include "ScriptEnum.h"
#include <BWAPI.h>
using namespace BWAPI;

typedef struct __unitInfo
{
  const char          * const pszScriptUnitName;
  Orders::Enum::Enum  computerIdleOrder;
  int                 iComputerInternal;
} unitInfo;

unitInfo pszUnitInfo[] =
{
  { "marine",                       Orders::Enum::Guard, 0 },
  { "ghost",                        Orders::Enum::Guard, 0 },
  { "vulture",                      Orders::Enum::Guard, 0 },
  { "goliath",                      Orders::Enum::Guard, 0 },
  { "",                             Orders::Enum::TurretGuard, 3 },
  { "siege_tank",                   Orders::Enum::Guard, 0 },
  { "",                             Orders::Enum::TurretGuard, 3 },
  { "scv",                          Orders::Enum::Guard, 3 },
  { "wraith",                       Orders::Enum::Guard, 0 },
  { "science_vessel",               Orders::Enum::Guard, 0 },
  { "gui_montag",                   Orders::Enum::Guard, 3 },
  { "dropship",                     Orders::Enum::PickupIdle, 0 },
  { "battlecruiser",                Orders::Enum::Guard, 0 },
  { "spider_mine",                  Orders::Enum::VultureMine, 3 },
  { "nuke",                         Orders::Enum::Nothing, 3 },
  { "civilian",                     Orders::Enum::Guard, 3 },
  { "sarah_kerrigan",               Orders::Enum::Guard, 3 },
  { "alan_schezar",                 Orders::Enum::Guard, 3 },
  { "alan_turret",                  Orders::Enum::TurretGuard, 3 },
  { "jim_raynor_vulture",           Orders::Enum::Guard, 3 },
  { "jim_raynor_marine",            Orders::Enum::Guard, 3 },
  { "tom_kazansky",                 Orders::Enum::Guard, 3 },
  { "magellan",                     Orders::Enum::Guard, 3 },
  { "edmund_duke",                  Orders::Enum::Guard, 3 },
  { "",                             Orders::Enum::TurretGuard, 3 },
  { "edmund_duke_sieged",           Orders::Enum::Guard, 3 },
  { "",                             Orders::Enum::TurretGuard, 3 },
  { "arcturus_mengsk",              Orders::Enum::Guard, 3 },
  { "hyperion",                     Orders::Enum::Guard, 3 },
  { "norad_2",                      Orders::Enum::Guard, 3 },
  { "siege_tank_sieged",            Orders::Enum::Guard, 0 },
  { "",                             Orders::Enum::TurretGuard, 3 },
  { "firebat",                      Orders::Enum::Guard, 0 },
  { "",                             Orders::Enum::Scanner, 3 },
  { "medic",                        Orders::Enum::Medic, 0 },
  { "larva",                        Orders::Enum::ComputerAI, 3 },
  { "egg",                          Orders::Enum::Guard, 3 },
  { "zergling",                     Orders::Enum::Guard, 0 },
  { "hydralisk",                    Orders::Enum::Guard, 0 },
  { "ultralisk",                    Orders::Enum::Guard, 0 },
  { "broodling",                    Orders::Enum::Guard, 0 },
  { "drone",                        Orders::Enum::Guard, 3 },
  { "overlord",                     Orders::Enum::AIPatrol, 3 },
  { "mutalisk",                     Orders::Enum::Guard, 0 },
  { "guardian",                     Orders::Enum::Guard, 0 },
  { "queen",                        Orders::Enum::Guard, 0 },
  { "defiler",                      Orders::Enum::Guard, 0 },
  { "scourge",                      Orders::Enum::Guard, 0 },
  { "torrasque",                    Orders::Enum::Guard, 3 },
  { "matriarch",                    Orders::Enum::Guard, 3 },
  { "infested_terran",              Orders::Enum::Guard, 0 },
  { "infested_kerrigan",            Orders::Enum::Guard, 3 },
  { "unclean_one",                  Orders::Enum::Guard, 3 },
  { "hunter_killer",                Orders::Enum::Guard, 3 },
  { "devouring_one",                Orders::Enum::Guard, 3 },
  { "kukulza",                      Orders::Enum::Guard, 3 },
  { "kukulza_guardian",             Orders::Enum::Guard, 3 },
  { "yggdrasill",                   Orders::Enum::ComputerAI, 3 },
  { "valkyrie",                     Orders::Enum::Guard, 0 },
  { "cocoon",                       Orders::Enum::Guard, 3 },
  { "corsair",                      Orders::Enum::Guard, 0 },
  { "dark_templar",                 Orders::Enum::Guard, 0 },
  { "devourer",                     Orders::Enum::Guard, 0 },
  { "dark_archon",                  Orders::Enum::Guard, 0 },
  { "probe",                        Orders::Enum::Guard, 3 },
  { "zealot",                       Orders::Enum::Guard, 0 },
  { "dragoon",                      Orders::Enum::Guard, 0 },
  { "high_templar",                 Orders::Enum::Guard, 0 },
  { "archon",                       Orders::Enum::Guard, 0 },
  { "shuttle",                      Orders::Enum::PickupIdle, 0 },
  { "scout",                        Orders::Enum::Guard, 0 },
  { "arbiter",                      Orders::Enum::InitializeArbiter, 0 },
  { "carrier",                      Orders::Enum::Carrier, 0 },
  { "interceptor",                  Orders::Enum::Nothing, 3 },
  { "dark_templar_hero",            Orders::Enum::Guard, 3 },
  { "zeratul",                      Orders::Enum::Guard, 3 },
  { "tassadar_zeratul",             Orders::Enum::Guard, 3 },
  { "fenix_zealot",                 Orders::Enum::Guard, 3 },
  { "fenix_dragoon",                Orders::Enum::Guard, 3 },
  { "tassadar",                     Orders::Enum::Guard, 3 },
  { "mojo",                         Orders::Enum::Guard, 3 },
  { "warbringer",                   Orders::Enum::Reaver, 3 },
  { "gantrithor",                   Orders::Enum::Carrier, 3 },
  { "reaver",                       Orders::Enum::Reaver, 0 },
  { "observer",                     Orders::Enum::AIPatrol, 3 },
  { "scarab",                       Orders::Enum::Nothing, 3 },
  { "danimoth",                     Orders::Enum::InitializeArbiter, 3 },
  { "aldaris",                      Orders::Enum::Guard, 3 },
  { "artanis",                      Orders::Enum::Guard, 3 },
  { "rhynadon",                     Orders::Enum::Guard, 3 },
  { "bengalaas",                    Orders::Enum::Guard, 3 },
  { "",                             Orders::Enum::Nothing, 0 },
  { "",                             Orders::Enum::Nothing, 0 },
  { "scantid",                      Orders::Enum::Guard, 3 },
  { "kakaru",                       Orders::Enum::Guard, 3 },
  { "ragnasaur",                    Orders::Enum::Guard, 3 },
  { "ursadon",                      Orders::Enum::Guard, 3 },
  { "lurker_egg",                   Orders::Enum::Guard, 3 },
  { "raszagal",                     Orders::Enum::Guard, 0 },
  { "samir_duran",                  Orders::Enum::Guard, 3 },
  { "alexei_stukov",                Orders::Enum::Guard, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "gerard_dugalle",               Orders::Enum::Guard, 3 },
  { "lurker",                       Orders::Enum::Guard, 0 },
  { "infested_duran",               Orders::Enum::Guard, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "command_center",               Orders::Enum::ComputerAI, 3 },
  { "comsat_station",               Orders::Enum::ComputerAI, 3 },
  { "nuke_silo",                    Orders::Enum::ComputerAI, 3 },
  { "supply_depot",                 Orders::Enum::ComputerAI, 3 },
  { "refinery",                     Orders::Enum::ComputerAI, 3 },
  { "barracks",                     Orders::Enum::ComputerAI, 3 },
  { "academy",                      Orders::Enum::ComputerAI, 3 },
  { "factory",                      Orders::Enum::ComputerAI, 3 },
  { "starport",                     Orders::Enum::ComputerAI, 3 },
  { "control_tower",                Orders::Enum::ComputerAI, 3 },
  { "science_facility",             Orders::Enum::ComputerAI, 3 },
  { "covert_ops",                   Orders::Enum::ComputerAI, 3 },
  { "physics_lab",                  Orders::Enum::ComputerAI, 3 },
  { "",                             Orders::Enum::ComputerAI, 3 },
  { "machine_shop",                 Orders::Enum::ComputerAI, 3 },
  { "",                             Orders::Enum::ComputerAI, 3 },
  { "engineering_bay",              Orders::Enum::ComputerAI, 3 },
  { "armory",                       Orders::Enum::ComputerAI, 3 },
  { "missile_turret",               Orders::Enum::TowerGuard, 3 },
  { "bunker",                       Orders::Enum::ComputerAI, 3 },
  { "",                             Orders::Enum::ComputerAI, 3 },
  { "",                             Orders::Enum::ComputerAI, 3 },
  { "",                             Orders::Enum::PowerupIdle, 3 },
  { "",                             Orders::Enum::PowerupIdle, 3 },
  { "infested_command_center",      Orders::Enum::ComputerAI, 3 },
  { "hatchery",                     Orders::Enum::InitCreepGrowth, 3 },
  { "lair",                         Orders::Enum::InitCreepGrowth, 3 },
  { "hive",                         Orders::Enum::InitCreepGrowth, 3 },
  { "nydus_canal",                  Orders::Enum::ComputerAI, 3 },
  { "hydralisk_den",                Orders::Enum::ComputerAI, 3 },
  { "defiler_mound",                Orders::Enum::ComputerAI, 3 },
  { "greater_spire",                Orders::Enum::ComputerAI, 3 },
  { "queens_nest",                  Orders::Enum::ComputerAI, 3 },
  { "evolution_chamber",            Orders::Enum::ComputerAI, 3 },
  { "ultralisk_cavern",             Orders::Enum::ComputerAI, 3 },
  { "spire",                        Orders::Enum::ComputerAI, 3 },
  { "spawning_pool",                Orders::Enum::ComputerAI, 3 },
  { "creep_colony",                 Orders::Enum::InitCreepGrowth, 3 },
  { "spore_colony",                 Orders::Enum::InitCreepGrowth, 3 },
  { "",                             Orders::Enum::ComputerAI, 3 },
  { "sunken_colony",                Orders::Enum::InitCreepGrowth, 3 },
  { "",                             Orders::Enum::ComputerAI, 3 },
  { "",                             Orders::Enum::ComputerAI, 3 },
  { "extractor",                    Orders::Enum::ComputerAI, 3 },
  { "",                             Orders::Enum::ComputerAI, 3 },
  { "",                             Orders::Enum::ComputerAI, 3 },
  { "",                             Orders::Enum::ComputerAI, 3 },
  { "",                             Orders::Enum::ComputerAI, 3 },
  { "nexus",                        Orders::Enum::ComputerAI, 3 },
  { "robotics_facility",            Orders::Enum::ComputerAI, 3 },
  { "pylon",                        Orders::Enum::InitializePsiProvider, 3 },
  { "assimilator",                  Orders::Enum::ComputerAI, 3 },
  { "",                             Orders::Enum::ComputerAI, 3 },
  { "observatory",                  Orders::Enum::ComputerAI, 3 },
  { "gateway",                      Orders::Enum::ComputerAI, 3 },
  { "",                             Orders::Enum::ComputerAI, 3 },
  { "photon_cannon",                Orders::Enum::TowerGuard, 3 },
  { "citadel_of_adun",              Orders::Enum::ComputerAI, 3 },
  { "cybernetics_core",             Orders::Enum::ComputerAI, 3 },
  { "templar_archives",             Orders::Enum::ComputerAI, 3 },
  { "forge",                        Orders::Enum::ComputerAI, 3 },
  { "stargate",                     Orders::Enum::ComputerAI, 3 },
  { "",                             Orders::Enum::ComputerAI, 3 },
  { "fleet_beacon",                 Orders::Enum::ComputerAI, 3 },
  { "arbiter_tribunal",             Orders::Enum::ComputerAI, 3 },
  { "robotics_support",             Orders::Enum::ComputerAI, 3 },
  { "shield_battery",               Orders::Enum::ComputerAI, 3 },
  { "",                             Orders::Enum::ComputerAI, 3 },
  { "",                             Orders::Enum::ComputerAI, 3 },
  { "",                             Orders::Enum::ComputerAI, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "",                             Orders::Enum::ComputerAI, 3 },
  { "",                             Orders::Enum::ComputerAI, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "",                             Orders::Enum::CTFCOPInit, 3 },
  { "",                             Orders::Enum::CTFCOPInit, 3 },
  { "",                             Orders::Enum::CTFCOPInit, 3 },
  { "",                             Orders::Enum::ComputerAI, 3 },
  { "",                             Orders::Enum::ComputerAI, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "",                             Orders::Enum::HiddenGun, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "",                             Orders::Enum::HiddenGun, 3 },
  { "",                             Orders::Enum::HiddenGun, 3 },
  { "",                             Orders::Enum::HiddenGun, 3 },
  { "",                             Orders::Enum::HiddenGun, 3 },
  { "",                             Orders::Enum::HiddenGun, 3 },
  { "",                             Orders::Enum::Nothing, 3 },
  { "",                             Orders::Enum::PowerupIdle, 3 },
  { "",                             Orders::Enum::PowerupIdle, 3 },
  { "",                             Orders::Enum::PowerupIdle, 3 },
  { "",                             Orders::Enum::PowerupIdle, 3 },
  { "",                             Orders::Enum::PowerupIdle, 3 },
  { "",                             Orders::Enum::PowerupIdle, 3 },
  { "",                             Orders::Enum::PowerupIdle, 3 },
  { "",                             Orders::Enum::PowerupIdle, 3 },
  { "",                             Orders::Enum::PowerupIdle, 3 },
  { "",                             Orders::Enum::PowerupIdle, 3 },
  { "",                             Orders::Enum::PowerupIdle, 3 },
  { "",                             Orders::Enum::PowerupIdle, 3 },
  { "",                             Orders::Enum::PowerupIdle, 3 },
  { "unknown",                      Orders::Enum::Unknown, 3 }

};
  
const char * const pszOpcodeName[] =
{ 
  "goto",
  "notowns_jump",
  "wait",
  "start_town",
  "start_areatown",
  "expand",
  "build",
  "upgrade",
  "tech",
  "wait_build",
  "wait_buildstart",
  "attack_clear",
  "attack_add",
  "attack_prepare",
  "attack_do",
  "wait_secure",
  "capt_expand",
  "build_bunkers",
  "wait_bunkers",
  "defensebuild_gg",
  "defensebuild_ag",
  "defensebuild_ga",
  "defensebuild_aa",
  "defenseuse_gg",
  "defenseuse_ag",
  "defenseuse_ga",
  "defenseuse_aa",
  "defenseclear_gg",
  "defenseclear_ag",
  "defenseclear_ga",
  "defenseclear_aa",
  "send_suicide",
  "player_enemy",
  "player_ally",
  "default_min",
  "defaultbuild_off",
  "stop",
  "switch_rescue",
  "move_dt",
  "debug",
  "fatal_error",
  "enter_bunker",
  "value_area",
  "transports_off",
  "check_transports",
  "nuke_rate",
  "max_force",
  "clear_combatdata",
  "random_jump",
  "time_jump",
  "farms_notiming",
  "farms_timing",
  "build_turrets",
  "wait_turrets",
  "default_build",
  "harass_factor",
  "start_campaign",
  "race_jump",
  "region_size",
  "get_oldpeons",
  "groundmap_jump",
  "place_guard",
  "wait_force",
  "guard_resources",
  "call",
  "return",
  "eval_harass",
  "creep",
  "panic",
  "player_need",
  "do_morph",
  "wait_upgrades",
  "multirun",
  "rush",
  "scout_with",
  "define_max",
  "train",
  "target_expansion",
  "wait_train",
  "set_attacks",
  "set_gencmd",
  "make_patrol",
  "give_money",
  "prep_down",
  "resources_jump",
  "enter_transport",
  "exit_transport",
  "sharedvision_on",
  "sharedvision_off",
  "nuke_location",
  "harass_location",
  "implode",
  "guard_all",
  "enemyowns_jump",
  "enemyresources_jump",
  "if_dif",
  "easy_attack",
  "kill_thread",
  "killable",
  "wait_finishattack",
  "quick_attack",
  "junkyard_dog",
  "fake_nuke",
  "disruption_web",
  "recall_location",
  "set_randomseed",
  "if_owned",
  "create_nuke",
  "create_unit",
  "nuke_pos",
  "help_iftrouble",
  "allies_watch",
  "try_townpoint",
  "unknown"
};

namespace AISCRIPT
{
  const char * const getOpcodeName(int iOpcode)
  {
    if ( iOpcode < 0 || iOpcode > Enum::LAST ) 
      return pszOpcodeName[Enum::LAST];
    return pszOpcodeName[iOpcode];
  }
  const char * const getUnitName(int iUnitType)
  {
    int t = iUnitType;
    if ( t < 0 || t > BWAPI::UnitTypes::None )
      t = BWAPI::UnitTypes::None;
    return pszUnitInfo[t].pszScriptUnitName;
  }
  Orders::Enum::Enum getUnitIdleOrder(int iUnitType)
  {
    int t = iUnitType;
    if ( t < 0 || t > BWAPI::UnitTypes::None )
      t = BWAPI::UnitTypes::None;
    return pszUnitInfo[t].computerIdleOrder;
  }
  int getUnitInternal(int iUnitType)
  {
    int t = iUnitType;
    if ( t > BWAPI::UnitTypes::None || t < 0 )
      t = BWAPI::UnitTypes::None;
    return pszUnitInfo[t].iComputerInternal;
  }

}
