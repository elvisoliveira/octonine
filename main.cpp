#include <string.h>

#include "downloadfeed.h"
#include "parsefeed.h"

int main(void) {

    downloadfeed download("http://elvisoliveira.com.br/sandbox/octopp/octopp.php");

    std::string response = download.getDocument();

    parsefeed parse(response);

    return 0;

}