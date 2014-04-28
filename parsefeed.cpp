#include <map>
#include <vector>

#include "parsefeed.h"

parsefeed::parsefeed(const std::string & document) {
	// convert returned document string in char
	char * cstr = new char[document.size() + 1];
	
	// strcpy only works with C style char
    std::strcpy(cstr, document.c_str());
	
	// initialize the rapidxml files
	rapidxml::xml_document<> doc;

	// parse the char using rapidXML
    doc.parse<0>(cstr);

	std::vector <std::map<std::string, std::string>> example;

    // loop feed itens
    for (rapidxml::xml_node<> * attr = doc.first_node("rss")->first_node("channel")->first_node("item"); attr; attr = attr->next_sibling()) {

		// create the basic hashmap
		std::map<std::string, std::string> postMap;

		// convert to C style hashmap
		postMap["link"] = attr->first_node("link")->value();
		postMap["title"] = attr->first_node("title")->first_node()->value();
		postMap["pubDate"] = attr->first_node("pubDate")->value();
		postMap["description"] = attr->first_node("description")->first_node()->value();
		postMap["guid"] = attr->first_node("guid")->value();

		// push hashmap to the end of vector
		example.push_back(postMap);

    }

	for(int i = 0; i < example.size(); i++) {

		std::cout << example.at(i)["link"] << std::endl;
		std::cout << example.at(i)["title"] << std::endl;
		std::cout << example.at(i)["pubDate"] << std::endl;
		std::cout << example.at(i)["description"] << std::endl;
		std::cout << example.at(i)["guid"] << std::endl;
		std::cout << std::endl;

	}

	
}