/*
 * rng_rdrand.c
 * Copyright (c) 2019 Kevin Sheppard.
 * Copyright (c) 2020 Reini Urban.

** This software is dual-licensed under the The University of Illinois/NCSA
   Open Source License (NCSA) and The 3-Clause BSD License**

# NCSA Open Source License
**Copyright (c) 2019 Kevin Sheppard. All rights reserved.**

Developed by: Kevin Sheppard (<kevin.sheppard@economics.ox.ac.uk>,
<kevin.k.sheppard@gmail.com>)
[http://www.kevinsheppard.com](http://www.kevinsheppard.com)

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal with
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimers.

Redistributions in binary form must reproduce the above copyright notice, this
list of conditions and the following disclaimers in the documentation and/or
other materials provided with the distribution.

Neither the names of Kevin Sheppard, nor the names of any contributors may be
used to endorse or promote products derived from this Software without specific
prior written permission.

**THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS WITH
THE SOFTWARE.**
 */

#include <dieharder/libdieharder.h>
#include "cpu_features.h"

typedef struct rdrand_state {
  int status;
  int retries;
} rdrand_state_t;

#define DH_USE_RDRAND 30
#define DH_USE_RDSEED 18

int g_can_rdseed = -1;

// https://software.intel.com/content/www/us/en/develop/articles/intel-digital-random-number-generator-drng-software-implementation-guide.html
extern int rdrand_capable(void) {
#if defined(__RDRND__) && __RDRND__ && \
  (defined(HAVE__RDRAND64_STEP) || defined(HAVE__RDRAND32_STEP))
    int flags[32];
    x86_feature_flags(flags, DH_ECX);
    return flags[DH_USE_RDRAND];
#else
    return 0;
#endif
}
static int rdseed_capable(void) {
#if defined(__RDRND__) && __RDRND__ && \
  (defined(HAVE__RDSEED64_STEP) || defined(HAVE__RDSEED32_STEP))
    int flags[32];
    if (g_can_rdseed != -1)
      return g_can_rdseed;
    x86_feature_flags(flags, DH_EBX);
    g_can_rdseed = flags[DH_USE_RDSEED];
    return g_can_rdseed;
#else
    return 0;
#endif
}

static inline
int rdrand_next64(rdrand_state_t *state, uint64_t *val) {
  /*
   * You **must** check the returned status
   *   1 if success
   *   0 if failure
   */
  int status = 0, retries_cnt = 0;
  while ((status == 0) && (retries_cnt++ <= state->retries)) {
#if defined(__RDRND__) && __RDRND__ && defined(HAVE__RDRAND64_STEP) && SIZEOF_SIZE_T == 8
    status = _rdrand64_step((long long unsigned int *)val);
#elif defined(HAVE__RDRAND32_STEP) && SIZEOF_SIZE_T == 4
    uint32_t low, high;
    status = _rdrand32_step(&low);
    status &= _rdrand32_step(&high);
    val[0] = ((uint64_t)high) << 32 | low;
#else
    /* Never called on platforms without RDRAND */
    state->status = 0;
    return 0;
#endif
    if (status == 0) {
#if defined(__RDRND__) && __RDRND__
      _mm_pause();
#endif
    }
  }
  state->status = status;
  return state->status;
}

static void rdrand_set(void *vstate, unsigned long int seed)
{
  rdrand_state_t* rng = (rdrand_state_t*) vstate;
  long long unsigned s = (uint64_t)seed;
  rng->retries = 100;
  if (rdseed_capable())
    _rdseed64_step(&s);
}

static unsigned long int rdrand_get(void *vstate)
{
  rdrand_state_t* rng = (rdrand_state_t*) vstate;
  uint64_t val;
  if (rdrand_next64(rng, &val))
    return (unsigned long int)val;
  else
    return 0UL;
}

// 64bit only
#define TO_DOUBLE(x)  ((x) >> 11) * 0x1.0p-53
static double rdrand_get_double (void *vstate)
{
  return TO_DOUBLE(rdrand_get(vstate));
}

static const gsl_rng_type rdrand_type =
{"rdrand",                      /* name */
 UINT64_MAX,			/* RAND_MAX */
 0,				/* RAND_MIN */
 sizeof (rdrand_state_t),
 &rdrand_set,
 &rdrand_get,
 &rdrand_get_double};

const gsl_rng_type *gsl_rng_rdrand = &rdrand_type;