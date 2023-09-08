/// 
/// 足跡作るよ
/// 
#include "DxLib.h"

/// 
/// マクロ定義
/// 
#define BLOCKSIZE	32					//マス目のサイズ
#define WIN_WIDTH	600					//ウィンドウサイズ幅
#define WIN_HEIGHT	600					//ウィンドウサイズ高さ
#define TITLE		"asiatoProgram"		//ウィンドウタイトル

/// 
/// プロトタイプ宣言
/// 
void PlayerUpdata();

/// 
/// グローバル変数宣言
/// 
int playX = 0, playY = 0;				//プレイヤー座標
int boxX = 0, boxY = 0;					//マス目の座標
char keys[256] = { 0 };					//最新のキーボード情報
char oldkeys[256] = { 0 };				//1ループ前のキーボード情報
int squares[18][18] =					//マス目を2次元配列で管理
{
	0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,
	0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,
	0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,
	0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,
	0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,

	0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,
	0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,
	0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,
	0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,
	0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,

	0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,
	0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,
	0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,
	0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,
	0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,

	0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,
	0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,
	0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,
};


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR IpCmdLine, _In_ int nShowCmd)
{
	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	//ウィンドウサイズでは変更せず、
	//ウィンドウサイズに併せて拡大できないようにする。
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	//ウィンドタイトルを変更
	SetMainWindowText(TITLE);

	//画面サイズの最大サイズ,カラービット数を設定する
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	//画面サイズを設定
	SetWindowSizeExtendRate(1.0);

	//画面の背景を設定する
	SetBackgroundColor(0x00, 0x00, 0x00);

	//Dxライブラリの初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	//描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	//ゲームループ
	while ( 1 )
	{

		//裏面にある画像を表面に出す
		ScreenFlip();

		//20見ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		//ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
	}
	
	//Dxライブラリ使用の終了処理
	DxLib_End();

	return 0;
}

void PlayerUpdata()
{
	if (keys[KEY_INPUT_W] == 1)
	{
		playY -= 1;
	}
	if (keys[KEY_INPUT_S] == 1)
	{
		playY += 1;
	}
	if (keys[KEY_INPUT_A] == 1)
	{
		playX -= 1;
	}
	if (keys[KEY_INPUT_D] == 1)
	{
		playX += 1;
	}
}