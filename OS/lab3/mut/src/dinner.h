#ifndef DINING_PHILOSOPHERS_H
#define DINING_PHILOSOPHERS_H

#include <stdlib.h>
#include <unistd.h>

#include <iostream>
#include <string>
#include <thread>
#include <vector>

#include "fork.h"
#include "philosopher.h"

void addPhilosopher(const std::string& name);

void startDinner(time_t dinningTime, int forksCount);

#endif
