#pragma once

#define WINCX		800
#define WINCY		600

#define	PURE		= 0
#define PI			3.141592f

#define OBJ_NOEVENT			0
#define OBJ_DEAD			1	


#define STAGE_HONG			1
#define STAGE_SILVER		2
#define STAGE_HERO			3
#define STAGE_CHAE			4
#define STAGE_MOO           5
#define STAGE_FINISH		6

#define VK_MAX				0xff

#define G_FORCE                9.80665f
#define SQUARE(X)            (X)*(X)
#define RADIAN(Degree)        (Degree)*PI/180.f
#define DEGREE(Radian)        (Radian)*180.f/PI

extern HWND		g_hWnd;
extern int g_CurrentStage; // ���� �������� � ������������ 

enum DIRECTION { DIR_LEFT, DIR_RIGHT, DIR_UP, DIR_DOWN, DIR_LU, DIR_RU, DIR_END };

enum OBJID { OBJ_PLAYER, OBJ_BULLET,OBJ_BLOCK,OBJ_MONSTER,OBJ_BOSS,OBJ_BOSSBULLET ,OBJ_MOUSE, OBJ_BUTTON, OBJ_END };

enum class GROUP_TYPE
{
	OBJ_PLAYER,
	OBJ_PLYAER_MISSILE,
	OBJ_MONSTER,
	OBJ_BOSS,
	OBJ_BOSS_MISSLE,
	OBJ_ITEM,
	OBJ_BLOCK,
	OBJ_BUTTON,
	OBJ_END
};

enum class SCENE_TYPE // �� �Ŵ��� 
{
	STAGE_START,
	STAGE_Hong, // ���� �������� 1
	STAGE_Silver,//���� �������� 2
	STAGE_Hero, // ���� �������� 3
	STAGE_Chae, // ä�� �������� 4 
	STAGE_Moo,  // ���� �������� 5
	SCENE_END = 32, // �ص�
   
};




typedef struct tagInfo
{
	float		fX, fY;
	float		fCX, fCY;	// ����, ���� ����

}INFO;

typedef struct tagLinePoint
{
	float		fX, fY;

	tagLinePoint()	{ZeroMemory(this, sizeof(tagLinePoint));}
		tagLinePoint(float _fX, float _fY)
		: fX(_fX), fY(_fY)
	{	}

}LINEPOINT;

typedef struct tagLine
{
	LINEPOINT	tLPoint;
	LINEPOINT	tRPoint;

	tagLine() { 	ZeroMemory(this, sizeof(tagLine));	}
	tagLine(LINEPOINT& _tLPoint, LINEPOINT& _tRPoint)
		: tLPoint(_tLPoint), tRPoint(_tRPoint) {	}

}LINE;


template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}