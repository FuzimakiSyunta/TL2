#include<cstdio>
#include<cstdlib>
#include <cassert>
#include "TextureConverter.h"
#include "windows.h"

//�R�}���h���C������
enum  Argument
{
	kApplicationPath,//�A�v���P�[�V�����p�X
	kfilePath,//�n���ꂽ�t�@�C���̃p�X

	NumArgument,

};

int main(int argc,char*argv[])
{
	
	assert(argc>=NumArgument);

	HRESULT hr = CoInitializeEx(nullptr, COINITBASE_MULTITHREADED);
	assert(SUCCEEDED(hr));

	TextureConverter textureConverter;
	textureConverter.ConvertTextureWICToDDS(argv[kfilePath]);

	CoUninitialize();
	system("pause");
	return 0;
}