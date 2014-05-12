#ifndef DOWNLOADIMAGE_H
#define	DOWNLOADIMAGE_H

#include <string>
#include <iostream>
#include <curl/curl.h>

#define CURL_STATICLIB
class downloadimage
{
public:
    downloadimage(std::string url);
private:
    CURL * curl;
    CURLcode res;
    size_t write_data;
};

#endif	/* DOWNLOADIMAGE_H */

