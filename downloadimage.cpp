#include "downloadimage.h"

size_t write_data(void * ptr, size_t size, size_t nmemb, FILE * stream) {
    size_t written;
    written = fwrite(ptr, size, nmemb, stream);
    return written;
}

static bool filewriterFlag = false;

static int fileWriter(char * data, size_t size, size_t nmemb, FILE * stream) {
    filewriterFlag = true;
    return fwrite(data, size, nmemb, stream);
}

downloadimage::downloadimage(std::string url) {

    std::vector<std::string> elems = downloadimage::explode(url);

    std::string image = elems[elems.size() - 1];
    
    std::string download = "http://elvisoliveira.com.br/sandbox/octopp/octopp-image.php?image=" + image;

    std::string outputFile = "C:\\development\\projects\\octonine\\files\\" + image;

    CURL * curl;
    FILE * fp;
    CURLcode res;
    const char * urld = download.c_str();
    const char * outfilename = outputFile.c_str();

    curl = curl_easy_init();

    if (curl) {

        filewriterFlag = false;

        fp = fopen(outfilename, "wb");

        if (fp == NULL) {
            curl_easy_cleanup(curl);
        }

        curl_easy_setopt(curl, CURLOPT_URL, urld);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fileWriter);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        res = curl_easy_perform(curl);

        curl_easy_cleanup(curl);

        fclose(fp);
    }

    if (!filewriterFlag)
        remove(outfilename);

}

std::vector<std::string> downloadimage::explode(std::string text) {
    int i = 0;
    char ch;

    std::string word;
    std::vector<std::string> words;

    std::string str = "/";

    while (ch = text[i++]) {

        std::stringstream ss;
        std::string s;

        ss << ch;
        ss >> s;

        if (strcmp(s.c_str(), str.c_str()) == 0) {
            if (!word.empty()) {
                words.push_back(word);
            }
            word = "";
        } else {
            word += ch;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }

    return words;

}