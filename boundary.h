#include "includes.h"


class Boundary
{
private:
  std::string message;
  std::ofstream boundary_logfile;
public:
  

  void console_read();
  bool check_command_name(std::string command_name);
  bool check_command_params(int count);


  template <class T>
  void logfile_print(std::string command_name, std::vector<T> command_params); 

  template <class T>
  void send_message_to_Control(int command_code, std::vector<T>);

  void console_write(int error_code);
  
};


template <class T>
  void Boundary::logfile_print(std::string command_name, std::vector<T> command_params)
{
  
}


  template <class T>
  void Boundary::send_message_to_Control(int command_code, std::vector<T>)
{
  
}