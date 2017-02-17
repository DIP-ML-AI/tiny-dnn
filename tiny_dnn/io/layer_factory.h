/*
    Copyright (c) 2013, Taiga Nomi
    All rights reserved.

    Use of this source code is governed by a BSD-style license that can be found
    in the LICENSE file.
*/
#pragma once
#include "tiny_dnn/layers/fully_connected_layer.h"
#include "tiny_dnn/util/util.h"

using namespace tiny_dnn::activation;

namespace tiny_dnn {

/**
* create multi-layer perceptron
*/
template <typename activation, typename Iter>
network<sequential> make_mlp(Iter first, Iter last) {
  typedef network<sequential> net_t;
  net_t n;

  Iter next = first + 1;
  for (; next != last; ++first, ++next)
    n << fully_connected_layer(*first, *next) << activation(*next);
  return n;
}

/**
 * create multi-layer perceptron
 */
template <typename activation>
network<sequential> make_mlp(const std::vector<serial_size_t> &units) {
  return make_mlp<activation>(units.begin(), units.end());
}

}  // namespace tiny_dnn
