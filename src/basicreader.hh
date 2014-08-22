#ifndef BASICREADER_HH_ 
#define BASICREADER_HH_

#include "threadpool/threadpool.hpp"
#include "define.hh"

class BasicReader {
    public:
        BasicReader();
        ~BasicReader();

        int read();
    private:
        boost::threadpool::pool _readtp;
};

#endif
