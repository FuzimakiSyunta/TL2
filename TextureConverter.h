#pragma once
#include <string>
#include "External/DirectXTex/DirectXTex.h"

class TextureConverter
{
public:
	
	/// <summary>
	/// テクスチャをWICからDDSに変換する
	/// </summary>
	/// <param name="filepath"></param>
	void ConvertTextureWICToDDS(const std::string& filepath);
private:
	/// <summary>
	/// テクスチャファイル読み込み
	/// </summary>
	/// <param name="filepath"></param>
	void LoadWICTextureFromFile(const std::string& filepath);
	/// <summary>
	/// マルチバイト文字をワイド文字に変換する
	/// </summary>
	/// <param name="filepath"></param>
	/// <returns></returns>
	static std::wstring ConvertMultiByteStringToWideString(const std::string& filepath);

	/// <summary>
	/// フォルダパスとファイル名を分離する
	/// </summary>
	/// <param name="filePath">ファイルパス</param>
	void SeparateFilePath(const std::wstring& filePath);

	/// <summary>
	/// DDSテクスチャとしてファイル書き出し
	/// </summary>
	void SaveToDDSTextureToFile();

	DirectX::TexMetadata metadata_; 
	DirectX::ScratchImage scratchImage_;

	//ディレクトリバス 
	std::wstring directoryPath_; 
	// ファイル名
	std::wstring fileName_; 
	// ファイル拡張子
	std::wstring fileExt_;
};

