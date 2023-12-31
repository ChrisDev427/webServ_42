#include "../includes/HandleConfigFile.hpp"
#include "../includes/Server.hpp"

static std::string find_php_cgi( char** envp ) {

	std::string paths, line;
	std::vector<std::string> vecPaths;
	for ( int i = 0; envp[i] != NULL; i++ ) {

		if ( strncmp(envp[i], "PATH=", 5 ) == 0 ) {
			paths = envp[i] + 5;
			for ( size_t j = 0; j < paths.length(); j++ ) {

				if ( paths[j] == ':' ) {

					vecPaths.push_back(line + "/php-cgi");
					line.clear();
					continue;
				}
				line.push_back(paths[j]);
			}
			if ( !line.empty() ) {
				vecPaths.push_back(line + "/php-cgi");
			}
		}
	}
	for ( size_t i = 0; i < vecPaths.size(); i++ ) {

		if ( access( vecPaths[i].c_str(), X_OK ) == 0 ) {
			return vecPaths[i];
		}
	}
	return "";
}

int main (int argc, char **argv, char **envp)
{
	if (argc > 2)
	{
		std::cerr << "Error: too many arguments" << std::endl;
		return (1);
	}
	std::string configFile;

	if (argc == 1 && access("default_config.conf", F_OK | R_OK) == 0)
		configFile = "default_config.conf";
	else if (argc == 2)
		configFile = argv[1];
	else
	{
		std::cerr << "Error: no default config file found" << std::endl;
		return (1);
	}
	try
	{
		Server server(configFile, find_php_cgi( envp ));
	}

	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}
