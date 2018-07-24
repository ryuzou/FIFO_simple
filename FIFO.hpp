//
// Created by ryuzo on 18/07/23.
//

#ifndef UNTITLED_FIFO_HPP
#define UNTITLED_FIFO_HPP

//ERROR is 1 (when read null)

#include <string>

class FIFO {
private:

    bool _init_done_ = 0;

    std::string FIFO_DIR;

    std::string FIFO_SUBDIR;

    std::string MAIN_DIR_PATH;

    inline bool CHEAK_INIT();

    char *Read_( std::string NAME );

    bool Create_( std::string FIFO_NAME, std::string MESSAGE );

public:

    bool init_Prosess( std::string P_Name );

    char *Find_FIFO( std::string NAME );

    bool Make_FIFO( std::string FIFO_NAME, std::string MESSAGE );
};


#endif //UNTITLED_FIFO_HPP
