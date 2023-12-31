/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getConfigFile.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:10:28 by chris             #+#    #+#             */
/*   Updated: 2023/11/29 15:02:06 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <stdexcept>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <string>
#include "policeColor.hpp"

#include "utils.hpp"

class getConfigFile {

    public:
        getConfigFile( char* file, std::string cgi_path );
        virtual ~getConfigFile();
        virtual std::string getValue( std::string str );
        virtual std::string getCGI_PATH() const;
        // class ConfigException : public std::exception
	    // {
		//     public :
		//     	ConfigException(const char* errorMessage) throw();
		//     	virtual ~ConfigException() throw();
		//     	const char *what() const throw();
		//     private :
		//     	const char *_errorMessage;
	    // };


    protected:
        std::vector<std::vector<std::string> > config;

    private:
        getConfigFile();
        // getConfigFile( getConfigFile const& src );
        getConfigFile & operator=( getConfigFile const& rhs );

        bool                        _serverToken;
        bool                        _locationToken;
        int                      _vectorIndice;
        std::string                 _cgi_path;

        void checkServerScope( std::string line, size_t lineNumber );
        void checkLocationScope( std::string line, size_t lineNumber );
        void checkSemicolon( std::string const& line, size_t lineNumber ) const;
        void checkSyntax_server_location( std::string & lin, size_t lineNumber );
        void checkValue( std::string line, size_t lineNumber );
        void checkListen( std::string line, size_t lineNumber );
        void checkBodySize( std::string line, size_t lineNumber );
        void checkHost( std::string line, size_t lineNumber );
        void checkMethods( std::string line, size_t lineNumber );

        void trimSpaces( std::string& line );
        void cleanLine( std::string & line );
};
