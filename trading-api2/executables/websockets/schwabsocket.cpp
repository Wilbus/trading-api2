#include "StreamHandler.h"

#include <iostream>

int main(int argc, char** argv)
{
    streamer::IStreamHandler* handler = new streamer::SchwabStreamHandler("testurl");
}