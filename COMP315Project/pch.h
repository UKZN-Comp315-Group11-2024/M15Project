// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
//System headers
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <cstdlib>
#include <fstream>
#include <thread>
#include <windows.h>
#include <process.h>
#include <msclr/marshal_cppstd.h>
#include <math.h>
#include <time.h> 

//Library header stuff
#include "SFML/Audio.hpp"
#include <cliext/list>

//include opencv core
#include "opencv2/core/core.hpp"
#include "opencv2/core.hpp"
#include "opencv2/face.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/opencv.hpp"
#include <direct.h>

//user defined headers
//Only add here if the header is unlikely to ever change in the future
#include "PlayerInfo.h"
#include "Destructible.h"
#include "PictureBox.h"
#include "facerec.h"
#include "customAlgs.h"

#endif //PCH_H
