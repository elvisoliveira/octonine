#include "downloadimage.h"

downloadimage::downloadimage(std::string url) {

    CURL * image;
    CURLcode imgresult;
    FILE * fp;

    curl = curl_easy_init();

    if (curl) {

        if (fp == NULL) {
            std::cout << "File cannot be opened";
        }

        char * addr = NULL;
        
        strcpy(addr, url.c_str());

        char * external = addr;
        char outfilename[FILENAME_MAX] = "C:\\development\\projects\\octonine\\tech.jpg";

        fp = fopen(outfilename, "wb");

        // init cURL params
        curl_easy_setopt(curl, CURLOPT_URL, external);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        // Grab image 
        imgresult = curl_easy_perform(image);

        if (imgresult) {
            std::cout << "Cannot grab the image!\n";
        }

        // clean cURL request
        curl_easy_cleanup(curl);

        fclose(fp);

    }
}

size_t write_data(void * ptr, size_t size, size_t nmemb, FILE * stream) {
    size_t written;
    written = fwrite(ptr, size, nmemb, stream);
    return written;
}