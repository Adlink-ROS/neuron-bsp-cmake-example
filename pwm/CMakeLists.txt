## Copyright 2019 ADLINK Technology Ltd. Advanced Robotic Platform Group
##
## Licensed under the Apache License, Version 2.0 (the "License");
## you may not use this file except in compliance with the License.
## You may obtain a copy of the License at
##
##     http://www.apache.org/licenses/LICENSE-2.0
##
## Unless required by applicable law or agreed to in writing, software
## distributed under the License is distributed on an "AS IS" BASIS,
## WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
## See the License for the specific language governing permissions and
## limitations under the License.

cmake_minimum_required(VERSION 3.5)

set(target pwm_example)

find_package(neuron-bsp PATHS /opt/neuron-bsp NO_DEFAULT_PATH REQUIRED)

add_executable(${target} main.cpp)

target_link_libraries(${target}
  PRIVATE
  neuron-bsp::pwm
  neuron-bsp::platform
  )
