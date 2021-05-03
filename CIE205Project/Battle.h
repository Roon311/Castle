#pragma once

#include "Enemies\Enemy.h"
#include "Castle\Castle.h"
#include "Generic_DS\Queue.h"
#include "Generic_DS\Stack.h"
#include"LinkedList.h"
#include"PriorityQueue.h"
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
	
					//Enemy * BEnemiesForDraw[MaxEnemyCount]; // This Array of Pointers is used for drawing elements in the GUI
											// No matter what list type you are using to hold enemies, 
											// you must pass the enemies to the GUI function as an array of enemy pointers. 
											// At every time step, you should update those pointers 
											// to point to the current active enemies 
											// then pass the pointers list to the GUI function

	Queue<Enemy*> Q_Inactive;		//Queue of inactive enemies
	Stack<Enemy*> S_Healers;
	Queue<Enemy*> Q_freezer;
	Priority_queue<Enemy*> Q_fighters;
	LinkedList<Enemy*> L_Killed;     //when linked list created
	Queue<Enemy*> Q_froozen;
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

	void AddtoDemoList(Enemy* Ptr);		//Add Enemy to the demo queue of enemies (for demo purposes only)
	void Just_A_Demo();	//just to show a demo and should be removed in phase1 1 & 2
	void Demo_UpdateEnemies();	//Randomly update enemies distance/status (for demo purposes)
	int getCurrentTimeStep();//to access private member	added by Nour
	int getEDrawCount();
	//
	// TODO: Add More Member Functions As Needed
	//
};

