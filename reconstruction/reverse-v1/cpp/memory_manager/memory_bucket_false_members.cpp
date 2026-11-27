/* Linkage owner for the two false-mode CBucket specializations.
 * Instantiates the real four virtual members per instance; no globals,
 * no fabricated objects. True-mode instances live in
 * memory_bucket_members.cpp and are untouched by this TU.
 */
#include "cbucket_classes.hpp"
#include "cbucket_false_check.ipp"
#include "cbucket_false_free.ipp"

template class CBucket<16, 1048576, false>;
template class CBucket<32768, 1048576, false>;
