#include<cstdio>
#include<cstdlib>
#include <cassert>
#include "TextureConverter.h"
#include "windows.h"

//コマンドライン引数
enum  Argument
{
	kApplicationPath,//アプリケーションパス
	kfilePath,//渡されたファイルのパス

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