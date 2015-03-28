#include <iostream>
#include <cstdlib>
#include <boost/program_options.hpp>

int main(int argc, char* args[])
{
  boost::program_options::options_description desc( "Options" );
  desc.add_options()
    ("help", "print help text")
    ;
  boost::program_options::variables_map vm;
  boost::program_options::store(boost::program_options::parse_command_line(ac,av,desc),vm);
  boost::program_options::notify(vm);
  if( vm.count("help") )
  {
    std::cout << desc << std::endl;
    exit( EXIT_SUCCESS );
  }
}
