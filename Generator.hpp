#ifndef GENERATOR_HPP
#define GENERATOR_HPP 
#define ASIO_STANDALONE
#define _WIN32_WINNT 0x0501

#include <asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <mutex>
#include <iostream>
#include <random>
#include <chrono>


class Generator{

    public:

                                        Generator();
                
                                        ~Generator();

                void                    Run();


    private:
                std::mutex              m_mutex;

                void                    GenerateAndPrintOut( std::shared_ptr< asio::io_service > io_service );

                std::random_device      rd;

                void                    PrintNum();

                int                     count;



};
#endif //GENERATE_HPP