#include "basicreader.hh"

#include <cstdio>

BasicReader::BasicReader() {
    _readtp.size_controller().resize(NUM_READ_THREAD);
}

BasicReader::~BasicReader() {

}

int BasicReader::read() {
    printf ("performing read\n");
    return 0;
}
