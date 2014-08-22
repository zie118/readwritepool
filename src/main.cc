#include <cstdio>
#include <cstring>
#include "basicreader.hh"
#include "basicwriter.hh"


boost::threadpool::pool maintp;

int main(int argc, char* argv[])
{
    BasicReader* reader = new BasicReader();
    BasicWriter* writer = new BasicWriter();
    maintp.size_controller().resize(2);

    // let's make the read write perform together by adding them to the main threadpool

    maintp.schedule(boost::bind(&BasicReader::read, reader, 10));
    maintp.schedule(boost::bind(&BasicWriter::write, writer, 5));
    return 0;
}
