/* Linkage owner for the seven observed true-mode CBucket specializations.
 * No globals or fresh objects: instantiate only the real four virtual
 * members, with their generated vtables and VMI RTTI, in this one TU.
 * Original anchors and template argument pairs are in the family contract.
 */
#include "cbucket_classes.hpp"
#include "cbucket_init_check.ipp"
#include "cbucket_size_free.ipp"

template class CBucket<8, 131072, true>;
template class CBucket<16, 262144, true>;
template class CBucket<32, 262144, true>;
template class CBucket<64, 524288, true>;
template class CBucket<128, 524288, true>;
template class CBucket<256, 1048576, true>;
template class CBucket<16384, 262144, true>;
