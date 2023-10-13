#include "includes.h"


class Control
{
private:
  std::string comand;
  std::vector<double> params;
  std::ofstream logfile;
public:

  template <class T>
  void read_message_from_Boundary(std::string command_name, std::vector<T> command_params);

  void create_field(std::vector<double> params, int* error_code);
  void generate_field(std::vector<double> params, int* error_code);
  void generate_hill(std::vector<double> params, int* error_code);
  void generate_stone(std::vector<double> params, int* error_code);
  void generate_log(std::vector<double> params, int* error_code);
  void move_cursor(std::vector<double> params, int* error_code);
  void set_cursor(std::vector<double> params, int* error_code);
  void print_field(std::string filename, int* error_code);
  
  int print_message(int* error_code);
};

// так как это шаблон, а не метод, его нужно описывать в файле .h
template <class T>
  void Control::read_message_from_Boundary(std::string command_name, std::vector<T> command_params)
{
  
}