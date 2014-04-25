#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"

#include <curl/curl.h>

size_t write_to_string(void * ptr, size_t size, size_t count, void * stream)
{
    ((std::string *) stream)->append((char *) ptr, 0, size * count);
    return size * count;
}

int main(void)
{

    CURL * curl = curl_easy_init();
    CURLcode res;

    // the "response" variable should now contain the contents of the HTTP response
    std::string response;

    if (curl)
    {
        // init cURL params
        curl_easy_setopt(curl, CURLOPT_URL, "http://9gagrss.com/feed/");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_to_string);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, & response);

        // 
        res = curl_easy_perform(curl);

        // clean cURL request
        curl_easy_cleanup(curl);



        std::string input_xml;
        std::string line;

        // only use xml_copy from here on!
        rapidxml::xml_document<> doc;


        char * cstr = new char[response.size() + 1];

        strcpy(cstr, response.c_str());

        doc.parse<0>(cstr);


        // first level
        for (rapidxml::xml_node<> * attr = doc.first_node("rss")->first_node("channel")->first_node("item"); attr; attr = attr->next_sibling())
        {

            //        attr->first_node("link")->value();
            //        attr->first_node("title")->first_node()->value();
            //        attr->first_node("pubDate")->value();
            //        attr->first_node("description")->first_node()->value();
            //        attr->first_node("guid")->value();

            std::cout << attr->first_node("link")->value();

        }

    }

    return 0;

}	