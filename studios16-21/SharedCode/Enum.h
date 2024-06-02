#pragma once

// avoid hardcoded here

enum ls { success_1 = 0, redundant_input = 1 };								// Lab 5 -> Question 1
enum rm { success_2 = 0, file_is_open = 2, file_not_exist = 3 };			// Lab 5 -> Question 2
enum touch {success_3 = 0, file_not_created = 4, file_not_added = 5};		// Lab 5 -> Question 3
enum cat { success_4 = 0, wrong_option_followed_by = 6, img_not_allowed = 7 };					// Lab 5 -> Question 4
enum ds { success_5 = 0, no_input = 8, wrong_additional_input = 9, file_not_exist_ds = 10 };		// Lab 5 -> Question 5
enum copy { success_6 = 0, not_enough_input = 11, no_original_file = 12, add_to_system_failed = 13 };	// Lab 5 -> Question 6
enum mc { success_mc = 0, mc_not_execute = 14 };

