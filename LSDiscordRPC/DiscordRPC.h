#pragma once
#include "pch.h"


#ifdef LSDISCORDRPC_EXPORTS
#define LSAddon_API __declspec(dllexport)
#else
#define LSAddon_API __declspec(dllimport)
#endif


extern "C" LSAddon_API void Init(const char* APPLICATION_ID);
extern "C" LSAddon_API void UpdateState(const char* szState, const char* szDetil);

