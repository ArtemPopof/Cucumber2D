/*
 * Main interfaces of Cucumber Engine
 * include window initialization routines
 * display initialization routines and so on.
 *
 * Author: Popov Artem
 * Date: 2.10.2016
 *
 * Version 0.0.1
 *
 */

#include "Platform/cucumber_system_configuration.h"

#include "cucumber_window.h"
#include "CucumberGL/CucumberGL.h"

#ifndef CucumberGL_LABEL
#define IS_CUCUMBERGL_INSTALLED false


/**
 * @brief First function you must call when using engine.
 *
 * First function you must call when using engine. Init engine parts
 * and adopt to the current system configuration;
 */

namespace Cucumber {
	void initEngine();
};
