%module tictactoe

%include <std_string.i>

%{
/* Includes the header in the wrapper code */

#include "boardgame.h"
#include "tictactoe.h"

%}

/* Parse the header file to generate wrappers */

%include "boardgame.h"
%include "tictactoe.h"