#ifndef PARSEFEED_H
#define	PARSEFEED_H

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>

#include <rapidxml-1.13/rapidxml.hpp>
#include <rapidxml-1.13/rapidxml_utils.hpp>
class parsefeed
{
public:
    parsefeed(const std::string & document);
    std::vector <std::map<std::string, std::string> > getvector();
private:
    std::string input_xml;
    std::string line;
    std::vector <std::map<std::string, std::string> > output_vector;
};

#endif

