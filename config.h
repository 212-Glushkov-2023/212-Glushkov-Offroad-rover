#include "includes.h"

const std::string BOUNDARY_LOGFILE_NAME = "boundary_logfile.txt";
const std::string CONTROL_LOGFILE_NAME = "control_logfile.txt";
const std::string COMMAND_FILE_NAME = "command.txt";
const double FIELD_SIZE_X = 10;
const double FIELD_SIZE_Y = 10;
const double CURSOR_POSITION_X = 5;
const double CURSOR_POSITION_Y = 5;
const double HILL_HIGHT = 4;
const double HILL_SIGMA[2][2] = {{0.4, 0}, {0, 0.4}};
const double STONE_R = 0.5;
const double LOG_R = 1;
const std::map<std::string, std::vector<int>> COMMAND_PARAMS = {
{"create_field", {0, 2}}, {"generate_field", {0, 2, 3, 4, 5}}, {"generate_hill", {0, 1, 5}}, {"generate_stone", {0, 1}}, {"generate_log", {0, 1}}, {"move_cursor", {2}}, 
{"set_cursor", {2}}, 
{"print_field", {1}}
};
