#include <cinttypes>
#include <gsl/gsl_rng.h>
#include <trng/lcg64.hpp>
#include <trng/lcg64_shift.hpp>
#include <trng/lcg64_count_shift.hpp>
#include <trng/mrg2.hpp>
#include <trng/mrg3.hpp>
#include <trng/mrg3s.hpp>
#include <trng/mrg4.hpp>
#include <trng/mrg5.hpp>
#include <trng/mrg5s.hpp>
#include <trng/yarn2.hpp>
#include <trng/yarn3.hpp>
#include <trng/yarn3s.hpp>
#include <trng/yarn4.hpp>
#include <trng/yarn5.hpp>
#include <trng/yarn5s.hpp>
#include <trng/mt19937.hpp>
#include <trng/mt19937_64.hpp>
#include <trng/xoshiro256plus.hpp>
#include <trng/uniform01_dist.hpp>

extern "C" {

#undef VERSION
#include "config.h"

static void trng_lcg64_set(void *vstate, unsigned long int seed) {
  auto *gen{new (vstate) trng::lcg64};
  gen->seed(seed);
}

static unsigned long int trng_lcg64_get(void *vstate) {
  auto *gen{reinterpret_cast<trng::lcg64 *>(vstate)};
  return gen->operator()();
}

static double trng_lcg64_get_double(void *vstate) {
  auto *gen{reinterpret_cast<trng::lcg64 *>(vstate)};
  trng::uniform01_dist<double> u;
  return u(*gen);
}

static const gsl_rng_type trng_lcg64_type = {
    "trng_lcg64",         // name
    trng::lcg64::max(),   // RAND_MAX
    trng::lcg64::min(),   // RAND_MIN
    sizeof(trng::lcg64),  // state size
    trng_lcg64_set,       // set
    trng_lcg64_get,       // get
    trng_lcg64_get_double // get double
};

const gsl_rng_type *gsl_rng_trng_lcg64 = &trng_lcg64_type;

//-----------------------------------------------------------------------------

static void trng_lcg64_shift_set(void *vstate, unsigned long int seed) {
  auto *gen{new (vstate) trng::lcg64_shift};
  gen->seed(seed);
}

static unsigned long int trng_lcg64_shift_get(void *vstate) {
  auto *gen{reinterpret_cast<trng::lcg64_shift *>(vstate)};
  return gen->operator()();
}

static double trng_lcg64_shift_get_double(void *vstate) {
  auto *gen{reinterpret_cast<trng::lcg64_shift *>(vstate)};
  trng::uniform01_dist<double> u;
  return u(*gen);
}

static const gsl_rng_type trng_lcg64_shift_type = {
    "trng_lcg64_shift",         // name
    trng::lcg64_shift::max(),   // RAND_MAX
    trng::lcg64_shift::min(),   // RAND_MIN
    sizeof(trng::lcg64_shift),  // state size
    trng_lcg64_shift_set,       // set
    trng_lcg64_shift_get,       // get
    trng_lcg64_shift_get_double // get double
};

const gsl_rng_type *gsl_rng_trng_lcg64_shift = &trng_lcg64_shift_type;

//-----------------------------------------------------------------------------

static void trng_lcg64_count_shift_set(void *vstate, unsigned long int seed) {
  auto *gen{new (vstate) trng::lcg64_count_shift};
  gen->seed(seed);
}

static unsigned long int trng_lcg64_count_shift_get(void *vstate) {
  auto *gen{reinterpret_cast<trng::lcg64_count_shift *>(vstate)};
  return gen->operator()();
}

static double trng_lcg64_count_shift_get_double(void *vstate) {
  auto *gen{reinterpret_cast<trng::lcg64_count_shift *>(vstate)};
  trng::uniform01_dist<double> u;
  return u(*gen);
}

static const gsl_rng_type trng_lcg64_count_shift_type = {
    "trng_lcg64_count_shift",         // name
    trng::lcg64_count_shift::max(),   // RAND_MAX
    trng::lcg64_count_shift::min(),   // RAND_MIN
    sizeof(trng::lcg64_count_shift),  // state size
    trng_lcg64_count_shift_set,       // set
    trng_lcg64_count_shift_get,       // get
    trng_lcg64_count_shift_get_double // get double
};

const gsl_rng_type *gsl_rng_trng_lcg64_count_shift = &trng_lcg64_count_shift_type;

//-----------------------------------------------------------------------------

static void trng_mrg2_set(void *vstate, unsigned long int seed) {
  auto *gen{new (vstate) trng::mrg2};
  gen->seed(seed);
}

static unsigned long int trng_mrg2_get(void *vstate) {
  auto *gen{reinterpret_cast<trng::mrg2 *>(vstate)};
  return gen->operator()();
}

static double trng_mrg2_get_double(void *vstate) {
  auto *gen{reinterpret_cast<trng::mrg2 *>(vstate)};
  trng::uniform01_dist<double> u;
  return u(*gen);
}

static const gsl_rng_type trng_mrg2_type = {
    "trng_mrg2",         // name
    trng::mrg2::max(),   // RAND_MAX
    trng::mrg2::min(),   // RAND_MIN
    sizeof(trng::mrg2),  // state size
    trng_mrg2_set,       // set
    trng_mrg2_get,       // get
    trng_mrg2_get_double // get double
};

const gsl_rng_type *gsl_rng_trng_mrg2 = &trng_mrg2_type;

//-----------------------------------------------------------------------------

static void trng_mrg3_set(void *vstate, unsigned long int seed) {
  auto *gen{new (vstate) trng::mrg3};
  gen->seed(seed);
}

static unsigned long int trng_mrg3_get(void *vstate) {
  auto *gen{reinterpret_cast<trng::mrg3 *>(vstate)};
  return gen->operator()();
}

static double trng_mrg3_get_double(void *vstate) {
  auto *gen{reinterpret_cast<trng::mrg3 *>(vstate)};
  trng::uniform01_dist<double> u;
  return u(*gen);
}

static const gsl_rng_type trng_mrg3_type = {
    "trng_mrg3",         // name
    trng::mrg3::max(),   // RAND_MAX
    trng::mrg3::min(),   // RAND_MIN
    sizeof(trng::mrg3),  // state size
    trng_mrg3_set,       // set
    trng_mrg3_get,       // get
    trng_mrg3_get_double // get double
};

const gsl_rng_type *gsl_rng_trng_mrg3 = &trng_mrg3_type;

//-----------------------------------------------------------------------------

static void trng_mrg3s_set(void *vstate, unsigned long int seed) {
  auto *gen{new (vstate) trng::mrg3s};
  gen->seed(seed);
}

static unsigned long int trng_mrg3s_get(void *vstate) {
  auto *gen{reinterpret_cast<trng::mrg3s *>(vstate)};
  return gen->operator()();
}

static double trng_mrg3s_get_double(void *vstate) {
  auto *gen{reinterpret_cast<trng::mrg3s *>(vstate)};
  trng::uniform01_dist<double> u;
  return u(*gen);
}

static const gsl_rng_type trng_mrg3s_type = {
    "trng_mrg3s",         // name
    trng::mrg3s::max(),   // RAND_MAX
    trng::mrg3s::min(),   // RAND_MIN
    sizeof(trng::mrg3s),  // state size
    trng_mrg3s_set,       // set
    trng_mrg3s_get,       // get
    trng_mrg3s_get_double // get double
};

const gsl_rng_type *gsl_rng_trng_mrg3s = &trng_mrg3s_type;

//-----------------------------------------------------------------------------

static void trng_mrg4_set(void *vstate, unsigned long int seed) {
  auto *gen{new (vstate) trng::mrg4};
  gen->seed(seed);
}

static unsigned long int trng_mrg4_get(void *vstate) {
  auto *gen{reinterpret_cast<trng::mrg4 *>(vstate)};
  return gen->operator()();
}

static double trng_mrg4_get_double(void *vstate) {
  auto *gen{reinterpret_cast<trng::mrg4 *>(vstate)};
  trng::uniform01_dist<double> u;
  return u(*gen);
}

static const gsl_rng_type trng_mrg4_type = {
    "trng_mrg4",         // name
    trng::mrg4::max(),   // RAND_MAX
    trng::mrg4::min(),   // RAND_MIN
    sizeof(trng::mrg4),  // state size
    trng_mrg4_set,       // set
    trng_mrg4_get,       // get
    trng_mrg4_get_double // get double
};

const gsl_rng_type *gsl_rng_trng_mrg4 = &trng_mrg4_type;

//-----------------------------------------------------------------------------

static void trng_mrg5_set(void *vstate, unsigned long int seed) {
  auto *gen{new (vstate) trng::mrg5};
  gen->seed(seed);
}

static unsigned long int trng_mrg5_get(void *vstate) {
  auto *gen{reinterpret_cast<trng::mrg5 *>(vstate)};
  return gen->operator()();
}

static double trng_mrg5_get_double(void *vstate) {
  auto *gen{reinterpret_cast<trng::mrg5 *>(vstate)};
  trng::uniform01_dist<double> u;
  return u(*gen);
}

static const gsl_rng_type trng_mrg5_type = {
    "trng_mrg5",         // name
    trng::mrg5::max(),   // RAND_MAX
    trng::mrg5::min(),   // RAND_MIN
    sizeof(trng::mrg5),  // state size
    trng_mrg5_set,       // set
    trng_mrg5_get,       // get
    trng_mrg5_get_double // get double
};

const gsl_rng_type *gsl_rng_trng_mrg5 = &trng_mrg5_type;

//-----------------------------------------------------------------------------

static void trng_mrg5s_set(void *vstate, unsigned long int seed) {
  auto *gen{new (vstate) trng::mrg5s};
  gen->seed(seed);
}

static unsigned long int trng_mrg5s_get(void *vstate) {
  auto *gen{reinterpret_cast<trng::mrg5s *>(vstate)};
  return gen->operator()();
}

static double trng_mrg5s_get_double(void *vstate) {
  auto *gen{reinterpret_cast<trng::mrg5s *>(vstate)};
  trng::uniform01_dist<double> u;
  return u(*gen);
}

static const gsl_rng_type trng_mrg5s_type = {
    "trng_mrg5s",         // name
    trng::mrg5s::max(),   // RAND_MAX
    trng::mrg5s::min(),   // RAND_MIN
    sizeof(trng::mrg5s),  // state size
    trng_mrg5s_set,       // set
    trng_mrg5s_get,       // get
    trng_mrg5s_get_double // get double
};

const gsl_rng_type *gsl_rng_trng_mrg5s = &trng_mrg5s_type;

//-----------------------------------------------------------------------------

static void trng_yarn2_set(void *vstate, unsigned long int seed) {
  auto *gen{new (vstate) trng::yarn2};
  gen->seed(seed);
}

static unsigned long int trng_yarn2_get(void *vstate) {
  auto *gen{reinterpret_cast<trng::yarn2 *>(vstate)};
  return gen->operator()();
}

static double trng_yarn2_get_double(void *vstate) {
  auto *gen{reinterpret_cast<trng::yarn2 *>(vstate)};
  trng::uniform01_dist<double> u;
  return u(*gen);
}

static const gsl_rng_type trng_yarn2_type = {
    "trng_yarn2",         // name
    trng::yarn2::max(),   // RAND_MAX
    trng::yarn2::min(),   // RAND_MIN
    sizeof(trng::yarn2),  // state size
    trng_yarn2_set,       // set
    trng_yarn2_get,       // get
    trng_yarn2_get_double // get double
};

const gsl_rng_type *gsl_rng_trng_yarn2 = &trng_yarn2_type;

//-----------------------------------------------------------------------------

static void trng_yarn3_set(void *vstate, unsigned long int seed) {
  auto *gen{new (vstate) trng::yarn3};
  gen->seed(seed);
}

static unsigned long int trng_yarn3_get(void *vstate) {
  auto *gen{reinterpret_cast<trng::yarn3 *>(vstate)};
  return gen->operator()();
}

static double trng_yarn3_get_double(void *vstate) {
  auto *gen{reinterpret_cast<trng::yarn3 *>(vstate)};
  trng::uniform01_dist<double> u;
  return u(*gen);
}

static const gsl_rng_type trng_yarn3_type = {
    "trng_yarn3",         // name
    trng::yarn3::max(),   // RAND_MAX
    trng::yarn3::min(),   // RAND_MIN
    sizeof(trng::yarn3),  // state size
    trng_yarn3_set,       // set
    trng_yarn3_get,       // get
    trng_yarn3_get_double // get double
};

const gsl_rng_type *gsl_rng_trng_yarn3 = &trng_yarn3_type;

//-----------------------------------------------------------------------------

static void trng_yarn3s_set(void *vstate, unsigned long int seed) {
  auto *gen{new (vstate) trng::yarn3s};
  gen->seed(seed);
}

static unsigned long int trng_yarn3s_get(void *vstate) {
  auto *gen{reinterpret_cast<trng::yarn3s *>(vstate)};
  return gen->operator()();
}

static double trng_yarn3s_get_double(void *vstate) {
  auto *gen{reinterpret_cast<trng::yarn3s *>(vstate)};
  trng::uniform01_dist<double> u;
  return u(*gen);
}

static const gsl_rng_type trng_yarn3s_type = {
    "trng_yarn3s",         // name
    trng::yarn3s::max(),   // RAND_MAX
    trng::yarn3s::min(),   // RAND_MIN
    sizeof(trng::yarn3s),  // state size
    trng_yarn3s_set,       // set
    trng_yarn3s_get,       // get
    trng_yarn3s_get_double // get double
};

const gsl_rng_type *gsl_rng_trng_yarn3s = &trng_yarn3s_type;

//-----------------------------------------------------------------------------

static void trng_yarn4_set(void *vstate, unsigned long int seed) {
  auto *gen{new (vstate) trng::yarn4};
  gen->seed(seed);
}

static unsigned long int trng_yarn4_get(void *vstate) {
  auto *gen{reinterpret_cast<trng::yarn4 *>(vstate)};
  return gen->operator()();
}

static double trng_yarn4_get_double(void *vstate) {
  auto *gen{reinterpret_cast<trng::yarn4 *>(vstate)};
  trng::uniform01_dist<double> u;
  return u(*gen);
}

static const gsl_rng_type trng_yarn4_type = {
    "trng_yarn4",         // name
    trng::yarn4::max(),   // RAND_MAX
    trng::yarn4::min(),   // RAND_MIN
    sizeof(trng::yarn4),  // state size
    trng_yarn4_set,       // set
    trng_yarn4_get,       // get
    trng_yarn4_get_double // get double
};

const gsl_rng_type *gsl_rng_trng_yarn4 = &trng_yarn4_type;

//-----------------------------------------------------------------------------

static void trng_yarn5_set(void *vstate, unsigned long int seed) {
  auto *gen{new (vstate) trng::yarn5};
  gen->seed(seed);
}

static unsigned long int trng_yarn5_get(void *vstate) {
  auto *gen{reinterpret_cast<trng::yarn5 *>(vstate)};
  return gen->operator()();
}

static double trng_yarn5_get_double(void *vstate) {
  auto *gen{reinterpret_cast<trng::yarn5 *>(vstate)};
  trng::uniform01_dist<double> u;
  return u(*gen);
}

static const gsl_rng_type trng_yarn5_type = {
    "trng_yarn5",         // name
    trng::yarn5::max(),   // RAND_MAX
    trng::yarn5::min(),   // RAND_MIN
    sizeof(trng::yarn5),  // state size
    trng_yarn5_set,       // set
    trng_yarn5_get,       // get
    trng_yarn5_get_double // get double
};

const gsl_rng_type *gsl_rng_trng_yarn5 = &trng_yarn5_type;

//-----------------------------------------------------------------------------

static void trng_yarn5s_set(void *vstate, unsigned long int seed) {
  auto *gen{new (vstate) trng::yarn5s};
  gen->seed(seed);
}

static unsigned long int trng_yarn5s_get(void *vstate) {
  auto *gen{reinterpret_cast<trng::yarn5s *>(vstate)};
  return gen->operator()();
}

static double trng_yarn5s_get_double(void *vstate) {
  auto *gen{reinterpret_cast<trng::yarn5s *>(vstate)};
  trng::uniform01_dist<double> u;
  return u(*gen);
}

static const gsl_rng_type trng_yarn5s_type = {
    "trng_yarn5s",         // name
    trng::yarn5s::max(),   // RAND_MAX
    trng::yarn5s::min(),   // RAND_MIN
    sizeof(trng::yarn5s),  // state size
    trng_yarn5s_set,       // set
    trng_yarn5s_get,       // get
    trng_yarn5s_get_double // get double
};

const gsl_rng_type *gsl_rng_trng_yarn5s = &trng_yarn5s_type;

//-----------------------------------------------------------------------------

static void trng_mt19937_set(void *vstate, unsigned long int seed) {
  auto *gen{new (vstate) trng::mt19937};
  gen->seed(seed);
}

static unsigned long int trng_mt19937_get(void *vstate) {
  auto *gen{reinterpret_cast<trng::mt19937 *>(vstate)};
  return gen->operator()();
}

static double trng_mt19937_get_double(void *vstate) {
  auto *gen{reinterpret_cast<trng::mt19937 *>(vstate)};
  trng::uniform01_dist<double> u;
  return u(*gen);
}

static const gsl_rng_type trng_mt19937_type = {
    "trng_mt19937",         // name
    trng::mt19937::max(),   // RAND_MAX
    trng::mt19937::min(),   // RAND_MIN
    sizeof(trng::mt19937),  // state size
    trng_mt19937_set,       // set
    trng_mt19937_get,       // get
    trng_mt19937_get_double // get double
};

const gsl_rng_type *gsl_rng_trng_mt19937 = &trng_mt19937_type;

//-----------------------------------------------------------------------------

static void trng_mt19937_64_set(void *vstate, unsigned long int seed) {
  auto *gen{new (vstate) trng::mt19937_64};
  gen->seed(seed);
}

static unsigned long int trng_mt19937_64_get(void *vstate) {
  auto *gen{reinterpret_cast<trng::mt19937_64 *>(vstate)};
  return gen->operator()();
}

static double trng_mt19937_64_get_double(void *vstate) {
  auto *gen{reinterpret_cast<trng::mt19937_64 *>(vstate)};
  trng::uniform01_dist<double> u;
  return u(*gen);
}

static const gsl_rng_type trng_mt19937_64_type = {
    "trng_mt19937_64",         // name
    trng::mt19937_64::max(),   // RAND_MAX
    trng::mt19937_64::min(),   // RAND_MIN
    sizeof(trng::mt19937_64),  // state size
    trng_mt19937_64_set,       // set
    trng_mt19937_64_get,       // get
    trng_mt19937_64_get_double // get double
};

const gsl_rng_type *gsl_rng_trng_mt19937_64 = &trng_mt19937_64_type;

//-----------------------------------------------------------------------------

static void trng_xoshiro256plus_set(void *vstate, unsigned long int seed) {
  auto *gen{new (vstate) trng::xoshiro256plus};
  gen->seed(seed);
}

static unsigned long int trng_xoshiro256plus_get(void *vstate) {
  auto *gen{reinterpret_cast<trng::xoshiro256plus *>(vstate)};
  return gen->operator()();
}

static double trng_xoshiro256plus_get_double(void *vstate) {
  auto *gen{reinterpret_cast<trng::xoshiro256plus *>(vstate)};
  trng::uniform01_dist<double> u;
  return u(*gen);
}

static const gsl_rng_type trng_xoshiro256plus_type = {
    "trng_xoshiro256plus",         // name
    trng::xoshiro256plus::max(),   // RAND_MAX
    trng::xoshiro256plus::min(),   // RAND_MIN
    sizeof(trng::xoshiro256plus),  // state size
    trng_xoshiro256plus_set,       // set
    trng_xoshiro256plus_get,       // get
    trng_xoshiro256plus_get_double // get double
};

const gsl_rng_type *gsl_rng_trng_xoshiro256plus = &trng_xoshiro256plus_type;
}
