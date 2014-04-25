#include "parsefeed.h"

parsefeed::parsefeed(const std::string & document) {

    rapidxml::xml_document<> doc;

    char * cstr = new char[document.size() + 1];

    strcpy(cstr, document.c_str());

    doc.parse<0>(cstr);

    // first level
    for (rapidxml::xml_node<> * attr = doc.first_node("rss")->first_node("channel")->first_node("item"); attr; attr = attr->next_sibling()) {

        //        attr->first_node("link")->value();
        //        attr->first_node("title")->first_node()->value();
        //        attr->first_node("pubDate")->value();
        //        attr->first_node("description")->first_node()->value();
        //        attr->first_node("guid")->value();

        std::cout << attr->first_node("link")->value();

    }

}