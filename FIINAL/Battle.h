#pragma once

#include "Enemies\Enemy.h"
#include "Castle\Castle.h"
#include "Generic_DS\Queue.h"
#include "Generic_DS\Stack.h"
#include"Fighter.h"
#include"Freezer.h"
#include"Healer.h"
#include"Fighter.h"
#include"LinkedList.h"
#include"Priority_queue.h"
#include "GUI\GUI.h"
// it is the controller of the project
class Battle
{
private:
	GUI* pGUI;
	Castle BCastle;
	int EnemyCount;	//the actual number of enemies in the game
	int ActiveCount, FrostedCount, KilledCount;	//no. of enemies (Active, Frosted, killed so far)
	int CurrentTimeStep;
	int EDrawCount; //count of enemies to be drawn. added by Nour

	Enemy * BEnemiesForDraw[MaxEnemyCount]; // This Array of Pointers is used for drawing elements in the GUI
											// No matter what list type you are using to hold enemies, 
											// you must pass the enemies to the GUI function as an array of enemy pointers. 
											// At every time step, you should update those pointers 
											// to point to the current active enemies 
											// then pass the pointers list to the GUI function

	bool isModeSelected = false;//added by nour

	Queue<Enemy*> Q_Inactive;		//Queue of inactive enemies
	Stack<Healer*> S_Healers;
	Queue<Freezer*> Q_freezers;
	//Priority_queue<Fighter*> Q_fighters;   ///makes an error
	Queue<Freezer*> Q_froozen_FR;
	Queue<Fighter*> Q_froozen_FT;
	Queue<Healer*> Q_froozen_HL;
	/////////////////////////
	Queue<Fighter*> L_Killed_Fighters; //by Rodina   
	Queue<Healer*> L_Killed_Healers;//by Rodina
	Queue<Freezer*> L_Killed_Freezers;//by Rodina
	/// ==> 
	//	DEMO-related members. Should be removed in phases 1&2
	//Queue for all enemies in the battle
	int DemoListCount;
	Enemy* DemoList[MaxEnemyCount];	//Important: This is just for demo
	/// ==>


	//
	// TODO: Add More Data Members As Needed
	//

public:

	Battle();
	void AddAllListsToDrawingList();		//Add enemy lists (inactive, active,.....) to drawing list to be displayed on user interface
	Castle* GetCastle();
	void RunSimulation();
	void ActivateEnemies();		//check the inactive list and activate all enemies that has arrived
	void Parsing();
	void Killing(Enemy* killed);
	void Freezing(Enemy* Freezed);
	void UnFreezing(Enemy* UnFreezed);
	void Freezing2ActiveEnemies();
	void AddtoDemoList(Enemy* Ptr);		//Add Enemy to the demo queue of enemies (for demo purposes only)
	void Just_A_Demo();	//just to show a demo and should be removed in phase1 1 & 2

	void AddtoBEnemiesForDraw(Enemy* Ptr);	//added by Nour
	void UpdateEnemies();//added by Nour
	//--------------------------------------Modes---------------------------------------//
	void InteractiveMode();//added by nour
	void SilentMode();//added by Nour
	void StepMode();//added by nour

	//-------------------------------------getters--------------------------------------//
	int getCurrentTimeStep() const;//added by Nour--->get the current time step	
	int getEDrawCount();//added by nour --->get enemies to be drawn count 
	int getEnemyCount() const;//added by Nour
	bool getisModeSelected() const;//added by Nour to get if mode is selected 

	//-------------------------------------setters--------------------------------------//
	void setCurrentTimetep(int step);//added by Nour
	void setisModeSelected(bool cond);//added by Nour
	void DrawEnemies(GUI* pGUI); //added by Nour
	void setEnemyCount(int count);//added by Nour
	
	//demo
	void Demo_UpdateEnemies();	//Randomly update enemies distance/status (for demo purposes)
};

