/*
 * cucumber_engine.cpp
 *
 *  Created on: Oct 3, 2016
 *      Author: artem96
 */

#include "cucumber_engine.h"

void Cucumber::initEngine() {
	// already initialized
	if (SystemConfiguration::getSystemType() != -1)
		return;

	// find out system configuration
	// in this engine version default system will
	// be linux, other systems must be added later

	SystemConfiguration::setSystemType(2102016, 0);
}


