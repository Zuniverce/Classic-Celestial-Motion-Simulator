#include "Engine.h"
#include "Global.h"
#include "Time.h"
#include "CelestialBody.h"
#include "Space.h"
#include "SpaceVector.h"

const double Engine::GravitationalConstant = 6.67259e-11;

constexpr auto CRASH = 001;
