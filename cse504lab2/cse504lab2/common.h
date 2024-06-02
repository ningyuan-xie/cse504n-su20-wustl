#pragma once

// Step 5. Declare an enumeration for different array indices
enum index { program_name = 0, input_file_name = 1, expected_number_of_command_line_arguments = 2 };

// Step 5. Declare an enumeration for different success and failure values of my program
enum open { success = 0, file_open_failed = 1, no_file_name_given = 2 };

// Step 5. Declare a helpful "usage message" function
int usage_message_function(std::string const s1, std::string const s2);

// Step 6. Declare a lower_case function
std::string lower_case_function(std::string s);