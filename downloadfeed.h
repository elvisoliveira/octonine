#ifndef DOWNLOADFEED_H
#define	DOWNLOADFEED_H

#include <curl/curl.h>
#include <string>

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