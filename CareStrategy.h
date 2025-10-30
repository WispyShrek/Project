#ifndef CARESTRATEGY_H
#define CARESTRATEGY_H

class CareStrategy {

/**
 * @brief Abstract class, Strategy participant in strategy design pattern.
 */
public:
	virtual void applyCare() = 0;
	CareStrategy();
	virtual ~CareStrategy();
};

#endif
