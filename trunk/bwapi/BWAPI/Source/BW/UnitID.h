#pragma once

namespace BW
{
  /**
   * Values from modding tools such as DATEdit.
   */
  namespace UnitID
  {
  enum Enum
    {
      Terran_Marine                 = 0x00,
      Terran_Ghost                  = 0x01,
      Terran_Vulture                = 0x02,
      Terran_Goliath                = 0x03,
      Terran_GoliathTurret          = 0x04,
      Terran_SiegeTankTankMode      = 0x05,
      Terran_TankTurretTankMode     = 0x06,
      Terran_SCV                    = 0x07,
      Terran_Wraith                 = 0x08,
      Terran_ScienceVessel          = 0x09,
      Terran_Hero_GuiMontag         = 0x0A,
      Terran_Dropship               = 0x0B,
      Terran_Battlecruiser          = 0x0C,
      Terran_VultureSpiderMine      = 0x0D,
      Terran_NuclearMissile         = 0x0E,
      Terran_Hero_Civilian          = 0x0F,
      Terran_Hero_SarahKerrigan     = 0x10,
      Terran_Hero_AlanSchezar       = 0x11,
      Terran_Hero_AlanTurret        = 0x12,
      Terran_Hero_JimRaynorV        = 0x13,
      Terran_Hero_JimRaynorM        = 0x14,
      Terran_Hero_TomKazansky       = 0x15,
      Terran_Hero_Magellan          = 0x16,
      Terran_Hero_EdmundDukeT       = 0x17,
      Terran_Hero_EdmundDukeTTurret = 0x18,
      Terran_Hero_EdmundDukeS       = 0x19,
      Terran_Hero_EdmundDukeSTurret = 0x1A,
      Terran_Hero_ArcturusMengsk    = 0x1B,
      Terran_Hero_Hyperion          = 0x1C,
      Terran_Hero_NoradII           = 0x1D,
      Terran_SiegeTankSiegeMode     = 0x1E,
      Terran_SiegeTankSiegeTurret   = 0x1F,
      Terran_Firebat                = 0x20,
      Spell_ScannerSweep            = 0x21,
      Terran_Medic                  = 0x22,
      Zerg_Larva                    = 0x23,
      Zerg_Egg                      = 0x24,
      Zerg_Zergling                 = 0x25,
      Zerg_Hydralisk                = 0x26,
      Zerg_Ultralisk                = 0x27,
      Zerg_Broodling                = 0x28,
      Zerg_Drone                    = 0x29,
      Zerg_Overlord                 = 0x2A,
      Zerg_Mutalisk                 = 0x2B,
      Zerg_Guardian                 = 0x2C,
      Zerg_Queen                    = 0x2D,
      Zerg_Defiler                  = 0x2E,
      Zerg_Scourge                  = 0x2F,
      Zerg_Hero_Torrasque           = 0x30,
      Zerg_Hero_Matriarch           = 0x31,
      Zerg_InfestedTerran           = 0x32,
      Zerg_Hero_InfestedKerrigan    = 0x33,
      Zerg_Hero_UncleanOne          = 0x34,
      Zerg_Hero_HunterKiller        = 0x35,
      Zerg_Hero_DevouringOne        = 0x36,
      Zerg_Hero_KukulzaMutalisk     = 0x37,
      Zerg_Hero_KukulzaGuardian     = 0x38,
      Zerg_Hero_Yggdrasill          = 0x39,
      Terran_Valkyrie               = 0x3A,
      Zerg_Cocoon                   = 0x3B,
      Protoss_Corsair               = 0x3C,
      Protoss_DarkTemplar           = 0x3D,
      Zerg_Devourer                 = 0x3E,
      Protoss_DarkArchon            = 0x3F,
      Protoss_Probe                 = 0x40,
      Protoss_Zealot                = 0x41,
      Protoss_Dragoon               = 0x42,
      Protoss_HighTemplar           = 0x43,
      Protoss_Archon                = 0x44,
      Protoss_Shuttle               = 0x45,
      Protoss_Scout                 = 0x46,
      Protoss_Arbiter               = 0x47,
      Protoss_Carrier               = 0x48,
      Protoss_Interceptor           = 0x49,
      Protoss_Hero_DarkTemplar      = 0x4A,
      Protoss_Hero_Zeratul          = 0x4B,
      Protoss_Hero_TassadarZeratul  = 0x4C,
      Protoss_Hero_FenixZealot      = 0x4D,
      Protoss_Hero_FenixDragoon     = 0x4E,
      Protoss_Hero_Tassadar         = 0x4F,
      Protoss_Hero_Mojo             = 0x50,
      Protoss_Hero_Warbringer       = 0x51,
      Protoss_Hero_Gantrithor       = 0x52,
      Protoss_Reaver                = 0x53,
      Protoss_Observer              = 0x54,
      Protoss_Scarab                = 0x55,
      Protoss_Hero_Danimoth         = 0x56,
      Protoss_Hero_Aldaris          = 0x57,
      Protoss_Hero_Artanis          = 0x58,
      Critter_Rhynadon              = 0x59,
      Critter_Bengalaas             = 0x5A,
      Unused_CargoShip              = 0x5B,
      Unused_MercenaryGunship       = 0x5C,
      Critter_Scantid               = 0x5D,
      Critter_Kakaru                = 0x5E,
      Critter_Ragnasaur             = 0x5F,
      Critter_Ursadon               = 0x60,
      Zerg_LurkerEgg                = 0x61,
      Protoss_Hero_Raszagal         = 0x62,
      Terran_Hero_SamirDuran        = 0x63,
      Terran_Hero_AlexeiStukov      = 0x64,
      Map_Revealer                  = 0x65,
      Terran_Hero_GerardDuGalle     = 0x66,
      Zerg_Lurker                   = 0x67,
      Zerg_Hero_InfestedDuran       = 0x68,
      Spell_DisruptionWeb           = 0x69,
      Terran_CommandCenter          = 0x6A,
      Terran_ComsatStation          = 0x6B,
      Terran_NuclearSilo            = 0x6C,
      Terran_SupplyDepot            = 0x6D,
      Terran_Refinery               = 0x6E,
      Terran_Barracks               = 0x6F,
      Terran_Academy                = 0x70,
      Terran_Factory                = 0x71,
      Terran_Starport               = 0x72,
      Terran_ControlTower           = 0x73,
      Terran_ScienceFacility        = 0x74,
      Terran_CovertOps              = 0x75,
      Terran_PhysicsLab             = 0x76,
      Unused_Starbase               = 0x77,
      Terran_MachineShop            = 0x78,
      Unused_RepairBay              = 0x79,
      Terran_EngineeringBay         = 0x7A,
      Terran_Armory                 = 0x7B,
      Terran_MissileTurret          = 0x7C,
      Terran_Bunker                 = 0x7D,
      Special_CrashedNoradII        = 0x7E,
      Special_IonCannon             = 0x7F,
      Powerup_UrajCrystal           = 0x80,
      Powerup_KhalisCrystal         = 0x81,
      Zerg_InfestedCommandCenter    = 0x82,
      Zerg_Hatchery                 = 0x83,
      Zerg_Lair                     = 0x84,
      Zerg_Hive                     = 0x85,
      Zerg_NydusCanal               = 0x86,
      Zerg_HydraliskDen             = 0x87,
      Zerg_DefilerMound             = 0x88,
      Zerg_GreaterSpire             = 0x89,
      Zerg_QueensNest               = 0x8A,
      Zerg_EvolutionChamber         = 0x8B,
      Zerg_UltraliskCavern          = 0x8C,
      Zerg_Spire                    = 0x8D,
      Zerg_SpawningPool             = 0x8E,
      Zerg_CreepColony              = 0x8F,
      Zerg_SporeColony              = 0x90,
      Unused_ZergBuilding1          = 0x91,
      Zerg_SunkenColony             = 0x92,
      Special_OvermindWithShell     = 0x93,
      Special_Overmind              = 0x94,
      Zerg_Extractor                = 0x95,
      Special_MatureChrysalis       = 0x96,
      Special_Cerebrate             = 0x97,
      Special_CerebrateDaggoth      = 0x98,
      Unused_ZergBuilding2          = 0x99,
      Protoss_Nexus                 = 0x9A,
      Protoss_RoboticsFacility      = 0x9B,
      Protoss_Pylon                 = 0x9C,
      Protoss_Assimilator           = 0x9D,
      Unused_ProtossBuilding1       = 0x9E,
      Protoss_Observatory           = 0x9F,
      Protoss_Gateway               = 0xA0,
      Unused_ProtossBuilding2       = 0xA1,
      Protoss_PhotonCannon          = 0xA2,
      Protoss_CitadelOfAdun         = 0xA3,
      Protoss_CyberneticsCore       = 0xA4,
      Protoss_TemplarArchives       = 0xA5,
      Protoss_Forge                 = 0xA6,
      Protoss_Stargate              = 0xA7,
      Special_StasisCellPrison      = 0xA8,
      Protoss_FleetBeacon           = 0xA9,
      Protoss_ArbiterTribunal       = 0xAA,
      Protoss_RoboticsSupportBay    = 0xAB,
      Protoss_ShieldBattery         = 0xAC,
      Special_KhaydarinCrystalForm  = 0xAD,
      Special_ProtossTemple         = 0xAE,
      Special_XelNagaTemple         = 0xAF,
      Resource_MineralPatch1        = 0xB0,
      Resource_MineralPatch2        = 0xB1,
      Resource_MineralPatch3        = 0xB2,
      Unused_Cave                   = 0xB3,
      Unused_CaveIn                 = 0xB4,
      Unused_Cantina                = 0xB5,
      Unused_MiningPlatform         = 0xB6,
      Unused_IndependantCC          = 0xB7,
      Unused_IndependantStarport    = 0xB8,
      Unused_IndependantJumpGate    = 0xB9,
      Unused_Ruins                  = 0xBA,
      Unused_KhaydarinFormation     = 0xBB,
      Resource_VespeneGeyser        = 0xBC,
      Special_WarpGate              = 0xBD,
      Special_PsiDisrupter          = 0xBE,
      Unused_ZergMarker             = 0xBF,
      Unused_TerranMarker           = 0xC0,
      Unused_ProtossMarker          = 0xC1,
      Beacon_Zerg                   = 0xC2,
      Beacon_Terran                 = 0xC3,
      Beacon_Protoss                = 0xC4,
      Beacon_ZergFlag               = 0xC5,
      Beacon_TerranFlag             = 0xC6,
      Beacon_ProtossFlag            = 0xC7,
      Special_PowerGenerator        = 0xC8,
      Special_OvermindCocoon        = 0xC9,
      Spell_DarkSwarm               = 0xCA,
      Doodad_FloorMissileTrap       = 0xCB,
      Doodad_FloorHatch             = 0xCC,
      Doodad_LeftUpperLevelDoor     = 0xCD,
      Doodad_RightUpperLevelDoor    = 0xCE,
      Doodad_LeftPitDoor            = 0xCF,
      Doodad_RightPitDoor           = 0xD0,
      Doodad_FloorGunTrap           = 0xD1,
      Doodad_LeftWallMissileTrap    = 0xD2,
      Doodad_LeftWallFlameTrap      = 0xD3,
      Doodad_RightWallMissileTrap   = 0xD4,
      Doodad_RightWallFlameTrap     = 0xD5,
      Start_Location                = 0xD6,
      Powerup_Flag                  = 0xD7,
      Powerup_YoungChrysalis        = 0xD8,
      Powerup_PsiEmitter            = 0xD9,
      Powerup_DataDisk              = 0xDA,
      Powerup_KhaydarinCrystal      = 0xDB,
      Mineral_Chunk1                = 0xDC,
      Mineral_Chunk2                = 0xDD,
      Vespene_Orb1                  = 0xDE,
      Vespene_Orb2                  = 0xDF,
      Vaspene_Sac1                  = 0xE0,
      Vaspene_Sac2                  = 0xE1,
      Vespene_Tank1                 = 0xE2,
      Vespene_Tank2                 = 0xE3,
      None                          = 0XE4, // Not actually unit ID from here on out
      MAX = None
    };
  };
};
