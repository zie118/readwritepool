#include <cstdio>
#include <cstring>
#include "basicreader.hh"
#include "basicwriter.hh"

int main(int argc, char* argv[])
{
    BasicReader* reader = new BasicReader();
    BasicWriter* writer = new BasicWriter();
    reader->read();
    writer->write();
    return 0;
}
