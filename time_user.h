#pragma once

#include <sys/time.h>
#include <stdint.h>

#define MILLION 1000000.0
#define THOUSAND 1000.0

extern uint64_t getTimeMicroSec();
extern uint64_t getTimeMilliSec();
extern uint32_t getTimeSec();