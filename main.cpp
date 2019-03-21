#include "Generator.hpp"
#define ASIO_STANDALONE
int main(int argc, char *argv[]){
    Generator* gen  = new Generator();

    gen->Run();

    return 0;
}