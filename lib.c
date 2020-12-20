#define _GNU_SOURCE

#include <stdio.h>
#include <time.h>
#include <dlfcn.h>
#include <stdint.h>

static int (*clock_gettime_o)(clockid_t,struct timespec *ts)=NULL;

static int64_t sec_old=0;

int clock_gettime(clockid_t clockid,struct timespec *ts)
{
    if (clock_gettime_o==NULL) clock_gettime_o=dlsym(RTLD_NEXT,"clock_gettime");

    int ret=clock_gettime_o(clockid,ts);
    if (clockid==CLOCK_MONOTONIC_RAW) {
    if (sec_old==0) sec_old=ts->tv_sec;
    ts->tv_sec-=sec_old;
    }

    return ret;
}
