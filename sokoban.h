#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <algorithm>


#define Field_h 15
#define Field_l 41
#define scrLink_am 3
#define scrLink_len 30
#define lvlfile_h 99
#define lvlfile_l 12


class WelcomeScreen;
class Field;
class Box;
class Finish;
class Character;


class ObjectOnMap {
protected:
	char image;
	int p_x;
	int p_y;
public:
	ObjectOnMap();
	ObjectOnMap(const int x, const int y);
	~ObjectOnMap();
	void StartPos(const int x, const int y);
	int ShowPosX();
	int ShowPosY();
	bool ChangePos(const int ofs_x, const int ofs_y);
	void InitPos(const int x, const int y);
};

class Character :public ObjectOnMap {
private:
public:
	Character(const int x, const int y);
	Character();
	~Character();
	void Move(const unsigned char mode, Box* box_array, Finish* finish_array, char(* map)[Field_l], const int box_amount);
	void MoveBox(const int pos_x, const int pos_y, Box* box_array, const unsigned box_amount,const unsigned char mode);

};
class Box:public ObjectOnMap {
private:
public:
	Box();
	Box(const int x, const int y);
	~Box();
	bool CmpPos(const int x, const int y);
	void Move(const unsigned char mode);

};
class Finish :public ObjectOnMap {
private:
public:
	Finish();
	Finish(const int x, const int y);
	~Finish();
};
class Field {
private:
	unsigned char points;
	char lvlf[lvlfile_h][lvlfile_l];
	char map[Field_h][Field_l];
	int box_amount;
	unsigned int total_lvl;
	Character character;
	Box* box_array;
	Finish* finish_array;
	unsigned int lvl;
	char screen_text[Field_h][Field_l];
	char scrLink[scrLink_am][scrLink_len] = { "face/launch_screen","face/scr_change","face/final_screen" };
	void ShowScreen(const unsigned int i);
public:
	Field();
	~Field();
	void LoadLevel(const int lvl);
	unsigned int ShowLvl();
	unsigned char WinCheck();
	void Show();
	void Game();
};