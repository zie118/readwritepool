#ifndef BASICWRITER_HH_ 
#define BASICWRITER_HH_

#include <atomic>
#include "threadpool.hpp"
#include "define.hh"

class BasicWriter {

    public:
        BasicWriter();
        ~BasicWriter();

        int write(int num_of_threads_to_issue);
    private:

        void doWrite(int dummy_parameter, std::atomic_int& writeCount);

        boost::threadpool::pool _writetp;

};

#endif
