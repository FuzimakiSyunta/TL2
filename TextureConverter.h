#pragma once
#include <string>
#include "External/DirectXTex/DirectXTex.h"

class TextureConverter
{
public:
	
	/// <summary>
	/// �e�N�X�`����WIC����DDS�ɕϊ�����
	/// </summary>
	/// <param name="filepath"></param>
	void ConvertTextureWICToDDS(const std::string& filepath);
private:
	/// <summary>
	/// �e�N�X�`���t�@�C���ǂݍ���
	/// </summary>
	/// <param name="filepath"></param>
	void LoadWICTextureFromFile(const std::string& filepath);
	/// <summary>
	/// �}���`�o�C�g���������C�h�����ɕϊ�����
	/// </summary>
	/// <param name="filepath"></param>
	/// <returns></returns>
	static std::wstring ConvertMultiByteStringToWideString(const std::string& filepath);

	/// <summary>
	/// �t�H���_�p�X�ƃt�@�C�����𕪗�����
	/// </summary>
	/// <param name="filePath">�t�@�C���p�X</param>
	void SeparateFilePath(const std::wstring& filePath);

	/// <summary>
	/// DDS�e�N�X�`���Ƃ��ăt�@�C�������o��
	/// </summary>
	void SaveToDDSTextureToFile();

	DirectX::TexMetadata metadata_; 
	DirectX::ScratchImage scratchImage_;

	//�f�B���N�g���o�X 
	std::wstring directoryPath_; 
	// �t�@�C����
	std::wstring fileName_; 
	// �t�@�C���g���q
	std::wstring fileExt_;
};

