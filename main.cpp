#include <cstdlib>
#include <iostream>
#include <vector>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"

using namespace std;

int main() {

    std::string input_xml;
    std::string line;

    ifstream in("feed.xml");

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

    vector<int> vecID;

    // get document's first node - 'player' node
    // get player's first child - 'frames' node
    // get frames' first child - first 'frame' node
    rapidxml::xml_node<> * nodeFrame = doc.first_node()->first_node()->first_node();

    while (nodeFrame) {
        std::cout << nodeFrame->first_node()->value();
        nodeFrame = nodeFrame->next_sibling();
    }


    return 0;
}