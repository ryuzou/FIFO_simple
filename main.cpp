#include <stdio.h>
#include <iostream>
#include "FIFO.hpp"

int main(){
    FIFO PROSESSA_to_B;
    PROSESSA_to_B.init_Prosess( "DIR1" );
    PROSESSA_to_B.Make_FIFO( "Test", "Hello_World" );
    printf( "%s", PROSESSA_to_B.Find_FIFO( "Test" ) );
    return 0;
}