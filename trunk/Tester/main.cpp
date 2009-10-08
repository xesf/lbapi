#include <iostream>
#include "../API/Core/Core.h"

using namespace LBAPI;

int main(int argc, char *argv[])
{
	std::cout << "Loading plugins..." << std::endl;
	Core::instance().loadPlugins("./plugins");
	return 0;
}
