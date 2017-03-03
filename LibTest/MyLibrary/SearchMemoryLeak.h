/**
 * @file	
 * @breif	
 * @author	
 */

#ifndef SEARCHLEAK_H
#define SEARCHLEAK_H

/// メモリを動的に確保するときに使うnewは必ずNewの方を使ってください
#ifdef _DEBUG
#include <crtdbg.h>
#define New new(_NORMAL_BLOCK, __FILE__, __LINE__)
#else
#define New new
#endif

#endif // !SEARCHLEAK_H