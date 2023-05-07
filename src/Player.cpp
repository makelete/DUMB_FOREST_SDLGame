#include "Player.h"
#include "OtherObj.h"

Player::Player()
{
	frame = 0;
	xpos = 332;
	ypos = 664;
	xval = 0;
	yval = 0;
	widthframe = 0;
	heightframe = 0;
	status = -1;
	onground = false;
	input_type.left = 0;
	input_type.right = 0;
	input_type.stayleft = 0;
	input_type.stayright = 0;
	input_type.jump = 0;

	brownfish1 = 0;
	greenfish1=0;


	brownfish2 = 0;
	greenfish2=0;


	brownfish2 = 0;
	greenfish2=0;
}

Player::~Player() {
	Free();
}

//Load image at specified path
bool Player::LoadImg(string path, SDL_Renderer* renderer) {
	bool ktra = BaseObj::LoadImg(path, renderer);

	if (ktra == true) {
		widthframe = 32;
		heightframe = 32;
	}
	return ktra;
}

//Array of the player's state
void Player::setclip() {
	if (widthframe > 0 && heightframe > 0) {
		FRAME_CLIP[0].x = 0;
		FRAME_CLIP[0].y = 0;
		FRAME_CLIP[0].w = widthframe;
		FRAME_CLIP[0].h = heightframe;

		FRAME_CLIP[1].x = widthframe;
		FRAME_CLIP[1].y = 0;
		FRAME_CLIP[1].w = widthframe;
		FRAME_CLIP[1].h = heightframe;

		FRAME_CLIP[2].x = widthframe * 2;
		FRAME_CLIP[2].y = 0;
		FRAME_CLIP[2].w = widthframe;
		FRAME_CLIP[2].h = heightframe;

		FRAME_CLIP[3].x = widthframe * 3 ;
		FRAME_CLIP[3].y = 0;
		FRAME_CLIP[3].w = widthframe;
		FRAME_CLIP[3].h = heightframe;

		FRAME_CLIP[4].x = widthframe * 4;
		FRAME_CLIP[4].y = 0;
		FRAME_CLIP[4].w = widthframe;
		FRAME_CLIP[4].h = heightframe;

		FRAME_CLIP[5].x = widthframe * 5;
		FRAME_CLIP[5].y = 0;
		FRAME_CLIP[5].w = widthframe;
		FRAME_CLIP[5].h = heightframe;

		FRAME_CLIP[6].x = widthframe * 6;
		FRAME_CLIP[6].y = 0;
		FRAME_CLIP[6].w = widthframe;
		FRAME_CLIP[6].h = heightframe;

		FRAME_CLIP[7].x = widthframe * 7;
		FRAME_CLIP[7].y = 0;
		FRAME_CLIP[7].w = widthframe;
		FRAME_CLIP[7].h = heightframe;

		FRAME_CLIP[8].x = widthframe * 8;
		FRAME_CLIP[8].y = 0;
		FRAME_CLIP[8].w = widthframe;
		FRAME_CLIP[8].h = heightframe;

		FRAME_CLIP[9].x = widthframe * 9;
		FRAME_CLIP[9].y = 0;
		FRAME_CLIP[9].w = widthframe;
		FRAME_CLIP[9].h = heightframe;

		FRAME_CLIP[10].x = widthframe * 10;
		FRAME_CLIP[10].y = 0;
		FRAME_CLIP[10].w = widthframe;
		FRAME_CLIP[10].h = heightframe;

		FRAME_CLIP[11].x = widthframe * 11;
		FRAME_CLIP[11].y = 0;
		FRAME_CLIP[11].w = widthframe;
		FRAME_CLIP[11].h = heightframe;
	}
}

//Show the player
void Player::show1(SDL_Renderer* des) {
	UpdateImgPlayer1(des);
	if ((input_type.left == 1 || input_type.right == 1|| input_type.stayright == 1|| input_type.stayleft == 1)&&onground==true&&input_type.jump==0) {
		if (input_type.left == 1 || input_type.right == 1) {
			frame++;
		}
		else
		{
			frame = 0;
		}
	}
	else {
		frame = 0;
	}
	if (input_type.jump == 1) {
		frame = 0;
	}

	if ((input_type.stayleft == 1 || input_type.stayright == 1) && frame > 10)
	{
		frame = 0;
	}

	if (frame > 11) frame = 0;

	rect.x = xpos;
	rect.y = ypos;

	SDL_Rect* currentclip = &FRAME_CLIP[frame];
	SDL_Rect renderQuad = {rect.x,rect.y,2 * widthframe, 2 * heightframe};

	if (currentclip != NULL)
	{
		renderQuad.w = 2 * currentclip->w;
		renderQuad.h = 2 * currentclip->h;
	}


	SDL_RenderCopy(des, texture, currentclip, &renderQuad);
}

void Player::show2(SDL_Renderer* des) {
	UpdateImgPlayer2(des);
	if ((input_type.left == 1 || input_type.right == 1 || input_type.stayright == 1 || input_type.stayleft == 1) && onground == true && input_type.jump == 0) {
		if (input_type.left == 1 || input_type.right == 1) {
			frame++;
		}
		else
		{
			frame = 0;
		}
	}
	else {
		frame = 0;
	}
	if (input_type.jump == 1) {
		frame = 0;
	}

	if ((input_type.stayleft == 1 || input_type.stayright == 1) && frame > 10)
	{
		frame = 0;
	}

	if (frame > 11) frame = 0;

	rect.x = xpos;
	rect.y = ypos;

	SDL_Rect* currentclip = &FRAME_CLIP[frame];
	SDL_Rect renderQuad = {rect.x,rect.y,widthframe * 2,heightframe * 2};

	if (currentclip != NULL)
	{
		renderQuad.w = 2 * currentclip->w;
		renderQuad.h = 2 * currentclip->h;
	}

	SDL_RenderCopy(des, texture, currentclip, &renderQuad);
}

//Receive keyboard input and manage the player's state


void Player::handleEvent1(SDL_Event e, SDL_Renderer* renderer, Mix_Chunk* sound[5])
{
	if (e.type == SDL_KEYDOWN) 
	{
		switch (e.key.keysym.sym) 
		{
		case SDLK_RIGHT:
			status = WALK_RIGHT;
			input_type.stayleft = 0;
			input_type.stayright = 0;
			input_type.right = 1;
			input_type.left = 0;

			UpdateImgPlayer1(renderer);
			break;

		case SDLK_LEFT:
			status = WALK_LEFT;
			input_type.stayleft = 0;
			input_type.stayright = 0;
			input_type.left = 1;
			input_type.right = 0;

			UpdateImgPlayer1(renderer);

			break;
		case SDLK_UP:
			if (onground ) {
				Mix_PlayChannel(-1, sound[0], 0);
				input_type.jump = 1;
				input_type.stayleft = 0;
				input_type.stayright = 0;
			}
			break;
		default:
			break;
		}
	}
	else if (e.type == SDL_KEYUP) {
		switch (e.key.keysym.sym) {
		case SDLK_RIGHT:
			status = STAY_RIGHT;
			if (onground == true) {
				input_type.stayright = 1;
				input_type.right = 0;
				input_type.stayleft = 0;
			}
			input_type.right = 0;
			input_type.stayleft = 0;

			UpdateImgPlayer1(renderer);

			break;
		case SDLK_LEFT:
			status = STAY_LEFT;
			if (onground == true) {
				input_type.stayleft = 1;
				input_type.left = 0;
				input_type.stayright = 0;
			}
			input_type.left = 0;
			input_type.stayright = 0;

			UpdateImgPlayer1(renderer);

			break;
		default:
			break;
		}
	}
}

void Player::handleEvent2(SDL_Event e,SDL_Renderer* renderer,Mix_Chunk* sound[5]) {
	if (e.type == SDL_KEYDOWN) {
		switch (e.key.keysym.sym) {
		case SDLK_d:
			status = WALK_RIGHT;
			input_type.stayleft = 0;
			input_type.stayright = 0;
			input_type.right = 1;
			input_type.left = 0;

			UpdateImgPlayer2(renderer);
			break;

		case SDLK_a:
			status = WALK_LEFT;
			input_type.stayleft = 0;
			input_type.stayright = 0;
			input_type.left = 1;
			input_type.right = 0;

			UpdateImgPlayer2(renderer);

			break;
		case SDLK_w:
			status = JUMP;
			if (onground) {
				Mix_PlayChannel(-1, sound[0], 0);
				input_type.jump = 1;
				input_type.stayleft = 0;
				input_type.stayright = 0;
			}

			break;
		default:

			break;
		}
	}
	else if (e.type == SDL_KEYUP) {
		switch (e.key.keysym.sym) {
		case SDLK_d:
			status = STAY_RIGHT;
			if (onground == true) {
				input_type.stayright = 1;
				input_type.right = 0;
				input_type.stayleft = 0;
			}
			input_type.right = 0;
			input_type.stayleft = 0;

			UpdateImgPlayer2(renderer);

			break;
		case SDLK_a:
			status = STAY_LEFT;
			if (onground == true) {
				input_type.stayleft = 1;
				input_type.left = 0;
				input_type.stayright = 0;
			}
			input_type.left = 0;
			input_type.stayright = 0;

			UpdateImgPlayer2(renderer);

			break;
		default:
			break;
		}
	}

}
//Manage the player's movement
void Player::DoPlayer1(Map& mapdata, int p) {
	xval = 0;
	yval += GRAVITY_SPEED;

	if (yval >= MAX_FALL_SPEED) {
		yval = MAX_FALL_SPEED;
	}
	if (input_type.left == 1) {
		xval -= PLAYER_SPEED;
	}
	if (input_type.right == 1) {
		xval += PLAYER_SPEED;
	}
	if (input_type.jump == 1) {
		if (onground == true) {
			yval -= JUMP_VAL;
		}
		onground = false;

		input_type.jump = 0;
	}

	CheckToMap1(mapdata);
	//CheckToFish(mapdata);

}


void Player::DoPlayer2(Map& mapdata, int p) {
	xval = 0;
	yval += GRAVITY_SPEED;

	if (yval >= MAX_FALL_SPEED) {
		yval = MAX_FALL_SPEED;
	}
	if (input_type.left == 1) {
		xval -= PLAYER_SPEED;
	}
	if (input_type.right == 1) {
		xval += PLAYER_SPEED;
	}
	if (input_type.jump == 1) {
		if (onground == true) {
			yval -= JUMP_VAL;
		}
		onground = false;

		input_type.jump = 0;
	}

	CheckToMap2(mapdata);
	//CheckToFish(mapdata);

}

//Check for player-map collisions
void Player::CheckToMap1(Map& mapdata) {
	int x1 = 0;
	int x2 = 0;

	int y1 = 0;
	int y2 = 0; 

	//check horizontal
	int height_min = (heightframe * 2 < TILE_SIZE ? heightframe * 2 : TILE_SIZE);

	x1 = (xpos + xval + 1)/TILE_SIZE;
	x2 = (xpos + xval + widthframe * 2 - 1)/ TILE_SIZE;

	y1 = (ypos + 1) / TILE_SIZE;
	y2 = (ypos + height_min - 1) / TILE_SIZE;

	if (x1 >= 0 && x2 < MAP_MAP_X && y1 >= 0 && y2 < MAP_MAP_Y) {
		if (xval > 0) // player moves to the right
		{

			if (mapdata.tile[y1][x2] == BROWN_FISH) {
				mapdata.tile[y1][x2] = 0;
				BrownFish_Player1();
			}
			if (mapdata.tile[y2][x2] == BROWN_FISH) {
				mapdata.tile[y2][x2] = 0;
				BrownFish_Player1();
			}
			if (mapdata.tile[y1][x2] == GREEN_FISH) {
				mapdata.tile[y1][x2] = 0;
				GreenFish_Player1();
			}
			if (mapdata.tile[y2][x2] == GREEN_FISH) {
				mapdata.tile[y2][x2] = 0;
				GreenFish_Player1();
			}

			else if (mapdata.tile[y1][x2] == GREEN_LIQUID || mapdata.tile[y2][x2] == GREEN_LIQUID) gameoverState = 1;
			else if (mapdata.tile[y1][x2] == POISON || mapdata.tile[y2][x2] == POISON) gameoverState = 1;
			else if (mapdata.tile[y1][x2] == BROWN_LIQUID && mapdata.tile[y2][x2] == BROWN_LIQUID) {}
			else {
				if ((mapdata.tile[y1][x2] != BLANK_TILE || mapdata.tile[y2][x2] != BLANK_TILE)) {
					xpos = (x2)*TILE_SIZE - 2 * widthframe - 1;
					xval = 0;
				}
			}
		}
		else if (xval < 0) //player move to the left
		{

			if (mapdata.tile[y2][x1] == BROWN_FISH ) {
				mapdata.tile[y2][x1] = 0;
				BrownFish_Player1();
			}
			else if (mapdata.tile[y1][x1]==BROWN_FISH) {
				mapdata.tile[y1][x1] = 0;
				BrownFish_Player1();
			}
			else if (mapdata.tile[y1][x1] == GREEN_FISH  )
			{
                mapdata.tile[y1][x1] = 0;
                GreenFish_Player1();
			}
			else if (mapdata.tile[y2][x1] == GREEN_FISH)
            {
                mapdata.tile[y2][x1]=0;
                GreenFish_Player1();
            }

			else if (mapdata.tile[y1][x1] == GREEN_LIQUID || mapdata.tile[y2][x1] == GREEN_LIQUID) gameoverState = 1;
			else if (mapdata.tile[y1][x1] == POISON || mapdata.tile[y2][x1] == POISON) gameoverState = 1;
			else if (mapdata.tile[y1][x1] == BROWN_LIQUID || mapdata.tile[y2][x1] == BROWN_LIQUID)
			{}
			else {
				if (mapdata.tile[y1][x1] != BLANK_TILE || mapdata.tile[y2][x1] != BLANK_TILE) {
					xpos = (x1 + 1)*TILE_SIZE;
					xval = 0;
				}
			}
		}

	}
	//check vertical
	int width_min = widthframe * 2 < TILE_SIZE ? widthframe * 2 : TILE_SIZE;
	x1 = (xpos) / TILE_SIZE;
	x2 = (xpos + width_min) / TILE_SIZE;

	y1 = (ypos + yval) / TILE_SIZE;
	y2 = (ypos + yval + heightframe * 2) / TILE_SIZE;

	if (x1 >= 0 && x2 < MAP_MAP_X && y1 >= 0 && y2 < MAP_MAP_Y) {
		if (yval > 0) //check movement by gravity force
		{
			if (mapdata.tile[y2][x2] == BROWN_FISH) {
				mapdata.tile[y2][x2] = 0;
				BrownFish_Player1();
			}
			else if (mapdata.tile[y2][x1] == BROWN_FISH) {
				mapdata.tile[y2][x1] = 0;
				BrownFish_Player1();
			}
			else if (mapdata.tile[y2][x1] == GREEN_FISH)
			{
                mapdata.tile[y2][x1] = 0;
                GreenFish_Player1();
			}
			else if (mapdata.tile[y2][x2] == GREEN_FISH)
            {
                mapdata.tile[y2][x2] = 0;
                GreenFish_Player1();
            }
			else if (mapdata.tile[y2][x1] == GREEN_LIQUID || mapdata.tile[y2][x2] == GREEN_LIQUID) gameoverState = 1;
			else if (mapdata.tile[y2][x1] == POISON || mapdata.tile[y2][x2] == POISON) gameoverState = 1;
			else if (mapdata.tile[y2][x1] == BROWN_LIQUID && mapdata.tile[y2][x2] == BROWN_LIQUID) {}
			else {
				if (mapdata.tile[y2][x1] != BLANK_TILE || mapdata.tile[y2][x2] != BLANK_TILE) {
					ypos = y2 * TILE_SIZE;
					ypos -= heightframe * 2 + 1;
					yval = 0;
					onground = true;
				}
			}
		}
		else if (yval < 0) //PLAYER JUMPS
		{

			if (mapdata.tile[y1][x2] == BROWN_FISH) {
				mapdata.tile[y1][x2] = 0;
				BrownFish_Player1();
			}
			else if (mapdata.tile[y1][x1] == BROWN_FISH) {
				mapdata.tile[y1][x1] = 0;
				BrownFish_Player1();
			}
			else if (mapdata.tile[y1][x1] == GREEN_FISH)
			{
			    mapdata.tile[y1][x1] = 0;
			    GreenFish_Player1();
			}
			else if (mapdata.tile[y1][x2] == GREEN_FISH)
            {
                mapdata.tile[y1][x2] = 0;
                GreenFish_Player1();
            }
			else if (mapdata.tile[y1][x2] == GREEN_LIQUID&& mapdata.tile[y1][x1] == GREEN_LIQUID) gameoverState = 1;
			else if (mapdata.tile[y1][x2] == POISON && mapdata.tile[y1][x1] == POISON) gameoverState = 1;

			else if (mapdata.tile[y1][x1] == BROWN_LIQUID || mapdata.tile[y1][x2] == BROWN_LIQUID) {}
			else{
			if (mapdata.tile[y1][x1] != BLANK_TILE || mapdata.tile[y1][x2] != BLANK_TILE) {
				ypos = (y1 + 1) * TILE_SIZE;
				yval = 0;
				}
			}
		}
	}

	xpos += xval;
	ypos += yval;
	if (xpos < 0) {
		xpos = 0;
	}
	else if ((xpos + widthframe * 2) > mapdata.maxx) {
		xpos = mapdata.maxx - widthframe * 2 - 1;
	}

	if (ypos < 0) {
		ypos = 0;
	}
}

//Score calculations
void Player::BrownFish_Player1() {
	brownfish1 +=10;
}
void Player::GreenFish_Player1(){
    greenfish1 -= 15;
}


void Player::CheckToMap2(Map& mapdata) {
	int x1 = 0;
	int x2 = 0;

	int y1 = 0;
	int y2 = 0;

	//check horizontal
	int height_min = (heightframe * 2 < TILE_SIZE ? heightframe * 2 : TILE_SIZE);

	x1 = (xpos + xval + 1) / TILE_SIZE;
	x2 = (xpos + xval + widthframe * 2 - 1) / TILE_SIZE;

	y1 = (ypos + 1) / TILE_SIZE;
	y2 = (ypos + height_min - 1) / TILE_SIZE;

	if (x1 >= 0 && x2 < MAP_MAP_X && y1 >= 0 && y2 < MAP_MAP_Y) {
		if (xval > 0) // player moves to the right
		{
			if (mapdata.tile[y1][x2] == GREEN_FISH) {
				mapdata.tile[y1][x2] = 0;
				GreenFish_Player2();
			}
			else if (mapdata.tile[y2][x2] == GREEN_FISH) {
				mapdata.tile[y2][x2] = 0;
				GreenFish_Player2();
			}
			else if (mapdata.tile[y1][x2] == BROWN_FISH)
			{
				mapdata.tile[y1][x2] = 0;
				BrownFish_Player2();
			}
			else if (mapdata.tile[y2][x2] == BROWN_FISH)
			{
				mapdata.tile[y2][x2] = 0;
				BrownFish_Player2();
			}
			else if (mapdata.tile[y2][x2] == BROWN_LIQUID) gameoverState = 1;
			else if (mapdata.tile[y2][x2] == POISON) gameoverState = 1;
			else if (mapdata.tile[y1][x2] == GREEN_LIQUID || mapdata.tile[y2][x2] == GREEN_LIQUID) {}
			else if (mapdata.tile[y2][x2] == BROWN_FISH)
			{
				mapdata.tile[y2][x2] = 0;
				BrownFish_Player2();
			}
			else {
				if ((mapdata.tile[y1][x2] != BLANK_TILE || mapdata.tile[y2][x2] != BLANK_TILE)) {
					xpos = (x2)*TILE_SIZE - 2 * widthframe - 1;
					xval = 0;
				}
			}
		}
		else if (xval < 0) //player move to the left
		{

			if (mapdata.tile[y2][x1] == GREEN_FISH) {
				mapdata.tile[y2][x1] = 0;
				GreenFish_Player2();
			}
			else if (mapdata.tile[y1][x1] == GREEN_FISH) {
				mapdata.tile[y1][x1] = 0;
				GreenFish_Player2();
			}

			else if (mapdata.tile[y1][x1] == BROWN_FISH)
			{
				mapdata.tile[y1][x1] = 0;
				BrownFish_Player2();
			}
			else if (mapdata.tile[y2][x1] == BROWN_FISH)
			{
				mapdata.tile[2][x1] = 0;
				BrownFish_Player2();
			}
			else if (mapdata.tile[y2][x1] == BROWN_LIQUID) gameoverState = 1;
			else if (mapdata.tile[y2][x1] == POISON) gameoverState = 1;
			else if (mapdata.tile[y2][x1] == GREEN_LIQUID) {}
			else {
				if (mapdata.tile[y1][x1] != BLANK_TILE || mapdata.tile[y2][x1] != BLANK_TILE) {
					xpos = (x1 + 1) * TILE_SIZE;
					xval = 0;
				}
			}
		}

	}
	//check vertical
	int width_min = widthframe * 2 < TILE_SIZE ? widthframe * 2 : TILE_SIZE;
	x1 = (xpos) / TILE_SIZE;
	x2 = (xpos + width_min) / TILE_SIZE;

	y1 = (ypos + yval) / TILE_SIZE;
	y2 = (ypos + yval + heightframe * 2) / TILE_SIZE;

	if (x1 >= 0 && x2 < MAP_MAP_X && y1 >= 0 && y2 < MAP_MAP_Y) {
		if (yval > 0) //check movement by gravity force
		{
			if (mapdata.tile[y2][x2] == BROWN_FISH) {
				mapdata.tile[y2][x2] = 0;
				BrownFish_Player2();
			}
			else if (mapdata.tile[y2][x1] == BROWN_FISH) {
				mapdata.tile[y2][x1] = 0;
				BrownFish_Player2();
			}

			if (mapdata.tile[y2][x2] == GREEN_FISH) {
				mapdata.tile[y2][x2] = 0;
				GreenFish_Player2();
			}
			else if (mapdata.tile[y2][x1] == GREEN_FISH) {
				mapdata.tile[y2][x1] = 0;
				GreenFish_Player2();

			}


			else if (mapdata.tile[y2][x2] == BROWN_LIQUID || mapdata.tile[y2][x1] == BROWN_LIQUID) gameoverState = 1;
			else if (mapdata.tile[y2][x2] == POISON || mapdata.tile[y2][x1] == POISON) gameoverState = 1;
			else if (mapdata.tile[y2][x2] == GREEN_LIQUID && mapdata.tile[y2][x1] == GREEN_LIQUID) {}
			else {
				if (mapdata.tile[y2][x1] != BLANK_TILE || mapdata.tile[y2][x2] != BLANK_TILE) {
					ypos = y2 * TILE_SIZE;
					ypos -= heightframe * 2 + 1;
					yval = 0;
					onground = true;
				}
			}
		}
		else if (yval < 0) //PLAYER JUMPS
		{

			if (mapdata.tile[y1][x2] == GREEN_FISH) {
				mapdata.tile[y1][x2] = 0;
				GreenFish_Player2();
			}
			else if (mapdata.tile[y1][x1] == GREEN_FISH) {
				mapdata.tile[y1][x1] = 0;
				GreenFish_Player2();
			}
			else if (mapdata.tile[y1][x1] == BROWN_FISH)
			{
				mapdata.tile[y1][x1] = 0;
				BrownFish_Player2();
			}
			else if (mapdata.tile[y1][x2] == BROWN_FISH)
			{
				mapdata.tile[y1][x2] = 0;
				BrownFish_Player2();
			}

			else if (mapdata.tile[y1][x1] == BROWN_LIQUID || mapdata.tile[y1][x2] == BROWN_LIQUID) gameoverState = 1;
			else if (mapdata.tile[y1][x1] == POISON || mapdata.tile[y1][x2] == POISON) gameoverState = 1;
			else if (mapdata.tile[y1][x1] == GREEN_LIQUID || mapdata.tile[y1][x2] == GREEN_LIQUID) {}
			else {
				if (mapdata.tile[y1][x1] != BLANK_TILE || mapdata.tile[y1][x2] != BLANK_TILE) {
					ypos = (y1 + 1) * TILE_SIZE;
					yval = 0;
				}
			}
		}
	}

	xpos += xval;
	ypos += yval;
	if (xpos < 0) {
		xpos = 0;
	}
	else if ((xpos + widthframe * 2) > mapdata.maxx) {
		xpos = mapdata.maxx - widthframe * 2 - 1;
	}

	if (ypos < 0) {
		ypos = 0;
	}
}

//Score calculations
void Player::BrownFish_Player2() {

	brownfish2 -=15;
}
void Player::GreenFish_Player2(){
    greenfish2 +=10 ;

}



//Update the player's status
void Player::UpdateImgPlayer1(SDL_Renderer* des) {
	if (onground) {
		if (input_type.left == 1) {
			LoadImg("assets/player1_run_left.png", des);
		}
		else if (input_type.right == 1) {
			LoadImg("assets/player1_run_right.png", des);
		}
		else if (status == STAY_LEFT && input_type.jump == 0 && input_type.left == 0 && input_type.right == 0) {
			LoadImg("assets/player1_stay_left.png",des);
		}
		else if (status == STAY_RIGHT && input_type.jump == 0 && input_type.left == 0 && input_type.right == 0) {
			LoadImg("assets/player1_stay_right.png",des);
		}

	}
	else {
		if (input_type.left == 1) {
		LoadImg("assets/player1_jump_left.png", des);
		}
		else if (input_type.right == 1) {
		LoadImg("assets/player1_jump_right.png", des);
		}
	}
}

void Player::UpdateImgPlayer2(SDL_Renderer* des) {
	if (onground) {
		if (input_type.left == 1) {
			LoadImg("assets/player2_run_left.png", des);
		}
		else if (input_type.right == 1) {
			LoadImg("assets/player2_run_right.png", des);
		}
		else if (status == STAY_LEFT && input_type.jump == 0 && input_type.left == 0 && input_type.right == 0) {
			LoadImg("assets/player2_stay_left.png", des);
		}
		else if (status == STAY_RIGHT && input_type.jump == 0 && input_type.left == 0 && input_type.right == 0) {
			LoadImg("assets/player2_stay_right.png", des);
		}
	}
	else {
		if (input_type.left == 1) {
			LoadImg("assets/player2_jump_left.png", des);
		}
		else if (input_type.right == 1) {
			LoadImg("assets/player2_jump_right.png", des);
		}
	}

}

//Check for player-mushroom collisions
void Player::CheckToMus(int p, OtherObj &mushroom) {

	int x1 = 0;
	int x2 = 0;

	int y1 = 0;
	int y2 = 0;

	bool checkCollision = false;
	int x1B = mushroom.Get_ObjPosx();
	int x2B = mushroom.Get_ObjPosx() + 32 * 3;
	int y1B = mushroom.Get_ObjPosy();
	int y2B = mushroom.Get_ObjPosy() + 32 * 3;
	//check horizontal
	int height_min = (heightframe * 2 < TILE_SIZE ? heightframe * 2 : TILE_SIZE);

	x1 = (xpos + xval + 0);
	x2 = (xpos + xval + widthframe * 2 - 30);

	y1 = (ypos + 20);
	y2 = (ypos + height_min + 20);

	if (x1 / TILE_SIZE >= 0 && x2 / TILE_SIZE < MAP_MAP_X && y1 / TILE_SIZE >= 0 && y2 / TILE_SIZE < MAP_MAP_Y) {
		if (x2 >= x1B && y2 >= y1B && x2 <= x2B && y2 <= y2B ||
			x1 >= x1B && y1 >= y1B && x1 <= x2B && y1 <= y2B ||
			x2 >= x1B && y1 >= y1B && x2 <= x2B && y1 <= y2B ||
			x1 >= x1B && y2 >= y1B && x1 <= x2B && y2 <= y2B
			) {
			checkCollision = true;
		}

		//If none of the sides from A are outside B\true;
		if (checkCollision) {
			if (xval > 0) {
				xpos = x2 + 80;
				xpos -= widthframe * 2 + 56;
				xval = 0;

			}
			else if (xval < 0) {
				xpos = x1 + 7;
				xval = 0;
			}
		}
	}
	//check vertical
	int width_min = widthframe * 2 < TILE_SIZE ? widthframe * 2 : TILE_SIZE;
	x1 = (xpos + 60);
	x2 = (xpos + width_min - 40);

	y1 = (ypos + yval);
	y2 = (ypos + yval + heightframe * 2 - 40);

	if (x1 / TILE_SIZE >= 0 && x2 / TILE_SIZE < MAP_MAP_X && y1 / TILE_SIZE >= 0 && y2 / TILE_SIZE < MAP_MAP_Y) {
		if (x2 >= x1B && y2 >= y1B && x2 <= x2B && y2 <= y2B) {
			checkCollision = true;
		}
		else if (x1 >= x1B && y1 >= y1B && x1 <= x2B && y1 <= y2B) {
			checkCollision = true;
		}
		else if (x2 >= x1B && y1 >= y1B && x2 <= x2B && y1 <= y2B) {
			checkCollision = true;
		}
		else if (x1 >= x1B && y2 >= y1B && x1 <= x2B && y2 <= y2B) {
			checkCollision = true;
		}
		else checkCollision = false;
		if (yval > 0) {
			if (checkCollision) {
				ypos = y2;
				ypos -= heightframe * 2 - 17;
				yval = -6;
			}
		}
		else if (yval < 0) {

			if (checkCollision) {
				ypos = y1 + 10;
				yval = 0;
			}
		}


	}
}

//Check for player-gate collisions
void Player::CheckToGate(int p, OtherObj &gate_)
{

	int x1 = 0;
	int x2 = 0;

	int y1 = 0;
	int y2 = 0;

    bool checkCollision = false;
    int x1B = gate_.Get_ObjPosx();
    int x2B = gate_.Get_ObjPosx() + 32;
    int y1B = gate_.Get_ObjPosy();
    int y2B = gate_.Get_ObjPosy() + 32;
    //check horizontal
	int height_min = (heightframe * 2 < TILE_SIZE ? heightframe * 2 : TILE_SIZE);

	x1 = (xpos+xval+1);
	x2 = (xpos + xval + widthframe * 2 -1);

	y1 = (ypos+1) ;
	y2 = (ypos + height_min +1) ;

	if (x1/TILE_SIZE >= 0 && x2/TILE_SIZE < MAP_MAP_X && y1/TILE_SIZE >= 0 && y2/TILE_SIZE < MAP_MAP_Y) {
             if(x2>=x1B&&y2>=y1B&&x2<=x2B&&y2<=y2B||
                x1>=x1B&&y1>=y1B&&x1<=x2B&&y1<=y2B||
                x2>=x1B&&y1>=y1B&&x2<=x2B&&y1<=y2B||
                x1>=x1B&&y2>=y1B&&x1<=x2B&&y2<=y2B
                )
                {
                    checkCollision=true;
                }
				if (checkCollision) {
					nextLevelPlayer[p] = true;
				}
				else nextLevelPlayer[p] = false;
		}
	//check vertical
	int width_min = widthframe * 2 < TILE_SIZE ? widthframe * 2 : TILE_SIZE;
	x1 = (xpos+1) ;
	x2 = (xpos + width_min-1) ;

	y1 = (ypos + yval) ;
	y2 = (ypos + yval + heightframe * 2 - 1) ;

	if (x1/TILE_SIZE >= 0 && x2/TILE_SIZE < MAP_MAP_X && y1/TILE_SIZE >= 0 && y2/TILE_SIZE < MAP_MAP_Y) {
                if(x2>=x1B&&y2>=y1B&&x2<=x2B&&y2<=y2B){
                    checkCollision=true;
                }
                else if(x1>=x1B&&y1>=y1B&&x1<=x2B&&y1<=y2B){
                    checkCollision=true;
                }
                else if(x2>=x1B&&y1>=y1B&&x2<=x2B&&y1<=y2B){
                    checkCollision=true;
                }
                else if(x1>=x1B&&y2>=y1B&&x1<=x2B&&y2<=y2B){
                    checkCollision=true;
                }
                else checkCollision=false;
    if(yval<0){
    if (checkCollision) {
            nextLevelPlayer[p] = true;
			}
		}
	}
}

bool Player::isEating_fish(Map& mapdata) {
	int x1 = 0;
	int x2 = 0;
	int y1 = 0;
	int y2 = 0;
	int height_min = (heightframe * 2 < TILE_SIZE ? heightframe * 2 : TILE_SIZE);

	x1 = (xpos+xval+10)/TILE_SIZE;
	x2 = (xpos + xval + widthframe * 2 - 10)/ TILE_SIZE;

	y1 = (ypos+30) / TILE_SIZE;
	y2 = (ypos + height_min +20) / TILE_SIZE;

	if (x1 >= 0 && x2 < MAP_MAP_X && y1 >= 0 && y2 < MAP_MAP_Y) {
		if (xval > 0)
		{
            if (mapdata.tile[y1][x2] == BROWN_FISH  || mapdata.tile[y2][x2] == BROWN_FISH) {
				isEatingFish = true;
			}
			else if (mapdata.tile[y1][x2] == GREEN_FISH || mapdata.tile[y2][x2] == GREEN_FISH)
			{
			    isEatingFish = true;
			}
			else
            {
                isEatingFish = false;
            }

		}
		else if (xval < 0)
		{

			if (mapdata.tile[y2][x1] == BROWN_FISH  || mapdata.tile[y1][x1] == BROWN_FISH) {
				isEatingFish = true;
			}
			else if (mapdata.tile[y2][x1] == GREEN_FISH || mapdata.tile[y1][x1] == GREEN_FISH)
			{
			    isEatingFish = true;
			}
			else
            {
                isEatingFish = false;
            }
		}
		if(isEatingFish) Mix_PlayChannel(1, sound[1], 0);
	}

	int width_min = widthframe * 2 < TILE_SIZE ? widthframe * 2 : TILE_SIZE;
	x1 = (xpos+25) / TILE_SIZE;
	x2 = (xpos + width_min+40) / TILE_SIZE;

	y1 = (ypos + yval) / TILE_SIZE;
	y2 = (ypos + yval + heightframe * 2 -17) / TILE_SIZE;

	if (x1 >= 0 && x2 < MAP_MAP_X && y1 >= 0 && y2 < MAP_MAP_Y) {
		if (yval > 0) 
		{
			if (mapdata.tile[y2][x2] == BROWN_FISH  || mapdata.tile[y2][x1] == BROWN_FISH) {
				isEatingFish = true;
			}
			else if (mapdata.tile[y2][x1] == GREEN_FISH || mapdata.tile[y2][x2] == GREEN_FISH)
			{
			    isEatingFish = true;
			}
			else
            {
                isEatingFish = false;
            }

		}
		else if (yval < 0) 
		{

			if (mapdata.tile[y1][x1] == BROWN_FISH  || mapdata.tile[y1][x2] == BROWN_FISH) {
				isEatingFish = true;
			}
			else if (mapdata.tile[y1][x1] == GREEN_FISH || mapdata.tile[y1][x2] == GREEN_FISH)
			{
			    isEatingFish = true;
			}
			else
            {
                isEatingFish = false;
            }

		}
		if(isEatingFish) Mix_PlayChannel(1, sound[1], 0);
	}
	return isEatingFish;
}