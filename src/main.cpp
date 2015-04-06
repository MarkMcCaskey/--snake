#include <iostream>

#include <SDL2/SDL.h>
#include <boost/program_options.hpp>

#include "../include/Board.hpp"

namespace po = boost::program_options;

int main(int argc, char* argv[])
{
    Board bd{};

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
        } else if( vm.count("graphics") )
	{
	  switch(vm["graphics"].as<string>())
	    {
	    case "sdl":
	      //set graphics mode to sdl
	      break;
	    case "ncurses":
	      //set graphics mode to ncurses
	      break;
	    default:
	      std::cout << "Option not recognized: " << vm["graphics"].as<string>() << std::endl;
	      exit( EXIT_FAILURE );
	      break;
	    }
	}
        po::notify(vm);
    }
    catch(po::error &e )
    {
        std::cerr << "Error: " << e.what() << std::endl;
        exit( EXIT_FAILURE );
    }
    exit( EXIT_SUCCESS );
}

void loop()
{

}
