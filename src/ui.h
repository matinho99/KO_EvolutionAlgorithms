/*
 * Created on: 4.06.2018
 */

#ifndef UI_HPP_
#define UI_HPP_

#include "ExecClass.h"
#include <stdlib.h>
#include <iostream>

std::string getFunctionString(FitnessFunction &ff);			///< Get the function as std::string.
void ui(ExecClass &e);										///< The function in which the UI is executed.

#endif /* UI_HPP_ */
