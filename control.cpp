#include "includes.h"


void Control::create_field(std::vector<double> params, int* error_code)
{
  *error_code = 0;
  try
  {
    if(params.size() == 0)
    {
      NoWay(FIELD_SIZE_X, FIELD_SIZE_Y);
    }
    else 
    {
      NoWay(params[0], params[1]);
    }
  } catch (int exception)
  {
    if (exception == 1) 
    {
      *error_code = 1; // некорректные размеры поля
    }
  }
}


void Control::generate_field(std::vector<double> params, int* error_code)
{
  
}


void Control::generate_hill(std::vector<double> params, int* error_code)
{
  
}


void Control::generate_stone(std::vector<double> params, int* error_code)
{
  
}


void Control::generate_log(std::vector<double> params, int* error_code)
{
  
}


void Control::move_cursor(std::vector<double> params, int* error_code)
{
  
}


void Control::set_cursor(std::vector<double> params, int* error_code)
{
  
}


void Control::print_field(std::string filename, int* error_code)
{
  
}

