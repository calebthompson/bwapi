#include <stdio.h>

#include <BWAPI.h>
#include <BWAPI/Client.h>
//#include <BWTA.h>

#include <windows.h>

#include <string>

using namespace BWAPI;

void drawStats();
void drawBullets();
void drawVisibilityData();
//void drawTerrainData();
void showPlayers();
void showForces();
bool show_bullets;
bool show_visibility_data;
/*
bool analyzed;
bool analysis_just_finished;
BWTA::Region* home;
BWTA::Region* enemy_base;
DWORD WINAPI AnalyzeThread();
*/
void reconnect()
{
  while(!BWAPIClient.connect())
  {
    Sleep(1000);
  }
}
int main(int argc, const char* argv[])
{
  std::cout << "Connecting..." << std::endl;;
  reconnect();
  while(true)
  {
    std::cout << "waiting to enter match" << std::endl;
    while ( !Broodwar->isInGame() )
    {
      BWAPI::BWAPIClient.update();
      if (!BWAPI::BWAPIClient.isConnected())
      {
        std::cout << "Reconnecting..." << std::endl;;
        reconnect();
      }
    }
    std::cout << "starting match!" << std::endl;
    Broodwar->sendText("Hello world!");
    Broodwar << "The map is " << Broodwar->mapName() << ", a " << Broodwar->getStartLocations().size() << " player map" << std::endl;
    // Enable some cheat flags
    Broodwar->enableFlag(Flag::UserInput);
    // Uncomment to enable complete map information
    //Broodwar->enableFlag(Flag::CompleteMapInformation);
    /*
    //read map information into BWTA so terrain analysis can be done in another thread
    BWTA::readMap();
    analyzed=false;
    analysis_just_finished=false;
    */
    show_bullets=false;
    show_visibility_data=false;

    if (Broodwar->isReplay())
    {
      Broodwar << "The following players are in this replay:" << std::endl;;
      Playerset players = Broodwar->getPlayers();
      for(Playerset::iterator p = players.begin(); p != players.end(); ++p )
      {
        if ( !p->getUnits().empty() && !p->isNeutral() )
          Broodwar << p->getName() << ", playing as " << p->getRace() << std::endl;
      }
    }
    else
    {
      Broodwar << "The match up is " << Broodwar->self()->getRace() << " vs " << Broodwar->enemy()->getRace() << std::endl;

      //send each worker to the mineral field that is closest to it
      Unitset units    = Broodwar->self()->getUnits();
      Unitset minerals  = Broodwar->getMinerals();
      for ( Unitset::iterator i = units.begin(); i != units.end(); ++i )
      {
        if ( i->getType().isWorker() )
        {
          Unit* closestMineral = NULL;

          for( Unitset::iterator m = minerals.begin(); m != minerals.end(); ++m )
          {
            if ( !closestMineral || i->getDistance(*m) < i->getDistance(closestMineral))
              closestMineral = *m;
          }
          if ( closestMineral )
            i->rightClick(closestMineral);
        }
        else if ( i->getType().isResourceDepot() )
        {
          //if this is a center, tell it to build the appropiate type of worker
          i->train(Broodwar->self()->getRace().getWorker());
        }
      }
    }
    while(Broodwar->isInGame())
    {
      for(std::list<Event>::const_iterator e = Broodwar->getEvents().begin(); e != Broodwar->getEvents().end(); ++e)
      {
        switch(e->getType())
        {
          case EventType::MatchEnd:
            if (e->isWinner())
              Broodwar << "I won the game" << std::endl;
            else
              Broodwar << "I lost the game" << std::endl;
            break;
          case EventType::SendText:
            if (e->getText()=="/show bullets")
            {
              show_bullets=!show_bullets;
            } else if (e->getText()=="/show players")
            {
              showPlayers();
            } else if (e->getText()=="/show forces")
            {
              showForces();
            } else if (e->getText()=="/show visibility")
            {
              show_visibility_data=!show_visibility_data;
            } /* else if (e->text=="/analyze")
            {
              if (analyzed == false)
              {
                Broodwar->printf("Analyzing map... this may take a minute");
                CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)AnalyzeThread, NULL, 0, NULL);
              }
            } */ else
            {
              Broodwar << "You typed \"" << e->getText() << "\"!" << std::endl;
            }
            break;
          case EventType::ReceiveText:
            Broodwar << e->getPlayer()->getName() << " said \"" << e->getText() << "\"" << std::endl;
            break;
          case EventType::PlayerLeft:
            Broodwar << e->getPlayer()->getName() << " left the game." << std::endl;
            break;
          case EventType::NukeDetect:
            if (e->getPosition()!=Positions::Unknown)
            {
              Broodwar->drawCircleMap(e->getPosition(), 40, Colors::Red, true);
              Broodwar << "Nuclear Launch Detected at " << e->getPosition() << std::endl;
            }
            else
              Broodwar << "Nuclear Launch Detected" << std::endl;
            break;
          case EventType::UnitCreate:
            if (!Broodwar->isReplay())
              Broodwar << "A " << e->getUnit()->getType() << " [" << e->getUnit() << "] has been created at " << e->getUnit()->getPosition() << std::endl;
            else
            {
              /*if we are in a replay, then we will print out the build order
              (just of the buildings, not the units).*/
              if (e->getUnit()->getType().isBuilding() && e->getUnit()->getPlayer()->isNeutral()==false)
              {
                int seconds=Broodwar->getFrameCount()/24;
                int minutes=seconds/60;
                seconds%=60;
                Broodwar->sendText("%.2d:%.2d: %s creates a %s",minutes,seconds,e->getUnit()->getPlayer()->getName().c_str(),e->getUnit()->getType().c_str());
              }
            }
            break;
          case EventType::UnitDestroy:
            if (!Broodwar->isReplay())
              Broodwar->sendText("A %s [%x] has been destroyed at (%d,%d)",e->getUnit()->getType().c_str(),e->getUnit(),e->getUnit()->getPosition().x,e->getUnit()->getPosition().y);
            break;
          case EventType::UnitMorph:
            if (!Broodwar->isReplay())
              Broodwar->sendText("A %s [%x] has been morphed at (%d,%d)",e->getUnit()->getType().c_str(),e->getUnit(),e->getUnit()->getPosition().x,e->getUnit()->getPosition().y);
            else
            {
              /*if we are in a replay, then we will print out the build order
              (just of the buildings, not the units).*/
              if (e->getUnit()->getType().isBuilding() && e->getUnit()->getPlayer()->isNeutral()==false)
              {
                int seconds=Broodwar->getFrameCount()/24;
                int minutes=seconds/60;
                seconds%=60;
                Broodwar->sendText("%.2d:%.2d: %s morphs a %s",minutes,seconds,e->getUnit()->getPlayer()->getName().c_str(),e->getUnit()->getType().c_str());
              }
            }
            break;
          case EventType::UnitShow:
            if (!Broodwar->isReplay())
              Broodwar->sendText("A %s [%x] has been spotted at (%d,%d)",e->getUnit()->getType().c_str(),e->getUnit(),e->getUnit()->getPosition().x,e->getUnit()->getPosition().y);
            break;
          case EventType::UnitHide:
            if (!Broodwar->isReplay())
              Broodwar->sendText("A %s [%x] was last seen at (%d,%d)",e->getUnit()->getType().c_str(),e->getUnit(),e->getUnit()->getPosition().x,e->getUnit()->getPosition().y);
            break;
          case EventType::UnitRenegade:
            if (!Broodwar->isReplay())
              Broodwar->sendText("A %s [%x] is now owned by %s",e->getUnit()->getType().c_str(),e->getUnit(),e->getUnit()->getPlayer()->getName().c_str());
            break;
          case EventType::SaveGame:
            Broodwar->sendText("The game was saved to \"%s\".",e->getText().c_str());
            break;
        }
      }

      if (show_bullets)
        drawBullets();

      if (show_visibility_data)
        drawVisibilityData();

      drawStats();
      Broodwar->drawTextScreen(300,0,"FPS: %f",Broodwar->getAverageFPS());
      /*
      if (analyzed && Broodwar->getFrameCount()%30==0)
      {
        //order one of our workers to guard our chokepoint.
        for(Unitset::iterator i=Broodwar->self()->getUnits().begin();i!=Broodwar->self()->getUnits().end();++i)
        {
          if ((*i)->getType().isWorker())
          {
            //get the chokepoints linked to our home region
            std::set<BWTA::Chokepoint*> chokepoints= home->getChokepoints();
            double min_length=10000;
            BWTA::Chokepoint* choke=NULL;

            //iterate through all chokepoints and look for the one with the smallest gap (least width)
            for(std::set<BWTA::Chokepoint*>::iterator c=chokepoints.begin();c!=chokepoints.end();++c)
            {
              double length=(*c)->getWidth();
              if (length<min_length || choke==NULL)
              {
                min_length=length;
                choke=*c;
              }
            }

            //order the worker to move to the center of the gap
            (*i)->rightClick(choke->getCenter());
            break;
          }
        }
      }
      if (analysis_just_finished)
      {
        Broodwar->printf("Finished analyzing map.");
        analysis_just_finished=false;
      }
      if (analyzed)
        drawTerrainData();
      */
      BWAPI::BWAPIClient.update();
      if (!BWAPI::BWAPIClient.isConnected())
      {
        std::cout << "Reconnecting..." << std::endl;
        reconnect();
      }
    }
    std::cout << "Game ended" << std::endl;
  }
  std::cout << "Press ENTER to continue..." << std::endl;
  std::cin.ignore();
  return 0;
}
/*
DWORD WINAPI AnalyzeThread()
{
  BWTA::analyze();

  //self start location only available if the map has base locations
  if (BWTA::getStartLocation(BWAPI::Broodwar->self())!=NULL)
  {
    home       = BWTA::getStartLocation(BWAPI::Broodwar->self())->getRegion();
  }
  //enemy start location only available if Complete Map Information is enabled.
  if (BWTA::getStartLocation(BWAPI::Broodwar->enemy())!=NULL)
  {
    enemy_base = BWTA::getStartLocation(BWAPI::Broodwar->enemy())->getRegion();
  }
  analyzed   = true;
  analysis_just_finished = true;
  return 0;
}
*/
void drawStats()
{
  int line = 0;
  Broodwar->drawTextScreen(5, 0, "I have %d units:", Broodwar->self()->allUnitCount(UnitTypes::AllUnits) );
  for ( UnitType::set::iterator i = UnitTypes::allUnitTypes().begin(); i != UnitTypes::allUnitTypes().end(); ++i )
  {
    int count = Broodwar->self()->allUnitCount(*i);
    if ( count )
    {
      Broodwar->drawTextScreen(5, 16*line, "- %d %s%c", count, (*i).c_str(), count == 1 ? ' ' : 's');
      ++line;
    }
  }
}

void drawBullets()
{
  Bulletset bullets = Broodwar->getBullets();
  for(Bulletset::iterator i = bullets.begin(); i != bullets.end(); ++i)
  {
    Position p = i->getPosition();
    double velocityX = i->getVelocityX();
    double velocityY = i->getVelocityY();
    Broodwar->drawLineMap(p, p + Position((int)velocityX, (int)velocityY), i->getPlayer() == Broodwar->self() ? Colors::Green : Colors::Red);
    Broodwar->drawTextMap(p, "%c%s", i->getPlayer() == Broodwar->self() ? Text::Green : Text::Red, i->getType().c_str());
  }
}

void drawVisibilityData()
{
  int wid = Broodwar->mapHeight(), hgt = Broodwar->mapWidth();
  for ( int x = 0; x < wid; ++x )
    for ( int y = 0; y < hgt; ++y )
    {
      if ( Broodwar->isExplored(x, y) )
        Broodwar->drawDotMap(x*32+16, y*32+16, Broodwar->isVisible(x, y) ? Colors::Green : Colors::Blue);
      else
        Broodwar->drawDotMap(x*32+16, y*32+16, Colors::Red);
    }
}
/*
void drawTerrainData()
{
  //we will iterate through all the base locations, and draw their outlines.
  for(std::set<BWTA::BaseLocation*>::const_iterator i=BWTA::getBaseLocations().begin();i!=BWTA::getBaseLocations().end();++i)
  {
    TilePosition p=(*i)->getTilePosition();
    Position c=(*i)->getPosition();

    //draw outline of center location
    Broodwar->drawBoxMap(p, p + TilePosition(4,3), Colors::Blue);

    //draw a circle at each mineral patch
    for(Unitset::iterator j=(*i)->getStaticMinerals().begin();j!=(*i)->getStaticMinerals().end();++j)
    {
      Position q=(*j)->getInitialPosition();
      Broodwar->drawCircleMap(q, 30, Colors::Cyan);
    }

    //draw the outlines of vespene geysers
    for(Unitset::iterator j=(*i)->getGeysers().begin();j!=(*i)->getGeysers().end();++j)
    {
      TilePosition q=(*j)->getInitialTilePosition();
      Broodwar->drawBoxMap(q, q + TilePosition(4,2), Colors::Orange);
    }

    //if this is an island expansion, draw a yellow circle around the base location
    if ((*i)->isIsland())
      Broodwar->drawCircleMap(c, 80, Colors::Yellow);
  }

  //we will iterate through all the regions and draw the polygon outline of it in green.
  for(std::set<BWTA::Region*>::const_iterator r=BWTA::getRegions().begin();r!=BWTA::getRegions().end();++r)
  {
    BWTA::Polygon p=(*r)->getPolygon();
    for(int j=0;j<(int)p.size();++j)
    {
      Position point1=p[j];
      Position point2=p[(j+1) % p.size()];
      Broodwar->drawLineMap(point1, point2, Colors::Green);
    }
  }

  //we will visualize the chokepoints with red lines
  for(std::set<BWTA::Region*>::const_iterator r=BWTA::getRegions().begin();r!=BWTA::getRegions().end();++r)
  {
    for(std::set<BWTA::Chokepoint*>::const_iterator c=(*r)->getChokepoints().begin();c!=(*r)->getChokepoints().end();++c)
    {
      Position point1=(*c)->getSides().first;
      Position point2=(*c)->getSides().second;
      Broodwar->drawLineMap(point1, point2, Colors::Red);
    }
  }
}
*/
void showPlayers()
{
  Playerset players = Broodwar->getPlayers();
  for(Playerset::iterator i = players.begin(); i != players.end(); ++i)
    Broodwar << "Player [" << i->getID() << "]: " << i->getName() << " is in force: " << i->getForce()->getName() << std::endl;
}

void showForces()
{
  Forceset forces=Broodwar->getForces();
  for(Forceset::iterator i = forces.begin(); i != forces.end(); ++i)
  {
    Playerset players = i->getPlayers();
    Broodwar << "Force " << i->getName() << " has the following players:" << std::endl;
    for(Playerset::iterator j = players.begin(); j != players.end(); ++j)
      Broodwar << "  - Player [" << j->getID() << "]: " << j->getName() << std::endl;
  }
}
