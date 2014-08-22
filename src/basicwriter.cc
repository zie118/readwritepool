#include "basicwriter.hh"

#include <cstdio>

BasicWriter::BasicWriter() {
    _writetp.size_controller().resize(NUM_READ_THREAD);
}

BasicWriter::~BasicWriter() {

}

int BasicWriter::write() {
    printf ("performing write\n");
    return 0;
}
