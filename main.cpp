#include <string.h>

#include "downloadfeed.h"
#include "parsefeed.h"

int main(void) {

    downloadfeed download("http://web.archive.org/web/20130419104110/http://9gagrss.com/feed");

    std::string response = download.getDocument();

    parsefeed parse(response);

    return 0;

}