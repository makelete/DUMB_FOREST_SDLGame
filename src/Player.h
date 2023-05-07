#pragma once
#include "CommonFunction.h"
#include "BaseObj.h"
#include "OtherObj.h"

#define GRAVITY_SPEED 0.2
#define MAX_FALL_SPEED 4
#define PLAYER_SPEED 2.5
#define BLANK_TILE 0
#define JUMP_VAL 7
#define BROWN_FISH 5
#define GREEN_FISH 6
#define POISON 4
#define BROWN_LIQUID 7
#define GREEN_LIQUID 8


class Player : public BaseObj
{
public:
	Player();
	~Player();

	enum WalkType {
		WALK_RIGHT = 0,
		WALK_LEFT = 1,
		STAY_LEFT = 2,
		STAY_RIGHT = 3,
		JUMP=4,
	};

	bool LoadImg(string path, SDL_Renderer* renderer);
	void show1(SDL_Renderer* des);
	void show2(SDL_Renderer* des);
	void handleEvent1(SDL_Event e, SDL_Renderer* renderer,Mix_Chunk* sound[5]);
	void handleEvent2(SDL_Event e, SDL_Renderer* renderer, Mix_Chunk* sound[5]);
	void setclip();

	void DoPlayer1(Map& mapdata, int p);
	void DoPlayer2(Map& mapdata, int p);

	void CheckToMap1(Map& mapdata);
	void CheckToMap2(Map& mapdata);

	void CheckToMus(int p, OtherObj &mushroom);

	void CheckToGate(int p,OtherObj &gate_);

	void UpdateImgPlayer1(SDL_Renderer* des);
	void UpdateImgPlayer2(SDL_Renderer* des);

	bool isEating_fish(Map& mapdata);
	void BrownFish_Player1();
	void GreenFish_Player1();

    int getScore1()
	{
	    
	    score1 = brownfish1 + greenfish1;
	    return score1;
	}
	void resetPoint()
	{
		score1=0;
		score2=0;
		brownfish1=0;
		brownfish2=0;
		greenfish1=0;
		greenfish2=0;
	}

	void BrownFish_Player2();
	void GreenFish_Player2();

    int getScore2()
	{
	    score2 = brownfish2 + greenfish2;
	    return score2;
	   
	}


	void setPos(float x,float y)
	{
		xpos = x;
		ypos = y;
	}
	void nextLevel(bool check) {
		check = true;
	}

	bool checkNextLevelP1() {
		return nextLevelPlayer[0];
	}
	bool checkNextLevelP2() {
		return nextLevelPlayer[1];
	}

	int GameOver1() { return gameoverState; }
	int GameOver2() { return gameoverState; }

	void changeState() {
		if (gameoverState == 1)
		{
			gameoverState = 0;
		}
	}

private:

	int brownfish1;
	int greenfish1;

	int score1=0;
	int score2=0;
	
	int brownfish2;
	int greenfish2;


	float xval;
	float yval;
	float xpos;
	float ypos;

	int widthframe;
	int heightframe;

	bool nextLevelPlayer[2]={0,0};

	SDL_Rect FRAME_CLIP[12];


	Input input_type;
	int frame;
	int status;
	bool onground=false;
	bool isEatingFish;
	int gameoverState=0;
};
