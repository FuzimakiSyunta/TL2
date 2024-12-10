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
	//�e�N�X�`���t�@�C���ǂݍ���
	LoadWICTextureFromFile(filepath);
	
	//DDS�ɕϊ����ď����o��
	SaveToDDSTextureToFile();
}

std::wstring TextureConverter::ConvertMultiByteStringToWideString(const std::string& filepath)
{
	//���C�h������ɕϊ������ۂ̕��������v�Z
	int filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, nullptr, 0);

	// ���C�h������
	std::wstring wString;
	wString.resize(filePathBufferSize);
	// ���C�h������ɕϊ�
	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, &wString[0], filePathBufferSize);

	return wstring();
}

void TextureConverter::LoadWICTextureFromFile(const std::string& filePath)
{
	// 2.�e�N�X�`����ǂݍ���
	std::wstring wFilePath = ConvertMultiByteStringToWideString(filePath);
	// 2 DDS�`���ɕϊ����ď����o��
	HRESULT result = LoadFromWICFile(wFilePath.c_str(), DirectX::WIC_FLAGS_NONE, &metaData_, scratchImage_) assert(SUCCEEDED(result));
	assert(SUCCEEDED(result));
	// �t�H���_�p�X�ƃt�@�C�����𕪗�����
	SeparateFilePath(wFilePath);
}

