#pragma once
// header file can be used to separate functions in the source file

// Step 7. Declare enumerations
namespace two_enum { // use "namespace" to: 1. organize code 2. prevent name clashes 3. scoping

	// different array indices
	enum enumeration_1 {program_name = 0, input_file_name = 1, expected_number_of_command_line_arguments = 2};

	// different success and failure values of my program
	enum enumeration_2 {success = 0, file_open_failed = 1, no_file_name_given = 2};

}
