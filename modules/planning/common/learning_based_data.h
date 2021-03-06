/******************************************************************************
 * Copyright 2020 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file learning_data.h
 **/

#pragma once

#include <vector>

#include "modules/planning/proto/learning_data.pb.h"

namespace apollo {
namespace planning {

class LearningBasedData {
 public:
  LearningBasedData() = default;

  void set_learning_data_frame(const LearningDataFrame& learning_data_frame) {
    learning_data_frame_.CopyFrom(learning_data_frame);
  }

  const LearningDataFrame &learning_data_frame() const {
    return learning_data_frame_;
  }

  void set_learning_data_adc_future_trajectory_points(
      const std::vector<common::TrajectoryPoint> &trajectory_points) {
    learning_data_adc_future_trajectory_points_ = trajectory_points;
  }

  const std::vector<common::TrajectoryPoint>
      &learning_data_adc_future_trajectory_points() const {
    return learning_data_adc_future_trajectory_points_;
  }

  void set_is_learning_trajectory_valid(const bool is_valid) {
    is_learning_trajectory_valid_ = is_valid;
  }

  const bool is_learning_trajectory_valid() const {
    return is_learning_trajectory_valid_;
  }

 private:
  LearningDataFrame learning_data_frame_;
  std::vector<common::TrajectoryPoint>
      learning_data_adc_future_trajectory_points_;
  bool is_learning_trajectory_valid_ = false;
};

}  // namespace planning
}  // namespace apollo
