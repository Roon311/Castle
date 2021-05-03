#include "Battle.h"
#include <time.h>
#include <fstream>

Battle::Battle()
{
	EnemyCount = 0;
	KilledCount = 0;
	ActiveCount = 0;
	FrostedCount = 0;
	DemoListCount = 0;
	CurrentTimeStep = 0;
	pGUI = NULL;
}
//--------------------------------------------getters------------------------------------------// added by Nour
int Battle::getCurrentTimeStep()
{
	return CurrentTimeStep;
}
int Battle::getEDrawCount()
{
	return  EDrawCount;
}

//---------------------------------------------------------------------------------------------//
void Battle::Parsing()
{
	ifstream finput("text - Copy.txt");
	char* pch;
	string CourseCode;
	char* context = nullptr;
	const int size = 300;
	char line[size];

	if (finput.getline(line, size)) //read file line by line
	{ //parse the line
		pch = strtok_s(line, " ", &context);
		if (pch != NULL)
		{
			if (pch != NULL)
			{
				int CH = stoi(pch);;
				pch = strtok_s(NULL, " ", &context);
				BCastle.SetHealth(CH);
			}
			if (pch != NULL)
			{
				int N = stoi(pch);;
				pch = strtok_s(NULL, " ", &context);
				BCastle.SetMax_Enemy(N);
			}
			if (pch != NULL)
			{
				int CP = stoi(pch);;
				pch = strtok_s(NULL, " ", &context);
				BCastle.SetPower(CP);
			}
		}
	}

	if (finput.getline(line, size)) //read file line by line
	{ //parse the line
		pch = strtok_s(line, " ", &context);
		if (pch != NULL)
		{
			int EnemyCount = stoi(pch);

		}
	}

	for (int i = 0; i < EnemyCount; i++)
	{
		//Enemy enemy1(1,2,3);
		if (finput.getline(line, size))
		{
			int ID, AT;
			ENMY_TYPE TYP;
			pch = strtok_s(line, " ", &context);
			if (pch != NULL)
			{
				ID = stoi(pch);;
				pch = strtok_s(NULL, " ", &context);
				//cout << ID << " ";
			}

			if (pch != NULL)
			{
				TYP = (ENMY_TYPE)stoi(pch);;
				pch = strtok_s(NULL, " ", &context);
				//cout << TYP << " ";
			}

			if (pch != NULL)
			{
				AT = stoi(pch);;
				pch = strtok_s(NULL, " ", &context);
				//cout << AT << " ";
			}
			Enemy enemy1(ID, AT, 60);  //torevise 
			enemy1.SetStatus(INAC);//

			if (pch != NULL)
			{
				int H = stoi(pch);;
				pch = strtok_s(NULL, " ", &context);
				enemy1.Set_Health(H);
			}

			if (pch != NULL)
			{
				int POW = stoi(pch);;
				pch = strtok_s(NULL, " ", &context);
				enemy1.Set_Power(POW);
			}

			if (pch != NULL)
			{
				int RLD = stoi(pch);
				pch = strtok_s(NULL, " ", &context);
				enemy1.Set_Reload(RLD);
			}

			if (pch != NULL)
			{
				int SPD = stoi(pch);;
				pch = strtok_s(NULL, " ", &context);
				enemy1.Set_Speed(SPD);
			}
			Enemy* eny = &enemy1;   //torevise 
			Q_Inactive.enqueue(eny);
		}
	}
}

void Battle::Killing(Enemy* killed) //omar adding
{
	L_Killed.InsertEnd(killed);
}
void Battle::Freezing(Enemy* Freezed) //omar adding
{
	Q_froozen.enqueue(Freezed);
}  
void Battle::UnFreezing(Enemy* UnFreezed) //omar adding
{
	Q_froozen.dequeue(UnFreezed);
} 

void Battle::AddtoDemoList(Enemy* Ptr)
{
	DemoList[DemoListCount++] = Ptr;

	// Note that this function doesn't allocate any enemy objects
	// It just enqueue a pointer that is already allocated into the queue
}


Castle* Battle::GetCastle()
{
	return &BCastle;
}


void Battle::RunSimulation()//starting the battle
{
	//bool flag = true;// added by Nour
	Parsing();
	pGUI = new GUI;//create a new GUI with pGUI pointing to it
	PROG_MODE	mode = pGUI->getGUIMode();
	//while (flag == true)//added by Nour
	//{
		//-------------------------------Added by Nour----------------------------------------//
		char c = NULL;
		keytype key = pGUI->pWind->GetKeyPress(c);
		
		if (key != 4)
		{
			//cout << "Lets Play" << endl; //for debugging 
			#pragma comment(lib,"winmm.lib")
			PlaySound("jujutsukaisen.wav", NULL, SND_ASYNC);
		}
		else { PlaySound("pszSound", NULL, SND_ASYNC); }
		//------------------------------------------------------------------------------------//
		switch (mode)	//Add a function for each mode in next phases
		{
		case MODE_INTR:
			break;
		case MODE_STEP:
			break;
		case MODE_SLNT:
			break;
		case MODE_DEMO:
			Just_A_Demo();

		}
		delete pGUI;
	}

//}


//This is just a demo function for project introductory phase
//It should be removed in phases 1&2
void Battle::Just_A_Demo()
{

	pGUI->PrintMessage("Just a Demo. Enter Enemies Count(next phases should read I/P filename):");
	EnemyCount = atoi(pGUI->GetString().c_str());	//get user input as a string then convert to integer

	pGUI->PrintMessage("Generating Enemies randomly... In next phases, Enemies should be loaded from a file...CLICK to continue");
	pGUI->waitForClick();

	CurrentTimeStep = 0;
	//
	// THIS IS JUST A DEMO Function
	// IT SHOULD BE REMOVED IN PHASE 1 AND PHASE 2
	//

	srand(time(NULL));
	int Enemy_id = 0;
	int ArrivalTime = 1;
	Enemy* pE = NULL;
	//Create Random enemies and add them all to inactive queue
	for (int i = 0; i < EnemyCount; i++)
	{
		ArrivalTime += (rand() % 3);	//Randomize arrival time
		pE = new Enemy(++Enemy_id, ArrivalTime);
		pE->SetStatus(INAC); //initiall all enemies are inactive
		Q_Inactive.enqueue(pE);		//Add created enemy to inactive Queue
	}

	AddAllListsToDrawingList();
	pGUI->UpdateInterface(CurrentTimeStep);	//upadte interface to show the initial case where all enemies are still inactive

	pGUI->waitForClick();

	while (KilledCount < EnemyCount)	//as long as some enemies are alive (should be updated in next phases)
	{
		CurrentTimeStep++;
		ActivateEnemies();

		Demo_UpdateEnemies();	//Randomly update enemies distance/status (for demo purposes only)

		pGUI->ResetDrawingList();
		AddAllListsToDrawingList();
		pGUI->UpdateInterface(CurrentTimeStep);
		Sleep(250);
	}
}

//Add enemy lists (inactive, active,.....) to drawing list to be displayed on user interface
void Battle::AddAllListsToDrawingList()
{
	//Add inactive queue to drawing list
	int InactiveCount;
	Enemy* const* EnemyList = Q_Inactive.toArray(InactiveCount);
	for (int i = 0; i < InactiveCount; i++)
		pGUI->AddToDrawingList(EnemyList[i]);

	//Add other lists to drawing list
	//TO DO
	//In next phases, you should add enemies from different lists to the drawing list
	//For the sake of demo, we will use DemoList
	for (int i = 0; i < DemoListCount; i++)
		pGUI->AddToDrawingList(DemoList[i]);
}

//check the inactive list and activate all enemies that has arrived
void Battle::ActivateEnemies()
{
	Enemy* pE;
	while (Q_Inactive.peekFront(pE))	//as long as there are more inactive enemies
	{
		if (pE->GetArrvTime() > CurrentTimeStep)	//no more arrivals at current time
			return;

		Q_Inactive.dequeue(pE);	//remove enemy from the queue
		pE->SetStatus(ACTV);	//make status active
		//pE->
		if (pE->Get_Type() == 0)
		{
			Q_fighters.push(pE);
		}
		else if (pE->Get_Type() == 1)
		{
			S_Healers.Push(pE);
		}
		else if (pE->Get_Type() == 2)
		{
			Q_freezer.enqueue(pE);
		}
		AddtoDemoList(pE);		//move it to demo list (for demo purposes)
	}
}


//Randomly update enemies distance/status (for demo purposes)
void Battle::Demo_UpdateEnemies()
{
	Enemy* pE;
	int Prop;
	//Freeze, activate, and kill propablities (for sake of demo)
	int FreezProp = 5, ActvProp = 10, KillProp = 1;
	srand(time(0));
	for (int i = 0; i < DemoListCount; i++)
	{
		pE = DemoList[i];
		switch (pE->GetStatus())
		{
		case ACTV:
			pE->DecrementDist();	//move the enemy towards the castle
			Prop = rand() % 100;
			if (Prop < FreezProp)		//with Freeze propablity, change some active enemies to be frosted
			{
				pE->SetStatus(FRST);
				ActiveCount--;
				FrostedCount++;
			}
			else	if (Prop < (FreezProp + KillProp))	//with kill propablity, kill some active enemies
			{
				pE->SetStatus(KILD);
				ActiveCount--;
				KilledCount++;
			}

			break;
		case FRST:
			Prop = rand() % 100;
			if (Prop < ActvProp)			//with activation propablity, change restore some frosted enemies to be active again
			{
				pE->SetStatus(ACTV);
				ActiveCount++;
				FrostedCount--;
			}

			else	if (Prop < (ActvProp + KillProp))			//with kill propablity, kill some frosted enemies
			{
				pE->SetStatus(KILD);
				FrostedCount--;
				KilledCount++;
			}

			break;
		}
	}
}
