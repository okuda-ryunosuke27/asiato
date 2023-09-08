/// 
/// ���Ս���
/// 
#include "DxLib.h"

/// 
/// �}�N����`
/// 
#define BLOCKSIZE	32					//�}�X�ڂ̃T�C�Y
#define WIN_WIDTH	600					//�E�B���h�E�T�C�Y��
#define WIN_HEIGHT	600					//�E�B���h�E�T�C�Y����
#define TITLE		"asiatoProgram"		//�E�B���h�E�^�C�g��

/// 
/// �v���g�^�C�v�錾
/// 
void PlayerUpdata();

/// 
/// �O���[�o���ϐ��錾
/// 
int playX = 0, playY = 0;				//�v���C���[���W
int boxX = 0, boxY = 0;					//�}�X�ڂ̍��W
char keys[256] = { 0 };					//�ŐV�̃L�[�{�[�h���
char oldkeys[256] = { 0 };				//1���[�v�O�̃L�[�{�[�h���
int squares[18][18] =					//�}�X�ڂ�2�����z��ŊǗ�
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
	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//�E�B���h�E�T�C�Y�ł͕ύX�����A
	//�E�B���h�E�T�C�Y�ɕ����Ċg��ł��Ȃ��悤�ɂ���B
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	//�E�B���h�^�C�g����ύX
	SetMainWindowText(TITLE);

	//��ʃT�C�Y�̍ő�T�C�Y,�J���[�r�b�g����ݒ肷��
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	//��ʃT�C�Y��ݒ�
	SetWindowSizeExtendRate(1.0);

	//��ʂ̔w�i��ݒ肷��
	SetBackgroundColor(0x00, 0x00, 0x00);

	//Dx���C�u�����̏���������
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	//�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	//�Q�[�����[�v
	while ( 1 )
	{

		//���ʂɂ���摜��\�ʂɏo��
		ScreenFlip();

		//20���~���b�ҋ@(�^��60FPS)
		WaitTimer(20);

		//ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
	}
	
	//Dx���C�u�����g�p�̏I������
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