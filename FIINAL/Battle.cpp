#include "Battle.h"
#include <time.h>
#include <fstream>
#include<iostream>

Battle::Battle()
{
	EnemyCount = 0;
	KilledCount = 0;
	ActiveCount = 0;
	FrostedCount = 0;
	DemoListCount = 0;
	EDrawCount = 0;
	CurrentTimeStep = 0;
	pGUI = NULL;
}
//--------------------------------------------getters------------------------------------------// added by Nour
int Battle::getCurrentTimeStep()const
{
	return CurrentTimeStep;
}
int Battle::getEDrawCount()
{
	return  EDrawCount;
}
bool Battle::getisModeSelected() const
{
	return isModeSelected;
}
int Battle::getEnemyCount() const
{
	return EnemyCount;
}
//--------------------------------------------Setters------------------------------------------// added by Nour

void Battle::setisModeSelected(bool cond)
{
	isModeSelected = cond;
}
void Battle::setCurrentTimetep(int step)
{
	CurrentTimeStep = step;
}
void Battle::setEnemyCount(int count)
{
	EnemyCount = count;
}
//---------------------------------------------------------------------------------------------//
void Battle::DrawEnemies(GUI* pGUI)
{
	//pGUI->DrawAllItems(BEnemiesForDraw, EnemyCount);
}
//---------------------------------------------------------------------------------------------//
void Battle::Parsing()
{
	string filename ="";
	ifstream finput;
	while (filename == "")
	{
		filename = OpenWindow("Choose the input text file: ");
	}

	finput.open(filename);

	//ifstream finput("text - Copy.txt");
	char* pch;
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
			EnemyCount = stoi(pch);

		}
	}

	for (int i = 0; i < EnemyCount; i++)
	{
		//Enemy enemy1(1,2,3);
		if (finput.getline(line, size))
		{
			int ID{};
			int AT{};
			int POW{}, RLD{}, SPD{};
			double H{};
			int TYP1;
			pch = strtok_s(line, " ", &context);
			if (pch != NULL)
			{
				ID = stoi(pch);;
				pch = strtok_s(NULL, " ", &context);
				//cout << ID << " ";
			}

			if (pch != NULL)
			{
				TYP1 = stoi(pch);;
				pch = strtok_s(NULL, " ", &context);
				//cout << TYP << " ";
			}

			if (pch != NULL)
			{
				AT = stoi(pch);;
				pch = strtok_s(NULL, " ", &context);
				//cout << AT << " ";
			}

			if (pch != NULL)
			{
				H = stoi(pch);;
				pch = strtok_s(NULL, " ", &context);
				//enemy1->Set_Health(H);
				//enemy1->Set_Original_Health(H);
			}

			if (pch != NULL)
			{
				POW = stoi(pch);;
				pch = strtok_s(NULL, " ", &context);
				//enemy1->Set_Power(POW);
			}

			if (pch != NULL)
			{
				RLD = stoi(pch);
				pch = strtok_s(NULL, " ", &context);
				//enemy1->Set_Reload(RLD);
			}

			if (pch != NULL)
			{
				SPD = stoi(pch);;
				pch = strtok_s(NULL, " ", &context);
				//enemy1->Set_Speed(SPD);
			} //torevise 
			//Q_Inactive.enqueue(enemy1);



			
			if (TYP1 == 0)
			{
				//Fighter* Fi = dynamic_cast<Fighter*>(pE);
				Fighter* fighter = new Fighter(ID, AT, MaxDistance);
				fighter->SetStatus(INAC);
				fighter->Set_Health(H);
				fighter->Set_Original_Health(H);
				fighter->Set_Power(POW);
				fighter->Set_Reload(RLD);
				fighter->Set_Speed(SPD);
				Q_Inactive.enqueue(fighter);
			}
			else if (TYP1 == 1)
			{
				Healer* healer = new Healer(ID, AT, MaxDistance);
				healer->SetStatus(INAC);
				healer->Set_Health(H);
				healer->Set_Original_Health(H);
				healer->Set_Power(POW);
				healer->Set_Reload(RLD);
				healer->Set_Speed(SPD);
				Q_Inactive.enqueue(healer);
			}
			else if (TYP1 == 2)
			{
				Freezer* freezer = new Freezer(ID, AT, MaxDistance);
				freezer->SetStatus(INAC);
				freezer->Set_Health(H);
				freezer->Set_Original_Health(H);
				freezer->Set_Power(POW);
				freezer->Set_Reload(RLD);
				freezer->Set_Speed(SPD);
				Q_Inactive.enqueue(freezer);
			}
		}
	}
}


string Battle::OpenWindow(const string& Message) 
{
	const int BUFSIZE = 512;
	char buffer[BUFSIZE] = { 0 };
	OPENFILENAME ofns = { 0 };
	ofns.lStructSize = sizeof(ofns);
	ofns.lpstrFile = buffer;
	ofns.lpstrFilter = "Text Files\0*.txt\0";
	ofns.nMaxFile = BUFSIZE;
	ofns.lpstrTitle = Message.c_str();
	GetOpenFileName(&ofns);
	return buffer;
}


void Battle::AddtoDemoList(Enemy* Ptr)
{
	DemoList[DemoListCount++] = Ptr;

	// Note that this function doesn't allocate any enemy objects
	// It just enqueue a pointer that is already allocated into the queue
}
void Battle::AddtoBEnemiesForDraw(Enemy* Ptr)//added by Nour
{
	if (EnemyCount < MaxEnemyCount)
	{
		BEnemiesForDraw[EDrawCount++] = Ptr;

	}
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
	keytype key = pGUI->GetPress();

	//if (key != 2)
	//{
	//	//cout << "Lets Play" << endl; //for debugging 
	//	#pragma comment(lib,"winmm.lib")
	//	PlaySound("jujutsukaisen.wav", NULL, SND_ASYNC);
	//}
	//else { PlaySound("pszSound", NULL, SND_ASYNC); }
	////------------------------------------------------------------------------------------//
	setisModeSelected(false);
	switch (mode)	//Add a function for each mode in next phases
	{
	case MODE_INTR:
		setisModeSelected(true);//added by Nour
		InteractiveMode();//added by Nour
		break;
	case MODE_STEP:
		StepMode();//added by nour
		break;
	case MODE_SLNT:
		SilentMode();//added by nour
		break;
	case MODE_DEMO://to be removed "nour"
		//Just_A_Demo();
		break;
	}
	delete pGUI;//deletes the interface 
}

//}

void Battle::InteractiveMode()//added by nour
{
	/*char c = NULL;
	keytype key = pGUI->pWind->GetKeyPress(c);
	key = pGUI->pWind->GetKeyPress(c);*/
	//cout << "key" << key << endl;
	//keytype key = pGUI->GetPress();
	bool flag = false;
	setCurrentTimetep(0);
	KilledCount = 0;
	pGUI->UpdateInterface(CurrentTimeStep);
	//while ((key != ESCAPE) && (getisModeSelected()==true))
	//{
	pGUI->FlushForClick();//Needed to change pWind to public because of flushing issues 
//	key = pGUI->pWind->GetKeyPress(c);
//	if (key != 4)
	//{

	while (KilledCount < EnemyCount)	//as long as some enemies are alive (should be updated in next phases)//by Nour
	{

		pGUI->waitForClick();	//check if click is inside the yellow box//by Nour
		CurrentTimeStep++;//by Nour
		pGUI->UpdateInterface(CurrentTimeStep);	//upadte interface to show the initial case where all enemies are still inactive//by Nour
		ActivateEnemies();//by Nour
		UpdateEnemies();//by Nour
		//Freezing2ActiveEnemies();
		pGUI->UpdateInterface(CurrentTimeStep);//by Nour
		///////////Update Battle Info/////////////// by Rodina
		pGUI->Set_Active_Healers(S_Healers.getSize());
		pGUI->Set_Active_Freezers(Q_freezers.getSize());
		pGUI->Set_Active_Fighters(Q_fighters.getSize());


		pGUI->Set_Frosted_Healers(Q_froozen_HL.getSize());
		pGUI->Set_Frosted_Freezers(Q_froozen_FR.getSize());
		//pGUI->Set_Frosted_Fighters(Q_froozen_FT.getSize());


		pGUI->Set_Killed_Healers(L_Killed_Healers.getSize());
		pGUI->Set_Killed_Freezers(L_Killed_Freezers.getSize());
		//pGUI->Set_Killed_Fighters(L_Killed_Fighters.getSize());


		///////////////Update_castle_Info/////////// by Rodina
		pGUI->Set_Castle_Health(BCastle.GetHealth());
		pGUI->Set_Castle_Status(BCastle.Get_Frosted());

		/// ///////
		pGUI->ResetDrawingList();
		AddAllListsToDrawingList();
		pGUI->UpdateInterface(CurrentTimeStep);

		//kill 1 enemy added by Nour
		if (S_Healers.getSize() != 0 && KilledCount != 1 && ActiveCount != 1 && flag == false)
		{
			Healer* killed = nullptr;
			S_Healers.Pop(killed);
			killed->SetStatus(KILD);//edited by Nour
			L_Killed_Healers.enqueue(killed);
			KilledCount++;

		}
		pGUI->ResetDrawingList();//by Nour
		AddAllListsToDrawingList();//by Nour
		pGUI->UpdateInterface(CurrentTimeStep);//by Nour

		//Freeze 2 enemies added by Nour
		if (Q_freezers.getSize() >= 2 && FrostedCount != 2 && CurrentTimeStep > 4)
		{
			Freezer* freeze = nullptr;
			Q_freezers.dequeue(freeze);
			freeze->SetStatus(FRST);//edited by Nour
			Q_froozen_FR.enqueue(freeze);
			FrostedCount++;

		}

	}
	Sleep(5000);//by Nour for debugging



}
void Battle::SilentMode()//added by nour
{

}
void Battle::StepMode()//added by nour
{
	//char c = NULL;
	//keytype key = pGUI->pWind->GetKeyPress(c);
	CurrentTimeStep = 0;
	//while (key != 4)
	//{
		//key = pGUI->pWind->GetKeyPress(c);
	int x = 0;
	int y = 0;
	//pGUI->pWind->WaitMouseClick(x, y);	//check if click is inside the yellow box
	pGUI->InDrawingArea(y);
	CurrentTimeStep++;
	Sleep(1000);
	pGUI->UpdateInterface(CurrentTimeStep);	//upadte interface to show the initial case where all enemies are still inactive
	cout << CurrentTimeStep << endl;
	//}
}
//This is just a demo function for project introductory phase
//It should be removed in phases 1&2
//void Battle::Just_A_Demo()
//{
//
//	pGUI->PrintMessage("Just a Demo. Enter Enemies Count(next phases should read I/P filename):");
//	EnemyCount = atoi(pGUI->GetString().c_str());	//get user input as a string then convert to integer
//
//	pGUI->PrintMessage("Generating Enemies randomly... In next phases, Enemies should be loaded from a file...CLICK to continue");
//	pGUI->waitForClick();
//
//	CurrentTimeStep = 0;
//	//
//	// THIS IS JUST A DEMO Function
//	// IT SHOULD BE REMOVED IN PHASE 1 AND PHASE 2
//	//
//
//	srand(time(NULL));
//	int Enemy_id = 0;
//	int ArrivalTime = 1;
//	Enemy* pE = NULL;
//	//Create Random enemies and add them all to inactive queue
//	for (int i = 0; i < EnemyCount; i++)
//	{
//		ArrivalTime += (rand() % 3);	//Randomize arrival time
//		pE = new Fighter(1,2,3);
//		pE->SetStatus(INAC); //initiall all enemies are inactive
//		Q_Inactive.enqueue(pE);		//Add created enemy to inactive Queue
//	}
//	//Q_Inactive;
//	AddAllListsToDrawingList();
//	pGUI->UpdateInterface(CurrentTimeStep);	//upadte interface to show the initial case where all enemies are still inactive
//
//	pGUI->waitForClick();
//
//	while (KilledCount < EnemyCount)	//as long as some enemies are alive (should be updated in next phases)
//	{
//		CurrentTimeStep++;
//		ActivateEnemies();
//
//		Demo_UpdateEnemies();	//Randomly update enemies distance/status (for demo purposes only)
//
//		pGUI->ResetDrawingList();
//		AddAllListsToDrawingList();
//		pGUI->UpdateInterface(CurrentTimeStep);
//		Sleep(250);
//	}
//}

//Add enemy lists (inactive, active,.....) to drawing list to be displayed on user interface
void Battle::AddAllListsToDrawingList()
{
	//Add inactive queue to drawing list
	int InactiveCount;
	Enemy* const* EnemyList = Q_Inactive.toArray(InactiveCount);
	for (int i = 0; i < InactiveCount; i++)
		pGUI->AddToDrawingList(EnemyList[i]);

	//-------------------------------added by Nour-------------------------------------//
	/*int KilledCount;
	Enemy* const* KilledList = L_Killed.toArray(KilledCount);
	for (int i = 0; i < KilledCount; i++)
		pGUI->AddToDrawingList(KilledList[i]);
	*/
	int KilledHealerCount;
	Healer* const* KilledHealerList = L_Killed_Healers.toArray(KilledHealerCount);
	for (int i = 0; i < KilledHealerCount; i++)
		pGUI->AddToDrawingList(KilledHealerList[i]);


	int  KilledFighterCount;
	Fighter* const* KilledFighterList = L_Killed_Fighters.toArray(KilledFighterCount);
	for (int i = 0; i < KilledFighterCount; i++)
		pGUI->AddToDrawingList(KilledFighterList[i]);


	int KilledFreezerCount;
	Freezer* const* KilledFreezerList = L_Killed_Freezers.toArray(KilledFreezerCount);
	for (int i = 0; i < KilledFreezerCount; i++)
		pGUI->AddToDrawingList(KilledFreezerList[i]);



	int HealersCount;
	Healer* const* HealersList = S_Healers.toArray(HealersCount);
	for (int i = 0; i < HealersCount; i++)
	{
		pGUI->AddToDrawingList(HealersList[i]);

	}

	int FighterCount;
	Fighter* const* FighterList = Q_fighters.toArray(FighterCount);
	for (int i = 0; i < FighterCount; i++)
		pGUI->AddToDrawingList(FighterList[i]);

	int FreezersCount;
	Freezer* const* FreezersList = Q_freezers.toArray(FreezersCount);
	for (int i = 0; i < FreezersCount; i++)
	{
		pGUI->AddToDrawingList(FreezersList[i]);
	}
	int FrozenFighterCount;
	Fighter* const* FrozenFighterList = Q_froozen_FT.toArray(FrozenFighterCount);
	for (int i = 0; i < FrozenFighterCount; i++)
		pGUI->AddToDrawingList(FrozenFighterList[i]);

	int FrozenFreezerCount;
	Freezer* const* FrozenFreezerList = Q_froozen_FR.toArray(FrozenFreezerCount);
	for (int i = 0; i < FrozenFreezerCount; i++)
		pGUI->AddToDrawingList(FrozenFreezerList[i]);

	int FrozenHealerCount;
	Healer* const* FrozenHealerList = Q_froozen_HL.toArray(FrozenHealerCount);
	for (int i = 0; i < FrozenHealerCount; i++)
		pGUI->AddToDrawingList(FrozenHealerList[i]);

	//Add other lists to drawing list
	//-------------------------------------------------------------------------------//

	//TO DO
	//In next phases, you should add enemies from different lists to the drawing list
	//For the sake of demo, we will use DemoList

	//for (int i = 0; i < EDrawCount; i++)//added by Nour
	//	pGUI->AddToDrawingList(BEnemiesForDraw[i]);

	//for (int i = 0; i < DemoListCount; i++)
	//	pGUI->AddToDrawingList(DemoList[i]);
}

//check the inactive list and activate all enemies that has arrived
void Battle::ActivateEnemies()
{
	Enemy* pE;
	while (Q_Inactive.peekFront(pE))	//as long as there are more inactive enemies
	{
		if (pE->GetArrvTime() > CurrentTimeStep)	//no more arrivals at current time
			return;
		else if (pE->GetArrvTime() == CurrentTimeStep)
		{
			ActiveCount++;
			Q_Inactive.dequeue(pE);	      //remove enemy from the queue
			ActiveForMove.enqueue(pE);
			pE->SetStatus(ACTV);	     //make status active

			Fighter* Fi = dynamic_cast<Fighter*>(pE);
			Healer* He = dynamic_cast<Healer*>(pE);
			Freezer* Fr = dynamic_cast<Freezer*>(pE);

		

			if (Fi != NULL)
			{
				Q_fighters.push(Fi, ActiveCount);
				Fi->SetStatus(ACTV);
			}
			else if (He != NULL)
			{
				S_Healers.Push(He);
				He->SetStatus(ACTV);
			}
			else if (Fr != NULL)
			{
				Q_freezers.enqueue(Fr);
				Fr->SetStatus(ACTV);
			}

		}
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
void Battle::UpdateEnemies()
{
	Enemy* pE;
	//Freeze, activate, and kill propablities (for sake of demo)
	int FreezProp = 5, ActvProp = 10, KillProp = 1;
	srand(time(0));
	for (int i = 0; i < ActiveCount; i++)
	{
		Fighter* Fi = nullptr;
		Healer* HE = nullptr;
		Freezer* Fr = nullptr;
		//pE = BEnemiesForDraw[i];
		if (ActiveCount != 0)
		{
			ActiveForMove.dequeue(pE);
			if (pE->GetStatus() == ACTV)
			{
				ActiveForMove.enqueue(pE);
			}

			/*if (pE->Get_Type() == FIGHTER)
				Fi = static_cast<Fighter*>(pE);
			else if (pE->Get_Type() == HEALER)
				HE = static_cast<Healer*>(pE);
			else if (pE->Get_Type() == FREEZER)
				Fr = static_cast<Freezer*>(pE);*/


				/*Fighter* Fi = static_cast<Fighter*>(pE);
				Healer* He = static_cast<Healer*>(pE);
				Freezer* Fr = static_cast<Freezer*>(pE);*/


			Fighter* Fi = dynamic_cast<Fighter*>(pE);
			Healer* HE = dynamic_cast<Healer*>(pE);
			Freezer* Fr = dynamic_cast<Freezer*>(pE);


			if (pE->GetStatus() == ACTV)
			{
				if (Fi != nullptr)
					Fi->Move();
				else if (HE != nullptr)
					HE->Move();
				else if (Fr != nullptr)
					Fr->Move();


			}
		}
	}
}

void Battle::Freezing2ActiveEnemies() //by Rodina
{
	Freezer* F_E = nullptr;
	Healer* H_E = nullptr;
	Fighter* FIG_E = nullptr;

	if (Q_freezers.getSize() > 2 && KilledCount < 2 && ActiveCount == 8)
	{
		Q_freezers.dequeue(F_E);
		F_E->SetStatus(FRST);
		Q_froozen_FR.enqueue(F_E);
		FrostedCount++;

		Q_freezers.dequeue(F_E);
		F_E->SetStatus(FRST);
		Q_froozen_FR.enqueue(F_E);
		FrostedCount++;

	}
	if (S_Healers.getSize() > 2 && KilledCount < 3 && ActiveCount == 6)
	{
		S_Healers.Pop(H_E);
		H_E->SetStatus(FRST);
		Q_froozen_HL.enqueue(H_E);
		FrostedCount++;

		S_Healers.Pop(H_E);
		H_E->SetStatus(FRST);
		Q_froozen_HL.enqueue(H_E);
		FrostedCount++;

	}
	if (Q_fighters.getSize() >= 2)
	{

		//Q_fighters.pop(FIG_E);
		Q_froozen_FT.enqueue(FIG_E);
		//Q_fighters.pop(FIG_E);
		Q_froozen_FT.enqueue(FIG_E);

	}


}
	
