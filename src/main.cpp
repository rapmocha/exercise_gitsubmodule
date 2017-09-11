// copyright 2017 rapmocha

#include <string>
#include <vector>
#include <iostream>
#include "lodepng/lodepng.h"

int main() {
  const std::string filename = "resources/keyboard.png";
  const std::string filename_out = "resources/out.png";
  std::vector<unsigned char> image;
  unsigned width, height;

  lodepng::hello();

  // decode
  {
    unsigned error = lodepng::decode(image, width, height, filename);
    if (error) {
      std::cout << "decoder error " << error << ": "
        << lodepng_error_text(error) << std::endl;
    }
  }

  // encode
  {
    unsigned error = lodepng::encode(filename_out, image, width, height);
    if (error) {
      std::cout << "encoder error " << error << ": "
        << lodepng_error_text(error) << std::endl;
    }
  }

  return 0;
}

