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

    std::vector <std::map<std::string, std::string> > example;

    // loop feed itens
    for (rapidxml::xml_node<> * attr = doc.first_node("articles")->first_node("article"); attr; attr = attr->next_sibling()) {

        // create the basic hashmap
        std::map<std::string, std::string> postMap;

        // convert to C style hashmap
        postMap["points"] = attr->first_node("points")->value();
        postMap["comments"] = attr->first_node("comments")->value();
        postMap["id"] = attr->first_node("id")->value();
        postMap["next"] = attr->first_node("next")->value();
        postMap["content"] = attr->first_node("content")->value();
        postMap["title"] = attr->first_node("title")->value();

        // push hashmap to the end of vector
        example.push_back(postMap);

    }

    parsefeed::output_vector = example;

}

std::vector <std::map<std::string, std::string> > parsefeed::getvector() {
    return parsefeed::output_vector;
}