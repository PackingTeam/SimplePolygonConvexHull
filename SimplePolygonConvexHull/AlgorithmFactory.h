#pragma once

#include "Algorithm.h"
#include "Sklansky72.h"
#include "BhattacharyaElGindy84.h"
#include "GhoshShyamasundar83.h"
#include "LeeGrahamYao83.h"
#include "McCallumAvis79.h"
#include "Melkman87.h"
#include "Orlowski85.h"
#include "PreparataShamos85.h"
#include "ShinWoo86.h"
#include "Sklansky82.h"

extern Algorithm* getMethodById(int id);