/**
 * @file	
 * @breif	������@���L�q����N���X�w�b�_
 * @author	shibata
 */

#ifndef CHART_H
#define CHART_H

#include "../Object/Object.h"

class Chart : public Object
{
public:
	Chart();
	virtual ~Chart();

	virtual void Draw();
};

#endif // !CHART_H