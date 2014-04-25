#include "downloadfeed.h"

downloadfeed::downloadfeed(const std::string& url) {

    curl = curl_easy_init();

    if (curl) {
        // init cURL params
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, & downloadfeed::setDocument);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, & response);

        // 
        res = curl_easy_perform(curl);

        // clean cURL request
        curl_easy_cleanup(curl);

    }
}

std::size_t downloadfeed::setDocument(void * ptr, size_t size, size_t count, void * stream) {
    ((std::string *) stream)->append((char *) ptr, 0, size * count);
    return size * count;
}

std::string downloadfeed::getDocument() {
    return response;
}

