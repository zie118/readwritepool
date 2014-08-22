#ifndef BASICWRITER_HH_ 
#define BASICWRITER_HH_

#include "threadpool/threadpool.hpp"
#include "define.hh"

class BasicWriter {

    public:
        BasicWriter();
        ~BasicWriter();

        int write();
    private:
        boost::threadpool::pool _writetp;

};

#endif
