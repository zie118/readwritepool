#ifndef BASICREADER_HH_ 
#define BASICREADER_HH_

#include <atomic>
#include "threadpool.hpp"
#include "define.hh"

class BasicReader {
    public:
        BasicReader();
        ~BasicReader();

        int read(int num_of_threads_to_issue);
    private:
        void doRead(int dummy_parameter, std::atomic_int& readCount);
        boost::threadpool::pool _readtp;

};

#endif
