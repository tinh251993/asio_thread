#include "Generator.hpp"
Generator::Generator(){  
       count = 0;    
}

Generator::~Generator(){

}

void   Generator::GenerateAndPrintOut(std::shared_ptr< asio::io_service > io_service){

	io_service->run();

}
void Generator::PrintNum()
{
	std::mt19937 mt(rd());
   
    std::uniform_int_distribution<int> dist(-10,10);

    auto val = dist(mt);	

	m_mutex.lock();

	asio::io_context io;

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	count++;

	std::cout<<count<<"  :  "<<std::this_thread::get_id() <<"  :  "<<val<<std::endl;	

	m_mutex.unlock();
}

void Generator::Run(){
    std::shared_ptr<asio::io_service > io_service(
		new asio::io_service
	);

	std::shared_ptr< asio::io_service::work > work(
		new asio::io_service::work( *io_service )
	);

	asio::io_service::strand strand( *io_service );

	std::vector<std::thread> vecOfThreads;

	//boost::thread_group worker_threads;

	for( int x = 0; x < 5; ++x ){

		vecOfThreads.push_back(std::thread(&Generator::GenerateAndPrintOut,this, io_service));
		//std::thread( &Generator::GenerateAndPrintOut,this, io_service ) ;

	}

	// for (int i = 0; i < 100; i++){

	// 	io_service->post(  std::thread( &Generator::PrintNum,this)  );
		
	// }
	   for(int i = 0; i < 100; i++) {
        io_service->post([&]() {
           this->PrintNum();
        });
    }

    //work.reset();

	for (std::thread & th : vecOfThreads)
	{
		// If thread Object is Joinable then Join that thread.
		if (th.joinable())
			th.join();
	}

}