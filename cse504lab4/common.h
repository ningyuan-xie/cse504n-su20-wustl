#pragma once

// Declare an enumeration for different array indices
enum index_enum { program_name = 0, input_argument_name_1 = 1, expected_number_of_command_line_arguments = 2, input_argument_name_2 = 3, input_argument_name_3 = 4 };

// Declare an enumeration for different success and failure values of my program
enum open_enum { success = 0, wrong_argument_name_given = 1, no_argument_name_given = 2 };

// Declare a helpful "usage message" function
int usage_message_function(std::string const s1, std::string const s2);

// Declare an enumeration for main method
enum main_enum { MAIN_DRAW = 3, MAIN_QUIT = 4 };