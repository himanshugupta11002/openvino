// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "shared_test_classes/single_op/scatter_elements_update.hpp"

namespace ov {
namespace test {
TEST_P(ScatterElementsUpdateLayerTest, Inference) {
    run();
}

TEST_P(ScatterElementsUpdate12LayerTest, Inference) {
    run();
}
}  // namespace test
}  // namespace ov
