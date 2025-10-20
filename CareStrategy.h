#ifndef CARESTRATEGY_H
#define CARESTRATEGY_H

class CareStrategy {


public:
	virtual void applyCare() = 0;
	CareStrategy();
	~CareStrategy();
};

#endif
