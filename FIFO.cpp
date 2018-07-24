//
// Created by ryuzo on 18/07/23.
//

#include "FIFO.hpp"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include <sys/fcntl.h>
#include <cstdlib>
#include <cstring>
#include <zconf.h>
#include <iostream>
#include <errno.h>
#include <error.h>

inline bool FIFO::CHEAK_INIT() {
    if( _init_done_ == 0 )
        return 1;
}

bool FIFO::init_Prosess(std::string P_Name) {
    FIFO_SUBDIR = P_Name;
    FIFO_DIR = "/home/ryuzo/tmp/FIFO";
    _init_done_ = 1;
    MAIN_DIR_PATH = FIFO_DIR + "/" + FIFO_SUBDIR;
}

bool FIFO::Create_( std::string FIFO_NAME, std::string MESSAGE ) {
    if( CHEAK_INIT() ) return 1;
    const char *cp_MESSAGE = MESSAGE.c_str();
    std::string  FIFO_FULL_PATH = MAIN_DIR_PATH + "/" + FIFO_NAME;
    const char *cp_FIFO_FULL_PATH = FIFO_FULL_PATH.c_str();
    int fd;
    mkfifo( cp_FIFO_FULL_PATH, 666 );
    fd = open( cp_FIFO_FULL_PATH, O_WRONLY );
    write( fd, cp_MESSAGE, strlen(cp_MESSAGE) + 1 );
    close( fd );
    return 0;
}

char* FIFO::Find_FIFO( std::string NAME ) {
    const char *cp_NAME = NAME.c_str();
    char *MESSAGE = NULL;
    if( CHEAK_INIT() ) return NULL;
    if( access( cp_NAME, F_OK ) != -1 )
        MESSAGE = Read_(NAME);
    else
        return NULL;
}

bool FIFO::Make_FIFO( std::string FIFO_NAME, std::string MESSAGE ) {
    std::string  FIFO_FULL_PATH = MAIN_DIR_PATH + "/" + FIFO_NAME;
    const char *cp_FIFO_FULL_PATH = FIFO_FULL_PATH.c_str();
    if( CHEAK_INIT() ) return 1;
    Create_( FIFO_NAME, MESSAGE );
}

char* FIFO::Read_( std::string NAME ) {
    char *MESSAGE = NULL;
    if( CHEAK_INIT() ) return NULL;
    std::string FIFO_FULL_PATH = MAIN_DIR_PATH + "/" + NAME;
    const char *cp_FIFO_FULL_PATH = FIFO_FULL_PATH.c_str();
    int fd;
    mkfifo( cp_FIFO_FULL_PATH, 666 );
    fd = open( cp_FIFO_FULL_PATH, O_RDONLY );
    read( fd, MESSAGE, sizeof(char)*10 );
    close( fd );
    return MESSAGE;
}
