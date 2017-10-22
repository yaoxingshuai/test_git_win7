/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef REUSE_HH_3238689037__H_
#define REUSE_HH_3238689037__H_


#include <sstream>
#include "boost/any.hpp"
#include "Specific.hh"
#include "Encoder.hh"
#include "Decoder.hh"

namespace ru {
struct F {
    bool g1;
    int32_t g2;
    F() :
        g1(bool()),
        g2(int32_t())
        { }
};

struct outer {
    F f1;
    F f2;
    outer() :
        f1(F()),
        f2(F())
        { }
};

}
namespace avro {
template<> struct codec_traits<ru::F> {
    static void encode(Encoder& e, const ru::F& v) {
        avro::encode(e, v.g1);
        avro::encode(e, v.g2);
    }
    static void decode(Decoder& d, ru::F& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.g1);
                    break;
                case 1:
                    avro::decode(d, v.g2);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.g1);
            avro::decode(d, v.g2);
        }
    }
};

template<> struct codec_traits<ru::outer> {
    static void encode(Encoder& e, const ru::outer& v) {
        avro::encode(e, v.f1);
        avro::encode(e, v.f2);
    }
    static void decode(Decoder& d, ru::outer& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.f1);
                    break;
                case 1:
                    avro::decode(d, v.f2);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.f1);
            avro::decode(d, v.f2);
        }
    }
};

}
#endif
