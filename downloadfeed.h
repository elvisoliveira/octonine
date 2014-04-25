#ifndef DOWNLOADFEED_H
#define	DOWNLOADFEED_H

#include <string>

// #define CURL_STATICLIB
#include <curl/curl.h>

class downloadfeed {
public:
    downloadfeed(const std::string & url);
    std::string getDocument();
private:
    CURL * curl;
    CURLcode res;
    static std::size_t setDocument(void * ptr, size_t size, size_t count, void * stream);
    // the "response" variable should now contain the contents of the HTTP response
    std::string response;
};

#endif