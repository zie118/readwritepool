#include "basicreader.hh"

#include <cstdio>

BasicReader::BasicReader() {
    _readtp.size_controller().resize(NUM_READ_THREAD);
}

BasicReader::~BasicReader() {

}

int BasicReader::read(int num_of_threads_to_issue) {
    printf ("performing num of read = %d\n", num_of_threads_to_issue);
    std::atomic_int localReadCount;

    // init counter
    localReadCount = num_of_threads_to_issue;

    // some preparation

    // issue threads
    for (int i = 0; i < num_of_threads_to_issue; i++) {
        _readtp.schedule(
            boost::bind(&BasicReader::doRead, this, i, boost::ref(localReadCount))
            );
    }

    //busy waiting
    while (localReadCount > 0) {
        usleep(WAITING_DURATION);
    }

    printf ("finishing read\n");
    return 0;
}

void BasicReader::doRead(int dummy_parameter, std::atomic_int& readCount)
{
    printf ("doRead %d now\n", dummy_parameter);

    // perform the read
    sleep(5);

    // finish with count decrement
    --readCount;
}
