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

#include <thread>
#include <chrono>

#include <neuron/platform/types.hpp>
#include <neuron/pwm/pwm.hpp>
#include <spdlog/spdlog.h>

using namespace neuron;

int main(int /*argc*/, char* /*argv*/[])
{
  nbsp_ret_t ret = enRet::SUCCESS;
  nbsp_pwm_dutycycle_t dutycycle = 0;
  spdlog::set_level(spdlog::level::debug);

  pwm::PWM channel(1);

  spdlog::info("Setting PWM dity cycle");

  ret = channel.setDutyCycle(dutycycle);

  if (ret != enRet::SUCCESS) {
    spdlog::error("Set PWM duty cycle failed");
    return 1;
  }

  ret = channel.operation(pwm::enCMD::START);

  if (ret != enRet::SUCCESS) {
    spdlog::error("Start PWM failed");
    return 1;
  }

  std::this_thread::sleep_for(std::chrono::milliseconds(200));

  ret = channel.operation(pwm::enCMD::STOP);

  if (ret != enRet::SUCCESS) {
    spdlog::error("Stop PWM failed");
    return 1;
  }

  return 0;
}
