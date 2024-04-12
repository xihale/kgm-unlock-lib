#include <array>
#include <cstddef>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <kgm.hpp>
#include <span>
#include <vector>

// std::array<uint8_t, 2048> buf;

int main(){

  std::ifstream file("../test/a.kgm", std::ios::in | std::ios::binary);
  std::ifstream check("../test/b.mp3", std::ios::in | std::ios::binary);

  if (!file.is_open() or !check.is_open()) {
    std::cerr << "location: " << std::filesystem::current_path() << std::endl;
    std::cerr << "Failed to open file" << std::endl;
    return 1;
  }

  const size_t size = std::filesystem::file_size("../test/a.kgm");

  std::vector<char> data(size);
  file.readsome(data.data(), size);

  auto res = xihale::unlock_music::kgm::decrypt({reinterpret_cast<uint8_t*>(data.data()), size});

  std::vector<char> check_buf(std::filesystem::file_size("../test/b.mp3"));
  check.readsome(check_buf.data(), check_buf.size());

  if (res != check_buf) {
    std::cerr << "Failed to decrypt" << std::endl;
    return 1;
  }

  return 0;

}