#include <iostream>
#include <cstdlib>
#include "boost/program_options.hpp"

namespace po = boost::program_options;

int main(int argc, char* argv[])
{
  po::options_description desc( "Options" );
  desc.add_options()
    ("help", "print help text")
    ;

  po::variables_map vm;

  try{
    po::store(po::parse_command_line(argc,argv,desc),vm);
    if( vm.count("help") )
    {
	std::cout << desc << std::endl;
	exit( EXIT_SUCCESS );
    }
    po::notify(vm);
  }
  catch(po::error &e )
    {
      //std::cerr << "Error: " e.what() << std::endl;
      exit( EXIT_FAILURE );
    }
  exit( EXIT_SUCCESS );
}
