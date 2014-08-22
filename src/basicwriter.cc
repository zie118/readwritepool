#include "basicwriter.hh"

#include <unistd.h>
#include <cstdio>

BasicWriter::BasicWriter() {
    _writetp.size_controller().resize(NUM_WRITE_THREAD);
}

BasicWriter::~BasicWriter() {

}

int BasicWriter::write(int num_of_threads_to_issue) {
    printf ("performing num of write = %d\n", num_of_threads_to_issue);
    std::atomic_int localWriteCount;

    // init counter
    localWriteCount = num_of_threads_to_issue;

    // some preparation

    // issue threads
    for (int i = 0; i < 5; i++) {
        _writetp.schedule(
            boost::bind(&BasicWriter::doWrite, this, // member function pointer and object pointer
                        i,                           // first parameter of doWrite 
                        boost::ref(localWriteCount)  // second paramter of doWrite, a reference
                        // if you have more parameters, add here one by one
                       ));
    }

    // busy waiting
    while (localWriteCount > 0) {
        usleep(WAITING_DURATION);
    }

    printf ("finishing write\n");
    return 0;
}

void BasicWriter::doWrite(int dummy_parameter, std::atomic_int& writeCount)
{
    printf ("doWrite %d now\n", dummy_parameter);

    // perform the write
    sleep(3);

    // finish with count decrement
    --writeCount;
}
