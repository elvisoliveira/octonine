#ifndef DOWNLOADIMAGE_H
#define	DOWNLOADIMAGE_H

#include <vector>
#include <sstream>
#include <utility>
#include <string>
#include <iostream>
#include <cstring>
#include <curl/curl.h>
class downloadimage
{
public:
    downloadimage(std::string url);
    std::vector<std::string> explode(std::string);
private:
    CURL * curl;
    CURLcode res;
};

#endif	/* DOWNLOADIMAGE_H */

