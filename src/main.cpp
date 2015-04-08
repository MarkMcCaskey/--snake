#include <iostream>

#include <SDL2/SDL.h>
#include <boost/program_options.hpp>

#include "../include/Board.hpp"

namespace po = boost::program_options;
enum class graphics_type{SDL, ncurses};

int main(int argc, char* argv[])
{
    Board bd{};
    //default graphics set to SDL
    graphics_type graphics = graphics_type::SDL;
    po::options_description desc( "Options" );
    desc.add_options()
        ("help", "print help text")
	("graphics", "select a graphics style. Valid options: sdl, ncurses")
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
	      graphics = graphics_type::SDL;
	      break;
	    case "ncurses":
	      graphics = graphics_type::ncurses;
	      break;
	    default:
	      std::cerr << "Error: option " << vm["graphics"].as<string>() << " not recognized" << std::endl;
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

    //other logic here
    //use options set above to change behavior down here
    
    exit( EXIT_SUCCESS );
}

void loop()
{

}
