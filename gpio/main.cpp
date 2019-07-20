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

#include <vector>

#include <neuron/platform/types.hpp>
#include <neuron/gpio/gpio.hpp>
#include <spdlog/spdlog.h>

using namespace neuron;

int main(int /*argc*/, char* /*argv*/[])
{
  nbsp_ret_t ret = enRet::SUCCESS;
  nbsp_gpio_dir_t dir;
  nbsp_gpio_resistance_t resist;
  nbsp_gpio_value_t value;
  spdlog::set_level(spdlog::level::debug);
  gpio::GPIO pin(0);

  ret = pin.selectStragetry(enDrvType::SEMA);

  if (ret != enRet::SUCCESS) {
    spdlog::error("select stragetry failed");
    return 1;
  }

  ret = pin.setResistance(gpio::enResistance::PULL_DOWN);

  if (ret != enRet::SUCCESS) {
    spdlog::error("setting pin resistance failed");
    return 1;
  }

  spdlog::info("read back pin internal resistance");


  ret = pin.getResistance(&resist);

  if (ret != enRet::SUCCESS) {
    spdlog::error("read back pin internal resistance failed");
  }

  spdlog::info("read back pin internal resistance is {}", resist);

  spdlog::info("setting pin direction to output");

  ret = pin.setDir(gpio::enDIR::OUTPUT);
  if (ret != enRet::SUCCESS) {
    spdlog::error("set pin direction failed");
    return 1;
  }

  spdlog::info("read back pin direction");

  ret = pin.getDir(&dir);
  if (ret != enRet::SUCCESS) {
    spdlog::error("read back pin direction failed");
    return 1;
  }
  spdlog::info("read back pin direction is {}", dir);

  spdlog::info("setting pin value to high");

  ret = pin.setValue(gpio::enValue::HIGH);

  if (ret != enRet::SUCCESS) {
    spdlog::error("set pin value to high failed");
    return 1;
  }

  spdlog::info("set pin direction to input");

  ret = pin.setDir(gpio::enDIR::INPUT);

  if (ret != enRet::SUCCESS) {
    spdlog::error("set pin direction to input failed");
    return 1;
  }

  spdlog::info("get pin value");

  ret = pin.getValue(&value);

  if (ret != enRet::SUCCESS) {
    spdlog::error("get pin value failed");
    return 1;
  }

  spdlog::info("pin value is {}", value);

  return 0;
}
