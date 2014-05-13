////////////////////////////////////////////////////////
//    ____         _          _   _  _                //
//   / __ \       | |        | \ | |(_)               //
//  | |  | |  ___ | |_  ___  |  \| | _  _ __    ___   //
//  | |  | | / __|| __|/ _ \ | . ` || || '_ \  / _ \  //
//  | |__| || (__ | |_| (_) || |\  || || | | ||  __/  //
//   \____/  \___| \__|\___/ |_| \_||_||_| |_| \___|  //
//                                                    //
////////////////////////////////////////////////////////

#include <string.h>
#include "downloadfeed.h"
#include "downloadimage.h"
#include "parsefeed.h"

int main(void) {

//    downloadfeed download = downloadfeed("http://elvisoliveira.com.br/sandbox/octopp/octopp.php");
//
//    std::string response = download.getDocument();
//
//    parsefeed parse(response);
    
    downloadimage image = downloadimage("http://g-ecx.images-amazon.com/images/G/02/gno/beacon/BeaconSprite-UK-02._V397961423_.png");

    return 0;

}