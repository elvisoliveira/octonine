#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"

using namespace std;

int main() {

    std::string input_xml;
    std::string line;

    ifstream in("C:/Users/elvis.nunes/Desktop/feed.xml");

    // read file into input_xml
    while (getline(in, line))
        input_xml += line;

    // make a safe-to-modify copy of input_xml
    // (you should never modify the contents of an std::string directly)
    vector<char> buffer(input_xml.begin(), input_xml.end());

    buffer.push_back('\0');

    // only use xml_copy from here on!
    rapidxml::xml_document<> doc;

    doc.parse<0>(&buffer[0]);

    // posts
    
   
    std::vector<std::map<std::string, std::string>> teste;

    // first level
    for (rapidxml::xml_node<> * attr = doc.first_node("rss")->first_node("channel")->first_node("item"); attr; attr = attr->next_sibling()) {


        
        m["link"] = attr->first_node("link")->value();
        m["title"] = attr->first_node("title")->first_node()->value();
        m["pubDate"] = attr->first_node("pubDate")->value();
        m["description"] = attr->first_node("description")->first_node()->value();
        m["guid"] = attr->first_node("guid")->value();

        v.push_back(m);

    }

    return 0;
}