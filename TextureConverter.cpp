#include "TextureConverter.h"
#include <Windows.h>
#include <filesystem>

using namespace DirectX;

TextureConverter::TextureConverter()
{
}

TextureConverter::~TextureConverter()
{
}

void TextureConverter::ConvertTextureWICToDDS(const std::string& filepath)
{
	//テクスチャファイル読み込み
	LoadWICTextureFromFile(filepath);
	
	//DDSに変換して書き出す
	SaveToDDSTextureToFile();
}

std::wstring TextureConverter::ConvertMultiByteStringToWideString(const std::string& filepath)
{
	//ワイド文字列に変換した際の文字数を計算
	int filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, nullptr, 0);

	// ワイド文字列
	std::wstring wString;
	wString.resize(filePathBufferSize);
	// ワイド文字列に変換
	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, &wString[0], filePathBufferSize);

	return wstring();
}

void TextureConverter::LoadWICTextureFromFile(const std::string& filePath)
{
	// 2.テクスチャを読み込む
	std::wstring wFilePath = ConvertMultiByteStringToWideString(filePath);
	// 2 DDS形式に変換して書き出す
	HRESULT result = LoadFromWICFile(wFilePath.c_str(), DirectX::WIC_FLAGS_NONE, &metaData_, scratchImage_) assert(SUCCEEDED(result));
	assert(SUCCEEDED(result));
	// フォルダパスとファイル名を分離する
	SeparateFilePath(wFilePath);
}

