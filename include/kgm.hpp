/**
@author xihale
@brief Main header for the kgm-unlock project
*/

#include <algorithm>
#include <cstdint> // uint8_t
#include <span>
#include <vector>

namespace xihale {
namespace unlock_music {
namespace kgm {

namespace utils { // do not call them directly

uint8_t get_mask(std::size_t pos);

} // namespace utils

std::vector<char> decrypt(std::span<uint8_t> data, bool is_vpr = false);

} // namespace kgm
} // namespace unlock_music
} // namespace xihale