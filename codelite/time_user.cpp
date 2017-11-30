#include "time_user.h"

uint64_t getTimeMicroSec() {
	struct timeval now;
	gettimeofday(&now, NULL);
	return (now.tv_sec + now.tv_usec / MILLION ) * MILLION;
}

uint64_t getTimeMilliSec() {
	return (getTimeMicroSec() / THOUSAND);
}

uint32_t getTimeSec() {
	return (getTimeMilliSec() / THOUSAND);
}