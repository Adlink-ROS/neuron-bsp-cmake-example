// Copyright 2019 ADLINK Technology Ltd. Advanced Robotic Platform Group
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <iostream>
#include <vector>

#include <neuron/platform/types.hpp>
#include <neuron/i2c/i2c.hpp>
#include <spdlog/spdlog.h>

using namespace neuron;

int main(int /*argc*/, char* /*argv*/[])
{
  uint8_t buffer[10];
  nbsp_ret_t ret = enRet::SUCCESS;
  spdlog::set_level(spdlog::level::debug);

  i2c::I2C bus(0);

  ret = bus.setFreq(i2c::enFREQ::FREQ_100KBPS);

  if (ret != enRet::SUCCESS) {
    spdlog::error("set i2c freq failed");
    return 1;
  }

  ret = bus.send(0x50, buffer, 10);

  if (ret != enRet::SUCCESS) {
    spdlog::error("write i2c bus failed");
    return 1;
  }

  ret = bus.read(0x50, buffer, 10);

  if (ret != enRet::SUCCESS) {
    spdlog::error("Read i2c bus failed");
    return 1;
  }

  return 0;
}

/**
 * @}
 */
