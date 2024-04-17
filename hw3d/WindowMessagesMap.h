#pragma once
#include <unordered_map>
#include <string> // ’Ç‰Á‚·‚é•K—v‚ª‚ ‚è‚Ü‚·
#include <Windows.h>

class WindowsMessageMap
{
public:
	WindowsMessageMap();
	std::string operator()(DWORD msg, LPARAM lp, WPARAM wp) const;
private:
	std::unordered_map<DWORD, std::string> map;
};