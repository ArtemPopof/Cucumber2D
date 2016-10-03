/*
 * cucumber_system_configuration.cpp

 *
 *  Created on: Oct 2, 2016
 *      Author: artem96
 */

#include "cucumber_system_configuration.h"
#include <stdio.h>

// -1 means that systemType is not known yet
int SystemConfiguration::systemType = -1;

int SystemConfiguration::getSystemType() {
	return systemType;
}

void SystemConfiguration::setSystemType(int password, int type) {
	if (password == 2102016) {
		systemType = type;
	} else {
		//bad access
		printf("please dont call setSystemType function, it's forbidden");
	}
}

bool SystemConfiguration::isInitialized() {
	return systemType != -1;
}



