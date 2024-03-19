// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "openvino/op/op.hpp"
#include "snippets/shape_inference/shape_inference.hpp"

namespace ov {
namespace snippets {
namespace op {

/**
 * @interface RankNormalization
 * @brief Generated by Canonicalization for rank normalization purposes. It can prepend input shapes with seve1s only first or last dimensions.
 * @arg num_prepend - num `1`s that will be inserted at the beginning of the input shape. Any value is allowed.
 * @arg num_append - num `1`s that will be inserted at the end of the input shape. Could be either 0 (default) or 1;
 * @ingroup snippets
 */
 // Note that technically the same goal could be achieved using op::Unsqueeze operation,
 // but RankNormalization has a much narrower semantics, and hence allows for an easier control and a more efficient shape infer.
 //
class  RankNormalization : public ov::op::Op {
public:
    OPENVINO_OP("RankNormalization", "SnippetsOpset");

    RankNormalization() = default;
    RankNormalization(const Output<Node>& data, size_t num_prepend, size_t num_append);

    void validate_and_infer_types() override;
    bool visit_attributes(AttributeVisitor& visitor) override;
    std::shared_ptr<Node> clone_with_new_inputs(const OutputVector& new_args) const override;

    size_t get_num_append() const { return m_num_append; }
    size_t get_num_prepend() const { return m_num_prepend; }

    class ShapeInfer : public IShapeInferSnippets {
        size_t m_num_prepend = 0;
        size_t m_num_append = 0;
    public:
        explicit ShapeInfer(const std::shared_ptr<ov::Node>& n);
        IShapeInferSnippets::Result
        infer(const std::vector<VectorDimsRef>& input_shapes) override;
    };

private:
    size_t m_num_prepend = 0;
    size_t m_num_append = 0;
};

} // namespace op
} // namespace snippets
} // namespace ov
