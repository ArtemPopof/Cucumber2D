/**
 * This class contains platform-depended information.
 *
 * @date 2.10.16 22:39
 * @authors Artem Popov
 * @version 0.0.1
 *
 * @todo This class must be changed in order to provide
 * flexibility over different systems.
 */

class SystemConfiguration {

private:
	/*
	 * Type of current OS.
	 *
	 * 0 for Linux
	 * 1 for Windows
	 * 2 for MacOS
	 */

	static int systemType;

public:

	/*
	 * Return system type
	 * see systemType
	 *
	 */

	static int getSystemType();
	static void setSystemType(int securityCode, int type);
	static bool isInitialized();

};
